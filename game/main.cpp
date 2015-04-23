#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"
#include "game.hpp"

int main()
{
	sf::Clock Clock;
	sf::RenderWindow App(sf::VideoMode(1920,1200,32), "MMMBall");
	const sf::Input& input = App.GetInput();
	Game game;	
	game.initPlayers();

	while (App.IsOpened()) {
		

		sf::Event Event;
		App.Clear(sf::Color(255,0,0));
		
		game.resetBallMovement();

		while (App.GetEvent(Event)) 
		{
			
			if (Event.Type == sf::Event::Closed){ App.Close(); }

			
			if (input.IsKeyDown(sf::Key::J)){
				game.movePlayer(0,"LEFT");			
			}
			if (input.IsKeyDown(sf::Key::L)){
				game.movePlayer(0,"RIGHT");			
			}
			if (input.IsKeyDown(sf::Key::I)){
				game.movePlayer(0,"UP");			
			}
			if (input.IsKeyDown(sf::Key::K)){
				game.movePlayer(0,"DOWN");			
			}
			
			if (input.IsKeyDown(sf::Key::W)){
				game.movePlayer(1,"UP");			
			}
			if (input.IsKeyDown(sf::Key::A)){
				game.movePlayer(1,"LEFT");			
			}
			if (input.IsKeyDown(sf::Key::S)){
				game.movePlayer(1,"DOWN");			
			}
			if (input.IsKeyDown(sf::Key::D)){
				game.movePlayer(1,"RIGHT");			
			}

			if (input.IsKeyDown(sf::Key::Space)){
				game.shootBall();	
			}
		}
		
		game.renderBackground(&App);
		game.renderSidelines(&App);
		game.renderGoals(&App);

		game.updatePhysicalObjects();
		
		
		game.renderPlayers(&App);
		game.getBallMovement();
		game.checkIntersect();
		game.moveBall();
		game.renderBall(&App);	
		
		App.Display();
	}

	return EXIT_SUCCESS;
}
