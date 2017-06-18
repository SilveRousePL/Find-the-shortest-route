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
	catch(CriticalException & e) //�apanie krytycznych wyj�tk�w
	{
		e.sysWindow();
	}
	catch(...) //�apanie nieznanych wyj�tk�w
	{
		CriticalException e("Unknown error");
		e.sysWindow();
	}
	return 0;
}