/*! \mainpage Pinball Game Project (P13240786)
 *
 * This is the documentation for my pinball game.
 *
 */

#include <SFML/Graphics.hpp>
#include "Randomiser.h"
#include "config.h"
#include "Vector2D.h"
#include "ball.h"
#include "rect.h"
#include "obb.h"
#include "manifold.h"
#include "TextureManager.h"
#include <list>

#include "paddle.h"
#include "roundBumper.h"
#include "rectangleBumper.h"

std::list<Ball> balls;
std::list<Ball>::iterator ballIt;

bool g_bIsPlaying = false;
bool g_bIsGameOver = false;
int g_iScoreTotal = 0;
int g_iBallsLeft = 3;
int g_iHighestScore = 0;

void loseLife();

int main(int, char const**)
{
    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(720, 980), "Pinball", sf::Style::Default);
    window.setFramerateLimit(300);
    settings.antialiasingLevel = 8;
    
    TextureManager txtManager;
	txtManager.loadTexture("background", "resources\\BackgroundGame.png");

	sf::Sprite background;
	background.setTexture(txtManager.getTexture("background"));
	background.setPosition(0, 0);

    sf::Color darkBlueCol = sf::Color(38, 70, 83);
    sf::Color cyanCol = sf::Color(42, 157, 143);
    sf::Color yellowCol = sf::Color(233, 196, 106);
    sf::Color orangeCol = sf::Color(244, 162, 97);
    sf::Color redCol = sf::Color(231, 111, 81);
    
    
    sf::Font arcadeFont;
	arcadeFont.loadFromFile("resources\\BebasNeue Regular.otf");

    
    sf::Text highestScoreText = sf::Text("Top Score: " + std::to_string(g_iHighestScore), arcadeFont, 60);
	highestScoreText.setFillColor(redCol);
    highestScoreText.setPosition(40, 5);

    sf::Text scoreText = sf::Text("Score: " + std::to_string(g_iScoreTotal), arcadeFont, 60);
    scoreText.setFillColor(redCol);
    scoreText.setPosition(40, 80);
    
    sf::Text ballsLeftText = sf::Text("Balls: " + std::to_string(g_iBallsLeft), arcadeFont, 60);
    ballsLeftText.setFillColor(redCol);
    ballsLeftText.setPosition(500, 5);

	sf::Text gameOverText = sf::Text("GAME OVER", arcadeFont, 150);
	gameOverText.setFillColor(sf::Color::Black);
	gameOverText.setPosition(100, 400);
    
    
    Randomiser rand;
    std::list<Rect> rects;
    std::list<Rect>::iterator rectIt;
    
    std::list<OBB> obbs;
    std::list<OBB>::iterator obbIt;
    
    
    std::list<RoundBumper> roundBumpers;
    std::list<RoundBumper>::iterator roundBumperIt;
    
    std::list<RectangleBumper> rectangleBumpers;
    std::list<RectangleBumper>::iterator rectBumperIt;
        
    Rect topWall = Rect(Vector2D(18,8.8), Vector2D(17, 0.7), darkBlueCol);
    Rect leftWall = Rect(Vector2D(0.5, 27.5), Vector2D(0.7,30), darkBlueCol);
    
    Rect rightWall = Rect(Vector2D(35.5, 27.5), Vector2D(0.7,30), darkBlueCol);
    Rect topRightCorner = Rect(Vector2D(34.8, 9.8), Vector2D(0.5, 0.5), darkBlueCol);
    Rect tunnel = Rect(Vector2D(32.9, 34),Vector2D(0.2,21),darkBlueCol);
    
    RoundBumper roundBumper1 = RoundBumper(Vector2D(10, 13), 1.7, 10, cyanCol);
    RoundBumper roundBumper2 = RoundBumper(Vector2D(27, 16), 1.7, 10, yellowCol);
    RoundBumper largeRoundBumper = RoundBumper(Vector2D(17.5, 21), 2, 10, orangeCol);
    RoundBumper largeRoundBumper2 = RoundBumper(Vector2D(6, 25), 2, 10, yellowCol);
    RoundBumper largeRoundBumper3 = RoundBumper(Vector2D(28, 25), 2, 10, cyanCol);
    
	Paddle leftPaddle = Paddle(Vector2D(10, 44.5), Vector2D(4.5, 0.6), 0.5, true, cyanCol);
	Paddle rightPaddle = Paddle(Vector2D(23, 44.5), Vector2D(4.5, 0.6), 0.5, false, cyanCol);

	Rect bottomLeftCorner = Rect(Vector2D(1.3, 37.5), Vector2D(0.5, 0.5), darkBlueCol);
    Rect bottomRightCorner = Rect(Vector2D(32.5, 37.5), Vector2D(0.5, 0.5), darkBlueCol);

    OBB leftRamp = OBB(Vector2D(5.5, 41), Vector2D(6, 0.5), 0.6, darkBlueCol);
    OBB rightRamp = OBB(Vector2D(27.7, 41), Vector2D(6, 0.5), -0.6, darkBlueCol);

    RectangleBumper rectBumper1 = RectangleBumper(Vector2D(4.5, 33), Vector2D(0.5, 2 ), 0.3, 20, darkBlueCol);
    RectangleBumper rectBumper2 = RectangleBumper(Vector2D(30, 33), Vector2D(0.5, 2 ), -0.3, 20, darkBlueCol);
    
    rectangleBumpers.push_back(rectBumper1);
    rectangleBumpers.push_back(rectBumper2);
    
    roundBumpers.push_back(roundBumper1);
    roundBumpers.push_back(roundBumper2);
    roundBumpers.push_back(largeRoundBumper);
    roundBumpers.push_back(largeRoundBumper2);
    roundBumpers.push_back(largeRoundBumper3);

    
    rects.push_back(topWall);
    rects.push_back(leftWall);
    rects.push_back(rightWall);
    rects.push_back(tunnel);
    rects.push_back(topRightCorner);
 
	rects.push_back(bottomLeftCorner);
	rects.push_back(bottomRightCorner);

    obbs.push_back(rightRamp);
    obbs.push_back(leftRamp);

	//obbs.push_back(testOBB);
   sf::Clock clock;
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
				if (!g_bIsPlaying && !g_bIsGameOver) {
					Vector2D pos = Vector2D(34, 55);
					Vector2D vel = Vector2D(0, -60);
					Vector2D acc = Vector2D(0, 20);
                
					Ball ball = Ball(pos, vel, acc, 0.9);
					ball.setColour(sf::Color::Black);
					balls.push_back(ball);
					g_bIsPlaying = true;
				}
            }
			else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
				leftPaddle.flip("up");
			}
			else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
				rightPaddle.flip("up");
			}

			else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left){
				leftPaddle.flip("down");
			}
			else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right){
				rightPaddle.flip("down");
			}

        }
        window.clear(sf::Color::Black);
        
        sf::Time tInterval = clock.getElapsedTime();
        const unsigned int uiElapsedTime = tInterval.asMilliseconds();
        
		if(uiElapsedTime >= 10 && !g_bIsGameOver)
        {
			const float fSeconds = tInterval.asSeconds();

            for(ballIt = balls.begin(); ballIt != balls.end(); ++ballIt){
                
                for(auto p = balls.begin(); p != balls.end(); ++p){

                    if (ballIt != p) {
                        Manifold m = Manifold(&ballIt->body, &p->body);
                        if (m.CircleVsCircle()) {
                            m.correctPosition();
                            m.applyRotationalImpulse();
                        }
                    }
                }
                
                for(roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt){
                    
                    Manifold m = Manifold(&roundBumperIt->body, &ballIt->body);
                    if (m.CircleVsCircle()) {
                        g_iScoreTotal += roundBumperIt->getPoints();
                        m.correctPosition();
                        m.applyRotationalImpulse();
                    }                    
                }
                
                for(rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt){
                    
                    Manifold m = Manifold(&rectBumperIt->body, &ballIt->body);
					if (m.CircleVsOBB()) {
                        g_iScoreTotal += rectBumperIt->getPoints();
                        m.correctPosition();
                        m.applyRotationalImpulse();
                    }                    
                }
                
                for(rectIt = rects.begin(); rectIt != rects.end(); ++rectIt){
                    
                    Manifold m = Manifold(&rectIt->body, &ballIt->body);
                    if (m.CircleVsRect()) {
                        m.correctPosition();
                        m.applyRotationalImpulse();
                    }
                }
                
                for(obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt){
                    Manifold m = Manifold(&obbIt->body, &ballIt->body);
                    if (m.CircleVsOBB()) {
                        m.correctPosition();
                        m.applyRotationalImpulse();
                    }
                }
                
				Manifold leftPaddleManifold = Manifold(&rightPaddle.body, &ballIt->body);
                if (leftPaddleManifold.CircleVsOBB()) {
                        leftPaddleManifold.correctPosition();
                        leftPaddleManifold.applyRotationalImpulse();
				}
					                
				Manifold rightPaddleManifold = Manifold(&leftPaddle.body, &ballIt->body);
				if (rightPaddleManifold.CircleVsOBB()) {
                        rightPaddleManifold.correctPosition();
                        rightPaddleManifold.applyRotationalImpulse();
                }

                ballIt->body.update(fSeconds);
		 }

			    for(roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt){
                    roundBumperIt->body.update(fSeconds);   
                }
                
                for(rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt){
                    rectBumperIt->body.update(fSeconds);
                }
                
                for(rectIt = rects.begin(); rectIt != rects.end(); ++rectIt){
                    rectIt->body.update(fSeconds);
                }
                
                for(obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt){
                    obbIt->body.update(fSeconds);
                }

			rightPaddle.body.update(fSeconds);
			rightPaddle.clampPaddle();

			leftPaddle.body.update(fSeconds);
			leftPaddle.clampPaddle();
			 
            clock.restart();
        }

		window.draw(background);

        scoreText.setString("Score: " + std::to_string(g_iScoreTotal));
        ballsLeftText.setString("Balls: " + std::to_string(g_iBallsLeft));
		highestScoreText.setString("Top score: " + std::to_string(g_iHighestScore));

		//printf("Score: %i ", iScoreTotal);
		//printf("Lives: %i \n", iBallsLeft);
		
		loseLife();

		if (g_iBallsLeft <= 0){
			g_bIsGameOver = true;
			//clock.restart();
		}

		//
		if (g_iScoreTotal > g_iHighestScore) {
			g_iHighestScore = g_iScoreTotal;
		}


        for(rectIt = rects.begin(); rectIt != rects.end(); ++rectIt)
        {
            window.draw(*rectIt);
        }
        
        for(obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt)
        {
            window.draw(*obbIt);
        }
        
        for(ballIt = balls.begin(); ballIt != balls.end(); ++ballIt)
        {
            window.draw(*ballIt);
        }
        
        for(roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt)
        {
            window.draw(*roundBumperIt);
        }
        
        for(rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt)
        {
            window.draw(*rectBumperIt);
        }
        
		window.draw(rightPaddle);
		window.draw(leftPaddle);

		
		if(g_bIsGameOver){
		    g_bIsPlaying = false;

			window.draw(gameOverText);
				
			//sf::Clock gameClock;
			float  fDelay = sf::seconds(2.0).asSeconds();

			sf::Time now = clock.getElapsedTime();
			printf("%f \n", now.asSeconds());
			if (now.asSeconds() >= fDelay) {

				g_iScoreTotal = 0;
				g_iBallsLeft = 3;

				g_bIsGameOver = false;
				clock.restart();
			}
		}

        window.draw(highestScoreText);
        window.draw(scoreText);
        window.draw(ballsLeftText);
        
        window.display();
    }
    return 0;
}

void loseLife() //!< Function to check if ball goes under 
{
	
    for(ballIt = balls.begin(); ballIt != balls.end();) {

		if(ballIt->body.getPosition().y() > 60)  {
			ballIt = balls.erase(ballIt);

			g_iBallsLeft--;
			g_bIsPlaying = false;

		} else {
			++ballIt;
		}
	}

}
