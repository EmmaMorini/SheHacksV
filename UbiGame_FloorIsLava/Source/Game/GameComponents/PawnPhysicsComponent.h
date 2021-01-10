#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"


namespace Game {
	class PawnPhysicsComponent : public GameEngine::CollidablePhysicsComponent {
		public:
			PawnPhysicsComponent();
			~PawnPhysicsComponent();

			virtual void OnAddToWorld() override;
			virtual void Update() override;

			void SetVelocity(sf::Vector2f vel) {m_wantedVelocity = vel;}

		protected:
			//Velocity that the pawn wants to have
			sf::Vector2f m_wantedVelocity;
			//Current pawn velocity
			sf::Vector2f m_velocity;
			//Position of the pawn in the last fram
			sf::Vector2f m_lastPos;
	};
}

