#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Color.h"
#include "Vector2.h"

class Entity {
	public:
		Entity(std::unordered_map<std::uint32_t, Entity* >* m_entities, float mass, float radius, Vector2 position, Color color);

		float mass;
		float radius;

		Vector2 position;
		Vector2 velocity;
		Vector2 acceleration;

		Color color;
		

		void draw(SDL_Renderer* renderer);
		void update(float deltaTime);
		int SDL_RenderFillCircle(SDL_Renderer* renderer, int x, int y, int radius);

		std::uint32_t id;
		std::unordered_map<std::uint32_t, Entity* >* m_entities;

		double g_constant;
		
};