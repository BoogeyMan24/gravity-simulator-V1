#include "Application.h"


Application::Application(const std::string& title) : 
	window(title)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL cannot be initialized. Got Error: " << SDL_GetError() << std::endl;
        return;
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "SDL_image cannot be initialized. Caught Error: "<< IMG_GetError() << std::endl;
        return;
    }

	std::cout << "SDL initialized." << std::endl;


	window.init();
}

void Application::loop() {
	const float countPerSecond = SDL_GetPerformanceFrequency();
    const float timePerFrame = countPerSecond / m_fps;

    std::uint64_t NOW = SDL_GetPerformanceCounter();
    std::uint64_t PREV = 0;
    std::uint64_t elapsedTime = 0;

    do {

		PREV = NOW;
        NOW = SDL_GetPerformanceCounter();
        elapsedTime = NOW - PREV;
        while(elapsedTime < timePerFrame) {
            NOW = SDL_GetPerformanceCounter();
            elapsedTime = NOW - PREV;
        }

		float deltaTime = elapsedTime / static_cast<float>(countPerSecond);

        window.handleEvents();
		window.updateAndDraw(&entity_manager, deltaTime);
    } while (window.isOpen());
}


void Application::quit() {
	SDL_Quit();
}