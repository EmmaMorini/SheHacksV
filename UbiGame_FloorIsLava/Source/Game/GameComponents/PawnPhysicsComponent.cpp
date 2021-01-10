#include "PawnPhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"



using namespace Game;


PawnPhysicsComponent::PawnPhysicsComponent() {
	//PawnPhysicsComponent::m_velocity = sf::Vector2f(0.f, 0.f);

}

PawnPhysicsComponent::~PawnPhysicsComponent() {

}

void PawnPhysicsComponent::OnAddToWorld()
{
	
}

void PawnPhysicsComponent::Update() {
	
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	float currentY = GetEntity()->GetPos().y;

	//A
	float gForce = 700.f;

	if (dt > 0.f) {
		m_velocity.x = m_wantedVelocity.x;

		//Accelerate Y or velocity by gravity in time
		m_velocity.y += gForce * dt;

		sf::Vector2f deltaVelocity = dt * m_velocity;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);

	}

	__super::Update();

	float deltaY = GetEntity()->GetPos().y - currentY;
	if (dt > 0.f) {
	m_velocity.y = deltaY / dt;
	}
}