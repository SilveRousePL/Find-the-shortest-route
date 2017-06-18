#include <iostream>
#include "Window.h"
#include "Graph.h"
#include "Exceptions.h"

using namespace std;

int main()
{
	try
	{
		Window win(1024,768);
		win.run();
	}
	catch(CriticalException & e) //³apanie krytycznych wyj¹tków
	{
		e.sysWindow();
	}
	catch(...) //³apanie nieznanych wyj¹tków
	{
		CriticalException e("Unknown error");
		e.sysWindow();
	}
	return 0;
}