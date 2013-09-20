#include "../includes/progressTracker.h"

progressTracker* progressTracker::getInstance()
{
	if(! instantiated )
	{
		progressTrackerPtr = new progressTracker();
		return progressTrackerPtr;
	}
	return progressTrackerPtr;
}

progressTracker::progressTracker()
{
	cout<<"hello";
}

int main(void)
{
	progressTracker* tracker = progressTracker::getInstance();
	return 1;
}
