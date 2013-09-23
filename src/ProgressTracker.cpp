#include "../includes/ProgressTracker.h"

ProgressTracker* ProgressTracker::getInstance()
{
	if(! instantiated )
	{
		ProgressTrackerPtr = new ProgressTracker();
		return ProgressTrackerPtr;
	}
	return ProgressTrackerPtr;
}

ProgressTracker::ProgressTracker()
{
	cout<<"hello";
}

int main(void)
{
	ProgressTracker* tracker = ProgressTracker::getInstance();
	return 1;
}
