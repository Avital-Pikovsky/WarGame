#pragma once
#include "Sniper.hpp"

namespace WarGame {

    class SniperCommander: public Sniper{
        public:
        SniperCommander(uint player_number, int points = 120, uint damage = 100, const uint health = 120):
        Sniper(player_number ,points, damage, health){}

        void attack(vector<vector<Soldier*>> &board,pair<int,int> location);

    };
}