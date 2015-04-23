#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ball.hpp"

class Player {

	public:
		Player();
		Player(int StartX, int StartY, sf::Color border, sf::Color center);
		void render(sf::RenderWindow* renderWindow);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		sf::Shape getShape();
		bool intersectsWithBall(Ball ball);
		bool currentlyIntersectsBall;
		void resetBallMovement();
		int getXBallMovement();
		int getYBallMovement();
		int getXPosition();
		int getYPosition();
		bool intersectsWithPlayer(Player otherGuy);
		
	private:
		int xPosition;
		int yPosition;
		sf::Color borderColor;
		sf::Color centerColor;
		sf::Shape shape;
		int xBallMovement;
		int yBallMovement;
		void controlPosition();
		

};
