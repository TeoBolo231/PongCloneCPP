
#ifndef PONGSFML_PLAYER_H
#define PONGSFML_PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
 public:
  Player();

  int setScore();
  int resetScore();
  int returnScore();
  void setScoreText();

  bool returnPlayerMovementUp();
  bool returnPlayerMovementDown();
  bool setMovementUpT();
  bool setMovementUpF();
  bool setMovementDownT();
  bool setMovementDownF();

  float returnPaddleSpeed();

  sf::Sprite player_sprite;
  sf::Text score_text;

 private:
  sf::Texture player_texture;
  bool player_up_movement = false;
  bool player_down_movement = false;
  int score = 0;
  float paddle_speed = 250.f;

};

#endif // PONGSFML_PLAYER_H
