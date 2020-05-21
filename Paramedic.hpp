#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame
{

    class Paramedic : public Soldier{
    public:
        Paramedic(uint player_number, uint points = 100, uint damage = 0, uint health = 50) :
        Soldier(player_number, points, damage, health) {}

        void ability(vector<vector<Soldier*>> &board,pair<int,int> location){
            
        }
    };
} // namespace WarGame