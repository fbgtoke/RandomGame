#ifndef _CHARACTER_BEHAVIOR_PLAYER_HPP
#define _CHARACTER_BEHAVIOR_PLAYER_HPP

#include "CharacterBehavior.hpp"
#include "Character.hpp"

class CharacterBehaviorPlayer : public CharacterBehavior {
public:
  CharacterBehaviorPlayer(Character* character);
  ~CharacterBehaviorPlayer() override;

  void init() override;
};

#endif // _CHARACTER_BEHAVIOR_PLAYER_HPP