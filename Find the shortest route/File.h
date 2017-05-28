#pragma once
#include <fstream>
#include <string>
#include "Graph.h"
#include "Exceptions.h"

class File
{
	std::fstream handle;
	std::string filename;
	Graph * graph;
	int ** data;

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