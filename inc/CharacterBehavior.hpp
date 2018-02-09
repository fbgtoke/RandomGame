#ifndef _CHARACTER_BEHAVIOR_HPP
#define _CHARACTER_BEHAVIOR_HPP

#include "GameObject.hpp"

class Character;

class CharacterBehavior : public GameObject {
public:
  CharacterBehavior(Character* character);
  virtual ~CharacterBehavior();
  enum Type {
    Player
  };
  static CharacterBehavior* create(Type type, Character* character);

protected:
  Character* mCharacter;
};

#endif // _CHARACTER_BEHAVIOR_HPP