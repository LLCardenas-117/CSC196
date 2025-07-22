#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Math/Math.h"

#include <SDL3/SDL.h>

void Player::Update(float dt) { //dt = Delta Time
    float speed = 200;
    float rotationRate = 180;

    // Rotation
    float rotate = 0;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;
    
    _transform.rotation += (rotate * rotationRate) * dt;

    // Thrust
    float thrust = 0;

    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +1;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    errera::vec2 direction{ 1, 0 };
    errera::vec2 force = direction.Rotate(errera::math::degToRad(_transform.rotation)) * thrust * speed;

    velocity += force * dt;

    Actor::Update(dt);

    /*if (direction.LengthSquare() > 0) {
        direction = direction.Normalized();
        GetTransform().position += (direction * speed) * dt;
    }*/
}
