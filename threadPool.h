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
  ThreadPool(size_t pool_size );
  

  // Destructor.
  ~ThreadPool();

  //Add task to the thread pool if a thread is currently available.
  template < typename Task >
  void run_task( Task task );

private:
  // Entry point for pool threads.
  void pool_main();
};

#endif
