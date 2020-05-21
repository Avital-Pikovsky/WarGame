
#include "FootSoldier.hpp"
#include <iostream>

namespace WarGame
{

    void FootSoldier::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
    {

        pair<double, Soldier *> closest = make_pair(1000, nullptr);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *s = board[i][j];

                if (s != nullptr && s->get_player_number() != player_number)
                {
                    double dis = distance(location.first, location.second, i, j);
                    if (dis < closest.first)
                    {
                        closest.first = dis;
                        closest.second = s;
                    }
                }
            }
        }
        int new_points = closest.second->get_points() - damage;
        if (new_points <= 0)
        {

            delete closest.second;
            closest.second = nullptr;
        }
        else{
            closest.second->set_points(new_points);
        }
    }
} // namespace WarGame
