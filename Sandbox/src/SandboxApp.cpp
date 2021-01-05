#include <StoneSword.h>


class Sandbox : public StoneSword::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

StoneSword::Application* StoneSword::CreateApplication() {
	return new Sandbox();
}