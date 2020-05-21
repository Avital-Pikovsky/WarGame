#pragma once
#include "FootSoldier.hpp"

namespace WarGame
{
    class FootCommander : public FootSoldier
    {
    public:
        FootCommander(uint player_number, int points = 150, uint damage = 20, const uint health = 150) : FootSoldier(player_number, points, damage, health) {}

        void attack(vector<vector<Soldier *>> &board, pair<int, int> location);
    };

} // namespace WarGame