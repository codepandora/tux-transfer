#ifndef PROGRESS_TRACKER
#define PROGRESS_TRACKER

#include<iostream>
#include<string.h>
#include "../lib/pugi/pugixml.hpp"

using namespace std;

class ProgressTracker
{
	const static bool instantiated = false;
	const static ProgressTracker* ProgressTrackerPtr;
	ProgressTracker();

	public:
		static ProgressTracker* getInstance();
		
};

#endif
