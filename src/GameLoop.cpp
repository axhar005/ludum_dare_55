#include "../inc/game.hpp"

void GameLoop(Layer &layers, rendermode mode) 
{
	static Camera2D	camera = {0};
	static struct Keys k;
	const int textureSize = 32;
	switch (mode) {
		case START: {
			for (size_t i = 0; i < layers.size(); i++) {
				for (size_t j = 0; j < layers[i].size(); j++) {
					if (layers[i][j]) {
						delete layers[i][j];
					}
				}
				layers[i].clear();
			}
			layers.clear();
			InitMapLayer(layers);
			//use to free the old objs
			k.setKeys(true);
			camera.offset = { SCREENWIDTH/2.0f, SCREENHEIGHT/2.0f };
			camera.rotation = 0.0f;
			camera.zoom = 3.0f;
			Player	*base = new Player(&layers);
			ObjFormat	*test = new ObjFormat(&layers);
			test->_texture = &getTexture("player_down")[0];
			Spawner	*sp = new Spawner(&layers, ((ObjFormat *)test));
			sp->_pos = (Vector2){30, 30};
			sp->_speed = 2;
			base->_texture = &getTexture("player_down")[0];
			base->keybord = &k;
			base->_pos.x = SCREENWIDTH/2.0f;
			base->_pos.y = SCREENHEIGHT/2.0f;
			getPLayer(base);
			AddImageFormatToLayer(layers, 1, sp);
			auto now = std::chrono::high_resolution_clock::now();
			auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
			auto value = now_ms.time_since_epoch();
			long long duration = value.count();
			std::srand(static_cast<unsigned int>(duration));
			int randomNumber = std::rand();
			AddImageFormatToLayer(layers, PLAYER, base);
			std::srand(std::time(nullptr));
			int seed = std::rand();
			SetRandomSeed(randomNumber);
			Map map(MapOptions(MAP_SIZE, MAP_SIZE, 15, 20));
			for (size_t i = 0; i < MAP_SIZE; i++) {
				for (size_t j = 0; j < MAP_SIZE; j++) {
					ObjFormat* base = new ObjFormat();
					base->_pos.x = i * textureSize;
					base->_pos.y = j * textureSize;
					base->_hitbox = {base->_pos.x, base->_pos.y, TEXTURE_SIZE, TEXTURE_SIZE};
					if (map.getMap()[i][j] == '0')
					{
						base->_texture = &getTexture("floor")[GetRandomValue(2,3)];
						AddImageFormatToLayer(layers, FLOOR, base);
					}
					else if (map.getMap()[i][j] == '1')
					{
						base->_texture = &getTexture("wall")[GetRandomValue(1,2)];
						AddImageFormatToLayer(layers, WALL, base);
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
			//std::cout << returnVecLayer(layers, SPELL).size() << "\n";
			DrawFPS(20, 20);
			//ui render
			break;
		}
		case ENDGAME: {
			for (size_t i = 0; i < layers.size(); i++) {
				for (size_t j = 0; j < layers[i].size(); j++) {
					if (layers[i][j]) {
						delete layers[i][j];
					}
				}
				layers[i].clear();
			}
			layers.clear();
			break;
		}
		default:
			break;
	}
}
