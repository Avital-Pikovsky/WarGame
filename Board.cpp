/**
 * make_pair: http://www.cplusplus.com/reference/utility/make_pair/
 * 
 **/
#include "Soldier.hpp"
#include "Board.hpp"

using namespace std;

namespace WarGame
{

    Soldier *&Board::operator[](std::pair<int, int> location)//מחזיר רפרנס ויכול להחזיר פוינטר
    {
        return this->board[location.second][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const//just get
    {
        return this->board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
    {
        Soldier *s = (*this)[source];
        std::pair<int, int> target;

        switch (direction)
        {
        case Up:
            target = make_pair(source.first + 1, source.second);
            break;
        case Down:
            target = make_pair(source.first - 1, source.second);
            break;
        case Left:
            target = make_pair(source.first, source.second - 1);
            break;
        case Right:
            target = make_pair(source.first, source.second + 1);
            break;
        }

        //If the move is illegal, it throws "std::invalid_argument"
        if (s == nullptr || s->get_player_number() != player_number || (*this)[target] != nullptr)
            throw invalid_argument("The move is illegal");

        //Out of the board
        if (target.first >= board.size() || target.first < 0 || target.second >= board.size() || target.second < 0)
            throw invalid_argument("Out of the board");

        (*this)[source] = nullptr;
        (*this)[target] = s;

        s->attack(board, target);
    }

    bool Board::has_soldiers(uint player_number) const
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *s = (*this)[{i, j}];
                if (s != nullptr && s->get_player_number() == player_number)
                    return true;
            }
        }
        return false;
    }

} // namespace WarGame