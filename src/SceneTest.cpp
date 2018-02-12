#include "SceneTest.hpp"

SceneTest::SceneTest() : Scene() {}

SceneTest::~SceneTest() {}

void SceneTest::init() {
  Scene::init();
  getInput().loadFromFile("default.input");

  mTilemap.loadFromFile("0.map");

  mCharacter.loadFromFile("scientist.char");
  mCharacter.init();
}

void SceneTest::event(const sf::Event& event) {
  Scene::event(event);

  if (event.type == sf::Event::KeyPressed)
    if (event.key.code == sf::Keyboard::Escape)
      end();
}

void SceneTest::update(const sf::Time& deltatime) {
  Scene::update(deltatime);

  Direction direction = mCharacter.getNextDirection();
  if (direction != NUM_DIRS && canMoveTowards(mCharacter, direction))
    mCharacter.moveTowards(direction);

  mCharacter.update(deltatime);
}

void SceneTest::draw(sf::RenderTarget& window, sf::RenderStates states) const {
  Scene::draw(window, states);

  window.draw(mTilemap);
  window.draw(mCharacter);
}

void SceneTest::end() {
  Scene::end();

  mCharacter.end();
}

bool SceneTest::canMoveTowards(const Character& character, Direction direction) const {
  sf::Vector2i position = character.getPositionInTiles();
  position += dir2vec<int>(direction);

  return character.isIdle() && mTilemap.getPermission(position.x, position.y) == 0;
}