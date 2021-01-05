#pragma once

#include "Core.h"

namespace StoneSword {
	class STONESWORD_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();
}


