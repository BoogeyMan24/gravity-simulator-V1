#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Color.h"
#include "Entity.h"

class EntityManager {
	public:
		EntityManager();

		void add(Entity* entity);

		void update(float deltaTime);
		void draw(SDL_Renderer* renderer);
		void updateAndDraw(float deltaTime, SDL_Renderer* renderer);

		uint32_t ids;
		std::unordered_map<std::uint32_t, Entity* > m_entities;
		
};