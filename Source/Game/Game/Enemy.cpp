#include "Enemy.h"

#include "Engine.h"
#include "Player.h"
#include "Framework/Game.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include "Rocket.h"
#include "GameData.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"
#include "Core/Random.h"
#include "Math/Vector2.h"

void Enemy::Update(float dt){
    bool playerSeen = false;

    Player* player = scene->GetActorByName<Player>("player");
    if (player) {
        errera::vec2 direction{ 1, 0 };
        direction = player->transform.position - transform.position;
        direction = direction.Normalized();

        errera::vec2 forward = errera::vec2{ 1,0 }.Rotate(errera::math::degToRad(transform.rotation));
        float angle = errera::math::radToDeg(errera::vec2::AngleBetween(forward, direction));

        playerSeen = angle <= 30;

        if (playerSeen) {
            float angle = errera::vec2::SignedAngleBetween(forward, direction);
            angle = errera::math::sign(angle);
            transform.rotation += errera::math::radToDeg(angle * 5 * dt);

        }
        
    }

    errera::vec2 force = errera::vec2{ 1, 0 }.Rotate(errera::math::degToRad(transform.rotation)) * speed;

    velocity += force * dt;

    transform.position.x = errera::math::wrap(transform.position.x, 0.0f, (float)errera::GetEngine().GetRenderer().GetWidth());
    transform.position.y = errera::math::wrap(transform.position.y, 0.0f, (float)errera::GetEngine().GetRenderer().GetHeight());

    fireTimer -= dt;
    if (fireTimer <= 0 && playerSeen) {
        fireTimer = fireTime;

        std::shared_ptr<errera::Model> missleModel = std::make_shared<errera::Model>(GameData::misslePoints, errera::vec3{ 0.0f, 0.0f, 1.0f });
        errera::Transform missleTransform{ this->transform.position, this->transform.rotation, 1.5f };
        auto rocket = std::make_unique<Rocket>(missleTransform, missleModel);
        rocket->speed = 1000.0f;
        rocket->lifespan = 1.5f;
        rocket->name = "rocket";
        rocket->tag = "enemy";

        scene->AddActor(std::move(rocket));
    }

    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other) {
    if (tag != other->tag) {
        destroyed = true;
        scene->GetGame()->AddPoints(100);
        for (int i = 0; i < 100; i++) {
            errera::Particle particle;
            particle.position = transform.position;
			particle.velocity = errera::random::onUnitCircle() * errera::random::getReal(10.0f, 200.0f);
            particle.color = errera::vec3{ 1, 1, 1 };
            particle.lifespan = 2;
            errera::GetEngine().GetParticleSystem().AddParticle(particle);
        }
    }
}
