#ifndef _CHARACTER_BEHAVIOR_RANDOM_HPP
#define _CHARACTER_BEHAVIOR_RANDOM_HPP

#include "CharacterBehavior.hpp"
#include "Character.hpp"

class CharacterBehaviorRandom : public CharacterBehavior {
public:
  CharacterBehaviorRandom(Character* character);
  ~CharacterBehaviorRandom() override;

  void update(const sf::Time& deltatime) override;
};

#endif // _CHARACTER_BEHAVIOR_RANDOM_HPP