#include "CharacterBehaviorPlayer.hpp"

CharacterBehaviorPlayer::CharacterBehaviorPlayer(Character* character)
  : CharacterBehavior(character) {}
CharacterBehaviorPlayer::~CharacterBehaviorPlayer() {}

void CharacterBehaviorPlayer::init() {
  CharacterBehavior::init();

  getInput().addOnPressedListener(Input::Left, [this](){
    mCharacter->setNextDirection(Left);
  });
  getInput().addOnPressedListener(Input::Right, [this](){
    mCharacter->setNextDirection(Right);
  });
  getInput().addOnPressedListener(Input::Up, [this](){
    mCharacter->setNextDirection(Up);
  });
  getInput().addOnPressedListener(Input::Down, [this](){
    mCharacter->setNextDirection(Down);
  });
  getInput().addOnPressedListener(Input::Cancel, [this](){
    mCharacter->setRunning(true);
  });

  getInput().addOnReleasedListener(Input::Left, [this](){
    if (mCharacter->getNextDirection() == Left)
      mCharacter->setNextDirection(NUM_DIRS);
  });
  getInput().addOnReleasedListener(Input::Right, [this](){
    if (mCharacter->getNextDirection() == Right)
      mCharacter->setNextDirection(NUM_DIRS);
  });
  getInput().addOnReleasedListener(Input::Up, [this](){
    if (mCharacter->getNextDirection() == Up)
      mCharacter->setNextDirection(NUM_DIRS);
  });
  getInput().addOnReleasedListener(Input::Down, [this](){
    if (mCharacter->getNextDirection() == Down)
      mCharacter->setNextDirection(NUM_DIRS);
  });
  getInput().addOnReleasedListener(Input::Cancel, [this](){
    mCharacter->setRunning(false);
  });
}