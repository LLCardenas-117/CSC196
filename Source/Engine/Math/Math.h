#pragma once
#include <algorithm>
#include <cmath>

namespace errera {
	namespace math {
		constexpr float pi = 3.1415926535897932384626433832795f;
		constexpr float twoPi = 2 * pi;
		constexpr float halfPi = pi / 2;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rad"></param>
		/// <returns></returns>
		constexpr float radToDeg(float rad) { return rad * (180 / pi); }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="deg"></param>
		/// <returns></returns>
		constexpr float degToRad(float deg) { return deg * (pi / 180); }

		using std::min;
		using std::max;
		using std::clamp;
		using std::sqrt;
		using std::sqrtf;
		using std::sin;
		using std::sinf;
		using std::cos;
		using std::cosf;
	}
}