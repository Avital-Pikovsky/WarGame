#include "SniperCommander.hpp"

namespace WarGame
{
    void SniperCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
    {
        Sniper::attack(board, location);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                Soldier *s = board[i][j];

                if (s != nullptr && s->get_player_number() == player_number)
                {
                    if (dynamic_cast<Sniper*>(s) && !dynamic_cast<SniperCommander*>(s))
                    {
                        s->attack(board, {i, j});
                    }
                }
            }
        }
    }
} // namespace WarGame