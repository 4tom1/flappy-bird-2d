#include "flappy_engine/GameObj.h"

flappy_engine::Engine* flappy_engine::GameObj::engine = nullptr;

void flappy_engine::GameObj::AddComponent(flappy_engine::Component com)
{
	switch (com)
	{
		case flappy_engine::sprite:
			if (!sprite) sprite = new Sprite(&transform);
			break;
		case flappy_engine::collider:
			if (!collider) collider = new Collider(&transform);
			break;
		case flappy_engine::animator:
			if (!animator) animator = new Animator(sprite);
			break;
		default:
			break;
	}
}

void flappy_engine::GameObj::DeleteComponent(flappy_engine::Component com)
{
	switch (com)
	{
		case flappy_engine::sprite:
			if (sprite) delete sprite;
			sprite = nullptr;
			break;
		case flappy_engine::collider:
			if (collider) delete collider;
			collider = nullptr;
			break;
		case flappy_engine::animator:
			if (animator) delete animator;
			animator = nullptr;
			break;
		default:
			break;
	}
}


void flappy_engine::GameObj::SetEngine(Engine* engine_ptr)
{
	engine = engine_ptr;
}

void flappy_engine::GameObj::Update() {}