#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Vertex.h"

class Connect : public sf::Drawable, public sf::Transformable
{
	int id_begin;
	int id_end;
	sf::RectangleShape line;
	sf::CircleShape arrowhead;
	sf::RectangleShape background;
	sf::Text cost;

public:
	Connect(int id_begin, int id_end, sf::Font & font, unsigned int cost);
	~Connect();

	void draw(sf::RenderTarget &, sf::RenderStates) const final; //Rysowanie obiektu
	void update(Vertex& vertex_begin, Vertex& vertex_end); //Aktualizacja wyglądu obiektu
	double calcLength(Vertex & vertex_begin, Vertex & vertex_end) const; //Obliczanie długości obiektu na pods. odległości pomiędzy dwoma wierzchołkami
	double calcAngle(Vertex & vertex_begin, Vertex & vertex_end) const; //Obliczanie kąta nachylenia obiektu
	sf::Vector2f calcCenter(Vertex& vertex_begin, Vertex& vertex_end) const; //Oblicza punkt centralny pomiędzy dwoma wierzchołkami
	void setID(int id_begin, int id_end); //Ustawia ID

	sf::Vector2i getVertexID() const; //Pobranie ID wierzchołków połączonych tym połączeniem
	sf::RectangleShape getShape() const;
	void setCost(unsigned int c); //Ustawia koszt połączenia
	void setColor(sf::Color color); //Ustawia kolor
};
