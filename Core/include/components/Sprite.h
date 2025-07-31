#pragma once

#include "Component.h"
#include <cassert>
#include <filesystem>


struct Sprite : public Component
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f SpriteSheetSize{ 1.f,1.f };


	void setSprite(const std::string& filepath)
	{
		assert(std::filesystem::exists(filepath) && "File not found");

		texture.loadFromFile(filepath);
		sprite.setTexture(texture);
	}


	void setSpriteFromSheet(const std::string& filepath, const int& x, const int& y)
	{
		assert(std::filesystem::exists(filepath) && "File not found");

		texture.loadFromFile(filepath);
		sprite.setTexture(texture);

		float tileSizeX = texture.getSize().x / SpriteSheetSize.x;
		float tileSizeY = texture.getSize().y / SpriteSheetSize.y;

		sprite.setTextureRect(sf::IntRect(x * tileSizeX, y * tileSizeY, tileSizeX, tileSizeY));
	}
};