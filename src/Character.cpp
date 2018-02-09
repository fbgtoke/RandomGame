#include "Character.hpp"
#include "CharacterReader.hpp"

Character::Character() : mBehavior(nullptr) {}

Character::~Character() {}

void Character::init() {
  GameObject::init();

  mState = Idle;
  mDirection = Down;

  mSprite.init();
  mSprite.loadFromFile("character.anim");
  mSprite.changeAnimation(mState);

  mRunning = false;

  mNextDirection = NUM_DIRS;
  mTargetPosition = sf::Vector2f(0, 0);
  mWalkSpeed = 20.f;
  mRunSpeed = 20.f;
  mTileSize = 16.f;
  mThreshold = 0.25f;
}

void Character::update(const sf::Time& deltatime) {
  GameObject::update(deltatime);

  if (mState == Idle) {
    mSprite.getCurrentAnimation().stop();

  } else {
    mSprite.getCurrentAnimation().play();

    sf::Vector2f dir = mTargetPosition - mSprite.getPosition();
    dir = normalize(dir) * (float)deltatime.asSeconds();

    if (mRunning) dir *= mRunSpeed;
    else dir *= mWalkSpeed; 

    mSprite.move(dir);

    float distance = length(mSprite.getPosition() - mTargetPosition);
    if (distance < mThreshold) {
      mSprite.setPosition(mTargetPosition);
      mState = Idle;
    }
  }

  mSprite.changeAnimation(mDirection);
  mSprite.update(deltatime);
}

void Character::draw(sf::RenderTarget& window, sf::RenderStates states) const {
  GameObject::draw(window, states);

  mSprite.draw(window, states);
}

void Character::setBehavior(CharacterBehavior* behavior) { mBehavior = behavior; }

void Character::moveTowards(Direction dir) {
  if (mState == Idle) {
    mDirection = dir;
    mState = Walking;

    mTargetPosition = mSprite.getPosition() + dir2vec<float>(dir) * mTileSize;
  }
}

void Character::setTileSize(unsigned int tileSize) { mTileSize = tileSize; }
void Character::setThreshold(float threshold) { mThreshold = threshold; }
void Character::setWalkSpeed(float walkSpeed) { mWalkSpeed = walkSpeed; }
void Character::setRunSpeed(float runSpeed) { mRunSpeed = runSpeed; }
void Character::setDirection(Direction direction) { mDirection = direction; }

void Character::setNextDirection(Direction dir) { mNextDirection = dir; }
Direction Character::getNextDirection() const { return mNextDirection; }

AnimatedSprite& Character::getSprite() { return mSprite; }

void Character::setRunning(bool run) { mRunning = run; }

void Character::setPositionInTiles(const sf::Vector2i& position) {
  sf::Vector2f pos(position.x, position.y);
  mSprite.setPosition(pos * mTileSize);
}

sf::Vector2i Character::getPositionInTiles() const {
  sf::Vector2i position;
  position.x = (int)floor(mSprite.getPosition().x/mTileSize);
  position.y = (int)floor(mSprite.getPosition().y/mTileSize);
  return position;
}

bool Character::isIdle() const { return mState == Idle; }

void Character::loadFromFile(const std::string& filename) {
  CharacterReader::read(*this, filename);
}