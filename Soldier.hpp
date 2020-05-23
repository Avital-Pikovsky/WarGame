#pragma once

#include <stdexcept>
#include <math.h>
#include <vector>

using namespace std;

namespace WarGame
{
    class Soldier
    {
    protected:
        uint player_number;
        int points;       //initial_health_points
        uint damage;       //damage_per_activity
        const uint health; //health_per_activity

        //Pitágoras - a^2+b^2=c^2
        double distance(int x1, int y1, int x2, int y2)
        {
            return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)*(1.0));
        }

    public:
        //Constructor:
        Soldier(uint n, int p, uint d, uint h) : player_number(n), points(p), damage(d), health(h) {}

        virtual ~Soldier() {}

        virtual void attack(vector<vector<Soldier *>> &board, pair<int, int> location) = 0;

        //Getters & setters:
        uint get_player_number()
        {
            return player_number;
        }
        int get_points()
        {
            return points;
        }
        uint get_damage()
        {
            return damage;
        }
        uint get_health()
        {
            return health;
        }
        void set_points(int p)
        {
            points = p;
        }
    };
} // namespace WarGame