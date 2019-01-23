#pragma once
#include"Game.h"
#include"ECS.h"
#include"Components.h"


class KeyboardController: public Component
{
public:
	KeyboardController() = default;
	~KeyboardController() = default;

	bool keydown[4] = { false };

	TransformComponent *transform;
	void init()override {
		transform = &entity->get_component<TransformComponent>();
	}
	void update() override {
		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				keydown[0] = true;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				keydown[1] = true;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				keydown[2] = true;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				keydown[3] = true;
				break;
			case SDLK_ESCAPE:
				Game::is_running = false;
				break;
			default:
				break;
			}
		}
		if (Game::event.type == SDL_KEYUP) {
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				keydown[0] = false;
				break;
			case SDLK_a:
				keydown[1] = false;
				break;
			case SDLK_d:
				keydown[2] = false;
				break;
			case SDLK_s:
				keydown[3] = false;
				break;
			default:
				break;
			}
			if (!keydown[0] && !keydown[3])
				transform->velocity.y = 0;
			if (!keydown[1] && !keydown[2])
				transform->velocity.x = 0;
		}
	}
};

