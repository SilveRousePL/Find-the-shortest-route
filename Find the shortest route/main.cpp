#include <iostream>
#include <string>
#include "Graph.h"
#include "Window.h"
#include <windows.h>

using namespace std;

int main()
{
	try
	{
		Window win(0,0);
		win.mainLoop();
	}
	catch(string & e)
	{
		MessageBox(nullptr, 
			("Exception occurred and application will be closed.\n" + e).c_str(), 
			"Error, exception occurred", MB_ICONERROR | MB_DEFBUTTON1);
	}
	return 0;
}