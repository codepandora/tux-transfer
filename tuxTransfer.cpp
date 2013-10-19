#include "src/CopyInstance.cpp"



int main(int argc, char* argv[])
{
	const char* srcs[] = {"/home/droidboyjr/Pictures/bans","/home/droidboyjr/Pictures/background.jpg"};
	const char* dest = "/home/droidboyjr/Documents/fresh";
	copyInstance ci( srcs, 2, dest );


	return 1;
}