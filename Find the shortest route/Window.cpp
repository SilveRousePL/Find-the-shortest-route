#include "Window.h"

using namespace std;

Window::Window(int width, int height) 
	: graph(nullptr), id_buffer(-1), mode(NONE)
{
	if (width < 128 || height < 128) throw CriticalException("Incorrect window size"); //Wyrzu� krytyczny wyj�tek, gdy rozmiar okna jest zbyt ma�y
	window.create(sf::VideoMode(width, height), "Find the shortest route - Dariusz Tomaszewski, 235565", sf::Style::Close); //Tworzenie okna
	window.setFramerateLimit(60); //Ograniczenie generowania klatek

	//Wyrzu� krytyczny wyj�tek, gdy za�adowano czcionki
	if (!font.loadFromFile("arial.ttf")) throw CriticalException("Font failed");

	//Ustawienie parametr�w komunikatu w dolnej cz�ci okna
	dialog.setFont(font);
	dialog.setCharacterSize(24);
	dialog.setFillColor(sf::Color(255, 255, 255));
	dialog.setOutlineThickness(2);
	dialog.setOutlineColor(sf::Color(64, 64, 64));
	dialog.setOrigin(dialog.getGlobalBounds().width / 2 , dialog.getGlobalBounds().height / 2);
	setDialog("Welcome!");
}

Window::~Window()
{
	delete file;
	delete graph;
}

void Window::run()
{
	graph = new Graph;
	file = new File(*graph);
	graph->setFont(font);
	render();
}

void Window::render()
{
	while (window.isOpen())
	{
		window.clear(sf::Color(128, 128, 128));
		eventCheck();
		window.draw(dialog);
		window.draw(*graph);
		window.display();
	}
}

void Window::eventCheck()
{
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) closeApp();
		mouseEvent();
		keyboardEvent();
	}
}

void Window::mouseEvent()
{
	//Wykrywanie obiekt�w pod kursorem
	int id_vertex = graph->detectVertex(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	int id_connect = graph->detectConnect(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	//Je�li zosta� naci�ni�ty lewy przycisk myszy (Potem sprawdzanie, jaki tryb pracy wybrali�my)
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mode == NONE)
		{
			if (id_vertex != -1)
			{
				graph->setVertexPosition(id_vertex, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
				graph->refreshConnects();
				setDialog(to_string(sf::Mouse::getPosition(window).x) + ", " + to_string(sf::Mouse::getPosition(window).y));
			}
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (mode == ADD_VERTEX) graph->addVertex(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			if (mode == ADD_CONNECT)
			{
				if (id_vertex != -1)
				{
					if (id_buffer == -1)
					{
						id_buffer = id_vertex;
						graph->setColorV(id_buffer, sf::Color(255, 255, 128));
					}
					else
					{
						if (text_buffer.length() == 0) text_buffer.push_back('1');
						graph->addConnect(id_buffer, id_vertex, stoi(text_buffer));
						graph->setColorV(id_buffer, sf::Color(255, 255, 255));
						id_buffer = -1;
					}
				}
			}
			if (mode == REMOVE)
			{
				/*if (id_vertex != -1 && id_connect != -1) graph->remVertex(id_vertex);
				else if (id_vertex != -1) graph->remVertex(id_vertex);
				else if (id_connect != -1) graph->remConnect(id_connect);*/
				if (id_connect != -1) graph->remConnect(id_connect);
			}
			if (mode == FIND)
			{
				graph->deleteColoring(sf::Color(255, 255, 255));
				if (id_vertex != -1)
				{
					if (id_buffer == -1)
					{
						id_buffer = id_vertex;
						graph->setColorV(id_buffer, sf::Color(128, 255, 128));
					}
					else
					{
						try
						{
							Path path = graph->findShortestPath(id_buffer, id_vertex);
							graph->setColorV(id_buffer, sf::Color(255, 255, 255));
							graph->coloringPath(path, sf::Color(64, 255, 64));
							stringstream ss;
							ss << path;
							setDialog(ss.str());
						}
						catch (WarningException & e)
						{
							e.sysWindow();
						}
						id_buffer = -1;
					}
				}
			}
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (mode == NONE)
			{
				graph->refreshConnects();
				setDialog("");
			}
		}
	}
}

void Window::keyboardEvent()
{
	if (event.type == sf::Event::KeyPressed)
	{
		graph->deleteColoring(sf::Color(255, 255, 255));
		if (mode == ADD_CONNECT && (event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9 || event.key.code == sf::Keyboard::BackSpace))
		{
			if (text_buffer.length() < 9 && event.key.code != sf::Keyboard::BackSpace)
			{
				if (text_buffer.length() == 0)
				{
					if (event.key.code != sf::Keyboard::Num0)
						text_buffer.push_back(event.key.code + 22);
				}
				else text_buffer.push_back(event.key.code + 22);
			}
			else if (event.key.code == sf::Keyboard::BackSpace && text_buffer.length() != 0) 
				text_buffer.pop_back();
			setDialog("Add Connect ### Cost = " + text_buffer);
		}
		if (event.key.code == sf::Keyboard::N)
		{
			graph->newGraph();
			setDialog("New Graph");
		}
		if (event.key.code == sf::Keyboard::O)
		{
			try
			{
				file->load(); 
				setDialog("Loaded Graph"); 
				graph->deleteColoring(sf::Color(255, 255, 255));
			}
			catch (WarningException & e) { e.sysWindow(); }
		}
		if (event.key.code == sf::Keyboard::S)
		{
			try { file->save(); setDialog("Saved Graph"); }
			catch (WarningException & e) { e.sysWindow(); }
		}
		if (event.key.code == sf::Keyboard::V)
		{
			mode = ADD_VERTEX;
			setDialog("Add Vertex");
		}
		if (event.key.code == sf::Keyboard::C)
		{
			mode = ADD_CONNECT;
			id_buffer = -1;
			text_buffer = "1";
			setDialog("Add Connect ### Cost = " + text_buffer);
		}
		if (event.key.code == sf::Keyboard::D)
		{
			mode = REMOVE;
			setDialog("Remove connect");
		}
		if (event.key.code == sf::Keyboard::F)
		{
			mode = FIND;
			id_buffer = -1;
			setDialog("Find the shortest path");
		}
		if (event.key.code == sf::Keyboard::Escape)
		{
			if (mode == NONE) closeApp();
			mode = NONE;
			setDialog("");
			id_buffer = -1;
		}
	}
}

void Window::setDialog(string text)
{
	dialog.setString(text);
	dialog.setPosition((window.getSize().x - dialog.getGlobalBounds().width) / 2, window.getSize().y - 2 * dialog.getCharacterSize());
}

void Window::closeApp()
{
	window.close();
}