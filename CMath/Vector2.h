#pragma once

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
#endif

#include <ostream>

#define StaticMembers(Type) Type Type::zero = Type(Type(0));\
							Type Type::one = Type(Type(1));\
							Type Type::minusOne = Type(Type(-1));

namespace CMath {

	template<typename Type> struct vec3;
	template<typename Type> struct vec4;

	template<typename Type> struct vec2 {

		vec2() : x(Type(0)), y(Type(0)) {}

		explicit vec2(Type all) : x(all), y(all) {}
		vec2(Type x, Type y) : x(x), y(y) {}

		vec2(const vec3<Type>& vec);
		vec2(const vec4<Type>& vec);

		Type x;
		Type y;

		static vec2<Type> zero;
		static vec2<Type> one;
		static vec2<Type> minusOne;

		//----Math Functions----

		inline Type Dot(const vec2<Type>& other) const { return x * other.x + y * other.y; }

		inline float LengthSq() const { return x * x + y * y; }
		inline float Length() const { return sqrt(x * x + y * y); }

		inline vec2<Type> Normalized() const { return *this / Length(); } //Returns a Normalized version of the vector
		inline void Normalize() { *this /= Length(); } //Modifies the Vector to it's Normalized version

		//----Math Operators----

		vec2<Type> operator+(const vec2<Type>& other) const { return vec2<Type>(x + other.x, y + other.y); }
		vec2<Type> operator-(const vec2<Type>& other) const { return vec2<Type>(x - other.x, y - other.y); }
		vec2<Type> operator*(const vec2<Type>& other) const { return vec2<Type>(x * other.x, y * other.y); }
		vec2<Type> operator/(const vec2<Type>& other) const { return vec2<Type>(x / other.x, y / other.y); }
		vec2<Type> operator%(const vec2<Type>& other) const {
			
			return vec2<Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y));
		
		}

		vec2<Type> operator+(Type other) const { return vec2<Type>(x + other, y + other); }
		vec2<Type> operator-(Type other) const { return vec2<Type>(x - other, y - other); }
		vec2<Type> operator*(Type other) const { return vec2<Type>(x * other, y * other); }
		vec2<Type> operator/(Type other) const { return vec2<Type>(x / other, y / other); }
		vec2<Type> operator%(Type other) const {
			
			return vec2<Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other));
		}

		//----Math and Assignement Operators----

		vec2<Type>& operator=(const vec2<Type>& other) {

			this->x = other.x;
			this->y = other.y;
			return *this;

		}
		vec2<Type>& operator+=(const vec2<Type>& other) {

			x += other.x;
			y += other.y;
			return *this;

		}
		vec2<Type>& operator-=(const vec2<Type>& other) {

			x -= other.x;
			y -= other.y;
			return *this;

		}
		vec2<Type>& operator*=(const vec2<Type>& other) {

			x *= other.x;
			y *= other.y;
			return *this;

		}
		vec2<Type>& operator/=(const vec2<Type>& other) {

			x /= other.x;
			y /= other.y;
			return *this;

		}
		vec2<Type>& operator%=(const vec2<Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			return *this;

		}

		vec2<Type>& operator+=(Type other) {

			x += other;
			y += other;
			return *this;

		}
		vec2<Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			return *this;

		}
		vec2<Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			return *this;

		}
		vec2<Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			return *this;

		}
		vec2<Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const vec2<Type>& other) { return x == other.x && y == other.y; }
		inline bool operator!=(const vec2<Type>& other) { return x != other.x || y != other.y; }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::vec<2, Type>& other) { return x == other.x && y == other.y; }
		inline bool operator!=(const glm::vec<2, Type>& other) { return x != other.x || y != other.y; }

		operator glm::vec<2, Type>() const { return glm::vec<2, Type>(x, y); }
	#endif

		//----Increments and Decrements----

		vec2<Type>& operator++() {

			x++;
			y++;
			return *this;

		}
		vec2<Type>& operator--() {

			x--;
			y--;
			return *this;

		}
		vec2<Type>  operator++(int) {

			vec2<Type> ret = *this;
			++*this;
			return ret;

		}
		vec2<Type>  operator--(int) {

			vec2<Type> ret = *this;
			--*this;
			return ret;

		}

		//----Misc Operators----

		vec2<Type> operator-() const { return vec2<Type>(-x, -y); }

	};

	template<typename Type> vec2<Type> operator+(Type left, const vec2<Type>& right) { return vec2<Type>(right.x + left, right.y + left); }
	template<typename Type> vec2<Type> operator*(Type left, const vec2<Type>& right) { return vec2<Type>(right.x * left, right.y * left); }

	//ostream operator overloadings
	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec2<T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "}";
		return os;

	}

	typedef vec2<float> Vector2;
	typedef vec2<int32_t> Vector2I;
	typedef vec2<uint32_t> UVector2I;

	StaticMembers(Vector2)
	StaticMembers(Vector2I)
	StaticMembers(UVector2I)

}

#include "Vector3.h"
#include "Vector4.h"

namespace CMath {

	template<typename Type> vec2<Type>::vec2(const vec3<Type>& vec) : x(vec.x), y(vec.y) {}
	template<typename Type> vec2<Type>::vec2(const vec4<Type>& vec) : x(vec.x), y(vec.y) {}

}