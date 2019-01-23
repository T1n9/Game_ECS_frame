#pragma once

class SpriteComponent : public Component {

private:
	TransformComponent* transform;

	DrawObject obj;
	SDL_Rect dest_rect;

public:
	//SpriteComponent() = default;
	SpriteComponent(const char* file):
		obj(file)
	{}

	~SpriteComponent() = default;

	void init() override {
		transform = &entity->get_component<TransformComponent>();
		dest_rect.x = transform->position.x;
		dest_rect.y = transform->position.y;
		dest_rect = transform->dest_rect;
	}
	void update() override{
		dest_rect = transform->dest_rect;
		//dest_rect.x = transform->position.x;
		//dest_rect.y = transform->position.y;
	}
	void draw() override {
		obj.render(dest_rect);
	}

	void set_tex(const char* file) {
		obj.change_pic(file);
	}

};