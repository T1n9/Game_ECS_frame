#pragma once
#include"Components.h"

class CollisionComponent: public Component
{
public:
	CollisionComponent() = default;
	~CollisionComponent() = default;

	void init() override{
		//TransformComponent must be added before this component
		transform = &entity->get_component<TransformComponent>();
	}
	void update() override{
		collider = transform->dest_rect;
	}

	SDL_Rect collider;
private:
	TransformComponent* transform;
	//std::string tag;

};
