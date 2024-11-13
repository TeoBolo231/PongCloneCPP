#include "Game.h"
#include <iostream>
#include "string"

/*============================================================================*/

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

/*============================================================================*/

Game::~Game()
{

}

/*============================================================================*/

bool Game::init()
{
  start_menu = true;
  game_running = false;
  pause_menu = false;
  end_screen = false;

  /*--------------------------------------------------------------------------*/

  //Start Menu

  // Background
  if (!start_menu_bg_texture.loadFromFile("Data/Images/start_bg.png"))
  {
    std::cout << "Start menu background texture not loaded\n";
    return false;
  }
  start_menu_bg_sprite.setTexture(start_menu_bg_texture);
  start_menu_bg_sprite.setScale
    (
      window.getSize().x / start_menu_bg_sprite.getGlobalBounds().width,
      window.getSize().y / start_menu_bg_sprite.getGlobalBounds().height
    );
  start_menu_bg_sprite.setPosition(0, 0);

  // Game Title
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  start_menu_title_text.setString("PONG");
  start_menu_title_text.setFont(font_game);
  start_menu_title_text.setStyle(sf::Text::Italic | sf::Text::Bold);
  start_menu_title_text.setCharacterSize(50);
  start_menu_title_text.setFillColor(sf::Color(0, 0, 0, 255));
  start_menu_title_text.setPosition
    (
      window.getSize().x/2 - start_menu_title_text.getGlobalBounds().width/2,
      0
    );

  // Rules
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  rules_text.setString("\n\n\n\n                     Controls\n\n"
                             "W = Move left paddle up\n"
                             "S = Move left paddle down\n"
                             "Up Arrow = Move right paddle up\n"
                             "Down Arrow = Move right paddle down\n"
                             "Space = Throw the ball\n\n"
                             "The first player who reaches " + std::to_string(max_score)+ " points wins!" );
  rules_text.setFont(font_game);
  rules_text.setCharacterSize(30);
  rules_text.setFillColor(sf::Color(0, 0, 0, 255));
  rules_text.setPosition
    (
      window.getSize().x/4 + window.getSize().x/30,
      window.getSize().y/5 - rules_text.getGlobalBounds().height/2
    );

  // Play Option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  start_menu_play_option.setString(">Play<");
  start_menu_play_option.setStyle(sf::Text::Italic | sf::Text::Bold);
  start_menu_play_option.setFont(font_game);
  start_menu_play_option.setCharacterSize(30);
  start_menu_play_option.setFillColor(sf::Color(0, 0, 0, 255));
  start_menu_play_option.setPosition
    (
      window.getSize().x/3 - start_menu_play_option.getGlobalBounds().width/2 + window.getSize().x/20,
      window.getSize().y - window.getSize().y/3 - start_menu_play_option.getGlobalBounds().height/2
    );

  // Quit Option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  start_menu_quit_option.setString("Quit");
  start_menu_quit_option.setFont(font_game);
  start_menu_quit_option.setCharacterSize(30);
  start_menu_quit_option.setFillColor(sf::Color(0, 0, 0, 255));
  start_menu_quit_option.setPosition
    (
      window.getSize().x - window.getSize().x/3 - start_menu_quit_option.getGlobalBounds().width/2 - window.getSize().x/20,
      window.getSize().y - window.getSize().y/3 - start_menu_quit_option.getGlobalBounds().height/2
    );

  /*--------------------------------------------------------------------------*/

  // Pause Menu

  // Background
  if (!background_pause_texture.loadFromFile("Data/Images/pause_bg.png"))
  {
    std::cout << "Pause background texture not loaded\n";
    return false;
  }
  background_pause_sprite.setTexture(background_pause_texture);
  background_pause_sprite.setScale
    (
      window.getSize().x / background_pause_sprite.getGlobalBounds().width,
      window.getSize().y / background_pause_sprite.getGlobalBounds().height
    );
  background_pause_sprite.setPosition(0, 0);

  // Pause Text
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  pause_title_text.setString("PAUSE");
  pause_title_text.setFont(font_game);
  pause_title_text.setCharacterSize(80);
  pause_title_text.setFillColor(sf::Color(0, 0, 0, 255));
  pause_title_text.setPosition
    (
      window.getSize().x/2 - pause_title_text.getGlobalBounds().width/2,
      window.getSize().y/3 - pause_title_text.getGlobalBounds().height/2 - window.getSize().y/10
    );

  // Restart Option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  restart_opt_pause_text.setString(">Restart<");
  restart_opt_pause_text.setStyle(sf::Text::Italic | sf::Text::Bold);
  restart_opt_pause_text.setFont(font_game);
  restart_opt_pause_text.setCharacterSize(30);
  restart_opt_pause_text.setFillColor(sf::Color(0, 0, 0, 255));
  restart_opt_pause_text.setPosition
    (
      window.getSize().x/3 - restart_opt_pause_text.getGlobalBounds().width/2 + window.getSize().x/20,
      window.getSize().y - window.getSize().y/3 - restart_opt_pause_text.getGlobalBounds().height/2
    );

  // Quit option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  quit_opt_pause_text.setString("Quit");
  quit_opt_pause_text.setFont(font_game);
  quit_opt_pause_text.setCharacterSize(30);
  quit_opt_pause_text.setFillColor(sf::Color(0, 0, 0, 255));
  quit_opt_pause_text.setPosition
    (
      window.getSize().x - window.getSize().x/3 - quit_opt_pause_text.getGlobalBounds().width,
      window.getSize().y - window.getSize().y/3 - quit_opt_pause_text.getGlobalBounds().height/2
    );

  /*--------------------------------------------------------------------------*/

  // End Screen

  //BG
  if (!end_bg_texture.loadFromFile("Data/Images/end_bg.png"))
  {
    std::cout << "End screen background texture not loaded\n";
    return false;
  }
  end_bg_sprite.setTexture(end_bg_texture);
  end_bg_sprite.setScale
    (
      window.getSize().x / end_bg_sprite.getGlobalBounds().width,
      window.getSize().y / end_bg_sprite.getGlobalBounds().height
    );
  end_bg_sprite.setPosition(0, 0);

  // Result
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  end_title_text.setString("Result printer placeholder");
  end_title_text.setFont(font_game);
  end_title_text.setCharacterSize(50);
  end_title_text.setFillColor(sf::Color(0, 0, 0, 255));
  end_title_text.setPosition
    (
      window.getSize().x/2 - end_title_text.getGlobalBounds().width/4,
      window.getSize().y/2 - window.getSize().y/4
    );

  // Play Again Option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  play_again_end_text.setString(">Play again<");
  play_again_end_text.setStyle(sf::Text::Italic | sf::Text::Bold);
  play_again_end_text.setFont(font_game);
  play_again_end_text.setCharacterSize(30);
  play_again_end_text.setFillColor(sf::Color(0, 0, 0, 255));
  play_again_end_text.setPosition
    (
      window.getSize().x/3 - play_again_end_text.getGlobalBounds().width/2 + window.getSize().x/20,
      window.getSize().y - window.getSize().y/3 - play_again_end_text.getGlobalBounds().height/2
    );

  // Quit option
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  quit_end_text.setString("Quit");
  quit_end_text.setFont(font_game);
  quit_end_text.setCharacterSize(30);
  quit_end_text.setFillColor(sf::Color(0, 0, 0, 255));
  quit_end_text.setPosition
    (
      window.getSize().x - window.getSize().x/3 - quit_end_text.getGlobalBounds().width/2,
      window.getSize().y - window.getSize().y/3 - quit_end_text.getGlobalBounds().height/2
    );


  /*--------------------------------------------------------------------------*/

  // GAME

  // BG GAME
  if (!game_bg_texture.loadFromFile("Data/Images/game_bg_1.png"))
  {
    std::cout << "Game background texture not loaded\n";
    return false;
  }
  game_bg_sprite.setTexture(game_bg_texture);
  game_bg_sprite.setScale
    (
      window.getSize().x / game_bg_sprite.getGlobalBounds().width,
      window.getSize().y / game_bg_sprite.getGlobalBounds().height
    );
  game_bg_sprite.setPosition(0, 0);

  // Ball
  ball_1.ball_sprite.setPosition
    (
      window.getSize().x/2 - ball_1.ball_sprite.getGlobalBounds().width/2 ,
      window.getSize().y/2 - ball_1.ball_sprite.getGlobalBounds().height/2
    );

  // Player 1
  player_1.player_sprite.setPosition
    (
      0 + window.getSize().x/20,
      window.getSize().y/2 - player_1.player_sprite.getGlobalBounds().height/2
    );

  // Player 2
  player_2.player_sprite.setPosition
    (
      window.getSize().x - player_2.player_sprite.getGlobalBounds().width - window.getSize().x/20,
      window.getSize().y/2 - player_2.player_sprite.getGlobalBounds().height/2
    );

  // Score Player 1
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  player_1.setScoreText();
  player_1.score_text.setFont(font_game);
  player_1.score_text.setCharacterSize(30);
  player_1.score_text.setFillColor(sf::Color(255, 255, 255, 255));
  player_1.score_text.setPosition
    (
      0 + player_1.score_text.getGlobalBounds().width/2 + window.getSize().x/20,
      -0
    );

  // Score Player 2
  if (!font_game.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout<<"Font not loaded\n";
    return false;
  }
  player_2.setScoreText();
  player_2.score_text.setFont(font_game);
  player_2.score_text.setCharacterSize(30);
  player_2.score_text.setFillColor(sf::Color(255, 255, 255, 255));
  player_2.score_text.setPosition
    (
      window.getSize().x - player_2.score_text.getGlobalBounds().width/2 - window.getSize().x/20,
      -0
    );

  return true;
}

/*============================================================================*/

void Game::update(float dt)
{
  if (game_running)
  {
    // Ball Wall Bounce
    ball_1.ballBounceWall(window);

    // Ball Paddle Bounce
    ball_1.ballBouncePaddles(player_1.player_sprite,
                             player_2.player_sprite,
                             player_1,
                             player_2);

    // Unstack Ball
    ball_1.unstuck();

    // Player 1 Paddle Movement
    if ( player_1.returnPlayerMovementUp() && player_1.player_sprite.getPosition().y > 0)
    {
      player_1.player_sprite.move(0,-player_1.returnPaddleSpeed()*dt);
    }
    else if (player_1.returnPlayerMovementDown() && (player_1.player_sprite.getPosition().y <
            (window.getSize().y - player_1.player_sprite.getGlobalBounds().height)))
    {
      player_1.player_sprite.move(0, player_1.returnPaddleSpeed()*dt);
    }

    // Player 2 Paddle Movement
    if (player_2.returnPlayerMovementUp() && player_2.player_sprite.getPosition().y > 0)
    {
      player_2.player_sprite.move(0,-player_2.returnPaddleSpeed()*dt);
    }
    else if (player_2.returnPlayerMovementDown() && (player_2.player_sprite.getPosition().y <
            (window.getSize().y - player_2.player_sprite.getGlobalBounds().height)))
    {
      player_2.player_sprite.move(0, player_2.returnPaddleSpeed()*dt);
    }

    // Launch and Move the Ball
    if (ball_1.returnBallStarted())
    {
      ball_1.ball_sprite.move(ball_1.ball_vector.x * ball_1.returnBallSpeed() * dt,
                              ball_1.ball_vector.y * ball_1.returnBallSpeed() * dt);
    }

    // Score Increment P1
    if (ball_1.ball_sprite.getPosition().x > window.getSize().x)
    {
      player_1.setScore();
      player_1.setScoreText();
      ball_1.ball_sprite.setPosition
        (
          window.getSize().x/2 - ball_1.ball_sprite.getGlobalBounds().width/2 ,
          window.getSize().y/2 - ball_1.ball_sprite.getGlobalBounds().height/2
        );
      ball_1.setBallStartedF();
      ball_1.setBallDirectionR();
      ball_1.setRandomBallDirectionY();
      ball_1.resetBallSpeed();
      ball_1.normalise();
    }

    // Score Increment P2
    if (ball_1.ball_sprite.getPosition().x < 0)
    {
      player_2.setScore();
      player_2.setScoreText();
      ball_1.ball_sprite.setPosition
        (
          window.getSize().x/2 - ball_1.ball_sprite.getGlobalBounds().width/2 ,
          window.getSize().y/2 - ball_1.ball_sprite.getGlobalBounds().height/2
        );
      ball_1.setBallStartedF();
      ball_1.setBallDirectionL();
      ball_1.setRandomBallDirectionY();
      ball_1.resetBallSpeed();
      ball_1.normalise();
    }

    // End Game Manager
    if (player_1.returnScore() == max_score || player_2.returnScore() == max_score)
    {
      game_running = false;
      end_screen = true;
      if (player_1.returnScore() == max_score)
      {
        end_title_text.setString("Player 1 Wins!");
      }
      else
      {
        end_title_text.setString("Player 2 Wins!");
      }
    }

  }
}

/*============================================================================*/

void Game::render()
{
  // Start Menu
  if (start_menu)
  {
    window.draw(start_menu_bg_sprite);
    window.draw(start_menu_title_text);
    window.draw(rules_text);
    window.draw(start_menu_play_option);
    window.draw(start_menu_quit_option);
  }

  // Pause Menu
  else if (pause_menu)
  {
    window.draw(background_pause_sprite);
    window.draw(pause_title_text);
    window.draw(continue_opt_pause_text);
    window.draw(restart_opt_pause_text);
    window.draw(quit_opt_pause_text);
  }

  // Win Screen
  else if (end_screen)
  {
    window.draw(end_bg_sprite);
    window.draw(end_title_text);
    window.draw(play_again_end_text);
    window.draw(quit_end_text);
  }

  // Game
  else if (game_running)
  {
    window.draw(game_bg_sprite);
    window.draw(player_1.score_text);
    window.draw(player_2.score_text);
    window.draw(player_1.player_sprite);
    window.draw(player_2.player_sprite);
    window.draw(ball_1.ball_sprite);
  }

  // Error
  else
  {
    std::cout<< "Rendering Error";
  }
}

/*============================================================================*/

void Game::mouseClicked(sf::Event event)
{
  // Gets Click Position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  // Start Menu
  if (start_menu)
  {
    if (collisionCheckText(click, start_menu_play_option))
    {
      start_menu = false;
      game_running = true;
    }
    if (collisionCheckText(click, start_menu_quit_option))
    {
      window.close();
    }
  }

  // Pause Menu
  if (pause_menu)
  {
    if (collisionCheckText(click, restart_opt_pause_text))
    {
      player_1.resetScore();
      player_2.resetScore();

      player_1.setScoreText();
      player_2.setScoreText();

      ball_1.resetBallSpeed();
      ball_1.setRandomBallDirectionY();
      ball_1.normalise();

      ball_1.ball_sprite.setPosition
        (
          window.getSize().x/2 - ball_1.ball_sprite.getGlobalBounds().width/2 ,
          window.getSize().y/2 - ball_1.ball_sprite.getGlobalBounds().height/2
        );

      ball_1.setBallStartedF();

      pause_menu = false;
      game_running = true;
    }
    if (collisionCheckText(click, quit_opt_pause_text))
    {
      window.close();
    }
  }

  // End Screen
  if (end_screen)
  {
    if (collisionCheckText(click, play_again_end_text))
    {
      player_1.resetScore();
      player_2.resetScore();

      player_1.setScoreText();
      player_2.setScoreText();

      ball_1.resetBallSpeed();
      ball_1.setRandomBallDirectionY();
      ball_1.normalise();

      ball_1.ball_sprite.setPosition
        (
          window.getSize().x/2 - ball_1.ball_sprite.getGlobalBounds().width/2 ,
          window.getSize().y/2 - ball_1.ball_sprite.getGlobalBounds().height/2
        );

      ball_1.setBallStartedF();

      end_screen = false;
      game_running = true;
    }
    if (collisionCheckText(click, quit_end_text))
    {
      window.close();
    }
  }
}

/*============================================================================*/

void Game::keyPressed(sf::Event event)
{
  // Start Menu
  if (start_menu)
  {
    if ((event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right))
    {
      play_selected = !play_selected;

      if(play_selected)
      {
        start_menu_play_option.setString(">Play<");
        start_menu_play_option.setStyle(sf::Text::Italic | sf::Text::Bold);
        start_menu_quit_option.setString("Quit");
        start_menu_quit_option.setStyle(sf::Text::Regular);
      }
      else
      {
        start_menu_play_option.setString("Play");
        start_menu_play_option.setStyle(sf::Text::Regular);
        start_menu_quit_option.setString(">Quit<");
        start_menu_quit_option.setStyle(sf::Text::Italic | sf::Text::Bold);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if(play_selected)
      {
        start_menu = false;
        game_running = true;
      }
      else
      {
        window.close();
      }
    }
  }

  // Pause Menu
  if (pause_menu)
  {
    if ((event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right))
    {
      play_selected = !play_selected;

      if(play_selected)
      {
        restart_opt_pause_text.setString(">Restart<");
        restart_opt_pause_text.setStyle(sf::Text::Italic | sf::Text::Bold);
        quit_opt_pause_text.setString("Quit");
        quit_opt_pause_text.setStyle(sf::Text::Regular);
      }
      else
      {
        restart_opt_pause_text.setString("Restart");
        restart_opt_pause_text.setStyle(sf::Text::Regular);
        quit_opt_pause_text.setString(">Quit<");
        quit_opt_pause_text.setStyle(sf::Text::Italic | sf::Text::Bold);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if(play_selected)
      {
        player_1.resetScore();
        player_2.resetScore();

        player_1.setScoreText();
        player_2.setScoreText();

        ball_1.resetBallSpeed();
        ball_1.setRandomBallDirectionY();
        ball_1.normalise();

        ball_1.ball_sprite.setPosition
          (
            window.getSize().x/2 - ball_1.ball_sprite.getGlobalBounds().width/2 ,
            window.getSize().y/2 - ball_1.ball_sprite.getGlobalBounds().height/2
          );

        ball_1.setBallStartedF();

        pause_menu = false;
        game_running = true;
      }
      else
      {
        window.close();
      }
    }
  }

  // End Screen
  if (end_screen)
  {
    if ((event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right))
    {
      play_selected = !play_selected;
      if(play_selected)
      {
        play_again_end_text.setString(">Play Again<");
        play_again_end_text.setStyle(sf::Text::Italic | sf::Text::Bold);
        quit_end_text.setString("Quit");
        quit_end_text.setStyle(sf::Text::Regular);
      }
      else
      {
        play_again_end_text.setString("Play Again");
        play_again_end_text.setStyle(sf::Text::Regular);
        quit_end_text.setString(">Quit<");
        quit_end_text.setStyle(sf::Text::Italic | sf::Text::Bold);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if(play_selected)
      {
        player_1.resetScore();
        player_2.resetScore();

        player_1.setScoreText();
        player_2.setScoreText();

        ball_1.resetBallSpeed();
        ball_1.setRandomBallDirectionY();
        ball_1.normalise();

        ball_1.ball_sprite.setPosition
          (
            window.getSize().x/2 - ball_1.ball_sprite.getGlobalBounds().width/2 ,
            window.getSize().y/2 - ball_1.ball_sprite.getGlobalBounds().height/2
          );

        ball_1.setBallStartedF();

        end_screen = false;
        game_running = true;
      }
      else
      {
        window.close();
      }
    }
  }

  // In Game
  if (game_running)
  {
    if (event.key.code == sf::Keyboard::Space)
    {
      ball_1.setBallStartedT();
    }
    else if (event.key.code == sf::Keyboard::W)
    {
      player_1.setMovementUpT();
    }
    else if (event.key.code == sf::Keyboard::S)
    {
      player_1.setMovementDownT();
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
      player_2.setMovementUpT();
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
      player_2.setMovementDownT();
    }
  }

  // Open/Close Pause Menu
  if (event.key.code == sf::Keyboard:: Escape)
  {
    if (game_running)
    {
      game_running = false;
      pause_menu = true;
    }
    else if (pause_menu)
    {
      pause_menu = false;
      game_running = true;
    }
  }

}

/*============================================================================*/

void Game::keyReleased(sf::Event event)
{
  if (game_running)
  {
    if (event.key.code == sf::Keyboard::W)
    {
      player_1.setMovementUpF();
    }
    else if (event.key.code == sf::Keyboard::S)
    {
      player_1.setMovementDownF();
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
      player_2.setMovementUpF();
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
      player_2.setMovementDownF();
    }
  }
}

/*============================================================================*/

bool Game::collisionCheckText(sf::Vector2i click, sf::Text text)
{
  if (click.x > text.getPosition().x
      && click.y > text.getPosition().y
      && click.x < text.getPosition().x + text.getGlobalBounds().width
      && click.y < text.getPosition().y + text.getGlobalBounds().height)
  {
    return true;
  }

  else
  {
    return false;
  }
}
