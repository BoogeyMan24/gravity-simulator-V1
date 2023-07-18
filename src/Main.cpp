#include "Application.h"



// Add Physics

// mass - changes how much other objects effect it (larger mass means less movement)
// radius - visual only
// position - starting position
// color - visual only (I would recommend making each circle a different color)

int main(int argc, char* argv[]) {
    Application app(std::string("Epic Gravity Simulator"));

	//											mass  radius  starting position   color of object in rgba
	Entity planet(&app.entity_manager.m_entities, 50000, 40, Vector2(400, 300), Color(255, 0, 0, 255));
	Entity planet1(&app.entity_manager.m_entities, 5, 10, Vector2(650, 300), Color(0, 255, 0, 255));

	// add planets to entity_manager so they update/draw every frame
	app.entity_manager.add(&planet1);
	app.entity_manager.add(&planet);

	// edit starting velocity
	planet1.velocity = Vector2(0, 372.6781453211);

    app.loop();

	app.quit();

	return 0;
}