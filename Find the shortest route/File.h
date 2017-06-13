#pragma once
#include <fstream>
#include <windows.h>
#include <string>
#include "Graph.h"
#include "Exceptions.h"

class File
{
	std::fstream handle;
	std::string file_path_;

public:
	File(std::string);
	~File();

	Graph open();
	bool save(Graph);

	bool isCorrect();
	std::string getFilename() const;
	void setFilename(std::string);
	int ** getData() const;
	int getAmount() const;
	
private:
	void _completeGraph();
};