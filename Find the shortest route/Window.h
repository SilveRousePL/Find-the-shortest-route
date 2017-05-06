#pragma once
#include "Graph.h"
#include "Button.h"
#include <vector>

using namespace std;

class Window
{
	Graph graph;
	vector<Button> button;

public:
	Window();
	~Window();

	void MainLoop();
};
