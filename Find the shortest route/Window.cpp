#include "Window.h"

using namespace std;

Window::Window(int width, int height) 
	: graph(nullptr), id_buffer(-1), mode(NONE)
{
	if (width <= 0 || height <= 0) throw string("Incorrect window size");
	window.create(sf::VideoMode(width, height), "Find the shortest route - 235565", sf::Style::Close);
	window.setFramerateLimit(60);

	if (!font.loadFromFile("arial.ttf")) throw CriticalException("Font failed");

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
	int id_vertex = graph->detectVertex(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	int id_connect = graph->detectConnect(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mode == NONE)
		{
			if (id_vertex != -1)
			{
				graph->setVertexPosition(id_vertex, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
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
						graph->addConnect(id_buffer, id_vertex, 1);
						graph->setColorV(id_buffer, sf::Color(255, 255, 255));
						id_buffer = -1;
					}
				}
			}
			if (mode == REMOVE)
			{
				if (id_vertex != -1 && id_connect != -1) graph->remVertex(id_vertex);
				else if (id_vertex != -1) graph->remVertex(id_vertex);
				else if (id_connect != -1) graph->remConnect(id_connect);
			}
			if (mode == FIND)
			{
				if (id_vertex != -1)
				{
					if (id_buffer == -1)
					{
						id_buffer = id_vertex;
						graph->setColorV(id_buffer, sf::Color(128, 255, 128));
					}
					else
					{
						graph->findShortestPath(id_buffer, id_vertex);
						graph->setColorV(id_buffer, sf::Color(255, 255, 255));
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
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::N)
		{
			graph->newGraph();
			setDialog("New Graph");
		}
		if (event.key.code == sf::Keyboard::O)
		{
			try { file->load(); setDialog("Loaded Graph"); }
			catch (WarningException & e) { e.sysWindow(); }
			catch (Info & i) { setDialog(i.what()); }
		}
		if (event.key.code == sf::Keyboard::S)
		{
			try { file->save(); setDialog("Saved Graph"); }
			catch (WarningException & e) { e.sysWindow(); }
			catch (Info & i) { setDialog(i.what()); }
		}
		if (event.key.code == sf::Keyboard::V)
		{
			mode = ADD_VERTEX;
			setDialog("Add Vertex");
		}
		if (event.key.code == sf::Keyboard::C)
		{
			mode = ADD_CONNECT;
			graph->setColorV(id_buffer, sf::Color(255, 255, 255));
			id_buffer = -1;
			setDialog("Add Connect");
		}
		if (event.key.code == sf::Keyboard::D)
		{
			mode = REMOVE;
			setDialog("Remove object");
		}
		if (event.key.code == sf::Keyboard::F)
		{
			mode = FIND;
			graph->setColorV(id_buffer, sf::Color(255, 255, 255));
			id_buffer = -1;
			setDialog("Find the shortest path");
		}
		if (event.key.code == sf::Keyboard::Escape)
		{
			if (mode == NONE) closeApp();
			else if (mode == ADD_CONNECT || mode == FIND) graph->setColorV(id_buffer, sf::Color(255, 255, 255));
			mode = NONE;
			setDialog("");
			id_buffer = -1;
		}
	}
}

string Window::textBox()
{
	/*HWND editID = GetDlgItem(hwnd, ID_EDIT);
	_TCHAR buff[20];
	GetWindowText(editID, buff, 20);
	double liczba = _tcstod(buff, NULL); //TUTAJ powinno byæ "_tcstod"
	_TCHAR szBuffer[1000];
	_stprintf(szBuffer, _T("Wynik to: %g pkt."), liczba); //TUTAJ powinno byæ %g a nie %i
	MessageBox(NULL, szBuffer, _T("Wniki skomplikowanych obliczeñ"), MB_ICONINFORMATION);

	HWND hText = CreateWindowEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 10, 150, 20, hWnd, (HMENU)ID_EDIT, hInstance, NULL);*/

	return "h";

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
