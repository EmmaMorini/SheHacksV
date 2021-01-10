#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include <string>

namespace Game
{

	class ObstacleEntity : public GameEngine::Entity
	{
	public:
		ObstacleEntity(std::string objectType);
		~ObstacleEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;		
	};
}

