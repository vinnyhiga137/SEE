#pragma once
#include <vector>

namespace SEE {
	class Sprite
	{
	public:
		Sprite(std::vector<float>* vertices);
		~Sprite();

		std::vector<float>* vertices;

	};
}