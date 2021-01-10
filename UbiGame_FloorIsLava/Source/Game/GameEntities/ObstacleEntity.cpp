#include "ObstacleEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include <SFML/Graphics.hpp>

#include <string>

using namespace Game;

ObstacleEntity::ObstacleEntity(std::string objectType)	
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetFillColor(sf::Color::Red);
	/*
	if (objectType == "Player") {
		m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	}
	else if(objectType == "Bookshelf"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Bookshelf);
	}
	else if(objectType == "Armchair1"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Armchair1);
	}
	else if(objectType == "Armchair2"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Armchair2);
	}
	else if(objectType == "Chair1"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Chair1); 
	}
	else if(objectType == "Chair2"){ 
		m_renderComponent->SetTexture(GameEngine::eTexture::Chair2);
	}
	else if(objectType == "Bathtub"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Bathtub);
	}
	else if(objectType == "BG"){
		m_renderComponent->SetTexture(GameEngine::eTexture::BG);
	}
	else if(objectType == "Particles"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Particles);
	} */
	if(objectType == "Number0"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number0);
	}
	else if(objectType == "Number1"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number1);
	}
	else if(objectType == "Number2"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number2);
	}
	else if(objectType == "Number3"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number3);
	}
	else if(objectType == "Number4"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number4);
	}
	else if(objectType == "Number5"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number5);
	}
	else if(objectType == "Number6"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number6);
	}
	else if(objectType == "Number7"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number7);
	}
	else if(objectType == "Number8"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number8);
	}
	else if(objectType == "Number9"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Number9);
	}
	else if(objectType == "Win"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Win);
	}
	else if(objectType == "Lose"){
		m_renderComponent->SetTexture(GameEngine::eTexture::Lose);
	}
	else{
		m_renderComponent->SetTexture(GameEngine::eTexture::Chair2);
	}
	//m_renderComponent->SetTexture(GameEngine::eTexture::Bookshelf); 
	m_renderComponent->SetZLevel(2);
	m_renderComponent->SetTileIndex(0, 0);

	AddComponent<GameEngine::CollidableComponent>();
}


ObstacleEntity::~ObstacleEntity()
{

}


void ObstacleEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void ObstacleEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
