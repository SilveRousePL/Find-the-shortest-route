#pragma once
#include <vector>
#include "Graph.h"
#include "Path.h"

class Search
{
	Graph graph; //Macierz opisuj¹ca schemat po³¹czeñ pomiêdzy wêz³ami
	size_t size; //Okresla rozmiar macierzy
	size_t start; //Wêze³ pocz¹tkowy
	size_t end; //Wêze³ koñcowy
	std::vector <Path> path; //Kontener zawieraj¹cy wszystkie mo¿liwe trasy biegn¹ce od wêz³a pocz¹tkowego do koñcowego
	Path result; //Trasa najkrótsza.

	std::vector <size_t> tmp_path_; //Tablica u¿ytych wêz³ów, zachowuje kolejnoœæ u¿ytych wêz³ów

public:
	Search(Graph graph, size_t start, size_t end);
	~Search();

	Path getShortestPath() const; //Zwraca trasê do punktu podanego w 1.ARG

private:
		/*		_badaj(int, int, int) - Metoda rekurencyjna badaj¹ca ca³y graf w poszukiwaniu tras od danego punktu pocz¹tkowego
		*		Argumenty:
		*		1.ARG int glebokosc - Liczba skoków od wêz³a pocz¹tkowego (Pierwsze wywo³anie = 0)
		*		2.ARG int suma - Bie¿¹cy koszt tej trasy (Pierwsze wywo³anie = 0)
		*		3.ARG int obecny - Nr wêz³a w którym obecnie siê znajduje (Pierwsze wywo³anie = Wêze³ pocz¹tkowy)
		*/
	void look_(int, int, int); //Metoda rekurencyjna badaj¹ca ca³y graf w poszukiwaniu tras od danego punktu pocz¹tkowego

									//Metody pomocnicze
	void _wyznaczNastepne(int, int *) const; //Zwraca indeks wêz³a s¹siaduj¹cego z podanym w 1.ARG w zale¿noœci od minimalnego kosztu. 2.ARG - Kolejna iteracja
	void _uzupelnijWyniki(); //Uzupe³nia tablicê tras najkrótszych gotow¹ do póŸniejszej obróbki
	void _sortuj(int, int); //Sortuje kontener "trasa" algorytmem "Quick Sort", aby ³atwiej wydobyæ okreœlone informacje

								//Metody do kontroli stanu wêz³ów
	void useVertex_(int); //Zapisuje stan wêz³a jako u¿yty
	bool isUsedVertex_(int) const; //Zwraca stan wêz³a
	void releaseVertex_(int); //Zapisuje stan wêz³a jako wolny
};

