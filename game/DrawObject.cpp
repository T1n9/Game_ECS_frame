#include "DrawObject.h"
#include"Utils.h"

#include<iostream>

DrawObject::DrawObject(const char* file) :
	obj_texture(Utils::load_texture(file), SDL_DestroyTexture),
	src_file(file)
{}

DrawObject::DrawObject(const DrawObject & obj) :
	obj_texture(Utils::load_texture(obj.get_src_file().c_str()), SDL_DestroyTexture)
{
	//std::cout << "copy cons" << std::endl;
}

DrawObject & DrawObject::operator=(const DrawObject & obj)
{
	if (this->src_file == obj.get_src_file())
		return *this;
	obj_texture.reset(Utils::load_texture(obj.get_src_file().c_str()));
	return *this;
}

DrawObject::DrawObject(DrawObject && obj) noexcept:
	obj_texture(obj.obj_texture.get(), SDL_DestroyTexture)
{
	obj.obj_texture = nullptr;
	//std::cout << "move constructor" << std::endl;
}

DrawObject & DrawObject::operator=(DrawObject && obj) noexcept
{
	//std::cout << "move operator" << std::endl;
	if (this->src_file == obj.get_src_file())
		return *this;
	obj_texture.reset(obj.obj_texture.get());
	obj.obj_texture = nullptr;
	return *this;
}

void DrawObject::change_pic(const char * file){
	obj_texture.reset(Utils::load_texture(file));
	src_file = file;
}

void DrawObject::render(const SDL_Rect& dest_rect){
	Utils::draw(obj_texture.get(), dest_rect);
}

