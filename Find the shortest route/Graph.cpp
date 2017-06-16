#include "Graph.h"

using namespace std;

Graph::Graph()
	: shortest_path(nullptr)
{}

Graph::~Graph()
{}

void Graph::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for (auto i = connect.begin(); i != connect.end(); i++)
		target.draw(*i, states);
	for (auto i = vertex.begin(); i != vertex.end(); i++)
		target.draw(*i, states);
}

void Graph::newGraph()
{
	vertex.clear();
	neighbor.clear();
	connect.clear();
}

void Graph::addVertex(sf::Vector2f pos)
{
	vertex.push_back(Vertex(pos, font, to_string(vertex.size())));
	vector<int> tmp(vertex.size());
	for (auto i = 0; i < neighbor.size(); i++)
		neighbor[i].push_back(0);
	neighbor.push_back(tmp);
}

void Graph::addConnect(int id_begin, int id_end, unsigned int cost)
{
	//Sprawdzenie warunków
	if (id_begin >= neighbor.size() || id_end >= neighbor.size() || id_begin < 0 || id_end < 0) return;
	if (id_begin == id_end) return;
	if (cost <= 0) return;
	for (auto it = connect.begin(); it != connect.end(); ++it)
		if (it->getVertexID().x == id_begin && it->getVertexID().y == id_end) return;

	//Czêœæ wykonywalna
	deletePath();
	neighbor[id_begin][id_end] = cost;
	connect.push_back(Connect(id_begin, id_end, font, cost));
	refreshConnects();
}

void Graph::remVertex(int id_vertex) //POPRAWIC
{
	if (id_vertex >= vertex.size() || id_vertex < 0) return;

	for (auto i = connect.size() - 1; i > 0 ; i--)
		if (connect[i].getVertexID().x == id_vertex || connect[i].getVertexID().y == id_vertex)
			remConnect(i);

	for (auto i = 0; i < connect.size(); i++)
		connect[i].changeID(id_vertex);
	
	vertex.erase(vertex.begin() + id_vertex);
	for (auto i = 0; i < neighbor.size(); i++)
		neighbor[i].erase(neighbor[i].begin() + id_vertex);
	neighbor.erase(neighbor.begin() + id_vertex);

	if (vertex.size() == 0) newGraph();
	else refreshConnects();

	/*cout << "Przed usunieciem: " << endl;
	for (int i = 0; i < vertex.size(); i++)
		cout << &vertex[i] << " ";
	cout << endl;*/

	/*cout << "Po usunieciu: " << endl;
	for (int i = 0; i < vertex.size(); i++)
		cout << &vertex[i] << " ";
	cout << endl;*/
}

void Graph::remConnect(int id_connect)
{
	if (id_connect >= connect.size() || id_connect < 0) return;
	deletePath();
	neighbor[connect[id_connect].getVertexID().x][connect[id_connect].getVertexID().y] = 0;
	connect.erase(connect.begin() + id_connect);

	refreshConnects();
}

void Graph::findShortestPath(int id_begin, int id_end)
{
	if (id_begin >= neighbor.size() || id_end >= neighbor.size() || id_begin < 0 || id_end < 0) return;
	if (id_begin == id_end) return;

	deletePath();
	try
	{
		refreshConnects();
		Search finder(neighbor, id_begin, id_end);
		shortest_path = new Path(finder.getShortestPath());
		coloringPath(*shortest_path, sf::Color(64, 255, 64));
	}
	catch(WarningException & e)
	{
		e.sysWindow();
	}
}

size_t Graph::getSize() const
{
	return vertex.size();
}

vector<Vertex> Graph::getVertex() const
{
	return vertex;
}

vector<vector<int>> Graph::getMatrix() const
{
	return neighbor;
}

int Graph::getIDConnectByVertexsID(int id_begin, int id_end) const
{
	for (int i = 0; i < vertex.size() - 1; i++)
	{
		if (connect[i].getVertexID().x == id_begin && connect[i].getVertexID().y == id_end) return i;
	}
	return -1;
}

void Graph::setVertexPosition(int id, sf::Vector2f position)
{
	if(id >= 0 && id < vertex.size()) vertex[id].setPos(position);
}

void Graph::setFont(sf::Font font)
{
	this->font = font;
}

void Graph::setColorV(int id, sf::Color color)
{
	if (id >= vertex.size() || id < 0) return;
	vertex[id].setColor(color);
}

void Graph::setColorC(int id, sf::Color color)
{
	if (id >= connect.size() || id < 0) return;
	connect[id].setColor(color);
}

int Graph::detectVertex(sf::Vector2f position)
{
	int id = 0;
	for (auto i = vertex.begin(); i != vertex.end(); i++)
	{
		if (i->getShape().getGlobalBounds().contains(position))
			return id;
		id++;
	}
	return -1;
}

int Graph::detectConnect(sf::Vector2f position)
{
	int id = 0;
	for (auto i = connect.begin(); i != connect.end(); i++)
	{
		if (i->getShape().getGlobalBounds().contains(position))
			return id;
		id++;
	}
	return -1;
}

void Graph::refreshConnects()
{
	for (auto it = connect.begin(); it != connect.end(); ++it)
		it->update(vertex[it->getVertexID().x], vertex[it->getVertexID().y]);
}

void Graph::coloringPath(Path path, sf::Color color)
{
	for (int i = 0; i < vertex.size(); i++)
		setColorV(path.getPath()[i], color);
	for (int i = 0; i < vertex.size() - 1; i++)
		setColorC(getIDConnectByVertexsID(i, i + 1), color);
}

void Graph::deletePath()
{
	if (shortest_path != nullptr)
	{
		coloringPath(*shortest_path, sf::Color(255, 255, 255));
		delete shortest_path;
	}
}
