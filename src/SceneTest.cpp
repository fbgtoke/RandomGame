#include "SceneTest.hpp"

SceneTest::SceneTest() : Scene() {}

SceneTest::~SceneTest() {
  for (Character* character : mCharacters)
    delete character;
  mCharacters.clear();
}

void SceneTest::init() {
  Scene::init();
  getInput().loadFromFile("default.input");

  mTilemap.loadFromFile("0.map");

  for (int i = 0; i < 5; ++i) {
    Character* character = new Character();
    character->loadFromFile("scientist.char");
    character->init();
    character->setPositionInTiles({i + 1, 1});
    mCharacters.push_back(character);
  }
}

void SceneTest::event(const sf::Event& event) {
  Scene::event(event);

  if (event.type == sf::Event::KeyPressed)
    if (event.key.code == sf::Keyboard::Escape)
      end();
}

void SceneTest::update(const sf::Time& deltatime) {
  Scene::update(deltatime);

  for (Character* character : mCharacters) {
    Direction direction = character->getNextDirection();
    if (direction != NUM_DIRS && canMoveTowards(character, direction))
      character->moveTowards(direction);

    character->update(deltatime);
  }
}

void SceneTest::draw(sf::RenderTarget& window, sf::RenderStates states) const {
  Scene::draw(window, states);

  window.draw(mTilemap);
  
  for (Character* character : mCharacters)
    window.draw(*character);
}

void SceneTest::end() {
  Scene::end();

  for (Character* character : mCharacters)
    character->end();
}

bool SceneTest::canMoveTowards(const Character* character, Direction direction) const {
  sf::Vector2i position = character->getPositionInTiles();
  position += dir2vec<int>(direction);

  return
    character->isIdle() &&
    mTilemap.getPermission(position.x, position.y) == 0 &&
    !characterAtTile(position);
}

bool SceneTest::characterAtTile(const sf::Vector2i& tile) const {
  for (Character* character : mCharacters)
    if (character->getPositionInTiles() == tile)
      return true;

  return false;
}