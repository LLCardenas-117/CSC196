#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>

#define NAME "Landon\n"

int main() {
	//const float deg = errera::radToDeg(errera::pi);
	errera::math::min(5, 3);
	errera::math::clamp(2, 3, 5);

	std::cout << NAME;
	std::cout << "Hello, World!\n";
	std::cout << errera::math::pi << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << errera::random::getRandomFloat() << std::endl;
	}
}