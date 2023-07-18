#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


class Vector2 {
	public:
		Vector2();
		Vector2(float x, float y);

		float x, y;
		
		void normalized();
		float distance(Vector2 vec);
		float distance(float x, float y);
		Vector2 direction(Vector2 vec);
		void setMagnitude(float new_magnitude);
		float magnitude();




		Vector2 operator=(Vector2 vec);
		Vector2 operator=(float n);

		Vector2 operator+(Vector2 vec);
		Vector2 operator+(float n);

		Vector2 operator-(Vector2 vec);
		Vector2 operator-(float n);

		Vector2 operator*(Vector2 vec);
		Vector2 operator*(float n);

		Vector2 operator/(Vector2 vec);
		Vector2 operator/(float n);



		Vector2 operator+=(Vector2 vec);
		Vector2 operator+=(float n);

		Vector2 operator-=(Vector2 vec);
		Vector2 operator-=(float n);

		Vector2 operator*=(Vector2 vec);
		Vector2 operator*=(float n);

		Vector2 operator/=(Vector2 vec);
		Vector2 operator/=(float n);
	private:		
		void divisionByZero();
};