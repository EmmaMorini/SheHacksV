#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/PawnPhysicsComponent.h"

#include "GameEngine/Util/CameraManager.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/ObstacleEntity.h"
#include <string>

using namespace Game;

GameBoard::GameBoard()
	: m_player(nullptr)
	, m_backGround(nullptr)
	, m_lava(nullptr)
	, m_lastObstacleSpawnTimer(0.f)
	, m_isGameOver(false)
{
	m_player = new PlayerEntity();

	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(50.f, 50.f));
	m_player->SetSize(sf::Vector2f(40.f, 60.f));

	CreateBackGround();
	//Debug
	for (int a = 0; a < 3; ++a)
	{
		//SpawnNewRandomObstacles();
	}
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!m_isGameOver)
	{
		m_lastObstacleSpawnTimer -= dt;
		if (m_lastObstacleSpawnTimer <= 0.f)
		{
			SpawnNewRandomObstacles();
			//SpawnNewRandomTiledObstacles();
		}

		//timer to end the game in 60 seconds 

		float gametime = GameEngine::GameEngineMain::GetInstance()->GetTime();

		//Start creating timer at top of screen

		int timertime = (int)gametime;

		sf::Vector2f posdig1 = sf::Vector2f(400.f, 400.f);
		sf::Vector2f sizedig1 = sf::Vector2f(32.f, 32.f);

		sf::Vector2f posdig2 = sf::Vector2f(400.f, 440.f);
		sf::Vector2f sizedig2 = sf::Vector2f(32.f, 32.f);

		//Check gametime and update number entities at top of screen
		//For numbers 0-9
		if (timertime < 10) {
			switch (timertime) {
			case 0: SpawnNewObstacle(posdig1, sizedig1, "Number0");
			case 1: SpawnNewObstacle(posdig1, sizedig1, "Number1");
			case 2: SpawnNewObstacle(posdig1, sizedig1, "Number2");
			case 3: SpawnNewObstacle(posdig1, sizedig1, "Number3");
			case 4: SpawnNewObstacle(posdig1, sizedig1, "Number4");
			case 5: SpawnNewObstacle(posdig1, sizedig1, "Number5");
			case 6: SpawnNewObstacle(posdig1, sizedig1, "Number6");
			case 7: SpawnNewObstacle(posdig1, sizedig1, "Number7");
			case 8: SpawnNewObstacle(posdig1, sizedig1, "Number8");
			case 9: SpawnNewObstacle(posdig1, sizedig1, "Number9");
			}
		}
		else if (timertime >= 10) {
			int seconddig = timertime % 10;
			timertime = timertime / 10;
			int firstdig = timertime % 10;

			switch (firstdig) {
			case 0: SpawnNewObstacle(posdig1, sizedig1, "Number0");
			case 1: SpawnNewObstacle(posdig1, sizedig1, "Number1");
			case 2: SpawnNewObstacle(posdig1, sizedig1, "Number2");
			case 3: SpawnNewObstacle(posdig1, sizedig1, "Number3");
			case 4: SpawnNewObstacle(posdig1, sizedig1, "Number4");
			case 5: SpawnNewObstacle(posdig1, sizedig1, "Number5");
			case 6: SpawnNewObstacle(posdig1, sizedig1, "Number6");
			case 7: SpawnNewObstacle(posdig1, sizedig1, "Number7");
			case 8: SpawnNewObstacle(posdig1, sizedig1, "Number8");
			case 9: SpawnNewObstacle(posdig1, sizedig1, "Number9");
			}
			switch (seconddig) {
			case 0: SpawnNewObstacle(posdig2, sizedig2, "Number0");
			case 1: SpawnNewObstacle(posdig2, sizedig2, "Number1");
			case 2: SpawnNewObstacle(posdig2, sizedig2, "Number2");
			case 3: SpawnNewObstacle(posdig2, sizedig2, "Number3");
			case 4: SpawnNewObstacle(posdig2, sizedig2, "Number4");
			case 5: SpawnNewObstacle(posdig2, sizedig2, "Number5");
			case 6: SpawnNewObstacle(posdig2, sizedig2, "Number6");
			case 7: SpawnNewObstacle(posdig2, sizedig2, "Number7");
			case 8: SpawnNewObstacle(posdig2, sizedig2, "Number8");
			case 9: SpawnNewObstacle(posdig2, sizedig2, "Number9");
			}
		}




		//std::cout << gametime << std::endl; // to print out the time passed to test out the timer
		if (gametime > 60.0)
		{
			SpawnEndMessage(true);
			m_isGameOver = true;

		}


		UpdateObstacles(dt);
		UpdateBackGround();
		UpdatePlayerDying();
	}
}


void GameBoard::UpdateObstacles(float dt)
{
	static float obstacleSpeed = 100.f;

	for (std::vector<GameEngine::Entity*>::iterator it = m_obstacles.begin(); it != m_obstacles.end();)
	{
		GameEngine::Entity* obstacle = (*it);
		sf::Vector2f currPos = obstacle->GetPos();
		currPos.x -= obstacleSpeed * dt;
		obstacle->SetPos(currPos);
		//If we are to remove ourselves
		if (currPos.x < -50.f)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(obstacle);
			it = m_obstacles.erase(it);
		}
		else
		{
			it++;
		}
	}
}


void GameBoard::UpdatePlayerDying() ////////////////////////////////////
{
	bool noGameOver = GameEngine::CameraManager::IsFollowCameraEnabled();

	if (noGameOver)
		return;

	static float xToPlayerDie = 0.f;
	if (m_player->GetPos().x < xToPlayerDie)
	{
		m_isGameOver = true;
		SpawnEndMessage(false);
	}
}


void GameBoard::SpawnNewRandomObstacles()
{
	static float minNextSpawnTime = 0.3f;
	static float maxNextSpawnTime = 0.7f;

	static float minObstacleXPos = 50.f;
	static float maxObstacleXPos = 450.f;

	//Make sure object is spawned on the ground
	static float minObstacleYPos = 0.f;
	static float maxObstacleYPos = 0.f;

	static float minObstacleHeight = 32.f;
	static float maxObstacleHeight = 32.f;
	static float minObstacleWidth = 32.f;
	static float maxObstacleWidth = 32.f;

	sf::Vector2f pos = sf::Vector2f(RandomFloatRange(minObstacleXPos, maxObstacleXPos), RandomFloatRange(minObstacleYPos, maxObstacleYPos));
	sf::Vector2f size = sf::Vector2f(RandomFloatRange(minObstacleWidth, maxObstacleWidth), RandomFloatRange(minObstacleHeight, maxObstacleHeight));

	//Generate random number from 1-6 and spawn a funiture item
	int num = rand() % 6 + 1;
	switch (num) {
	case 1: /*Spawn the bookshelf*/ SpawnNewObstacle(pos, size, "Bookshelf");
	case 2: /*Spawn the armchair 1*/ SpawnNewObstacle(pos, size, "Armchair1");
	case 3: /*Spawn the armchair 2*/ SpawnNewObstacle(pos, size, "Armchair2");
	case 4: /*Spawn the chair 1*/ SpawnNewObstacle(pos, size, "Chair1");
	case 5: /*Spawn the chair 2*/ SpawnNewObstacle(pos, size, "Chair2");
	case 6: /*Spawn the bathtub*/ SpawnNewObstacle(pos, size, "Bathtub");

	}

	//SpawnNewObstacle(pos, size);

	m_lastObstacleSpawnTimer = RandomFloatRange(minNextSpawnTime, maxNextSpawnTime);


}

//End message pop-up code//
void GameBoard::SpawnEndMessage(bool win)
{
	sf::Vector2f pos = sf::Vector2f(0, 0);
	sf::Vector2f size = sf::Vector2f(500.f, 500.f);

	SpawnEnd(pos, size, win);
}

void GameBoard::SpawnEnd(const sf::Vector2f& pos, const sf::Vector2f& size, bool win)
{
	if (win == true) {
		SpawnNewObstacle(pos, size, "Win");
	}
	else {
		SpawnNewObstacle(pos, size, "Lose");
	}
	//PlayerEntity* player = new PlayerEntity();
	//GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	//player->SetPos(pos);
	//player->SetSize(sf::Vector2f(size.x, size.y));
}
//

/*void GameBoard::SpawnNewRandomTiledObstacles()
{
	static int minObstacleCount = 2;
	static int maxObstacleCount = 7;

	static float minNextSpawnTime = 0.3f;
	static float maxNextSpawnTime = 0.7f;

	static float minObstacleXPos = 350.f;
	static float maxObstacleXPos = 450.f;
	static float minObstacleYPos = 20.f;
	static float maxObstacleYPos = 450.f;

	sf::Vector2f pos = sf::Vector2f(RandomFloatRange(minObstacleXPos, maxObstacleXPos), RandomFloatRange(minObstacleYPos, maxObstacleYPos));
	sf::Vector2f size = sf::Vector2f(32.f, 32.f);

	int obstacleCount = (int)RandomFloatRange((float)minObstacleCount, (float)maxObstacleCount);
	for (int a = 0; a < obstacleCount; ++a)
	{
		SpawnNewObstacle(pos, size);
		pos.y += size.y;
	}

	m_lastObstacleSpawnTimer = RandomFloatRange(minNextSpawnTime, maxNextSpawnTime);
}
*/


void GameBoard::SpawnNewObstacle(const sf::Vector2f& pos, const sf::Vector2f& size, std::string objectType)
{
	ObstacleEntity* obstacle = new ObstacleEntity(objectType);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);
	obstacle->SetPos(pos);
	obstacle->SetSize(sf::Vector2f(size.x, size.y));

	m_obstacles.push_back(obstacle);
}


void GameBoard::CreateBackGround()
{
	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

	m_backGround = bgEntity;

	GameEngine::Entity* lavaEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render2 = lavaEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render2->SetTexture(GameEngine::eTexture::Lava);
	render2->SetZLevel(1);
	lavaEntity->SetPos(sf::Vector2f(250.f, 450.f));
	lavaEntity->SetSize(sf::Vector2f(500.f, 100.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(lavaEntity);

	m_lava = lavaEntity;
}


void GameBoard::UpdateBackGround()
{
	if (!m_backGround || !m_lava || !m_player)
		return;

	if (!GameEngine::CameraManager::IsFollowCameraEnabled())
		return;

	m_backGround->SetPos(m_player->GetPos());
}