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

void flappy_engine::Sprite::DefaultTex()
{
	setTexture(texture);
}

void flappy_engine::Sprite::Update()
{
	sf::Vector2f center;
	center.x = GetSize().x / 2;
	center.y = GetSize().y / 2;
	
	sf_transform.rotate(transform->rotation, center);

	setPosition(transform->position.x, transform->position.y);
	setScale(transform->scale.x, transform->scale.y);
}

sf::Vector2f flappy_engine::Sprite::GetSize()
{
	sf::Vector2f vec2f;
	vec2f.x = texture.getSize().x * transform->scale.x;
	vec2f.y = texture.getSize().y * transform->scale.y;
	
	return vec2f;
}