#pragma once

#ifdef INCLUDE_GLM
#include <GLM/glm.hpp>
#endif

#include "Vector3.h"

namespace CMATH_NAMESPACE {

	template<typename Type> struct vec4 {

		vec4() : x(Type(0)), y(Type(0)), z(Type(0)), w(Type(0)) {}

		explicit vec4(Type all) : x(all), y(all), z(all), w(all) {}
		vec4(Type x, Type y, Type z, Type w = Type(0)) : x(x), y(y), z(z), w(w) {}

		vec4(const vec2<Type>& xy, Type z = Type(0), Type w = Type(0)) : x(xy.x), y(xy.y), z(z), w(w) {}
		vec4(Type x, const vec2<Type>& yz, Type w = Type(0)) : x(x), y(yz.x), z(yz.x), w(w) {}
		vec4(Type x, Type y, const vec2<Type>& zw) : x(x), y(y), z(zw.x), w(zw.y) {}
		vec4(const vec2<Type>& xy, const vec2<Type>& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}

		vec4(const vec3<Type>& xyz, Type w = Type(0)) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
		vec4(Type x, const vec3<Type>& yzw) : x(x), y(yzw.x), z(yzw.y), w(yzw.z) {}

#ifdef INCLUDE_GLM
		vec4(const glm::vec<4, Type>& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}
#endif

		Type x;
		Type y;
		Type z;
		Type w;

		static vec4<Type> zero;
		static vec4<Type> one;
		static vec4<Type> minusOne;

		//----Math functions----

		inline Type Dot(const vec4<Type>& other) const { return x * other.x + y * other.y + z * other.z + w * other.w; }

		inline float LengthSq() const { return x * x + y * y + z * z + w * w; }
		inline float Length() const { return sqrt(x * x + y * y + z * z + w * w); }

		//Returns a Normalized version of the vector
		inline vec4<Type> Normalized() const { return *this / Length(); }
		//Modifies the Vector to it's Normalized version
		inline void Normalize() { *this /= Length(); } 

		//----Math Operators----

		vec4<Type> operator+(const vec4<Type>& other) const { return vec4<Type>(x + other.x, y + other.y, z + other.z, w + other.w); }
		vec4<Type> operator-(const vec4<Type>& other) const { return vec4<Type>(x - other.x, y - other.y, z - other.z, w - other.w); }
		vec4<Type> operator*(const vec4<Type>& other) const { return vec4<Type>(x * other.x, y * other.y, z * other.z, w * other.w); }
		vec4<Type> operator/(const vec4<Type>& other) const { return vec4<Type>(x / other.x, y / other.y, z / other.z, w / other.w); }
		vec4<Type> operator%(const vec4<Type>& other) const {

			return vec4<Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y),
							  z - other.z * (int32_t) ((int32_t) z / other.z),
							  w - other.w * (int32_t) ((int32_t) w / other.w));

		}

		vec4<Type> operator+(Type other) const { return vec4<Type>(x + other, y + other, z + other, w + other); }
		vec4<Type> operator-(Type other) const { return vec4<Type>(x - other, y - other, z - other, w - other); }
		vec4<Type> operator*(Type other) const { return vec4<Type>(x * other, y * other, z * other, w * other); }
		vec4<Type> operator/(Type other) const { return vec4<Type>(x / other, y / other, z / other, w / other); }
		vec4<Type> operator%(Type other) const {

			return vec4<Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other),
							  z - other * (int32_t) ((int32_t) z / other),
							  w - other * (int32_t) ((int32_t) w / other));
		}

		//----Math and Assignement operators----

		vec4<Type>& operator=(const vec4<Type>& other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
			return *this;

		}
		vec4<Type>& operator+=(const vec4<Type>& other) {

			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;

		}
		vec4<Type>& operator-=(const vec4<Type>& other) {

			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;

		}
		vec4<Type>& operator*=(const vec4<Type>& other) {

			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;

		}
		vec4<Type>& operator/=(const vec4<Type>& other) {

			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;

		}
		vec4<Type>& operator%=(const vec4<Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			z -= other.z * (int32_t) ((int32_t) z / other.z);
			w -= other.w * (int32_t) ((int32_t) w / other.w);
			return *this;

		}

		vec4<Type>& operator+=(Type other) {

			x += other;
			y += other;
			z += other;
			w += other;
			return *this;

		}
		vec4<Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			z -= other;
			w -= other;
			return *this;

		}
		vec4<Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			z *= other;
			w *= other;
			return *this;

		}
		vec4<Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			z /= other;
			w /= other;
			return *this;

		}
		vec4<Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			z -= other * (int32_t) ((int32_t) z / other);
			w -= other * (int32_t) ((int32_t) w / other);
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const vec4<Type>& other) { return x == other.x && y == other.y && z == other.z && w == other.w; }
		inline bool operator!=(const vec4<Type>& other) { return x != other.x || y != other.y || z != other.z || w != other.w; }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::vec<4, Type>& other) { return x == other.x && y == other.y && z == other.z && w == other.w; }
		inline bool operator!=(const glm::vec<4, Type>& other) { return x != other.x || y != other.y || z != other.z || w != other.w; }

		operator glm::vec<4, Type>() const { return glm::vec<4, Type>(x, y, z, w); }
	#endif

		//----Increments and Decremenets----

		vec4<Type>& operator++() {

			x++;
			y++;
			z++;
			w++;
			return *this;

		}
		vec4<Type>& operator--() {

			x--;
			y--;
			z--;
			w--;
			return *this;

		}
		vec4<Type>  operator++(int) {

			vec4<Type> ret = *this;
			++* this;
			return ret;

		}
		vec4<Type>  operator--(int) {

			vec4<Type> ret = *this;
			--* this;
			return ret;

		}

		//----Misc. Operators----

		vec4<Type> operator-() const { return vec4<Type>(-x, -y, -z, -w); }

	};

	template<typename Type> vec4<Type> operator+(Type left, const vec4<Type>& right) { return vec4<Type>(right.x + left, right.y + left, right.z + left, right.w + left); }
	template<typename Type> vec4<Type> operator*(Type left, const vec4<Type>& right) { return vec4<Type>(right.x * left, right.y * left, right.z * left, right.w * left); }

	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec4<T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "} Z: {" << vec.z << "} W: {" << vec.w << "}";
		return os;

	}

	typedef vec4<float> Vector4;
	typedef vec4<int32_t> Vector4I;
	typedef vec4<uint32_t> UVector4I;

	StaticMembers(Vector4);
	StaticMembers(Vector4I);
	StaticMembers(UVector4I);

}