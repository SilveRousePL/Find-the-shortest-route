#include "Connect.h"
#include "Exceptions.h"

using namespace std;

Connect::Connect(int id_begin, int id_end, sf::Font & font, unsigned int cost)
	: id_begin(id_begin), id_end(id_end), arrowhead(15,3)
{
	this->cost.setFont(font);
	setCost(cost);

	line.setFillColor(sf::Color(255, 255, 255));
	line.setOutlineThickness(2);
	line.setOutlineColor(sf::Color(0, 0, 0));
	arrowhead.setFillColor(sf::Color(255, 255, 255));
	arrowhead.setOutlineThickness(2);
	arrowhead.setOutlineColor(sf::Color(0, 0, 0));
	setColor(sf::Color(255, 255, 255));
}

Connect::~Connect()
{

}

void Connect::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(background, states);
	target.draw(line, states);
	target.draw(cost, states);
	target.draw(arrowhead, states);
}

void Connect::update(Vertex & vertex_begin, Vertex & vertex_end)
{
	double length = calcLength(vertex_begin, vertex_end);
	double angle = calcAngle(vertex_begin, vertex_end);
	sf::Vector2f center = calcCenter(vertex_begin, vertex_end);
	sf::Vector2f cost_origin = sf::Vector2f(vertex_begin.getPos().x - vertex_end.getPos().x + center.x, vertex_begin.getPos().y - vertex_end.getPos().y + center.y);
	line.setPosition(vertex_begin.getPos());
	line.setSize(sf::Vector2f(length, 2));
	line.setRotation(angle);
	background.setPosition(vertex_begin.getPos());
	background.setSize(sf::Vector2f(length, 20));
	background.setRotation(angle);
	arrowhead.setOrigin(15,-20);
	arrowhead.setPosition(vertex_end.getPos());
	arrowhead.setRotation(angle + 90);
	cost.setPosition(center);
	cost.setRotation(angle);
}

double Connect::calcLength(Vertex & vertex_begin, Vertex & vertex_end) const
{
	double tmp = (vertex_end.getPos().x - vertex_begin.getPos().x)*(vertex_end.getPos().x - vertex_begin.getPos().x) + (vertex_end.getPos().y - vertex_begin.getPos().y)*(vertex_end.getPos().y - vertex_begin.getPos().y);
	return sqrt(tmp);
}

double Connect::calcAngle(Vertex & vertex_begin, Vertex & vertex_end) const
{
	double ly = vertex_end.getPos().y - vertex_begin.getPos().y;
	double lx = vertex_end.getPos().x - vertex_begin.getPos().x;
	if (lx > 0) return atan(ly / lx) * (180 / M_PI);
	if (lx < 0) return 180 + atan(ly / lx) * (180 / M_PI);
	if (lx == 0 && ly > 0) return 90;
	return -90;
}

sf::Vector2f Connect::calcCenter(Vertex & vertex_begin, Vertex & vertex_end) const
{
	return sf::Vector2f((vertex_begin.getPos().x + vertex_end.getPos().x) / 2, (vertex_begin.getPos().y + vertex_end.getPos().y) / 2);
}

void Connect::setID(int id_begin, int id_end)
{
	if (id_begin >= 0 && id_end >= 0)
	{
		this->id_begin = id_begin;
		this->id_end = id_end;
	}
}

sf::RectangleShape Connect::getShape() const
{
	return line;
}

sf::Vector2i Connect::getVertexID() const
{
	return sf::Vector2i(id_begin, id_end);
}

void Connect::setCost(unsigned int c)
{
	string c_str = to_string(c);
	if (c_str[c_str.length()-1] == '6' || c_str[c_str.length() - 1] == '9') c_str += ".";
	cost.setString(c_str);
	cost.setCharacterSize(16);
	cost.setFillColor(sf::Color(255, 255, 255));
	cost.setOutlineThickness(2);
	cost.setOutlineColor(sf::Color(0, 0, 0));
}

void Connect::setColor(sf::Color color)
{
	if (color.r > 250 && color.g > 250 && color.b > 250) background.setFillColor(sf::Color(255, 255, 255, 0));
	else background.setFillColor(color);
}