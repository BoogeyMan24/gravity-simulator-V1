#include "Entity.h"


Entity::Entity(std::unordered_map<std::uint32_t, Entity* >* entities, float mass, float radius, Vector2 position, Color color) :
	position(position),
	velocity(0.0, 0.0),
	color(color)
{
	this-> m_entities = entities;
	this->mass = mass;
	this->radius = radius;
	g_constant = 1000;
}


void Entity::draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillCircle(renderer, position.x, position.y, radius);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Entity::update(float deltaTime) {
	acceleration = 0;

	for (auto& [id, entity] : *m_entities) {
		if(id != this->id) {
			float acc_mag = g_constant * entity->mass / (std::pow(this->position.distance(entity->position), 2));
			
			Vector2 acc_vec = this->position.direction(entity->position);
			
			acc_vec.setMagnitude(acc_mag);
			
			acceleration += acc_vec;

			std::cout << acceleration.x << std::endl;

			velocity += acceleration * deltaTime;
			position += velocity * deltaTime;

			
		}
	}
}


int Entity::SDL_RenderFillCircle(SDL_Renderer* renderer, int x, int y, int radius) {
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx, x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety, x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety, x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx, x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}