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
                if (k >= 0 && k < board.size() && l >= 0 && l < board[0].size())
                {
                    Soldier *s = board[k][l];

                    if (s != nullptr && s->get_player_number() == player_number)
                    {
                        if (!(k == i && l == j))
                            s->set_points(s->get_health());
                    }
                }
            }
        }
    }
} // namespace WarGame