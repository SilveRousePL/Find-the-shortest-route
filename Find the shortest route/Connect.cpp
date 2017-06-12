#include "Connect.h"
#include "Exceptions.h"

using namespace std;

Connect::Connect(Vertex * begin, Vertex * end, sf::Font font, string cost) : vertex_begin(begin), vertex_end(end)
{
	this->cost.setFont(font);
	this->cost.setFillColor(sf::Color(0, 0, 0));
	setCost(cost);

	line.setFillColor(sf::Color(0, 0, 0));

	update();
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

void Connect::update()
{
	length = calcLength();
	angle = calcAngle();

	line.setPosition(vertex_begin->getPosition());
	line.setSize(sf::Vector2f(length, 2));

	this->setRotation(angle);
}

void Connect::setCost(string cost)
{
	if (cost[cost.length()-1] == 6 || cost[cost.length() - 1] == 9) cost += ".";
	this->cost.setString(cost);
	this->cost.setPosition(sf::Vector2f(length - this->cost.getGlobalBounds().width / 2, -1 * this->cost.getCharacterSize() - 5));

	//text->move(sf::Vector2f(shape->get))
	//text.move(sf::Vector2f((size.x - text.getGlobalBounds().width) / 2, (size.y - text.getCharacterSize()) / 2));
}

void Connect::setColor(sf::Color color, float outline_thickness=10)
{
	line.setOutlineThickness(outline_thickness);
	line.setOutlineColor(color);
}

double Connect::calcLength() const
{
	double tmp = (vertex_end->getPosition().x - vertex_begin->getPosition().x)*(vertex_end->getPosition().x - vertex_begin->getPosition().x) + (vertex_end->getPosition().y - vertex_begin->getPosition().y)*(vertex_end->getPosition().y - vertex_begin->getPosition().y);
	if (tmp < 0) throw CriticalException("The argument of sqrt() is less than zero. (ConnectUI.cpp)");
	return sqrt(tmp);
}

double Connect::calcAngle() const
{
	double ly = vertex_end->getPosition().y - vertex_begin->getPosition().y;
	double lx = vertex_end->getPosition().x - vertex_begin->getPosition().x;
	if (lx == 0) return -90;
	return -atan(ly / lx) * (180 / 3.14159265359);
}
