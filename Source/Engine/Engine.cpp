#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

namespace errera {
	bool Engine::Initialize() {
		_renderer = std::make_unique<Renderer>();
		_renderer->Initialize();
		_renderer->CreateWindow("ERRERA Engine", 1280, 1024);

		_input = std::make_unique<InputSystem>();
		_input->Initialize();

		_audio = std::make_unique<AudioSystem>();
		_audio->Initialize();
		return true;
	}

	void Engine::Update() {
		_time.Tick();
		_input->Update();
		_audio->Update();
	}

	void Engine::Draw() {
		//
	}

	void Engine::Shutdown()	{
		_audio->Shutdown();
		_input->Shutdown();
		_renderer->Shutdown();
	}

	Engine& GetEngine()
	{
		static Engine engine;
		return engine;
	}
}

