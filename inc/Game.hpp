#ifndef _GAME_HPP
#define _GAME_HPP

#include "Utils.hpp"
#include "Scene.hpp"

class Game {
public:
  static Game* instance();

  void run();
  void stop();
  bool isRunning() const;

private:
  Game();
  Game(const Game&);
  Game& operator=(const Game&);

  static Game* mGame;
  
  bool mRunning;

  sf::RenderWindow mWindow;
  sf::Clock mClock;

  Scene* mCurrentScene;

  void init();
  void event();
  void update();
  void draw();
  void end();

  void manageScenes();
};

#endif // _GAME_HPP