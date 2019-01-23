#pragma once
#include"DrawObject.h"
#include"SDL_image.h"
#include"Game.h"

class Map
{
public:
	Map(const char* map_file, int height = Game::win_height, int width = Game::win_width);
	~Map() = default;
	void render() { map_obj.render(dest_rect);	 }

private:
	SDL_Rect dest_rect;
	DrawObject map_obj;
};

Map::Map(const char * map_file, int height, int width) :
	map_obj(map_file)
{
	dest_rect.h = height;
	dest_rect.w = width;
	dest_rect.x = dest_rect.y = 0;
}

