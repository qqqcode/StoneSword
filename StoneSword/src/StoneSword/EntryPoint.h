#pragma once

#ifdef SS_PLATFROM_WINDOWS

extern StoneSword::Application* StoneSword::CreateApplication();

int main(int argc,char** argv) {
	auto app = StoneSword::CreateApplication();
	app->Run();
	delete app;
}

#endif // SS_PLATFROM_WINDOWS
