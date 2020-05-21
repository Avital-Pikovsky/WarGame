#pragma once

#include <stdexcept>
#include <math.h>
#include "Board.hpp"

using namespace std;

namespace WarGame {
    class Soldier{
        protected:
        uint player_number;
        uint points; //initial_health_points
        uint damage; //damage_per_activity
        const uint health; //health_per_activity

        //Pitágoras - a^2+b^2=c^2
        double distance(uint x1, uint y1, uint x2, uint y2){
                return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        }

        public:
        //Constructor:
        Soldier(uint n, uint p, uint d, uint h):
        player_number(n),points(p), damage(d), health(h){}

        virtual void attack(vector<vector<Soldier*>> &board,pair<int,int> location) = 0; 

        //Getters & setters:
        uint get_player_number(){
            return player_number;
        }
        uint get_points(){
            return points;
        }
        uint get_damage(){
            return damage;
        }
        uint get_health(){
            return health;
        }
        void set_points(uint p){
            points = p;
        }

    };
}