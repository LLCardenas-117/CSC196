#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"

#include "GameData.h"
#include "Rocket.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"

void Player::Update(float dt) { //dt = Delta Time
    // Rotation
    float rotate = 0;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;
    
    transform.rotation += (rotate * rotationRate) * dt;

    // Thrust
    float thrust = 0;

    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +1;
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    errera::vec2 direction{ 1, 0 };
    errera::vec2 force = direction.Rotate(errera::math::degToRad(transform.rotation)) * thrust * speed;

    velocity += force * dt;

    transform.position.x = errera::math::wrap(transform.position.x, 0.0f, (float)errera::GetEngine().GetRenderer().GetWidth());
    transform.position.y = errera::math::wrap(transform.position.y, 0.0f, (float)errera::GetEngine().GetRenderer().GetHeight());

    // check fire key pressed
    // spawn rocket with staying to the players position
    if (errera::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) {

        std::shared_ptr<errera::Model> missleModel = std::make_shared<errera::Model>(GameData::enemyShipPoints, errera::vec3{ 0.749f, 0.250f, 0.749f });
        errera::Transform missleTransform{ errera::vec2{transform.position.x, transform.position.y}, 0, 2.5 };
        std::unique_ptr<Rocket> enemy = std::make_unique<Rocket>(missleTransform, missleModel);
        //Rocket(const errera::Transform & transform, std::shared_ptr<errera::Model> model)
    }

    Actor::Update(dt);
}
