#include "ResourceManager.h"

using namespace std;

ResourceManager::ResourceManager()
{
	loadFont("arial.ttf");
}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::loadFont(string font_path)
{
	if (!font_holder_.loadFromFile(font_path)) throw CriticalException("Error loading font");
}

sf::Font & ResourceManager::getFont()
{
	return font_holder_;
}
