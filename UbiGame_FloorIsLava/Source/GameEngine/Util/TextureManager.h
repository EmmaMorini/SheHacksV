#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player = 0,
			Bookshelf,
			Armchair1,
			Armchair2,
			Chair1,
			Chair2,
			Bathtub,
			BG,
			Particles,
			Number1,
			Number2,
			Number3,
			Number4,
			Number5,
			Number6,
			Number7,
			Number8,
			Number9,
			Number0,
			Win,
			Lose,
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Number1: return "1.png";
		case eTexture::Number2: return "2.png";
		case eTexture::Number3: return "3.png";
		case eTexture::Number4: return "4.png";
		case eTexture::Number5: return "5.png";
		case eTexture::Number6: return "6.png";
		case eTexture::Number7: return "7.png";
		case eTexture::Number8: return "8.png";
		case eTexture::Number9: return "9.png";
		case eTexture::Number0: return "0.png";
		case eTexture::Player:    return "player.png";
		case eTexture::Bookshelf: return "bookshelf.png";
		case eTexture::Armchair1: return "armchair.png";
		case eTexture::Armchair2: return "armchair2.png";
		case eTexture::Chair1:	  return "chair.png";
		case eTexture::Chair2:	  return "chair2.png";
		case eTexture::Bathtub:	  return "bathtub.png";
		case eTexture::BG:		  return "bg.png";
		case eTexture::Particles: return "particles.png";
		case eTexture::Win:		  return "win.png";
		case eTexture::Lose: return "lose.png";
		default:       return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

