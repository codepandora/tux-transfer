#include<boost/progress.hpp>
#include<boost/timer.hpp>
#include<vector>

using namespace std;

int main(void)
{
	int cnt = 100;
	boost::progress_display showProgress( cnt );
	for( int i=0; i<cnt;i++)
	{
		volatile vector<int> v(1024*1000);
		++showProgress;
	}
	return 1;
}