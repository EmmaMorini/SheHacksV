#include "TextureManager.h"

using namespace GameEngine;

TextureManager* TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		m_textures[a] = nullptr;
	}
}


TextureManager::~TextureManager()
{
	UnLoadTextures();
}


void TextureManager::LoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		sf::Texture* texture = new sf::Texture();
		std::string filePath;
		filePath.append("Resources/img/");
		filePath.append(GetPath((eTexture::type)a));
		texture->loadFromFile(filePath);

		m_textures[a] = texture;
	}
}


void TextureManager::UnLoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		delete m_textures[a];
		m_textures[a] = nullptr;
	}
}

namespace TextureHelper
{
    sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
    {
        switch (texture)
        {
        case  GameEngine::eTexture::Player:  return sf::Vector2f(68.f, 110.f);
        //case  GameEngine::eTexture::Tileset: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Bookshelf: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Armchair1: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Armchair2: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Chair1: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Chair2: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Bathtub: return sf::Vector2f(32.f, 32.f); 
        case  GameEngine::eTexture::BG:	     return sf::Vector2f(500.f, 500.f);
        case  GameEngine::eTexture::Particles: return sf::Vector2f(31.f, 32.f);
		case  GameEngine::eTexture::Number0: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number1: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number2: return sf::Vector2f(32.f, 32.f); 
		case  GameEngine::eTexture::Number3: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number4: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number5: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number6: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number7: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number8: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Number9: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::Win: return sf::Vector2f(500.f, 500.f);
		case  GameEngine::eTexture::Lose: return sf::Vector2f(500.f, 500.f);
		case  GameEngine::eTexture::Lava: return sf::Vector2f(500.f, 100.f);

        default:							 return sf::Vector2f(-1.f, -1.f);
        }
    }
}
