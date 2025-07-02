#pragma once
#include <cstdlib>

namespace errera {
	namespace random {
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		inline int getRandomInt() { return rand(); }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="max"></param>
		/// <returns></returns>
		inline int getRandomInt(int max) { return rand() % max; }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="min"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		inline int getRandomInt(int min, int max) { return min + getRandomInt(max - min + 1); }

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		inline float getRandomFloat() { return rand() / static_cast<float>(RAND_MAX); }
	}
}