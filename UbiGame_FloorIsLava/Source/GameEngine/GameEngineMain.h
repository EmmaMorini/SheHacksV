#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "Game/GameBoard.h"

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"

namespace GameEngine
{
	class GameEngineMain
	{
	public:		
		~GameEngineMain();
				
		static GameEngineMain* GetInstance() { if (!sm_instance) sm_instance = new GameEngineMain(); return sm_instance; }
		//Returns time between update frames in seconds
		static float		   GetTimeDelta() { return GetInstance()->m_lastDT; }

		//Returns the time passed since game begun
		static float		   GetTime() { return GetInstance()->m_currentT; }
		//

		static float		   GetGameTime() { return sm_gameClock.getElapsedTime().asSeconds(); }

		sf::RenderWindow* GetRenderWindow() const { return m_renderWindow; }
		void Update();		
		void SetRenderTarget(sf::RenderTarget* target) { m_renderTarget = target; }

		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);

		void OnInitialised();
		bool IsGameOver() const { return m_gameBoard && m_gameBoard->IsGameOver(); }

	private:
		GameEngineMain();

		void CreateAndSetUpWindow();
		
		void AddPendingEntities();
		void RemovePendingEntities();
		void UpdateWindowEvents();
		void UpdateEntities();
		void RenderEntities();		

		static float WINDOW_HEIGHT;
		static float WINDOW_WIDTH;

		static GameEngineMain* sm_instance;
		static sf::Clock	   sm_deltaTimeClock;
		static sf::Clock	   sm_gameClock;

		std::vector<Entity*> m_entitiesToAdd;
		std::vector<Entity*> m_entities;
		std::vector<Entity*> m_entitiesToRemove;

		sf::RenderTarget*   m_renderTarget;
		sf::RenderWindow*   m_renderWindow; //In future they will be different						

		Game::GameBoard*    m_gameBoard;
		float				m_lastDT;

		//varuable for time since game begun
		float				m_currentT;

		bool m_windowInitialised;
	};
}
