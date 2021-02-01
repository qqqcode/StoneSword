#include <StoneSword.h>

class ExampleLayer : public StoneSword::Layer
{
public:
	ExampleLayer() :Layer("example") {
	}

	void OnUpdate() override
	{
		SS_INFO("ExampleLayer::Update");
	}

	void OnEvent(StoneSword::Event& event) override
	{
		SS_TRACE("{0}",event);
	}
};

class Sandbox : public StoneSword::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverLay(new StoneSword::ImGuiLayer());
	}
	~Sandbox() {}
};

StoneSword::Application* StoneSword::CreateApplication() {
	return new Sandbox();
}