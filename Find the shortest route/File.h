#pragma once
#include <fstream>
#include <windows.h>
#include <string>
#include "Graph.h"
#include "Exceptions.h"

class File
{
	std::fstream handle;
	Graph * graph;
	std::string file_path_;

public:
	File(Graph & graph);
	~File();

	void load();
	void save();
	bool isGood() const;;
	
private:
	std::string fileOpenDialog();
	std::string fileSaveDialog();
	int parseFile();
	void createFile();
};