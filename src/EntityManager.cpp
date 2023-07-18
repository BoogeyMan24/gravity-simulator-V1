#include "EntityManager.h"


EntityManager::EntityManager() {
	ids = 0;
}


void EntityManager::add(Entity* entity) {
	entity->id = ids++;
	m_entities[entity->id] = entity;
}

void EntityManager::update(float deltaTime) {
	for (auto& [id, entity] : m_entities) {
		entity->update(deltaTime);
		
	}
}

void EntityManager::draw(SDL_Renderer* renderer) {
	for (auto& [id, entity] : m_entities) {
		entity->draw(renderer);
	}
}

void EntityManager::updateAndDraw(float deltaTime, SDL_Renderer* renderer) {
	for (auto& [id, entity] : m_entities) {
		entity->update(deltaTime);
		entity->draw(renderer);
	}
}