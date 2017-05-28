#include "File.h"

using namespace std;

File::File(string filename)
{
	setFilename(filename);
}

File::~File()
{
	if (handle.good()) handle.close();
}

Graph File::open()
{
	handle.open(filename, ios::in);
	if (!handle.good()) throw WarningException("Failed to open file: " + filename);
}

void File::setFilename(string filename)
{
	if (filename.length() > 0) this->filename = filename;
	else throw WarningException("Filename is wrong");
}

bool File::isCorrect()
{
	if (!handle.good()) return false;

	string tmp;
	int n = 0;
	while (!handle.eof())
	{
		getline(handle, tmp);
		n++;
	}
	handle.seekg(0, ios::beg);
	if (n <= 0) return false;


	return true;
}
/*
void Plik::_wczytaj()
{
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
		{
			string tmp = "-1";
			p >> tmp;
			dane[i][j] = atoi(tmp.c_str());
		}
}*/