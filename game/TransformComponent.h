#pragma once
#include"Components.h"
#include"Vector2d.h"

class TransformComponent : public Component
{
public:
	//实话说我不确定是否还需要这个position变量
	Vector2d position;
	Vector2d velocity;
	int speed = 5;

	SDL_Rect dest_rect;

	TransformComponent() = default;
	TransformComponent(int x, int y, int size, int speed):
		position(x,y),
		speed(speed)
	{
		dest_rect.h = dest_rect.w = size;
	};

	~TransformComponent() = default;

	//void init()override {
	//}
	void update()override {
		position.x += speed * velocity.x;
		position.y += speed * velocity.y;

		position.x = Utils::clamp(position.x, Game::win_width - dest_rect.w);
		position.y = Utils::clamp(position.y, Game::win_height - dest_rect.h);

		dest_rect.x = position.x;
		dest_rect.y = position.y;
	}

};
