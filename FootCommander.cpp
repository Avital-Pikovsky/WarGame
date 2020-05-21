#include "FootCommander.hpp"
#include <iostream>

namespace WarGame
{

    void FootCommander::attack(vector<vector<Soldier *>> &board, pair<int, int> location)
    {
        FootSoldier::attack(board, location);
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                Soldier *s = board[i][j];

                if (s != nullptr && s->get_player_number() == player_number)
                {
                    if (dynamic_cast<FootSoldier*>(s) && !dynamic_cast<FootCommander*>(s)) {
                        s->attack(board, {i,j});
                    }
                }
            }
        }
    }
} // namespace WarGame