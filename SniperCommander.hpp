#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Sniper.hpp"

namespace WarGame {

    class SniperCommander: public Sniper{
        public:
        SniperCommander(uint player_number, uint points = 120, uint damage = 100, uint health = 0):
        Sniper(player_number ,points, damage, health){}

        void attack(vector<vector<Soldier*>> &board,pair<int,int> location){
            
        }

    };
}