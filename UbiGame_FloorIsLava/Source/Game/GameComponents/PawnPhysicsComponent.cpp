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

	float gametime = GameEngine::GameEngineMain::GetInstance()->GetTime();
	
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	float currentY = GetEntity()->GetPos().y;

	//A
	float gForce = 700.f;

	if (dt > 0.f) {
		float lerpTime = 5.2f;
		m_velocity.x = m_wantedVelocity.x;
		m_velocity.y += m_wantedVelocity.y;

		//Accelerate Y or velocity by gravity in time

		if(gametime > 8){
			m_velocity.y += gForce * dt;
		}
		else {
			m_velocity.y = 0;
			m_velocity.x = 0;
		}
		

		sf::Vector2f deltaVelocity = dt * m_velocity;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);

	}

	__super::Update();

	float deltaY = GetEntity()->GetPos().y - currentY;
	if (dt > 0.f) {
		m_velocity.y = deltaY / dt;
	}
}

float PawnPhysicsComponent::Lerp(float a, float b, float f){
	return (a * (1.0f - f)) + (b * f);
}