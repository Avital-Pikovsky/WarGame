#pragma once
#include "Paramedic.hpp"

namespace WarGame
{

    class ParamedicCommander : public Paramedic
    {

    public:
        ParamedicCommander(uint player_number, int points = 200, uint damage = 0, const uint health = 200):
        Paramedic(player_number, points, damage, health) {}

        void attack(vector<vector<Soldier*>> &board,pair<int,int> location);
    };

}; // namespace WarGame
