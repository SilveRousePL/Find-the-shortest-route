#pragma once
#include <vector>
#include "Array2D.h"
#include "Graph.h"
#include "Path.h"

class Search
{
	uint8_t ** vertex_map; //Mapa w�z��w
	uint8_t ** neighbor_matrix; //Macierz s�siedztwa
	size_t size; //Rozmiar macierzy (ilo�� w�z��w)
	uint8_t id_begin; //ID w�z�a pocz�tkowego
	uint8_t id_end; //ID w�z�a ko�cowego
	Path * result = nullptr; //Trasa najkr�tsza.

	std::vector <uint8_t> tmp_path_; //Tablica ID u�ytych w�z��w, zachowuje kolejno�� u�ycia

public:
	Search(Graph graph, uint8_t id_begin, uint8_t id_end);
	~Search();

	Path getShortestPath() const; //Zwraca rezultat wyszukiwania

private:
	void look_(uint8_t deep, uint8_t sum, uint8_t current); //Metoda rekurencyjna badaj�ca graf w poszukiwaniu najkr�tszej trasy pomi�dzy dwoma w�z�ami											  
	/* Argumenty:
	deep - Liczba skok�w od w�z�a pocz�tkowego (Pierwsze wywo�anie = 0)
	sum - Bie��cy koszt tej trasy (Pierwsze wywo�anie = 0)		
	current - Nr w�z�a w kt�rym obecnie si� znajduje (Pierwsze wywo�anie = W�ze� pocz�tkowy) */
															   
	void generateVertexMap_(); //Generuje map� w�z��w
	void useVertex_(uint8_t); //Zapisuje stan w�z�a jako u�yty
	bool isUsedVertex_(uint8_t) const; //Zwraca stan w�z�a
	void releaseVertex_(uint8_t); //Zapisuje stan w�z�a jako wolny
};

