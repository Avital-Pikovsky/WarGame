#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Paramedic.hpp"

namespace WarGame
{

    class ParamedicCommander : public Paramedic
    {

    public:
        ParamedicCommander(uint player_number, uint points = 100, uint damage = 0, uint health = 50):
        Paramedic(player_number, points, damage, health) {}

        void attack(vector<vector<Soldier*>> &board,pair<int,int> location){
            
        }
    };

}; // namespace WarGame
