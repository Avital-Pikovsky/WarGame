#include "Paramedic.hpp"

namespace WarGame
{

    void Paramedic::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
    {

        int i = location.first;
        int j = location.second;

        for (int k = i - 1; k <= i + 1; k++)
        {
            for (int l = j - 1; l <= j + 1; l++)
            {
                Soldier *s = board[k][l];

                if (s != nullptr && s->get_player_number() == player_number)
                {
                    if (k != i && l != j)
                        s->set_points(health);
                }
            }
        }
    }
} // namespace WarGame