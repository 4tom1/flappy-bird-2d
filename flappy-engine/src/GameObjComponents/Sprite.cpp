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
	setScale(transform->scale.x, transform->scale.y);
}

sf::Vector2f flappy_engine::Sprite::GetSize()
{
	sf::Vector2f vec2f;
	vec2f.x = texture.getSize().x * transform->scale.x;
	vec2f.y = texture.getSize().y * transform->scale.y;
	
	return vec2f;
}

void flappy_engine::Sprite::DefaultTex()
{
	setTexture(texture);
}

//void flappy_engine::Sprite::Rotate(float angle)
//{
//	if ((int)angle % 90 == 0)
//	{
//		
//	}
//
//	else
//	{
//		float radius = sqrt(powf(GetSize().x, 2) + powf(GetSize().y, 2)) / 2;
//		
//		float x = GetSize().x / 2, y = GetSize().y / 2;
//
//		Position pos2 = { transform->position.x + x, transform->position.y + y };
//
//		float tg = x / y + tanf(angle);
//
//		float x_, y_;
//
//		x_ = sqrt(pow(radius, 2) / (pow(tg, 4) + pow(tg, 2)));
//		y_ = tg * x_;
//
//		Position pos3 = { transform->position.x + x_, transform->position.y + y_ };
//
//		Position vec2 = { pos3.x - pos2.x, pos3.y - pos2.y };
//
//		std::cout << vec2.x << " - x " << vec2.y << " - y " << std::endl;
//
//		transform->position.x += vec2.x;
//		transform->position.y += vec2.y;
//	}
//
//	rotate(angle);
//}