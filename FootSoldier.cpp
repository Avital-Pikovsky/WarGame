
#include "FootSoldier.hpp"
#include <iostream>

namespace WarGame
{

    void FootSoldier::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
    {
        pair<double, Soldier *> closest = make_pair(distance(board.size(), board[0].size(), 0, 0), nullptr);

        int fir,sec;

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
                        fir=i;
                        sec=j;
                    }
                }
            }
        }
        if (closest.second != nullptr)
        {
            int new_points = closest.second->get_points() - damage;
            if (new_points <= 0)
            {
                delete board[fir][sec];
                board[fir][sec] = nullptr;
            }
            else
            {
                closest.second->set_points(new_points);
            }
        }
    }
} // namespace WarGame
