#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>

namespace PapaSmurfie {
	struct Vector2 {
		float x, y;

		Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

		Vector2 normalized() const{
			float mag = this->magnitude();
			if (mag == 0.0f) return Vector2{ 0.0f, 0.0f };
			float normX = x / mag;
			float normY = y / mag;
			return Vector2{ normX, normY };
		}

		float magnitude() const{
			return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
		}

		Vector2 operator+(const Vector2& other) const{
			return Vector2{x + other.x, y + other.y};
		}

		Vector2 operator-(const Vector2& other) const {
			return Vector2{ x - other.x, y - other.y };
		}
		Vector2 operator*(const float scalar)const {
			return Vector2{ x * scalar, y * scalar };
		}
		Vector2 operator/(const float scalar)const {
			return Vector2{ x / scalar,y / scalar };
		}

		Vector2& operator+=(const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const Vector2& vec2);
	};
	
	inline std::ostream& operator<<(std::ostream& os, const Vector2& vec2) {
			os << vec2.x << ", " << vec2.y;
			return os;
		}
}