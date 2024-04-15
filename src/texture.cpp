#include "../inc/game.hpp"

vec_tex &getTexture(const std::string& Texture_){

	static std::map<std::string, vector<Texture2D> > T;
	static bool init;

	if (!init){

		std::map<std::string, std::vector<std::string> > Textures = {
			{"chat", {"antoine/cat.png"}},
			{"floor", {"Image/Floor/Tile1.png", "Image/Floor/Tile1.png"}},
			{"wall", {"Image/Wall/Wall.png"}},
			
			//player
			{"player_down", {"Image/Character/CharacterDown.png"}},
			{"player_up", {"Image/Character/CharacterUp.png"}},
			{"player_left", {"Image/Character/CharacterLeft.png"}},
			{"player_right", {"Image/Character/CharacterRight.png"}},
			{"player_dash_down", {"Image/Character/CharacterDashDown.png"}},
			{"player_dash_up", {"Image/Character/CharacterDashUp.png"}},
			{"player_dash_left", {"Image/Character/CharacterDashLeft.png"}},
			{"player_dash_right", {"Image/Character/CharacterDashRight.png"}},
			// {"player_attack_down", {"Image/Character/CharacterAttackDown.png"}},
			{"player_attack_up", {"Image/Character/CharacterAttackUp.png"}},
			{"player_attack_left", {"Image/Character/CharacterAttackLeft.png"}},
			{"player_attack_right", {"Image/Character/CharacterAttackRight.png"}},
		};

		for (auto& pair : Textures) {
			std::string name = pair.first;
			for (auto& file : pair.second) {
				T[name].push_back(importImageToTexture2D(file.c_str()));
			}
		}
		init = true;
	}
	auto it = T.find(Texture_);
	if (it == T.end() && Texture_ != ""){
		std::cout << "could not load texture: " << Texture_ << std::endl;
			throw std::runtime_error("could not load texture"); 
	}
	return it->second;
}