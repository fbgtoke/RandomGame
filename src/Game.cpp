#include "Game.hpp"

Game* Game::mGame = nullptr;

Game::Game() {}
Game::Game(const Game&) {}
Game& Game::operator=(const Game&) { return *this; }

Game* Game::instance() {
  if (mGame == nullptr) {
    mGame = new Game();
    mGame->init();
  }

  return mGame;
}

void Game::run() {
  if (isRunning()) return;
  mRunning = true;

  while (isRunning()) {
    event();
    update();
    draw();

    manageScenes();
  }

  end();
}

void Game::stop() {
  if (!isRunning()) return;
  mRunning = false;
}

bool Game::isRunning() const { return mRunning; }

void Game::init() {
  mRunning = false;

  const sf::VideoMode videoMode(kScreenWidth, kScreenHeight);
  mWindow.create(videoMode, kScreenTitle);
  mWindow.setFramerateLimit(kFramerateLimit);
  mWindow.setKeyRepeatEnabled(false);

  mClock.restart();

  mCurrentScene = Scene::create(Scene::Test);
  mCurrentScene->init();
}

void Game::event() {
  sf::Event event;

  if (mCurrentScene != nullptr) {
    while (mWindow.pollEvent(event)) {
      mCurrentScene->event(event);
    }

    if (event.type == sf::Event::Closed)
      stop();
  }
}

void Game::update() {
  sf::Time deltatime = mClock.restart();

  if (mCurrentScene != nullptr)
    mCurrentScene->update(deltatime);
}

void Game::draw() {
  mWindow.clear();

  if (mCurrentScene != nullptr)
    mWindow.draw(*mCurrentScene);

  mWindow.display();
}

void Game::end() {
  mWindow.close();

  if (mCurrentScene != nullptr)
    mCurrentScene->end();
}

void Game::manageScenes() {
  if (mCurrentScene == nullptr)
    stop();

  else if (mCurrentScene->hasEnded()) {
    delete mCurrentScene;
    mCurrentScene = nullptr;

    stop();
  }
}