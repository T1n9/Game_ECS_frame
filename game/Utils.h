#pragma once
#include<string>
#include<direct.h>
#include<SDL.h>
#include<SDL_image.h>
#include"Game.h"



class Utils final
{
public:
	Utils();
	~Utils() = default;
	Utils(const Utils&) = delete;
	Utils& operator=(const Utils&) = delete;

	static Utils& get_instance();

	static SDL_Texture* load_texture(const char* file);
	static void draw(SDL_Texture* texture, const SDL_Rect& dest_rect);

	static int clamp(int value, int max, int min = 0) {
		if (value <= min)	return min;
		else if (value >= max)	return max;
		else	return value;
	}
	
	static bool collision(const SDL_Rect& rect1, const SDL_Rect& rect2);

	template<typename S>
	static std::string get_source_file(S&& file) {
		return project_path + "\\resource\\" + std::forward<S>(file);
	}


private:

	static const std::string project_path;

};

