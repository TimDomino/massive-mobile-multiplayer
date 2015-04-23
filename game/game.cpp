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

void Game::checkIntersect()
{
	for (int i = 0; i < players.size(); ++i)
	{
		sf::Vector2f hitPoint = players[i].intersectsWithBall(ball);
		double currentSpeed = players[i].computeCurrentSpeed();

		// an intersection was found
		if (hitPoint.x < 5000 || hitPoint.y < 5000)
		{
			long double hitFactor(0.3 * currentSpeed / MAX_SPEED);

			long double newBallX( hitFactor * (hitPoint.x - players[i].getPosX()) );
			long double newBallY( hitFactor * (hitPoint.y - players[i].getPosY()) );
			
			ball.setVelocity(newBallX, newBallY);
		}
	}

	/*
	for (int i = 0; i < players.size(); ++i){
		players[i].intersectsWithBall(ball);
		for (int j = 0; j < players.size(); ++j){
			if (i != j){
				if (players[i].intersectsWithPlayer(players[j])){
					std::cout<<"Player "<<i<<" and player "<<j<<" intersect!"<<std::endl;
				}			
			}		
		}
	}
	*/
}


void Game::initPlayers() 
{
	Player player2(480,600,sf::Color(0,0,0),sf::Color(0,0,255));	
	Player player1(1400,600,sf::Color(0,0,0),sf::Color(255,0,255));

	players.push_back(player2);
	players.push_back(player1);
			
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

void Game::renderGoals(sf::RenderWindow* window){
	sf::Shape goalLeft = sf::Shape::Rectangle(45,500,100,700,sf::Color(0,0,0,0),5,sf::Color(255,255,255));
	sf::Shape goalRight = sf::Shape::Rectangle(1820,500,1875,700,sf::Color(0,0,0,0),5,sf::Color(255,255,255));
	window->Draw(goalLeft);
	window->Draw(goalRight);
	

}

void Game::renderPlayers(sf::RenderWindow* window) 
{
	for (int i = 0; i < players.size(); i++)
	{
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

 
void Game::updatePhysicalObjects()
{
	// update ball
	ball.frameUpdate();

	// update players
	for (int i = 0; i < players.size(); i++)
	{
		players[i].frameUpdate();	
	}
}