#pragma once
#include "Soldier.hpp"

namespace WarGame {
    class FootSoldier: public Soldier{
        public:
        FootSoldier(uint player_number, int points = 100, uint damage = 10, const uint health = 100):
        Soldier(player_number, points, damage, health){}

        void attack(vector<vector<Soldier*>> &board,pair<int,int> location);
    };
}