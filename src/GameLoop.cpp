#include "../inc/game.hpp"

void GameLoop(Layer &layers, rendermode mode) {
	static Camera2D	camera = {0};
	static struct Keys k;

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
		camera.zoom = 1.0f;
		for (size_t i = 0; i < 1; i++) {
			Player	*base = new Player();
			base->_texture = &getTexture("chat")[0];
			base->keybord = &k;
			base->_pos.x = SCREENWIDTH/2.0f;
			base->_pos.y = SCREENHEIGHT/2.0f;
			AddImageFormatToLayer(layers, 1, base);
		}
		for (size_t i = 0; i < 40; i++) {
			ObjFormat* base = new ObjFormat();
			base->_texture = &getTexture("chat")[0];
			base->_pos.x = i * 200;
			base->_pos.y = 0;
			AddImageFormatToLayer(layers, 0, base);
		}
		//AddImageFormatToLayer()
		/*
		add code here
		*/
		break;
	}
	case RUN: {
		ObjFormat*	tmp = editTexture(layers, 1, 0);
		camera.target = tmp->_pos;
		//
		BeginMode2D(camera);
		render(layers);
		EndMode2D();
		//ui render
		break;
	}
	default:
		break;
	}
}