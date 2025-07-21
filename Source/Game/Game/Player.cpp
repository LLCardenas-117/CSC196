#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"

#include <SDL3/SDL.h>

void Player::Update(float dt) { //dt = Delta Time
    float speed = 200;
    errera::vec2 direction{ 0,0 };

    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y = +1;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = +1;

    if (direction.LengthSquare() > 0) {
        direction = direction.Normalized();
        GetTransform().position += (direction * speed) * dt;
    }
}
