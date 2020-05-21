#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame
{

    class Sniper : public Soldier
    {
    public:
        Sniper(uint player_number, uint points = 100, uint damage = 50, uint health = 0) :
        Soldier(player_number, points, damage, health) {}

        void attack(vector<vector<Soldier *>> &board, pair<int, int> location){

        }
    };
} // namespace WarGame