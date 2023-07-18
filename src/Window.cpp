#include "Window.h"

Window::Window(const std::string& title, int x, int y, int w, int h, std::uint32_t flags) :
	m_title(title)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_flags = flags;
}

void Window::init() {
	m_window = SDL_CreateWindow(m_title.c_str(), m_x, m_x, m_w, m_h, m_flags);
	if(!m_window) {
        std::cout << "Failed to create a new window\n";
		throw std::runtime_error(SDL_GetError());
    }

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer) {
		throw std::runtime_error(SDL_GetError());
	}
	

	m_open = true;
}
void Window::handleEvents() {
	SDL_Event event;
	while(SDL_PollEvent(&event) > 0)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                m_open = false;
                break;
        }
    }
}

void Window::updateAndDraw(EntityManager* entity_manager, float deltaTime) {
	SDL_RenderClear(m_renderer);
	entity_manager->updateAndDraw(deltaTime, m_renderer);
	SDL_RenderPresent(m_renderer);
}



bool Window::isOpen() const {
	return m_open;
}

SDL_Renderer* Window::getRenderer() const {
	return m_renderer;
}


void Window::close() {
	SDL_DestroyWindow(m_window);
	m_open = false;
	m_window_surface = NULL;
	m_window = NULL;
}