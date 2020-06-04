#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>

//check exceptions in diff cases

TEST_CASE("Sniper VS Sniper") { //good
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new Sniper(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
	board[{7,1}] = new Sniper(2);
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("Foot vs Foot") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1); //soldier 1 - 100
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
	board[{7,1}] = new FootSoldier(2); //soldier 2 - 100
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up); //soldier 2 - 90
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up)); //no soldier thehre
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up); //soldier 2 - 80
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2,{7,1},WarGame::Board::MoveDIR::Up));
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 90
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{6,1},WarGame::Board::MoveDIR::Down); //sodier 1 - 80
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{5,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 70
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{2,1},WarGame::Board::MoveDIR::Up); //soldier 2 - 70
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{3,1},WarGame::Board::MoveDIR::Up));//there is another soldier in the destenation
    CHECK_THROWS(board.move(2,{4,1},WarGame::Board::MoveDIR::Down)); //gam ze
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{3,1},WarGame::Board::MoveDIR::Down); //soldier 2 - 60
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{4,1},WarGame::Board::MoveDIR::Up); //soldier 1 - 60
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{5,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 50
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
	board.move(2,{4,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 40
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{3,1},WarGame::Board::MoveDIR::Up); //soldier 1 - 30
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{4,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 20
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{3,1},WarGame::Board::MoveDIR::Up); //soldier 1 - 10
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{4,1},WarGame::Board::MoveDIR::Down); //soldier 1 - 0
    CHECK(board.has_soldiers(2));
    CHECK(!board.has_soldiers(1));

}
TEST_CASE("3 VS 3") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);//player 1 footSoldier1 {0,1}
   // CHECK_THROWS((board[{0,1}] = new FootSoldier(1))); //there is already soldier there
    board[{0,0}] = new FootCommander(1); //player 1 commanderSoldier {0,0}
    board[{0,2}] = new FootSoldier(1);//player 1 footSoldier2 {0,2}
    CHECK(board.has_soldiers(1)); //there is no need to write this any time

    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootCommander(2);//player 2 commanderSoldier {7,0}
	board[{7,1}] = new FootSoldier(2);//player 2 footSoldier1 {7,1}
    board[{7,2}] = new FootSoldier(2);//player 2 footSoldier2 {7,2}

    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 90
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up)); //no soldier there
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 80 
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(2,{7,0},WarGame::Board::MoveDIR::Left)); // cant move left
    board.move(2,{7,0},WarGame::Board::MoveDIR::Down); //player 1 commanderSoldier - 130, player 1 footsoldier1 - 70,   player 1 footsoldier2 - 90, 
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);//player 2 commanderSoldier - 130, player 2 footsoldier1 - 70,   player 2 footsoldier2 - 90, 
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

     board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
    board.move(1,{1,2},WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
	
	// the winner is team 1
}
TEST_CASE("One soldier of this type"){
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootSoldier(1);//player 1 soldier1
	CHECK(board.has_soldiers(1));
    board[{0,1}] = new FootCommander(1);//player 1 soldier2
	CHECK(board.has_soldiers(1));
    board[{0,2}] = new Sniper(1);//player 1 soldier3
	CHECK(board.has_soldiers(1));
    board[{0,3}] = new SniperCommander(1);//player 1 soldier4
	CHECK(board.has_soldiers(1));
    board[{0,4}] = new Paramedic(1);//player 1 soldier5
    board[{0,5}] = new ParamedicCommander(1);//player 1 soldier6
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootSoldier(2);//player 2 soldier1
    board[{7,1}] = new FootCommander(2);//player 2 soldier2
    board[{7,2}] = new Sniper(2);//player 2 soldier3
    board[{7,3}] = new SniperCommander(2);//player 2 soldier4
    board[{7,4}] = new Paramedic(2);//player 2 soldier5
    board[{7,5}] = new ParamedicCommander(2);//player 2 soldier6


	//consider using for.....
    CHECK(board.has_soldiers(2));
    board.move(1,{0,0},WarGame::Board::MoveDIR::Up); //player2 soldier1 - 90
    CHECK(board.has_soldiers(2));
    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);//player2 soldier2 - 130, player 2 soldier1 - 80
    CHECK(board.has_soldiers(2));
    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);//player2 soldier6 - 150
    CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);//player2 soldier6 - 50, player 2 soldier2 80 //need to define that commander shoots first
    CHECK(board.has_soldiers(2));
    board.move(1,{0,4},WarGame::Board::MoveDIR::Up);//player1 soldier4 - 120 //need to define that curing id done after the step/move
    CHECK(board.has_soldiers(2));
    board.move(1,{0,5},WarGame::Board::MoveDIR::Up); //player1 soldier5 - 100, player 1 soldier4 - 120, player 1 soldier6 - 200
    CHECK(board.has_soldiers(2));
	
	
    //sniper 1 will kill them all
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down); //player2 soldier6 - 100, player 2 soldier2 80
	CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up); //player2 soldier4 - 20, player2 soldier3 - 50 //need to define to check the closes when there are equalh healh points
	CHECK(board.has_soldiers(2));
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down); //player2 soldier5 - 0, player2 soldier6 - 50
    CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up); //player2 soldier1 - 0, player2 soldier2 - 30
        //just to be Sure all is dead

        board.move(1,{1,2},WarGame::Board::MoveDIR::Down); //player2 soldier3 - 0, player2 soldier 6 - 20/10
        board.move(1,{0,2},WarGame::Board::MoveDIR::Up); //player2 soldier3 - 0, player2 soldier 6 - 0
        board.move(1,{1,2},WarGame::Board::MoveDIR::Down); //player2 soldier3 - 0, player2 soldier 6 - 0

    //just to be Sure all is dead
    CHECK(!board.has_soldiers(2));
	
	//good test
}
TEST_CASE("2 VS 2"){
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1); //player1 soldier1 - 100
    board[{0,0}] = new FootCommander(1); //player1 soldier2 - 150
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootCommander(2); //player2 soldier1 - 100
    board[{7,1}] = new FootSoldier(2); //player2 soldier2 - 150

    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up); // player2 soldier2 - 90
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up); // player2 soldier2 - 80
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(2,{7,0},WarGame::Board::MoveDIR::Left));
    board.move(2,{7,0},WarGame::Board::MoveDIR::Down); //player1 soldier1 - 90
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,0},WarGame::Board::MoveDIR::Up); // player2 soldier1 - 130, player2 soldier2 - 70
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up); // player2 soldier1 - 110, player2 soldier2 - 60
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down); // player2 soldier1 - 90, player2 soldier2 - 50
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up); // player2 soldier1 - 70, player2 soldier2 - 40
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down); // player2 soldier1 - 50, player2 soldier2 - 30
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);// player2 soldier1 - 30, player2 soldier2 - 20
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down); // player2 soldier1 - 10, player2 soldier2 - 10
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

        board.move(1,{1,0},WarGame::Board::MoveDIR::Up);// player2 soldier1 - 0, player2 soldier2 - 0
    
    CHECK(board.has_soldiers(1));
        board.move(1,{2,0},WarGame::Board::MoveDIR::Down); // i think youve done
    CHECK(board.has_soldiers(1)); 
    CHECK(!board.has_soldiers(2)); 
	//the winner is team 1
}