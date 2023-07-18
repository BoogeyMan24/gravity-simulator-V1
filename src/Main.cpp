#include "Application.h"



// Add Physics



int main(int argc, char* argv[]) {
    Application app(std::string("Epic Physics Engine"));


	Entity planet(&app.entity_manager.m_entities, 100000, 50, Vector2(400, 300), Color(255, 0, 0, 255));
	Entity planet1(&app.entity_manager.m_entities, 5, 5, Vector2(600, 300), Color(0, 255, 0, 255));
	app.entity_manager.add(&planet1);
	app.entity_manager.add(&planet);
	planet1.velocity = Vector2(0, 400);

    app.loop();

	app.quit();

	return 0;
}