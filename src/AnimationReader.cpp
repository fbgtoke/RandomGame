#include "AnimationReader.hpp"

void AnimationReader::read(Animation& animation, const std::string& filename) {
  std::ifstream file(filename);

  if (file.is_open()) {
    read(animation, file);
    file.close();
  } else {
    std::cout << "Could not load animation " << filename << std::endl;
  }
}

void AnimationReader::read(Animation& animation, std::ifstream& stream) {
  std::string line;

  while (getline(stream, line)) {
    if (line.find("frame") != std::string::npos) readFrame(animation, line);
    else if (line.find("time") != std::string::npos) readTimePerFrame(animation, line);
    else if (line.find("repeat") != std::string::npos) readRepeat(animation, line);
    else if (line.find("play") != std::string::npos) readPlay(animation, line);
    else if (line.find("end") != std::string::npos) break;
  }
}

void AnimationReader::readFrame(Animation& animation, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  sf::IntRect rect;

  stream >> command >> rect.left >> rect.top >> rect.width >> rect.height;
  animation.addFrame(rect);
}

void AnimationReader::readTimePerFrame(Animation& animation, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  float seconds;

  stream >> command >> seconds;
  animation.setTimePerFrame(sf::seconds(seconds));
}

void AnimationReader::readRepeat(Animation& animation, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  bool repeat;

  stream >> command >> repeat;
  animation.setRepeat(repeat);
}

void AnimationReader::readPlay(Animation& animation, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  bool play;

  stream >> command >> play;
  animation.setPlay(play);
}
