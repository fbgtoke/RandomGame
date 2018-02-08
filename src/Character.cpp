#include "Character.hpp"

Character::Character() {}

Character::~Character() {}

void Character::init() {
  GameObject::init();

  mState = Idle;
  mDirection = Down;

  mSprite.init();
  mSprite.loadFromFile("res/animations/character.anim");  
  mSprite.changeAnimation(mState);

  mRunning = false;

  mNextDirection = NUM_DIRS;
  mTargetPosition = sf::Vector2f(0, 0);
  mSpeed = 20.f;
  mTileSize = 16.f;
  mThreshold = 0.25f;

  getInput().addOnPressedListener(Input::Left, [this](){
    mNextDirection = Left;
  });
  getInput().addOnPressedListener(Input::Right, [this](){
    mNextDirection = Right;
  });
  getInput().addOnPressedListener(Input::Up, [this](){
    mNextDirection = Up;
  });
  getInput().addOnPressedListener(Input::Down, [this](){
    mNextDirection = Down;
  });
  getInput().addOnPressedListener(Input::Cancel, [this](){
    mRunning = true;
  });

  getInput().addOnReleasedListener(Input::Left, [this](){
    if (mNextDirection == Left) mNextDirection = NUM_DIRS;
  });
  getInput().addOnReleasedListener(Input::Right, [this](){
    if (mNextDirection == Right) mNextDirection = NUM_DIRS;
  });
  getInput().addOnReleasedListener(Input::Up, [this](){
    if (mNextDirection == Up) mNextDirection = NUM_DIRS;
  });
  getInput().addOnReleasedListener(Input::Down, [this](){
    if (mNextDirection == Down) mNextDirection = NUM_DIRS;
  });
  getInput().addOnReleasedListener(Input::Cancel, [this](){
    mRunning = false;
  });
}

void Character::update(const sf::Time& deltatime) {
  GameObject::update(deltatime);

  if (mState == Idle) {
    mSprite.getCurrentAnimation().stop();

    if (mNextDirection != NUM_DIRS) {
      moveTowards(mNextDirection);
    }
  } else {
    mSprite.getCurrentAnimation().play();

    sf::Vector2f dir = mTargetPosition - mSprite.getPosition();
    dir = normalize(dir) * (float)deltatime.asSeconds();

    if (mRunning) dir *= mSpeed * 2.f;
    else dir *= mSpeed; 

    mSprite.move(dir);

    float minDistance = mRunning? mThreshold * 2.f : mThreshold;
    float distance = length(mSprite.getPosition() - mTargetPosition);
    if (distance < minDistance) {
      mSprite.setPosition(mTargetPosition);

      if (mNextDirection != NUM_DIRS) {
        moveTowards(mNextDirection);
      } else {
        mState = Idle;
      }
    }
  }

  mSprite.changeAnimation(mDirection);
  mSprite.update(deltatime);
}

void Character::draw(sf::RenderTarget& window, sf::RenderStates states) const {
  GameObject::draw(window, states);

  mSprite.draw(window, states);
}

void Character::end() {}

void Character::moveTowards(Direction dir) {
  mDirection = dir;
  mState = Walking;

  mTargetPosition = mSprite.getPosition() + dir2vec<float>(dir) * mTileSize;
}