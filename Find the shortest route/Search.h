#pragma once
#include <vector>
#include "Graph.h"
#include "Path.h"

class Search
{
		Graph graph; //Macierz opisuj�ca schemat po��cze� pomi�dzy w�z�ami
		int rozmiar; //Okresla rozmiar macierzy
		int poczatek; //W�ze� pocz�tkowy
		vector <Path> trasa; //Kontener zawieraj�cy wszystkie mo�liwe trasy biegn�ce od w�z�a pocz�tkowego, generowane
		vector <Path> wynik; //Gotowa tablica tras najkr�tszych.
		vector <int> _obecna_trasa; //Tablica u�ytych w�z��w, zachowuje kolejno�� u�ytych w�z��w

	public:
		Search();
		//Search(int **, int, int);
		~Search();

		Path & getShortestPath(int); //Zwraca tras� do punktu podanego w 1.ARG

	private:
		/*		_badaj(int, int, int) - Metoda rekurencyjna badaj�ca ca�y graf w poszukiwaniu tras od danego punktu pocz�tkowego
		*		Argumenty:
		*		1.ARG int glebokosc - Liczba skok�w od w�z�a pocz�tkowego (Pierwsze wywo�anie = 0)
		*		2.ARG int suma - Bie��cy koszt tej trasy (Pierwsze wywo�anie = 0)
		*		3.ARG int obecny - Nr w�z�a w kt�rym obecnie si� znajduje (Pierwsze wywo�anie = W�ze� pocz�tkowy)
		*/
		void _badaj(int, int, int); //Metoda rekurencyjna badaj�ca ca�y graf w poszukiwaniu tras od danego punktu pocz�tkowego

									//Metody pomocnicze
		void _wyznaczNastepne(int, int *) const; //Zwraca indeks w�z�a s�siaduj�cego z podanym w 1.ARG w zale�no�ci od minimalnego kosztu. 2.ARG - Kolejna iteracja
		void _uzupelnijWyniki(); //Uzupe�nia tablic� tras najkr�tszych gotow� do p�niejszej obr�bki
		void _sortuj(int, int); //Sortuje kontener "trasa" algorytmem "Quick Sort", aby �atwiej wydoby� okre�lone informacje

								//Metody do kontroli stanu w�z��w
		void _uzyjWezla(int); //Zapisuje stan w�z�a jako u�yty
		bool _czyUzytyWezel(int) const; //Zwraca stan w�z�a
		void _zwolnijWezel(int); //Zapisuje stan w�z�a jako wolny
};

