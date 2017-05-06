#pragma once
#include <string>

using namespace std;

class Button
{
	int width;
	int height;
	string name;
	int color[3];

public:
	Button();
	~Button();

	void SetColor(int[3]);
};

