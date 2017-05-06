#pragma once
#include <fstream>
#include <string>

using namespace std;

class File
{
	fstream f;
	string name;

public:
	File();
	~File();

	bool Read();
	bool Write();
};

