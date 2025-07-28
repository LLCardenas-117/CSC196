#include "Rocket.h"

#include "Engine.h"
#include "Player.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"

void Rocket::Update(float dt) {

    errera::vec2 force = errera::vec2{ 1, 0 }.Rotate(errera::math::degToRad(transform.rotation)) * speed;

    velocity += force * dt;

    transform.position.x = errera::math::wrap(transform.position.x, 0.0f, (float)errera::GetEngine().GetRenderer().GetWidth());
    transform.position.y = errera::math::wrap(transform.position.y, 0.0f, (float)errera::GetEngine().GetRenderer().GetHeight());

    Actor::Update(dt);
}