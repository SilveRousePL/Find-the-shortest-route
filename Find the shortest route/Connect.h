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
	void update(Vertex& vertex_begin, Vertex& vertex_end); //Aktualizacja wygl¹du obiektu
	double calcLength(Vertex & vertex_begin, Vertex & vertex_end) const; //Obliczanie d³ugoœci obiektu na pods. odleg³oœci pomiêdzy dwoma wierzcho³kami
	double calcAngle(Vertex & vertex_begin, Vertex & vertex_end) const; //Obliczanie k¹ta nachylenia obiektu
	sf::Vector2f calcCenter(Vertex& vertex_begin, Vertex& vertex_end) const; //Oblicza punkt centralny pomiêdzy dwoma wierzcho³kami
	void setID(int id_begin, int id_end); //Ustawia ID

	sf::Vector2i getVertexID() const; //Pobranie ID wierzcho³ków po³¹czonych tym po³¹czeniem
	sf::RectangleShape getShape() const;
	void setCost(unsigned int c); //Ustawia koszt po³¹czenia
	void setColor(sf::Color color); //Ustawia kolor
};
