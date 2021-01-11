#pragma once

#ifdef SS_PLATFROM_WINDOWS

extern StoneSword::Application* StoneSword::CreateApplication();

int main(int argc,char** argv) {

	StoneSword::Log::Init();
	SS_CORE_WARN("Initialized CoreLog!");

	SS_INFO("Initialized ClientLog!{}");


	auto app = StoneSword::CreateApplication();
	app->Run();
	delete app;
}

#endif // SS_PLATFROM_WINDOWS
