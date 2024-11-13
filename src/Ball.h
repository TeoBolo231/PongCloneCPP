
#ifndef PONGSFML_BALL_H
#define PONGSFML_BALL_H
#include <SFML/Graphics.hpp>
#include "Player.h"


class Ball
{
 public:
  Ball();

  void normalise();

  float returnBallSpeed();
  void resetBallSpeed();

  float setBallDirectionR();
  float setBallDirectionL();
  float setRandomBallDirectionX();
  float setRandomBallDirectionY();

  bool returnBallStarted();
  bool setBallStartedT();
  bool setBallStartedF();

  void ballBounceWall(sf::RenderWindow& window);
  void ballBouncePaddles(sf::Sprite paddle_1,
                         sf::Sprite paddle_2,
                         Player player_1,
                         Player player_2);
  void unstuck();

  struct Vector2d
  {
    float x;
    float y;
  };

  Vector2d ball_vector;

  sf::Sprite ball_sprite;
  sf::Texture ball_texture;

 private:
  float ball_speed;
  float ball_speed_min = 300.f;
  float ball_speed_inc = 10.f;
  float increment = 1.8f;
  float pos_threshold = 0.3f;
  float neg_threshold = -0.3f;
  float unstuck_val = 0.7f;
  float switch_direction = -1.f;
  bool ball_started = false;
};

#endif // PONGSFML_BALL_H
