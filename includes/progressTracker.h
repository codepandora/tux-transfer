#ifndef PROGRESSTRACKER
#define PROGRESSTRACKER

#include<iostream>
#include<string.h>
#include "../lib/pugi/pugixml.hpp"

using namespace std;

class progressTracker
{
	static bool instantiated;
	static progressTracker* progressTrackerPtr;
	progressTracker();

	public:
		static progressTracker* getInstance();
		
};

#endif
