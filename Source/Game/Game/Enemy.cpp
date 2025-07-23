#include "Enemy.h"

#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"

void Enemy::Update(float dt){
    Actor* player = scene->GetActorByName("player");
    if (player) {
        errera::vec2 direction{ 1, 0 };
        direction = player->transform.position - transform.position;
        direction = direction.Normalized();
        transform.rotation = errera::math::radToDeg(direction.Angle());
    }

    errera::vec2 force = errera::vec2{ 1, 0 }.Rotate(errera::math::degToRad(transform.rotation)) * speed;

    velocity += force * dt;

    transform.position.x = errera::math::wrap(transform.position.x, 0.0f, (float)errera::GetEngine().GetRenderer().GetWidth());
    transform.position.y = errera::math::wrap(transform.position.y, 0.0f, (float)errera::GetEngine().GetRenderer().GetHeight());

    Actor::Update(dt);
}
