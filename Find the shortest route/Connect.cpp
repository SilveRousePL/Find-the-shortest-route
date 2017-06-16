#include "Connect.h"
#include "Exceptions.h"

using namespace std;

Connect::Connect(int id_begin, int id_end, sf::Font & font, unsigned int cost)
	: id_begin(id_begin), id_end(id_end)
{
	this->cost.setFont(font);
	this->cost.setFillColor(sf::Color(0, 0, 0));
	setCost(cost);

	line.setFillColor(sf::Color(0, 0, 0));
	line.setOutlineThickness(2);
}

Connect::~Connect()
{

}

void Connect::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(line, states);
	target.draw(cost, states);
}

void Connect::update(Vertex & vertex_begin, Vertex & vertex_end)
{
	line.setPosition(vertex_begin.getPos());
	line.setSize(sf::Vector2f(calcLength(vertex_begin, vertex_end), 2));
	line.setRotation(calcAngle(vertex_begin, vertex_end));
}

double Connect::calcLength(Vertex & vertex_begin, Vertex & vertex_end) const
{
	double tmp = (vertex_end.getPos().x - vertex_begin.getPos().x)*(vertex_end.getPos().x - vertex_begin.getPos().x) + (vertex_end.getPos().y - vertex_begin.getPos().y)*(vertex_end.getPos().y - vertex_begin.getPos().y);
	if (tmp < 0) throw CriticalException("The argument of sqrt() is less than zero. (ConnectUI.cpp)");
	return sqrt(tmp);
}

double Connect::calcAngle(Vertex & vertex_begin, Vertex & vertex_end) const
{
	double ly = vertex_end.getPos().y - vertex_begin.getPos().y;
	double lx = vertex_end.getPos().x - vertex_begin.getPos().x;
	if (lx > 0) return atan(ly / lx) * (180 / M_PI);
	if (lx < 0) return 180 + atan(ly / lx) * (180 / M_PI);
	if (lx == 0 && ly > 0) return -90;
	return 90;
}

void Connect::changeID(int id_begin)
{
	if (this->id_begin >= id_begin && this->id_begin != 0) this->id_begin--;
	if (this->id_end >= id_begin && this->id_end != 0) this->id_end--;
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
	string cost = to_string(c);
	if (cost[cost.length()-1] == '6' || cost[cost.length() - 1] == '9') cost += ".";
	this->cost.setString(cost);
	this->cost.setPosition(sf::Vector2f(length - this->cost.getGlobalBounds().width / 2, -1 * this->cost.getCharacterSize() - 5));

	//text->move(sf::Vector2f(shape->get))
	//text.move(sf::Vector2f((size.x - text.getGlobalBounds().width) / 2, (size.y - text.getCharacterSize()) / 2));
}

void Connect::setColor(sf::Color color)
{
	line.setOutlineColor(color);
}