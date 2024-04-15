#include "../inc/game.hpp"

void GameLoop(Layer &layers, rendermode mode) 
{
	static Camera2D	camera = {0};
	static struct Keys k;
	const int textureSize = 32;
	switch (mode) {
		case RESTART:
			for (size_t i = 0; i < layers.size(); i++) {
				for (size_t j = 0; j < layers[i].size(); j++) {
					delete layers[i][j];
				}
				layers[i].clear();
			}
			layers.clear();
			InitMapLayer(layers);
			//use to free the old objs
		case START: {
			k.setKeys(true);
			camera.offset = { SCREENWIDTH/2.0f, SCREENHEIGHT/2.0f };
			camera.rotation = 0.0f;
			camera.zoom = 3.0f;
			Player	*base = new Player(&layers);
			base->_texture = &getTexture("player_down")[0];
			base->keybord = &k;
			base->_pos.x = SCREENWIDTH/2.0f;
			base->_pos.y = SCREENHEIGHT/2.0f;
			getPLayer(base);
			AddImageFormatToLayer(layers, PLAYER, base);
			std::srand(std::time(nullptr));
			int seed = std::rand();
			SetRandomSeed(seed);
			Map map(MapOptions(MAP_SIZE, MAP_SIZE, 15, 20));
			for (size_t i = 0; i < MAP_SIZE; i++) {
				for (size_t j = 0; j < MAP_SIZE; j++) {
					ObjFormat* base = new ObjFormat();
					base->_pos.x = i * textureSize;
					base->_pos.y = j * textureSize;
					if (map.getMap()[i][j] == '0')
					{
						base->_texture = &getTexture("floor")[GetRandomValue(2,3)];
						AddImageFormatToLayer(layers, FLOOR, base);
					}
					else if (map.getMap()[i][j] == '1')
					{
						base->_texture = &getTexture("wall")[GetRandomValue(1,2)];
						AddImageFormatToLayer(layers, WALL, base);
						base->_hitbox.x = base->_pos.x;
						base->_hitbox.y = base->_pos.y;
					}
				}
			}
			//AddImageFormatToLayer()
			/*
			add code here
			*/
			break;
		}
		case RUN: {
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
