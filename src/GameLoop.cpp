#include "../inc/game.hpp"

void GameLoop(Layer &layers, rendermode mode) {
	static Camera2D	camera = {0};
	static struct Keys k;
	const int textureSize = 32;
	switch (mode) {
	case RESTART: {
		for (size_t i = 0; i < layers.size(); i++) {
			for (size_t j = 0; j < layers[i].size(); j++) {
				layers[i][j]->kill();
			}
		}
		render(layers);
		//use to free the old objs
	}
	case START: {
		
		k.setKeys(true);
		camera.offset = { SCREENWIDTH/2.0f, SCREENHEIGHT/2.0f };
		camera.rotation = 0.0f;
		camera.zoom = 3.0f;
		Player	*base = new Player();
		base->_texture = &getTexture("player_down")[0];
		base->keybord = &k;
		base->_pos.x = SCREENWIDTH/2.0f;
		base->_pos.y = SCREENHEIGHT/2.0f;
		getPLayer(base);
		AddImageFormatToLayer(layers, 1, base);
		for (size_t i = 0; i < 400; i++) {
			for (size_t j = 0; j < 400; j++) {
				ObjFormat* base = new ObjFormat();
				SetRandomSeed(i + j);
				base->_texture = &getTexture("floor")[GetRandomValue(0,1)];
				base->_pos.x = i * textureSize;
				base->_pos.y = j * textureSize;
				AddImageFormatToLayer(layers, 0, base);
			}
		}
		//AddImageFormatToLayer()
		/*
		add code here
		*/
		break;
	}
	case RUN: {
		ObjFormat*	tmp = editTexture(layers, 1, 0);
		camera.target = (Vector2){tmp->_pos.x + (TEXTURE_SIZE / 2), tmp->_pos.y + (TEXTURE_SIZE / 2)};

		//
		BeginMode2D(camera);
		Player* ptmp = (Player*)tmp;
		render(layers);
		// hitbox checks?
		
		EndMode2D();
		DrawFPS(20, 20);
		//ui render
		break;
	}
	default:
		break;
	}
}