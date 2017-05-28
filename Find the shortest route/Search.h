#pragma once
#include <vector>
#include "Graph.h"
#include "Path.h"

class Search
{
		Graph graph; //Macierz opisuj¹ca schemat po³¹czeñ pomiêdzy wêz³ami
		int rozmiar; //Okresla rozmiar macierzy
		int poczatek; //Wêze³ pocz¹tkowy
		vector <Path> trasa; //Kontener zawieraj¹cy wszystkie mo¿liwe trasy biegn¹ce od wêz³a pocz¹tkowego, generowane
		vector <Path> wynik; //Gotowa tablica tras najkrótszych.
		vector <int> _obecna_trasa; //Tablica u¿ytych wêz³ów, zachowuje kolejnoœæ u¿ytych wêz³ów

	public:
		Search();
		//Search(int **, int, int);
		~Search();

		Path & getShortestPath(int); //Zwraca trasê do punktu podanego w 1.ARG

	private:
		/*		_badaj(int, int, int) - Metoda rekurencyjna badaj¹ca ca³y graf w poszukiwaniu tras od danego punktu pocz¹tkowego
		*		Argumenty:
		*		1.ARG int glebokosc - Liczba skoków od wêz³a pocz¹tkowego (Pierwsze wywo³anie = 0)
		*		2.ARG int suma - Bie¿¹cy koszt tej trasy (Pierwsze wywo³anie = 0)
		*		3.ARG int obecny - Nr wêz³a w którym obecnie siê znajduje (Pierwsze wywo³anie = Wêze³ pocz¹tkowy)
		*/
		void _badaj(int, int, int); //Metoda rekurencyjna badaj¹ca ca³y graf w poszukiwaniu tras od danego punktu pocz¹tkowego

									//Metody pomocnicze
		void _wyznaczNastepne(int, int *) const; //Zwraca indeks wêz³a s¹siaduj¹cego z podanym w 1.ARG w zale¿noœci od minimalnego kosztu. 2.ARG - Kolejna iteracja
		void _uzupelnijWyniki(); //Uzupe³nia tablicê tras najkrótszych gotow¹ do póŸniejszej obróbki
		void _sortuj(int, int); //Sortuje kontener "trasa" algorytmem "Quick Sort", aby ³atwiej wydobyæ okreœlone informacje

								//Metody do kontroli stanu wêz³ów
		void _uzyjWezla(int); //Zapisuje stan wêz³a jako u¿yty
		bool _czyUzytyWezel(int) const; //Zwraca stan wêz³a
		void _zwolnijWezel(int); //Zapisuje stan wêz³a jako wolny
};

