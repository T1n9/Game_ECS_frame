#include "Utils.h"

const std::string Utils::project_path;

Utils::Utils() {
	char buff[1000];
	_getcwd(buff, 1000);
	const_cast<std::string&>(project_path) = buff;
}
Utils& Utils::get_instance(){
	static Utils instance;
	return instance;
}

SDL_Texture* Utils::load_texture(const char* file) {

	std::string full_path = std::string("resource/") + file;
	SDL_Surface* tmp_surface = IMG_Load(full_path.c_str());


	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::game_renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);
	return tex;
}

void Utils::draw(SDL_Texture * texture, const SDL_Rect& dest_rect){
	SDL_RenderCopy(Game::game_renderer, texture, NULL, &dest_rect);
}

bool Utils::collision(const SDL_Rect & rect1, const SDL_Rect & rect2)
{
	if (rect1.x + rect1.w >= rect2.x &&
		rect2.x + rect2.w >= rect1.x &&
		rect1.y + rect1.h >= rect2.y &&
		rect2.y + rect2.h >= rect1.y
		)
		return true;
	else	return false;
}



//Utils::~Utils()
//{
//}
