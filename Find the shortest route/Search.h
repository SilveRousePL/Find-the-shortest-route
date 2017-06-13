#pragma once
#include <vector>
#include "Array2D.h"
#include "Graph.h"
#include "Path.h"

class Search
{
	uint8_t ** vertex_map; //Mapa wêz³ów
	uint8_t ** neighbor_matrix; //Macierz s¹siedztwa
	size_t size; //Rozmiar macierzy (iloœæ wêz³ów)
	uint8_t id_begin; //ID wêz³a pocz¹tkowego
	uint8_t id_end; //ID wêz³a koñcowego
	Path * result = nullptr; //Trasa najkrótsza.

	std::vector <uint8_t> tmp_path_; //Tablica ID u¿ytych wêz³ów, zachowuje kolejnoœæ u¿ycia

public:
	Search(Graph graph, uint8_t id_begin, uint8_t id_end);
	~Search();

	Path getShortestPath() const; //Zwraca rezultat wyszukiwania

private:
	void look_(uint8_t deep, uint8_t sum, uint8_t current); //Metoda rekurencyjna badaj¹ca graf w poszukiwaniu najkrótszej trasy pomiêdzy dwoma wêz³ami											  
	/* Argumenty:
	deep - Liczba skoków od wêz³a pocz¹tkowego (Pierwsze wywo³anie = 0)
	sum - Bie¿¹cy koszt tej trasy (Pierwsze wywo³anie = 0)		
	current - Nr wêz³a w którym obecnie siê znajduje (Pierwsze wywo³anie = Wêze³ pocz¹tkowy) */
															   
	void generateVertexMap_(); //Generuje mapê wêz³ów
	void useVertex_(uint8_t); //Zapisuje stan wêz³a jako u¿yty
	bool isUsedVertex_(uint8_t) const; //Zwraca stan wêz³a
	void releaseVertex_(uint8_t); //Zapisuje stan wêz³a jako wolny
};

