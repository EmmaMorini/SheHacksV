#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string>

namespace Game
{
	//Used for storing and controling all game related entities
	class PlayerEntity;

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		//Temp - for nice architecture this should be within some sort of IUpdatable interface that GameEngine handles (so that not only entities can be updated)
		void Update();
		void UpdateObstacles(float dt);
		void UpdatePlayerDying();
		void SpawnNewRandomObstacles();
		//end message
		void SpawnEndMessage(bool win);
		void SpawnEnd(const sf::Vector2f& pos, const sf::Vector2f& size, bool win);
		//
		void SpawnNewRandomTiledObstacles();
		void SpawnNewObstacle(const sf::Vector2f& pos, const sf::Vector2f& size, std::string objectType);

		bool IsGameOver() const { return m_isGameOver; }

	protected:
		//Placeholder temp - should go to helpers or smth.
		float RandomFloatRange(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}

		void CreateBackGround();
		void UpdateBackGround();

		PlayerEntity* m_player;
		GameEngine::Entity* m_backGround;
		GameEngine::Entity* m_lava;

		std::vector<GameEngine::Entity*> m_obstacles;
		float m_lastObstacleSpawnTimer;
		bool  m_isGameOver;

		int timertime;
	};
}

