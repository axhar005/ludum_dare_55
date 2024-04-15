#include "../inc/game.hpp"

vec_tex &getTexture(const std::string& Texture_){

	static std::map<std::string, vector<Texture2D> > T;
	static bool init;

	if (!init){

		std::map<std::string, std::vector<std::string> > Textures = {
			{"chat", {"antoine/cat.png"}},
			{"floor", {"Image/Floor/Tile1.png", "Image/Floor/Tile2.png", "Image/Floor/CompoTile1.png", "Image/Floor/CompoTile2.png"}},
			{"wall", {"Image/Wall/Wall.png", "Image/Wall/SkullWall.png", "Image/Wall/SkullWall_1.png"}},
			
			//player
			{"player_standby", {"Image/Player/Standby/PlayerStandby0.png", "Image/Player/Standby/PlayerStandby1.png", "Image/Player/Standby/PlayerStandby2.png", "Image/Player/Standby/PlayerStandby3.png"}},
			{"player_down", {"Image/Player/PlayerDown.png"}},
			{"player_up", {"Image/Player/PlayerUp.png"}},
			{"player_left", {"Image/Player/MoveLeft/PlayerLeft0.png", "Image/Player/MoveLeft/PlayerLeft1.png"}},
			{"player_right", {"Image/Player/MoveRight/PlayerRight0.png", "Image/Player/MoveRight/PlayerRight1.png"}},
			//game icons
			{"SoulMoneyUI", {"Image/SoulMoney.png"}},
			{"FireBallUI", {"Image/Spell/GUI/FireBallGUI.png"}},
			{"IceSpikeUI", {"Image/Spell/GUI/IceSpikeGUI.png"}},
			{"SlowZoneUI", {"Image/Spell/GUI/SlowZoneGUI.png"}},
			{"WindSlashUI", {"Image/Spell/GUI/WindSlashGUI.png"}}
			
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