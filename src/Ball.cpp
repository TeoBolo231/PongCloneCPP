
#include "Ball.h"
#include <iostream>
#include <math.h>

Ball::Ball()
{
  if (!ball_texture.loadFromFile("Data/Images/ball.png"))
  {
    std::cout <<"Ball texture not loaded\n";

  }
  ball_sprite.setTexture(ball_texture);
  ball_sprite.setScale(0.2, 0.2);

  ball_vector.x = setRandomBallDirectionX();
  ball_vector.y = setRandomBallDirectionY();
  ball_speed = ball_speed_min;
  normalise();
}

/*============================================================================*/

void Ball::normalise()
{
  float a = pow(ball_vector.x, 2.0);
  float b = pow(ball_vector.y, 2.0);
  float sum = a + b;
  float mag_x = ball_vector.x/(sqrt(sum));
  float mag_y = ball_vector.y/(sqrt(sum));
  ball_vector.x = mag_x;
  ball_vector.y = mag_y;
}

/*============================================================================*/

float Ball::returnBallSpeed()
{
  return ball_speed;
}

/*============================================================================*/

void Ball::resetBallSpeed()
{
  ball_speed = ball_speed_min;
}

/*============================================================================*/

float Ball::setBallDirectionR()
{
  return  ball_vector.x = 1.f;
}

/*============================================================================*/

float Ball::setBallDirectionL()
{
  return ball_vector.x = -1.f;
}

/*============================================================================*/

float Ball::setRandomBallDirectionX()
{
  int sign = rand() % 2;
  if (sign == 0)
  {
    return ball_vector.x = 1.f;
  }
  else
  {
    return ball_vector.x = -1.f;
  }
}

/*============================================================================*/

float Ball::setRandomBallDirectionY()
{
  int sign = rand() % 2;
  if (sign == 0)
  {
    return ball_vector.y = 1.f;
  }
  else
  {
    return ball_vector.y = -1.f;
  }
}

/*============================================================================*/

bool Ball::returnBallStarted()
{
  return ball_started;
}

/*============================================================================*/

bool Ball::setBallStartedT()
{
  return ball_started = true;
}

/*============================================================================*/

bool Ball::setBallStartedF()
{
  return ball_started = false;
}

/*============================================================================*/

void Ball::ballBounceWall(sf::RenderWindow& window)
{
  if (ball_sprite.getPosition().y <= 0 ||
      ball_sprite.getPosition().y >= window.getSize().y - ball_sprite.getGlobalBounds().height)
  {
    ball_vector.y *= switch_direction;
    ball_speed += ball_speed_inc;
  }
}

/*============================================================================*/

void Ball::ballBouncePaddles(sf::Sprite paddle_1, sf::Sprite paddle_2, Player player_1, Player player_2)
{
  if (ball_sprite.getGlobalBounds().intersects(paddle_1.getGlobalBounds()) ||
   ball_sprite.getGlobalBounds().intersects(paddle_2.getGlobalBounds()))
  {
    if ((ball_vector.x < neg_threshold && ball_vector.y < neg_threshold && player_1.returnPlayerMovementUp()) ||
        (ball_vector.x > pos_threshold && ball_vector.y < neg_threshold && player_2.returnPlayerMovementUp()) ||
        (ball_vector.x < neg_threshold && ball_vector.y > pos_threshold && player_1.returnPlayerMovementDown()) ||
        (ball_vector.x > pos_threshold && ball_vector.y > pos_threshold && player_2.returnPlayerMovementDown()))
    {
      ball_vector.y *= increment;
      ball_vector.x *= switch_direction;
      normalise();
      ball_speed += ball_speed_inc;
    }
    else if ((ball_vector.x < neg_threshold && ball_vector.y > pos_threshold && player_1.returnPlayerMovementUp()) ||
             (ball_vector.x > pos_threshold && ball_vector.y > pos_threshold && player_2.returnPlayerMovementUp()) ||
             (ball_vector.x < neg_threshold && ball_vector.y < neg_threshold && player_1.returnPlayerMovementDown()) ||
             (ball_vector.x > pos_threshold && ball_vector.y < neg_threshold && player_2.returnPlayerMovementDown()))
    {
      ball_vector.y = ball_vector.y * increment * switch_direction;
      ball_vector.x *= switch_direction;
      normalise();
      ball_speed += ball_speed_inc;
    }
    else if (((!player_1.returnPlayerMovementUp()) && (!player_1.returnPlayerMovementDown())) ||
             ((!player_2.returnPlayerMovementUp() && (!player_2.returnPlayerMovementDown()))))
    {
      ball_vector.x *= switch_direction;
      normalise();
      ball_speed -= ball_speed_inc;
    }
    else
    {
      std::cout<<"collision error\n";
    }
  }
}

/*============================================================================*/

void Ball::unstuck()
{
  if ((ball_vector.x < pos_threshold && ball_vector.x > neg_threshold)||(ball_vector.y < pos_threshold && ball_vector.y > neg_threshold))
  {
    ball_vector.y += unstuck_val;
    ball_vector.x += unstuck_val;
    normalise();
  }
}
