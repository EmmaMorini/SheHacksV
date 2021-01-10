#include "GameEngine/GameEngineMain.h"

int main()
{
	GameEngine::GameEngineMain* mainEngine = GameEngine::GameEngineMain::GetInstance();
	//added and to close the windows after 8 seconds of play time (change later for 60 sec game)
	while (mainEngine->GetRenderWindow()->isOpen() && GameEngine::GameEngineMain::GetInstance()->GetTime() < 80.0)
	{				
		mainEngine->Update();
	}

	delete mainEngine;
	return 0;
}