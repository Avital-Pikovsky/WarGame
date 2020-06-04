#pragma once
#include "Soldier.hpp"
using namespace WarGame;

namespace WarGame
{

    class Paramedic : public Soldier{
    public:
        Paramedic(uint player_number, uint points = 100, uint damage = 0, const uint health = 100) :
        Soldier(player_number, points, damage, health) {}

        void attack(vector<vector<Soldier*>> &board,pair<int,int> location);

    };
} // namespace WarGame