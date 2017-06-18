#pragma once
#include <vector>
#include "Path.h"
#include "Exceptions.h"

class Search
{
	typedef std::vector<std::vector<int>> Matrix;
	int ** vertex_map; //Mapa w�z��w
	int ** adjacency_matrix; //Macierz s�siedztwa
	size_t size; //Rozmiar macierzy (ilo�� w�z��w)
	int id_begin; //ID w�z�a pocz�tkowego
	int id_end; //ID w�z�a ko�cowego
	Path * result = nullptr; //Trasa najkr�tsza.

	std::vector <int> tmp_path_; //Tablica ID u�ytych w�z��w, zachowuje kolejno�� u�ycia

public:
	Search(Matrix & adjacency_matrix, int id_begin, int id_end);
	~Search();

	Path getShortestPath() const; //Zwraca rezultat wyszukiwania

private:
	void look_(int deep, int sum, int current); //Metoda rekurencyjna badaj�ca graf w poszukiwaniu najkr�tszej trasy pomi�dzy dwoma w�z�ami											  
	/* Argumenty:
	deep - Liczba skok�w od w�z�a pocz�tkowego (Pierwsze wywo�anie = 0)
	sum - Bie��cy koszt tej trasy (Pierwsze wywo�anie = 0)		
	current - Nr w�z�a w kt�rym obecnie si� znajduje (Pierwsze wywo�anie = W�ze� pocz�tkowy) */
															   
	void generateVertexMap_(); //Generuje map� w�z��w na podstawie macierzy s�siedztwa
	void useVertex_(int); //Zapisuje stan w�z�a jako u�yty
	bool isUsedVertex_(int) const; //Zwraca stan w�z�a
	void releaseVertex_(int); //Zapisuje stan w�z�a jako wolny
};

