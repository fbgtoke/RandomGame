#include "Animation.hpp"
#include "AnimationReader.hpp"

Animation::Animation() {}
Animation::~Animation() {}

void Animation::addFrame(const sf::IntRect& rect) { mFrames.push_back(rect); }

void Animation::setTimePerFrame(const sf::Time& time) { mTimePerFrame = time; }

void Animation::init() {
  mCurrentFrame = 0;
  mTimePerFrame = sf::seconds(1.f);
  mCurrentFrameTime = sf::seconds(0.f);

  mPlay = false;
  mRepeat = false;
}

void Animation::update(const sf::Time& deltatime) {
  if (isPlaying()) {
    mCurrentFrameTime += deltatime;

    if (mCurrentFrameTime >= mTimePerFrame) {
      mCurrentFrameTime -= mTimePerFrame;
      nextFrame();
    }
  }
}

void Animation::play() { mPlay = true; }
void Animation::pause() { mPlay = false; }
void Animation::stop() {
  mPlay = false;
  mCurrentFrame = 0;
}

void Animation::setRepeat(bool repeat) { mRepeat = repeat; }
void Animation::setPlay(bool play) { mPlay = play; }

bool Animation::isPlaying() const { return mPlay && !hasEnded(); }
bool Animation::hasEnded() const { return !mRepeat && (mCurrentFrame == mFrames.size() - 1); }

sf::IntRect Animation::getCurrentFrame() const { return mFrames[mCurrentFrame]; }

void Animation::nextFrame() {
  mCurrentFrame = (mCurrentFrame + 1)%mFrames.size();
}

void Animation::prevFrame() {
  mCurrentFrame = (mCurrentFrame + mFrames.size() - 1)%mFrames.size();
}

void Animation::loadFromFile(const std::string& filename) {
  AnimationReader::read(*this, filename);
}