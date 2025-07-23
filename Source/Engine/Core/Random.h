#pragma once
#include <cstdlib>

namespace errera::random {
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	inline int GetRandomInt() { return rand(); }

	/// <summary>
	/// 
	/// </summary>
	/// <param name="max"></param>
	/// <returns></returns>
	inline int GetRandomInt(int max) { return rand() % max; }

	/// <summary>
	/// 
	/// </summary>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <returns></returns>
	inline int GetRandomInt(int min, int max) { return min + GetRandomInt(max - min + 1); }

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	inline float GetRandomFloat() { return rand() / static_cast<float>(RAND_MAX); }
}