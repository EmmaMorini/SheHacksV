#include "AnimationManager.h"


using namespace GameEngine;

AnimationManager* AnimationManager::sm_instance = nullptr;

AnimationManager::AnimationManager()
{

}


AnimationManager::~AnimationManager()
{

}


void AnimationManager::InitStaticGameAnimations()
{
	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::BirdIdle,
			eTexture::Player,
			sf::Vector2i(0, 0),
			8,
			12)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::BirdFly,
			eTexture::Player,
			sf::Vector2i(0, 1),
			10,
			15)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::Smoke,
			eTexture::Particles,
			sf::Vector2i(0, 0),
			0,
			0) // bandaid solution to remove smoke
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::Lava,
			eTexture::Lava,
			sf::Vector2i(0, 0),
			2,
			1)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::None,
			eTexture::Chair2,
			sf::Vector2i(0, 0),
			2,
			1)
	);
}


void AnimationManager::ReleaseStaticGameAnimations()
{
	m_animDefinitions.clear();
}


const SAnimationDefinition* AnimationManager::GetAnimDefinition(EAnimationId::type animId) const
{
	for (int a = 0; a < m_animDefinitions.size(); ++a)
	{
		if (m_animDefinitions[a].m_animId == animId)
			return &m_animDefinitions[a];
	}

	return nullptr;
}
