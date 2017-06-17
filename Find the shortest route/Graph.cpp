#include "Graph.h"

using namespace std;

Graph::Graph()
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
	adjacency.clear();
	connect.clear();
}

void Graph::addVertex(sf::Vector2f pos)
{
	vertex.push_back(Vertex(vertex.size(), pos, font, to_string(vertex.size()))); //Dodanie nowego Vertexa
	vector<int> tmp(vertex.size()); //Utworzenie tymczasowego vectora do zagnie¿d¿enia w macierzy s¹siedztwa
	for (auto i = 0; i < adjacency.size(); i++)
		adjacency[i].push_back(0); //Dodanie nowej kolumny
	adjacency.push_back(tmp); //Dodanie nowego wiersza
}

void Graph::addConnect(int id_begin, int id_end, unsigned int cost)
{
	//Sprawdzenie warunków koniecznych
	if (id_begin >= adjacency.size() || id_end >= adjacency.size() || id_begin < 0 || id_end < 0) return;
	if (id_begin == id_end) return; //Nie mo¿na po³¹czyæ do siebie samego
	if (cost <= 0) return; //Koszty musz¹ byæ dodatnie
	for (auto it = connect.begin(); it != connect.end(); ++it) //Czy istnieje ju¿ takie po³¹czenie
		if (it->getVertexID().x == id_begin && it->getVertexID().y == id_end) return;

	//Czêœæ wykonywalna
	adjacency[id_begin][id_end] = cost; //Wpisanie do macierzy kosztu
	connect.push_back(Connect(id_begin, id_end, font, cost)); //Utworzenie po³¹czenia
	refreshConnects(); //Odœwie¿enie grafiki
}

void Graph::remVertex(int id_vertex) //Do poprawek
{
	if (id_vertex >= vertex.size() || id_vertex < 0) return; //Vertex o podanym ID musi istnieæ

	//Wykrywanie i usuwanie po³¹czeñ ju¿ niepotrzebnych
	for (auto i = connect.size() - 1; i >= 0; i--)
	{
		if (connect[i].getVertexID().x == id_vertex || connect[i].getVertexID().y == id_vertex)
		{
			adjacency[connect[i].getVertexID().x][connect[i].getVertexID().y] = 0;
			connect.erase(connect.begin() + i);
		}
	}
	
	//Zachowanie po³¹czeñ z odpowiednimi Vertexami
	for (auto i = 0; i < connect.size(); i++)
	{
		auto x = connect[i].getVertexID().x;
		auto y = connect[i].getVertexID().y;
		if (x > id_vertex) x--;
		if (y > id_vertex) y--;
		connect[i].setID(x, y);
	}
	
	//Usuniêcie Vertexa i usuniêcie odpowiedniego wiersza i kolumny macierzy s¹siedztwa
	vertex.erase(vertex.begin() + id_vertex);
	for (auto i = 0; i < adjacency.size(); i++)
		adjacency[i].erase(adjacency[i].begin() + id_vertex);
	adjacency.erase(adjacency.begin() + id_vertex);

	//Odœwie¿enie
	if (vertex.size() == 0) newGraph();
	else refreshConnects();
}

void Graph::remConnect(int id_connect)
{
	if (id_connect >= connect.size() || id_connect < 0) return;
	adjacency[connect[id_connect].getVertexID().x][connect[id_connect].getVertexID().y] = 0;
	connect.erase(connect.begin() + id_connect);

	refreshConnects();
}

Path Graph::findShortestPath(int id_begin, int id_end)
{
	if (id_begin >= adjacency.size() || id_end >= adjacency.size() || id_begin < 0 || id_end < 0 || id_begin == id_end) throw WarningException("Invalid Value");
	refreshConnects();
	Search finder(adjacency, id_begin, id_end);
	return finder.getShortestPath();
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
	return adjacency;
}

int Graph::getIDConnectByVertexsID(int id_begin, int id_end) const
{
	for (int i = 0; i < connect.size(); i++)
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
	for (int i = 0; i < path.getPath().size(); i++)
		setColorV(path.getPath()[i], color);
	for (int i = 0; i < path.getPath().size() - 1; i++)
	{
		setColorC(getIDConnectByVertexsID(path.getPath()[i], path.getPath()[i + 1]), color);
		cout << getIDConnectByVertexsID(path.getPath()[i], path.getPath()[i + 1])
			<< " - "
			<< path.getPath()[i]
			<< " "
			<< path.getPath()[i + 1]
			<< endl;
	}
}

void Graph::deleteColoring(sf::Color color)
{
	for (int i = 0; i < vertex.size(); i++)
		setColorV(i, color);
	for (int i = 0; i < connect.size(); i++)
		setColorC(i, color);
}