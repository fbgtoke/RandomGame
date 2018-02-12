#include "CharacterBehavior.hpp"
#include "CharacterBehaviorPlayer.hpp"
#include "CharacterBehaviorRandom.hpp"

CharacterBehavior::CharacterBehavior(Character* character) : mCharacter(character) {}
CharacterBehavior::~CharacterBehavior() {}

CharacterBehavior* CharacterBehavior::create(CharacterBehavior::Type type, Character* character) {
  switch(type) {
  case Player: return new CharacterBehaviorPlayer(character); break;
  case Random: return new CharacterBehaviorRandom(character); break;
  default: return nullptr; break;
  }
}