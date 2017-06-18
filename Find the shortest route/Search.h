#pragma once
#include <vector>
#include "Path.h"
#include "Exceptions.h"

class Search
{
	typedef std::vector<std::vector<int>> Matrix;
	int ** vertex_map; //Mapa wêz³ów
	int ** adjacency_matrix; //Macierz s¹siedztwa
	size_t size; //Rozmiar macierzy (iloœæ wêz³ów)
	int id_begin; //ID wêz³a pocz¹tkowego
	int id_end; //ID wêz³a koñcowego
	Path * result = nullptr; //Trasa najkrótsza.

	std::vector <int> tmp_path_; //Tablica ID u¿ytych wêz³ów, zachowuje kolejnoœæ u¿ycia

public:
	Search(Matrix & adjacency_matrix, int id_begin, int id_end);
	~Search();

	Path getShortestPath() const; //Zwraca rezultat wyszukiwania

private:
	void look_(int deep, int sum, int current); //Metoda rekurencyjna badaj¹ca graf w poszukiwaniu najkrótszej trasy pomiêdzy dwoma wêz³ami											  
	/* Argumenty:
	deep - Liczba skoków od wêz³a pocz¹tkowego (Pierwsze wywo³anie = 0)
	sum - Bie¿¹cy koszt tej trasy (Pierwsze wywo³anie = 0)		
	current - Nr wêz³a w którym obecnie siê znajduje (Pierwsze wywo³anie = Wêze³ pocz¹tkowy) */
															   
	void generateVertexMap_(); //Generuje mapê wêz³ów na podstawie macierzy s¹siedztwa
	void useVertex_(int); //Zapisuje stan wêz³a jako u¿yty
	bool isUsedVertex_(int) const; //Zwraca stan wêz³a
	void releaseVertex_(int); //Zapisuje stan wêz³a jako wolny
};

