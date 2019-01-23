#pragma once

#include"Utils.h"

struct SDL_Window;
struct SDL_Renderer;

class Game
{
public:
	enum { win_width = 800, win_height = 640 };

	Game() = default;
	~Game() = default;

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handle_events();
	void update();
	void render();
	void clean();
	void start();
	
	static bool running() { return is_running;	}
	static SDL_Renderer * game_renderer;

	static SDL_Event event;

	static bool is_running;
private:
	static const int  frame_delay = 1000 / 60;
	uint32_t frame_start = 0;
	int frame_time = 0;

	//Utils& utils() { return Utils::get_instance();	}
	
	int cnt = 0;

	SDL_Window * window;

};

