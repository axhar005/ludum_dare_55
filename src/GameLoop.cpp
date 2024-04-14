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
		Texture2D cat = importImageToTexture2D("antoine/cat.png");
		Player*	playerTmp = new Player();
		playerTmp->_texture = &cat;
		playerTmp->keybord = &k;
		AddImageFormatToLayer(layers, 0, playerTmp);
		std::cout << "ici2\n";
		/*
		add code here
		*/
		break;
	}
	case RUN:
		//camera.target = player->_pos;
		//
		std::cout << "run\n";
		BeginMode2D(camera);
		render(layers);
		EndMode2D();
		//ui render
		break;
	default:
		break;
	}
}