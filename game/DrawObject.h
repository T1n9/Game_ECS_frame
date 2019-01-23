#pragma once
#include"SDL.h"
#include"SDL_image.h"
#include<string>

class DrawObject
{
public:
	DrawObject(const char* file);
	~DrawObject() = default;
	
	DrawObject(const DrawObject&);
	DrawObject& operator=(const DrawObject&);

	DrawObject(DrawObject&&) noexcept;
	DrawObject& operator=(DrawObject&&) noexcept;

	void change_pic(const char* file);

	//如果可能需要操作原图就需要src_rect
	void render(const SDL_Rect&);
	std::string get_src_file()const { return src_file; }

private:
	std::string src_file;
	std::unique_ptr<SDL_Texture, decltype(SDL_DestroyTexture)*> obj_texture;

};

