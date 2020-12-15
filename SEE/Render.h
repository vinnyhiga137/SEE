#pragma once
#include "pch.h"
#include "Sprite.h"

namespace SEE {
	class Render {
	private:

		// Local attributes
		static SEE::Render* instance;

		unsigned int shaderProgram;
		unsigned int testVao;

		Render();
		~Render();

	public:

		static Render* GetInstance();

		void SetupShaderProgram(
			const char* vertexFile, 
			const char* fragFile,
			SEE::Sprite* sprite);

		void DrawContent();

	};
}