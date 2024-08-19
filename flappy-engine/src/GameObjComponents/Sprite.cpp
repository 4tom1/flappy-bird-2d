#include <iostream>

#include "flappy_engine/GameObjComponents/Sprite.h"

bool flappy_engine::Sprite::Create(const char* file_path)
{
	if (!texture.loadFromFile(file_path))
	{
		std::cout << "Error: cannot open a file " << file_path << ";" << std::endl;
		getchar();
		
		return false;
	}

	setTexture(texture);

	return true;
}

void flappy_engine::Sprite::Update()
{
	setPosition(transform->position.x, transform->position.y);
	setRotation(transform->rotation);
	setScale(transform->scale.x, transform->scale.y);
}