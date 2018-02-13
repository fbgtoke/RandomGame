#include "SceneTest.hpp"
#include "SceneReader.hpp"

SceneTest::SceneTest() : Scene() {}

SceneTest::~SceneTest() {
  for (Character* character : mCharacters)
    delete character;
  mCharacters.clear();
}

void SceneTest::init() {
  Scene::init();
  getInput().loadFromFile("default.input");

  loadFromFile("test.json");
}

void SceneTest::event(const sf::Event& event) {
  Scene::event(event);

  if (event.type == sf::Event::KeyPressed)
    if (event.key.code == sf::Keyboard::Escape)
      end();
}

void SceneTest::update(const sf::Time& deltatime) {
  Scene::update(deltatime);

  Character* current = mCharacters.front();
  if (current != nullptr && current->isIdle()) {
    Direction direction = current->getNextDirection();
    if (direction != NUM_DIRS && canMoveTowards(current, direction)) {
      current->moveTowards(direction);

      mCharacters.erase(mCharacters.begin());
      mCharacters.push_back(current);
    }
  }

  for (Character* character : mCharacters)
    character->update(deltatime);
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

Tilemap& SceneTest::getTilemap() { return mTilemap; }
std::list<Character*>& SceneTest::getCharacters() { return mCharacters; }

void SceneTest::loadFromFile(const std::string& filename) {
  SceneReader::read(this, filename);
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