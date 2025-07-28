#pragma once
#include "../Core/StringHelper.h"

#include <vector>
#include <memory>
#include <string>

namespace errera {
	class Scene {
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(class Renderer& renderer);

		void AddActor(std::unique_ptr < class Actor >);

		void RemoveAllActors();

		template<typename T = Actor>
		T* GetActorByName(const std::string& name);

		template<typename T = Actor>
		std::vector<T*> GetActorsByTag(const std::string& tag);
		
	private:
		std::vector < std::unique_ptr <Actor>> _actors;
	};

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="name"></param>
	/// <returns></returns>
	template<typename T>
	inline T* Scene::GetActorByName(const std::string& name) {
		for (auto& actor : _actors) {
			if (errera::tolower(actor->name) == errera::tolower(name)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					return object;
				}
			}
		}
		return nullptr;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="tag"></param>
	/// <returns></returns>
	template<typename T>
	inline std::vector<T*> Scene::GetActorsByTag(const std::string& tag) {
		std::vector<T*> results;
		for (auto& actor : _actors) {
			if (tolower(actor->tag) == tolower(tag)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					results.push_back(object);
				}
			}
		}

		return results;
	}
}