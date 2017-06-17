#include "File.h"
#include <sstream>

using namespace std;

File::File(Graph & graph)
	: graph(&graph), file_path_("")
{}

File::~File()
{
	if (isGood()) handle.close();
}

void File::load()
{
	try { file_path_ = fileOpenDialog(); }
	catch (Info & i) { i.sysWindow(); return; }
	if (isGood()) handle.close();
	handle.open(file_path_, ios::in);
	if (isGood() && graph != nullptr)
	{
		if (parseFile() == 0) throw WarningException("Failed to open file");
		handle.close();
	}
	else throw WarningException("Failed to open file");
}

void File::save()
{
	if (!isGood())
	{
		try { file_path_ = fileSaveDialog(); }
		catch (Info & i) { i.sysWindow(); return; }
	}
	handle.close();
	handle.open(file_path_, ios::out | ios::trunc);
	if (!isGood()) throw WarningException("Failed to save file");
	createFile();
}

bool File::isGood() const
{
	return handle.good();
}

string File::fileOpenDialog()
{
	OPENFILENAME ofn;
	char sFilename[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = "Graph Files (*.grh)\0*.grh\0Text Files (*.txt)\0*.txt\0All Files\0*.*\0";
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFile = sFilename;
	ofn.lpstrDefExt = "grh";
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	if (!GetOpenFileName(&ofn)) throw Info("Load canceled");
	return ofn.lpstrFile;
}

string File::fileSaveDialog()
{
	OPENFILENAME ofn;
	char sFilename[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = "Graph File (*.grh)\0*.grh\0Text File (*.txt)\0*.txt\0";
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFile = sFilename;
	ofn.lpstrDefExt = "grh";
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	if (!GetSaveFileName(&ofn)) throw Info("Save canceled");
	return ofn.lpstrFile;
}

int File::parseFile()
{
	if (!isGood()) return 0;
	handle.seekg(0);
	vector<string> file_v;
	vector<string> file_m;
	string tmp;
	for (int i = 0; !handle.eof(); i++)
	{
		getline(handle, tmp);
		if (tmp[0] == 'V' || tmp[0] == 'v')
		{
			tmp[0] = ' ';
			file_v.push_back(tmp);
		}
		if (tmp[0] == 'M' || tmp[0] == 'm')
		{
			tmp[0] = ' ';
			file_m.push_back(tmp);
		}
	}
	handle.seekg(0);
	if (file_v.size() != file_m.size()) return 0;
	
	graph->newGraph();
	stringstream ss;
	for (int i = 0; i < file_v.size(); i++)
	{
		ss.clear();
		float x = 0, y = 0;
		ss << file_v[i];
		ss >> x >> y;
		graph->addVertex(sf::Vector2f(x, y));
	}
	for (int i = 0; i < file_m.size(); i++)
	{
		ss.clear();
		ss << file_m[i];
		for (int j = 0; j < file_m.size(); j++)
		{
			float x = 0;
			ss >> x;
			graph->addConnect(i, j, x);
		}
	}
	return file_v.size();
}

void File::createFile()
{
	for (int i = 0; i < graph->getSize(); i++)
	{
		handle << "V " << graph->getVertex()[i].getPos().x << " " << graph->getVertex()[i].getPos().y << endl;
	}
	handle << endl;
	for (int i = 0; i < graph->getSize(); i++)
	{
		handle << "M ";
		for (int j = 0; j < graph->getSize(); j++)
			handle << graph->getMatrix()[i][j] << " ";
		handle << endl;
	}
}