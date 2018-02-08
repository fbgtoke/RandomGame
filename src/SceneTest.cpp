#include "SceneTest.hpp"

SceneTest::SceneTest() : Scene() {}

SceneTest::~SceneTest() {}

void SceneTest::init() {
  Scene::init();

  mTilemap.loadFromFile("res/tilemaps/0.map");
  mCharacter.init();

  getInput().addKeyboardBinding(sf::Keyboard::Left, Input::Left);
  getInput().addKeyboardBinding(sf::Keyboard::Right, Input::Right);
  getInput().addKeyboardBinding(sf::Keyboard::Up, Input::Up);
  getInput().addKeyboardBinding(sf::Keyboard::Down, Input::Down);

  getInput().addKeyboardBinding(sf::Keyboard::X, Input::Cancel);
  getInput().addKeyboardBinding(sf::Keyboard::Space, Input::Cancel);
}

void SceneTest::event(const sf::Event& event) {
  Scene::event(event);

  if (event.type == sf::Event::KeyPressed)
    if (event.key.code == sf::Keyboard::Escape)
      end();
}

void SceneTest::update(const sf::Time& deltatime) {
  Scene::update(deltatime);

  mCharacter.update(deltatime);
}

void SceneTest::draw(sf::RenderTarget& window, sf::RenderStates states) const {
  Scene::draw(window, states);

  window.draw(mTilemap);
  window.draw(mCharacter);
}

void SceneTest::end() {
  Scene::end();
}