#include "CharacterBehaviorRandom.hpp"

CharacterBehaviorRandom::CharacterBehaviorRandom(Character* character)
  : CharacterBehavior(character) {}

CharacterBehaviorRandom::~CharacterBehaviorRandom() {}

void CharacterBehaviorRandom::update(const sf::Time& deltatime) {
  CharacterBehavior::update(deltatime);

  Direction nextDirection = static_cast<Direction>(rand()%NUM_DIRS);
  mCharacter->setNextDirection(nextDirection);
}