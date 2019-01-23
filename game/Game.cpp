#include "Game.h"
#include<iostream>
#include"SDL.h"
#include"SDL_image.h"


#include"DrawObject.h"
#include"Map.h"
#include"ECS.h"
#include"Components.h"
#include"Vector2d.h"

using std::endl;
using std::cout;


//DrawObject *player;
Map* map1;

bool Game::is_running = true;
SDL_Renderer* Game::game_renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto& new_player(manager.add_entity());
auto& enemy(manager.add_entity());


void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN:0;

	if (0 == SDL_Init(SDL_INIT_EVERYTHING)) {
		
		//cout << "subsystem initialized..." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//if (window)	cout << "window created..." << endl;
		
		game_renderer = SDL_CreateRenderer(window, -1, 0);
		if (game_renderer) {
			//cout << "renderer created..." << endl;
			SDL_SetRenderDrawColor(game_renderer, 255, 0, 0, 255);
		}

		if (window && game_renderer)	is_running = true;
	}


	//player = new DrawObject("huaji.png", 32, 32);


	map1 = new Map("bg.png");

	new_player.add_component<TransformComponent>(100,100, 32, 5);
	new_player.add_component<SpriteComponent>("goutou.png");
	new_player.add_component<KeyboardController>();
	new_player.add_component<CollisionComponent>();

	enemy.add_component<TransformComponent>(200, 200, 32, 0);
	enemy.add_component<SpriteComponent>("puke.png");
	enemy.add_component<CollisionComponent>();
}

void Game::handle_events()
{
	SDL_PollEvent(&event); 
	switch (event.type)
	{
	case SDL_QUIT:
		is_running = false;
		break;
	default:
		break;
	}
}

void Game::update()
{

	manager.update();

	//new_player.get_component<TransformComponent>().position.add({ 1,0 });

	if (new_player.get_component<TransformComponent>().position.x > 200)
		new_player.get_component<SpriteComponent>().set_tex("huaji.png");
	else
		new_player.get_component<SpriteComponent>().set_tex("goutou.png");

	if (Utils::collision(new_player.get_component<CollisionComponent>().collider,
		enemy.get_component<CollisionComponent>().collider))
		cout << "ouch" << endl;

	++cnt;
	//std::cout << "x:";
	//std::cout << new_player.get_component<TransformComponent>().position.x << std::endl;
}

void Game::render()
{
	SDL_RenderClear(game_renderer);
	
	map1->render();
	manager.draw();

	SDL_RenderPresent(game_renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(game_renderer);
	SDL_Quit();
	//cout << "game cleeaned" << endl;
}

void Game::start()
{
	init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_width, win_height, false);
	while (running()) {
		frame_start = SDL_GetTicks();

		handle_events();
		update();
		render();

		frame_time = SDL_GetTicks() - frame_start;
		if (frame_delay > frame_time)	SDL_Delay(frame_delay - frame_time);

	}
	clean();
}

