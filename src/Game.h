#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class Game
{
 public:
  explicit Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

  // Objects
  Player player_1;
  Player player_2;
  Ball ball_1;

 private:
  bool collisionCheckText(sf::Vector2i click, sf::Text text);

  sf::RenderWindow& window;

  // General
  sf::Font font_game;
  bool play_selected = true;

  // Game States
  bool start_menu;
  bool pause_menu;
  bool end_screen;
  bool game_running;

  // Game Variables
  int max_score = 5;

  // Start Menu
  sf::Text start_menu_title_text;

  sf::Sprite start_menu_bg_sprite;
  sf::Texture start_menu_bg_texture;

  sf::Text start_menu_play_option;
  sf::Text start_menu_quit_option;

  sf::Text rules_text;

  // Pause Menu
  sf::Sprite background_pause_sprite;
  sf::Texture background_pause_texture;

  sf::Text pause_title_text;

  sf::Text continue_opt_pause_text;
  sf::Text restart_opt_pause_text;
  sf::Text quit_opt_pause_text;

  // End Screen
  sf::Sprite end_bg_sprite;
  sf::Texture end_bg_texture;

  sf::Text end_title_text;
  sf::Text play_again_end_text;
  sf::Text quit_end_text;

  // Game
  sf::Sprite game_bg_sprite;
  sf::Texture game_bg_texture;
};

#endif // PONG_GAME_H
