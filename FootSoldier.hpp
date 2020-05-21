#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

namespace WarGame {
    class FootSoldier: public Soldier{
        public:
        FootSoldier(uint player_number, uint points = 100, uint damage = 10, uint health = 0):
        Soldier(player_number, points, damage, health){}

        void attack(vector<vector<Soldier*>> &board,pair<int,int> location){
            pair<double, Soldier*> closest = make_pair(max(board.size(),board[0].size()), nullptr);

            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    Soldier *s = board[i][j];

                    if(s!=nullptr && s->get_player_number() != player_number){
                    double dis = distance(location.first,location.second, i, j);
                        if(dis < closest.first){
                            closest.first = dis;
                            closest.second = s;
                        }
                    }
                }
            }
            int new_points = closest.second -> get_points() - damage;
            if(new_points <= 0) {
                delete closest.second;
                closest.second = nullptr;
            }
            else
            closest.second -> set_points(new_points);

        }

    };
}