#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "EntityManager.h"


class Window {
	public:
		Window(const std::string& title, int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED, int w = 1024, int h = 600, std::uint32_t flags = (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN));
	
		void init();
		bool isOpen() const;
		void close();

		void handleEvents();
		void updateAndDraw(EntityManager* entity_manager, float deltaTime);

		SDL_Renderer* getRenderer() const;
	private:
		SDL_Window*   m_window;
		SDL_Surface*  m_window_surface;
		SDL_Renderer* m_renderer;
		SDL_Event     m_window_event;

		std::string m_title;
		int m_x, m_y, m_w, m_h;
		std::uint32_t m_flags;

		bool m_open;
};