#pragma once
#include <vector>
#include "Vertex.h"
#include "Connect.h"
#include "Path.h"
#include "Search.h"

class Graph : public sf::Drawable, public sf::Transformable
{
	typedef std::vector<std::vector<int>> Matrix;
	Matrix adjacency; //Macierz s�siedztwa grafu
	std::vector <Vertex> vertex; //Zbi�r wierzcho�k�w
	std::vector <Connect> connect; //Zbi�r po��cze�
	sf::Font font; //Czcionka (dobr� praktyk� jest zrobienie Resource Managera, ale �adowany jest tylko jeden element, wi�c jest to zb�dne)

public:
	Graph();
	~Graph();

	void draw(sf::RenderTarget &, sf::RenderStates) const final; //Metoda rysuj�ca

	void newGraph(); //Wyczyszczenie istniej�cego grafu
	void addVertex(sf::Vector2f pos); //Dodaj wierzcho�ek
	void addConnect(int id_begin, int id_end, unsigned int cost); //Dodaj po��czenie
	//void remVertex(int id_vertex); //Usu� wierzcho�ek
	void remConnect(int id_connect); //Usu� po��czenie
	Path findShortestPath(int id_begin, int id_end); //Znajd� najkr�tsz� scie�k�

	size_t getSize() const; //Pobierz rozmiar
	std::vector <Vertex> getVertex() const; //Pobierz kontener wierzcho�k�w
	Matrix getMatrix() const; //Pobierz macierz s�siedztwa
	int getIDConnectByVertexsID(int id_begin, int id_end) const; //Znajd� ID po��czenia na pods. ID wierzcho�k�w po��czonych

	void setVertexPosition(int id, sf::Vector2f position); //Ustaw pozycj� wierzcho�ka
	void setFont(sf::Font font); //Ustaw czcionk�
	void setColorV(int id, sf::Color color); //Ustaw kolor wierzcho�ka
	void setColorC(int id, sf::Color color); //Ustaw kolor po��czenia
	void coloringPath(Path path, sf::Color color); //Pokoloruj wierzcho�ki i po��czenia na podstawie podanej trasy
	void deleteColoring(sf::Color color); //Usu� wszystkie wcze�niej ustawione kolory

	int detectVertex(sf::Vector2f position); //Zwraca ID wierzcho�ka na podstawie pozycji (np. kursora) na ekranie
	int detectConnect(sf::Vector2f position); //Zwraca ID po��czenia na podstawie pozycji (np. kursora) na ekranie
	void refreshConnects(); //Od�wie�enie wygl�du po��cze� (k�t nachylenia itp.)
};
