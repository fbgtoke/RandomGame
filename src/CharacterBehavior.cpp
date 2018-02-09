#include "CharacterBehavior.hpp"
#include "CharacterBehaviorPlayer.hpp"

CharacterBehavior::CharacterBehavior(Character* character) : mCharacter(character) {}
CharacterBehavior::~CharacterBehavior() {}

CharacterBehavior* CharacterBehavior::create(CharacterBehavior::Type type, Character* character) {
  switch(type) {
  case CharacterBehavior::Player: return new CharacterBehaviorPlayer(character); break;
  default: return nullptr; break;
  }
}