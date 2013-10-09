#ifndef THREAD_POOL
#define THREAD_POOL

#include <queue>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

using namespace std;

class ThreadPool
{
private:
  queue< boost::function<void()> > tasks_;
  boost::thread_group threads_;
  size_t available_;
  boost::mutex mutex_;
  boost::condition_variable condition_;
  bool running_;

public:

  // Constructor.
  ThreadPool(size_t pool_size ) : available_( pool_size ), running_( true )
  {
    for (size_t i = 0; i < pool_size; ++i)
    {
      threads_.create_thread( boost::bind( &ThreadPool::pool_main, this ) ) ;
	cout<<"Thread Created"<<endl;
    }
  }

  // Destructor.
  ~ThreadPool()
  {
    // Set running flag to false then notify all threads.
    {
      boost::unique_lock<boost::mutex> lock(mutex_);
      running_ = false;
      condition_.notify_all();
    }

    try
    {
      threads_.join_all();
    }
    // Suppress all exceptions.
    catch ( ... ) {}
  }

  //Add task to the thread pool if a thread is currently available.
  template < typename Task >
  void run_task( Task task )
  {
    boost::unique_lock< boost::mutex > lock( mutex_ );

    // If no threads are available, then return.
    if ( available_ == 0 ) return;

    // Decrement count, indicating thread is no longer available.
    --available_;

    // Set task and signal condition variable so that a worker thread will
    // wake up andl use the task.
    tasks_.push( boost::function< void() >( task ) );
    condition_.notify_one();
  }

private:
  // Entry point for pool threads.
  void pool_main()
  {
    while( running_ )
    {
      // Wait on condition variable while the task is empty and the pool is
      // still running.
      boost::unique_lock< boost::mutex > lock( mutex_ );
      while ( tasks_.empty() && running_ )
      {
        condition_.wait( lock );
      }
      // If pool is no longer running, break out.
      if ( !running_ ) break;

      // Copy task locally and remove from the queue.  This is done within
      // its own scope so that the task object is destructed immediately
      // after running the task.  This is useful in the event that the
      // function contains shared_ptr arguments bound via bind.
      {
        boost::function< void() > task = tasks_.front();
        tasks_.pop();

        lock.unlock();

        // Run the task.
        try
        {
          task();
        }
        // Suppress all exceptions.
        catch ( ... ) {}
      }

      // Task has finished, so increment count of available threads.
      lock.lock();
      ++available_;
    } // while running_
  }
};

#endif

void work() 
{
 while(1)
 {
	cout<<"Work"<<endl;
	try
        {
            // Sleep and check for interrupt.
            // To check for interrupt without sleep,
            // use boost::this_thread::interruption_point()
            // which also throws boost::thread_interrupted
            boost::this_thread::sleep(boost::posix_time::milliseconds(500));
        }
        catch(boost::thread_interrupted&)
        {
            cout << "Thread is stopped" << endl;
            return;
        }  
 }
}

void more_work( int n) 
{
   while(1)
 {
	cout<<n<<endl;
	try
        {
            // Sleep and check for interrupt.
            // To check for interrupt without sleep,
            // use boost::this_thread::interruption_point()
            // which also throws boost::thread_interrupted
            boost::this_thread::sleep(boost::posix_time::milliseconds(500));
        }
        catch(boost::thread_interrupted&)
        {
            cout << "Thread is stopped" << endl;
            return;
        }  
 }

}

int main()
{
  cout<<"Starting Thread Pool"<<endl; 
  ThreadPool pool( 3 );
  pool.run_task( work );                        // Function pointer.
  pool.run_task( work );                    
  pool.run_task( boost::bind( more_work, 5 ) ); // Callable object.

  char ch;
  cin>>ch;

  return 0;
}
