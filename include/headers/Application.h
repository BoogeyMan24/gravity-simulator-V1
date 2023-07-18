#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_image.h>
#include "Window.h"
#include "EntityManager.h"
#include "Entity.h"



class Application {
	public:
		Application(const std::string& title);
	
		void loop();

		void quit();

		EntityManager entity_manager;
		Window  window;

	private:
		float m_fps{60.f};
		
};