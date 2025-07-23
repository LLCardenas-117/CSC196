#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "../Core/StringHelper.h"

namespace errera {
	/// <summary>
	/// 
	/// </summary>
	/// <param name="dt"></param>
	void Scene::Update(float dt) {
		for (auto& actor : _actors) {
			actor->Update(dt);
		}
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="renderer"></param>
	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : _actors) {
			actor->Draw(renderer);
		}
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="actor"></param>
	void Scene::AddActor(std::unique_ptr<class Actor> actor) {
		actor->scene = this;
		_actors.push_back(std::move(actor));
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	Actor* Scene::GetActorByName(const std::string& name)
	{
		for (auto& actor : _actors) {
			if (tolower(actor->name) == tolower(name)) {
				return actor.get();
			}
		}

		return nullptr;
	}
}