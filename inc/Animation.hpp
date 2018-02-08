#ifndef _ANIMATION_HPP
#define _ANIMATION_HPP

#include "GameObject.hpp"

class Animation : public GameObject {
public:
  Animation();
  ~Animation() override;

  void addFrame(const sf::IntRect& rect);
  void setTimePerFrame(const sf::Time& time);

  void init() override;
  void update(const sf::Time& deltatime) override;

  void play();
  void pause();
  void stop();

  void setRepeat(bool repeat);
  void setPlay(bool play);

  bool isPlaying() const;
  bool hasEnded() const;

  sf::IntRect getCurrentFrame() const;

  void nextFrame();
  void prevFrame();

  void loadFromFile(const std::string& filename);

private:
  unsigned int mCurrentFrame;
  std::vector<sf::IntRect> mFrames;
  sf::Time mTimePerFrame;

  sf::Time mCurrentFrameTime;

  bool mPlay;
  bool mRepeat;
};

#endif // _ANIMATION_HPP