#pragma once
#include <vector>
#include "Vertex.h"
#include "Connect.h"
#include "Path.h"
#include "Search.h"

class Graph : public sf::Drawable, public sf::Transformable
{
	typedef std::vector<std::vector<int>> Matrix;
	Matrix adjacency; //Macierz s¹siedztwa grafu
	std::vector <Vertex> vertex; //Zbiór wierzcho³ków
	std::vector <Connect> connect; //Zbiór po³¹czeñ
	sf::Font font; //Czcionka (dobr¹ praktyk¹ jest zrobienie Resource Managera, ale ³adowany jest tylko jeden element, wiêc jest to zbêdne)

public:
	Graph();
	~Graph();

	void draw(sf::RenderTarget &, sf::RenderStates) const final; //Metoda rysuj¹ca

	void newGraph(); //Wyczyszczenie istniej¹cego grafu
	void addVertex(sf::Vector2f pos); //Dodaj wierzcho³ek
	void addConnect(int id_begin, int id_end, unsigned int cost); //Dodaj po³¹czenie
	//void remVertex(int id_vertex); //Usuñ wierzcho³ek
	void remConnect(int id_connect); //Usuñ po³¹czenie
	Path findShortestPath(int id_begin, int id_end); //ZnajdŸ najkrótsz¹ scie¿kê

	size_t getSize() const; //Pobierz rozmiar
	std::vector <Vertex> getVertex() const; //Pobierz kontener wierzcho³ków
	Matrix getMatrix() const; //Pobierz macierz s¹siedztwa
	int getIDConnectByVertexsID(int id_begin, int id_end) const; //ZnajdŸ ID po³¹czenia na pods. ID wierzcho³ków po³¹czonych

	void setVertexPosition(int id, sf::Vector2f position); //Ustaw pozycjê wierzcho³ka
	void setFont(sf::Font font); //Ustaw czcionkê
	void setColorV(int id, sf::Color color); //Ustaw kolor wierzcho³ka
	void setColorC(int id, sf::Color color); //Ustaw kolor po³¹czenia
	void coloringPath(Path path, sf::Color color); //Pokoloruj wierzcho³ki i po³¹czenia na podstawie podanej trasy
	void deleteColoring(sf::Color color); //Usuñ wszystkie wczeœniej ustawione kolory

	int detectVertex(sf::Vector2f position); //Zwraca ID wierzcho³ka na podstawie pozycji (np. kursora) na ekranie
	int detectConnect(sf::Vector2f position); //Zwraca ID po³¹czenia na podstawie pozycji (np. kursora) na ekranie
	void refreshConnects(); //Odœwie¿enie wygl¹du po³¹czeñ (k¹t nachylenia itp.)
};
