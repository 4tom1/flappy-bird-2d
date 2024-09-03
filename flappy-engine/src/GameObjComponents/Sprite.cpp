#include <iostream>

#include "flappy_engine/GameObjComponents/Sprite.h"

void flappy_engine::Sprite::Create(const char* file_path)
{
	if (!texture.loadFromFile(file_path))
	{
		std::cout << "Error: cannot open a file " << file_path << ";" << std::endl;
		std::getchar();
	
		return;
	}

	setTexture(texture);
}

void flappy_engine::Sprite::Update()
{
	setRotation(transform->rotation);
	setPosition(transform->position.x, transform->position.y);
}

sf::Vector2f flappy_engine::Sprite::GetSize()
{
	sf::Vector2f vec2f;
	vec2f.x = texture.getSize().x * getScale().x; // It is bad way to do this.
	vec2f.y = texture.getSize().y * getScale().y; // It is bad way to do this.
	
	return vec2f;
}

void flappy_engine::Sprite::DefaultTex()
{
	setTexture(texture);
}