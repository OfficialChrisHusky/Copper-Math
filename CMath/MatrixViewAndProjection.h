#pragma once

#include "Matrix4.h"
#include "Trigonometry.h"

namespace CMATH_NAMESPACE {

	template<typename T> inline mat<4, T> ViewMatrix(const vec<3, T>& pos, const vec<3, T>& forward, const vec<3, T>& up) {

		vec<3, T> f(forward.Normalized());
		vec<3, T> s((f.Cross(up)).Normalized());
		vec<3, T> u(s.Cross(f));

		mat<4, T> ret;

		ret[0].x =  s.x;
		ret[1].x =  s.y;
		ret[2].x =  s.z;
		ret[0].y =  u.x;
		ret[1].y =  u.y;
		ret[2].y =  u.z;
		ret[0].z = -f.x;
		ret[1].z = -f.y;
		ret[2].z = -f.z;

		ret[3].x = -s.Dot(pos);
		ret[3].y = -u.Dot(pos);
		ret[3].z =  f.Dot(pos);

		return ret;

	}
	template<typename T> inline mat<4, T> ProjectionMatrix(T fov, T aspectRatio, T nearPlane, T farPlane) {

		T tanHalfFov = Tan(fov / T(2));
		mat<4, T> ret(T(0));

		ret[0].x =  T(1) / (aspectRatio * tanHalfFov);
		ret[1].y =  T(1) / tanHalfFov;
		ret[2].z = -(farPlane + nearPlane) / (farPlane - nearPlane);
		ret[2].w =  T(-1);
		ret[3].z = -(T(2) * farPlane * nearPlane) / (farPlane - nearPlane);

		return ret;

	}

}