#include "../inc/game.hpp"

void GameLoop(Layer &layers, rendermode mode) 
{
	static Camera2D	camera = {0};
	static struct Keys k;
	const int textureSize = 32;
	switch (mode) 
	{
		case RESTART:
		{
			for (size_t i = 0; i < layers.size(); i++) {
				for (size_t j = 0; j < layers[i].size(); j++) {
					layers[i][j]->kill();
				}
			}
			render(layers);
			//use to free the old objs
		}
		case START:
		{
			k.setKeys(true);
			camera.offset = { SCREENWIDTH/2.0f, SCREENHEIGHT/2.0f };
			camera.rotation = 0.0f;
			camera.zoom = 3.0f;
			//player
			Player	*playertmp = new Player(&layers);
			playertmp->_texture = &getTexture("player_down")[0];
			playertmp->keybord = &k;
			playertmp->_pos.x = SCREENWIDTH/2.0f;
			playertmp->_pos.y = SCREENHEIGHT/2.0f;
			getPLayer(playertmp);
			AddImageFormatToLayer(layers, PLAYER, playertmp);
			//map
			for (size_t i = 0; i < 25; i++) {
				for (size_t j = 0; j < 25; j++) {
					ObjFormat* base = new ObjFormat();
					SetRandomSeed(i + j);
					base->_texture = &getTexture("floor")[GetRandomValue(0,1)];
					base->_pos.x = i * textureSize;
					base->_pos.y = j * textureSize;
					if (j < 5)
						AddImageFormatToLayer(layers, WALL, base);
					else
						AddImageFormatToLayer(layers, FLOOR, base);
				}
			}
			break;
			//AddImageFormatToLayer()
			/*
			add code here
			*/
		}
		case RUN:
		{
		ObjFormat*	tmp = editObj(layers, PLAYER, 0);
		camera.target = (Vector2){tmp->_pos.x + (TEXTURE_SIZE / 2), tmp->_pos.y + (TEXTURE_SIZE / 2)};
		//
		BeginMode2D(camera);
		render(layers);
		
		EndMode2D();
		DrawFPS(20, 20);
		//ui render
		break;
	}
		default:
			break;
	}
}
