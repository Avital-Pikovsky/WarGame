#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include <list>


namespace WarGame
{
    class FootCommander : public FootSoldier
    {
    public:
        FootCommander(uint player_number, uint points = 100, uint damage = 10, uint health = 0) : FootSoldier(player_number, points, damage, health) {}

        void attack(vector<vector<Soldier *>> &board, pair<int, int> location)
        {
            FootSoldier::attack(board, location);
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    Soldier *s = board[i][j];

                    if(s!=nullptr && s->get_player_number() != player_number){
                        if(FootSoldier *f = dynamic_cast<FootSoldier *>(s)){
                            f->attack(board,{i,j});
                        }
                    }
                }
            }
        }
    };

} // namespace WarGame