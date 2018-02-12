#include "CharacterBehaviorPlayer.hpp"

CharacterBehaviorPlayer::CharacterBehaviorPlayer(Character* character)
  : CharacterBehavior(character) {}
CharacterBehaviorPlayer::~CharacterBehaviorPlayer() {}

void CharacterBehaviorPlayer::init() {
  CharacterBehavior::init();

  getInput().addOnPressedListener(
    Input::Left,
    { this, [this](){ this->mCharacter->setNextDirection(Left); } }
  );
  getInput().addOnPressedListener(
    Input::Right,
    { this, [this](){ this->mCharacter->setNextDirection(Right); } }
  );
  getInput().addOnPressedListener(
    Input::Up,
    { this, [this](){ this->mCharacter->setNextDirection(Up); } }
  );
  getInput().addOnPressedListener(
    Input::Down,
    { this, [this](){ this->mCharacter->setNextDirection(Down); } }
  );
  getInput().addOnPressedListener(
    Input::Cancel,
    { this, [this](){ this->mCharacter->setRunning(true); } }
  );

  getInput().addOnReleasedListener(Input::Left, {
    this,
    [this](){
    if (this->mCharacter->getNextDirection() == Left)
      this->mCharacter->setNextDirection(NUM_DIRS);
  }});
  getInput().addOnReleasedListener(Input::Right, {
    this,
    [this](){
    if (this->mCharacter->getNextDirection() == Right)
      this->mCharacter->setNextDirection(NUM_DIRS);
  }});
  getInput().addOnReleasedListener(Input::Up, {
    this,
    [this](){
    if (this->mCharacter->getNextDirection() == Up)
      this->mCharacter->setNextDirection(NUM_DIRS);
  }});
  getInput().addOnReleasedListener(Input::Down, {
    this,
    [this](){
    if (this->mCharacter->getNextDirection() == Down)
      this->mCharacter->setNextDirection(NUM_DIRS);
  }});
  getInput().addOnReleasedListener(Input::Cancel, {
    this,
    [this](){
    this->mCharacter->setRunning(false);
  }});
}

void CharacterBehaviorPlayer::end() {
  CharacterBehavior::end();

  getInput().removeOnPressedListener(Input::Left, this);
  getInput().removeOnPressedListener(Input::Right, this);
  getInput().removeOnPressedListener(Input::Up, this);
  getInput().removeOnPressedListener(Input::Down, this);
  getInput().removeOnPressedListener(Input::Cancel, this);
}