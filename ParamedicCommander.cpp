#include "ParamedicCommander.hpp"

namespace WarGame
{
    void ParamedicCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *s = board[i][j];

                if (s != nullptr && s->get_player_number() == player_number)
                {
                    if (dynamic_cast<Paramedic*>(s) && !dynamic_cast<ParamedicCommander*>(s))
                    {
                        s->attack(board, {i, j});
                    }
                }
            }
        }
    }
} // namespace WarGame