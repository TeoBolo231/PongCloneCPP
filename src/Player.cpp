#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

/*============================================================================*/

Player::Player()
{
  if (!player_texture.loadFromFile("Data/Images/paddleP1.png"))
  {
    std::cout <<"Player texture not loaded\n";
  }
  player_sprite.setTexture(player_texture);
  player_sprite.setScale(0.7, 1);
}

/*============================================================================*/

int Player::setScore()
{
  score++;
}

/*============================================================================*/

int Player::resetScore()
{
  score = 0;
}

/*============================================================================*/

int Player::returnScore()
{
  return score;
}

/*============================================================================*/

void Player::setScoreText()
{
  score_text.setString(std::to_string(score));
}

/*============================================================================*/

bool Player::returnPlayerMovementUp()
{
 return player_up_movement;
}

/*============================================================================*/

bool Player::returnPlayerMovementDown()
{
  return player_down_movement;
}

/*============================================================================*/

bool Player::setMovementUpT()
{
  return player_up_movement = true;
}

/*============================================================================*/

bool Player::setMovementUpF()
{
  return player_up_movement = false;
}

/*============================================================================*/

bool Player::setMovementDownT()
{
  return player_down_movement = true;
}

/*============================================================================*/

bool Player::setMovementDownF()
{
  return player_down_movement = false;
}

/*============================================================================*/

float Player::returnPaddleSpeed()
{
  return paddle_speed;
}

