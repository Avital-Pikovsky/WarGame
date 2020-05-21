#include "Sniper.hpp"
namespace WarGame
{

void Sniper::attack(vector<vector<Soldier *>> &board, pair<int, int> location){

            pair<double, Soldier*> strongest = make_pair(max(board.size(),board[0].size()), nullptr);

            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    Soldier *s = board[i][j];

                    if(s!=nullptr && s->get_player_number()!=player_number){
                        double points = s->get_points();
                        if(points > strongest.first){
                            strongest.first = points;
                            strongest.second = s;
                        }
                    }
                }
            }
            int new_points = strongest.second -> get_points() - damage;
            if(new_points <= 0) {
                delete strongest.second;
                strongest.second = nullptr;
            }
            else
            strongest.second -> set_points(new_points);

        }
}