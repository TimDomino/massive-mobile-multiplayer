#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <set>

#include "Player.hpp"
#include "Ball.hpp"
#include "PhysicalObject.hpp"


class Game
{
	
	public:
		Game();
		~Game();

		Player* addNewPlayer(std::string const& name, int number);
		void removePlayer(Player* playerToRemove);
	
		void renderBackground(sf::RenderWindow* window);
		void renderPlayers(sf::RenderWindow* window);		
		void renderBall(sf::RenderWindow* window);
		void renderSidelines(sf::RenderWindow* window);
		void renderGoals(sf::RenderWindow* window);
		void renderScoreLine(sf::RenderWindow* window);
		void renderFpsDisplay(sf::RenderWindow* window, float value);

		void updatePhysicalObjects();
		void applyIntersectionPhysics(); 
		void applyShootingForce(Player* player);
		void applyElasticImpact(PhysicalObject* lhs, PhysicalObject* rhs, float lhsAbsorption, float rhsAbsorption);

		void checkForGoal();
		void createField();

	private:

		//graphical objects
		std::vector<sf::ConvexShape> lines_;
		std::vector<sf::RectangleShape> field_;
		sf::RectangleShape goalLeft_;
		sf::RectangleShape goalRight_;
		sf::CircleShape centerCircle_;
		sf::CircleShape centerPoint_;
		sf::RectangleShape scoreLine_;
		sf::Text score_;
		sf::Text fpsString_;
		sf::Font font_;
		sf::CircleShape blueBox_;
		sf::CircleShape redBox_;

		//internal graphical methods
		void createFieldLines();
		void createGreen();
		void createGoals();
		void createScoreLine();
		void createFpsDisplay();

		//game logic objects
		std::set<Player*> players;
		Ball* ball;

		bool ballWasInLeftGoal_;
		bool ballWasInRightGoal_;
		int framesToReset_;

		int pointsBlueTeam_;
		int pointsRedTeam_;

		int numPlayersRed_;
		int numPlayersBlue_;
};

#endif //GAME_HPP
