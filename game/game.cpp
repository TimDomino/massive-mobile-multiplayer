#include "game.hpp"

Game::Game() {
	ballXMovement = 0;
	ballYMovement = 0;
}

void Game::renderBackground(sf::RenderWindow* window) {

		int pos = 0;
		for (int i = 0; i < 10; ++i){
			sf::Color currentGreen;			
			if (i%2 == 0){
				currentGreen = sf::Color(50,200,50);						
			}else{
				currentGreen = sf::Color(75,220,75);
			}
			sf::Shape rect = sf::Shape::Rectangle(pos,0,pos+192,1200,currentGreen);
			window->Draw(rect);
			pos+=192;
		}
	

}

void Game::checkIntersect(){
	for (int i = 0; i < players.size(); ++i){
		if (players[i].intersectsWithBall(ball)){
			std::cout<<"Player "<<i<<" intersects with the ball!"<<std::endl;		
		}else{
			std::cout<<"Player "<<i<<" does not intersect with the ball!"<<std::endl;	
		}
	}

}

void Game::resetBallMovement(){
	ballXMovement = 0;
	ballYMovement = 0;
	for (int i = 0; i < players.size(); i++){
		players[i].resetBallMovement();	
	}
}

void Game::initPlayers() {
	Player player1(1400,600,sf::Color(0,0,0),sf::Color(255,0,255));
	Player player2(480,600,sf::Color(0,0,0),sf::Color(0,0,255));
	players.push_back(player1);
	players.push_back(player2);		
}

void Game::initBall() {
	ball = Ball();
}

void Game::renderBall(sf::RenderWindow* window){
	ball.render(window);
}

void Game::renderSidelines(sf::RenderWindow* window) {
	sf::Shape leftGoalLine;
	leftGoalLine.AddPoint(100, 26,  sf::Color(255, 255, 255),     sf::Color(255, 255, 255));
	leftGoalLine.AddPoint(100, 1173,   sf::Color(255, 255, 255),   sf::Color(22, 255, 255));
	leftGoalLine.AddPoint(105, 1173,   sf::Color(255, 255, 255),   sf::Color(22, 255, 255));
	leftGoalLine.AddPoint(105, 26,   sf::Color(255, 255, 255),   sf::Color(22, 255, 255));
	window->Draw(leftGoalLine);

	sf::Shape topSideLine;
	topSideLine.AddPoint(100, 26,  sf::Color(255, 255, 255),     sf::Color(255, 255, 255));
	topSideLine.AddPoint(1820, 26,  sf::Color(255, 255, 255),     sf::Color(255, 255, 255));
	topSideLine.AddPoint(1820, 31,  sf::Color(255, 255, 255),     sf::Color(255, 255, 255));
	topSideLine.AddPoint(105, 31,   sf::Color(255, 255, 255),   sf::Color(22, 255, 255));	
	window->Draw(topSideLine);

	sf::Shape rightGoalLine;
	rightGoalLine.AddPoint(1820,26, sf::Color(255,255,255), sf::Color(255,255,255));
	rightGoalLine.AddPoint(1820,1178, sf::Color(255,255,255), sf::Color(255,255,255));
	rightGoalLine.AddPoint(1815,1178, sf::Color(255,255,255), sf::Color(255,255,255));
	rightGoalLine.AddPoint(1815,26, sf::Color(255,255,255), sf::Color(255,255,255));
	window->Draw(rightGoalLine);

	sf::Shape bottomSideLine;
	bottomSideLine.AddPoint(1820,1178,sf::Color(255,255,255),sf::Color(255,255,255));
	bottomSideLine.AddPoint(100,1178,sf::Color(255,255,255),sf::Color(255,255,255));
	bottomSideLine.AddPoint(100,1173,sf::Color(255,255,255),sf::Color(255,255,255));
	bottomSideLine.AddPoint(1820,1173,sf::Color(255,255,255),sf::Color(255,255,255));
	window->Draw(bottomSideLine);

	sf::Shape centerLine;
	centerLine.AddPoint(957,26,sf::Color(255,255,255),sf::Color(255,255,255));
	centerLine.AddPoint(957,1178,sf::Color(255,255,255),sf::Color(255,255,255));
	centerLine.AddPoint(962,1178,sf::Color(255,255,255),sf::Color(255,255,255));
	centerLine.AddPoint(962,26,sf::Color(255,255,255),sf::Color(255,255,255));
	window->Draw(centerLine);
	

	sf::Shape kickoffCircle = sf::Shape::Circle(960,600,185,sf::Color(0,0,0,0),5.f,sf::Color(255,255,255));
	window->Draw(kickoffCircle);

	sf::Shape kickoffPoint = sf::Shape::Circle(960,600,10,sf::Color(255,255,255));
	window->Draw(kickoffPoint);
}

void Game::renderPlayers(sf::RenderWindow* window) {
	for (int i = 0; i < players.size(); i++){
		players[i].render(window);	
	}

}

void Game::movePlayer(int playerNumber, std::string direction){

	if (direction == "UP"){
		players[playerNumber].moveUp();	
	}
	else if (direction == "DOWN"){
		players[playerNumber].moveDown();	
	}
	else if (direction == "LEFT"){
		players[playerNumber].moveLeft();	
	}
	else if (direction == "RIGHT"){
		players[playerNumber].moveRight();	
	}

}

void Game::getBallMovement() {
	for (int i = 0; i<players.size();++i){
		if (players[i].currentlyIntersectsBall){
			ballXMovement+=players[i].getXBallMovement();
			ballYMovement+=players[i].getYBallMovement();
		}	
	}
}

void Game::moveBall() {
	ball.move(ballXMovement,ballYMovement);
}
 
