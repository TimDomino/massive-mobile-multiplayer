#include "player.hpp"

 Player::Player(int StartX, int StartY, sf::Color border, sf::Color center){
	xPosition = StartX;
	yPosition = StartY;
	borderColor = border;
	centerColor = center;
}

 Player::Player() {
	xPosition = 0;
	yPosition = 0;
	borderColor = sf::Color(0,0,0);
	centerColor = sf::Color(255,0,0);
}

void Player::render(sf::RenderWindow* renderWindow) {

		sf::Shape playerdot = sf::Shape::Circle(xPosition,yPosition,45,centerColor,5,borderColor);
		renderWindow->Draw(playerdot);
}

void Player::moveUp() {
	yPosition-=5;

}

void Player::moveDown() {
	yPosition+=5;
}

void Player::moveLeft() {
	xPosition-=5;
}

void Player::moveRight() {
	xPosition+=5;
}


