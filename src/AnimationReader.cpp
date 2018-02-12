#include "AnimationReader.hpp"

const std::string AnimationReader::kPrefix = "res/animations/";

void AnimationReader::read(Animation* animation, const std::string& filename) {
  std::ifstream file(kPrefix + filename);

  std::string content;
  std::stringstream ss;
  Json json;

  if (file.is_open()) {
    content.assign( (std::istreambuf_iterator<char>(file) ),
                    (std::istreambuf_iterator<char>()    ) );
    
    ss << content;
    ss >> json;
    read(animation, json);

    file.close();
  } else {
    std::cout << "Could not load animation " << filename << std::endl;
  }
}

void AnimationReader::read(Animation* animation, Json& json) {
  if (json.count("frames")) {
    for (unsigned int i = 0; i < json.at("frames").size(); ++i) {
      sf::IntRect frame;
      frame.left   = json.at("frames")[i][0];
      frame.top    = json.at("frames")[i][1];
      frame.width  = json.at("frames")[i][2];
      frame.height = json.at("frames")[i][3];
      animation->addFrame(frame);
    }
  }

  if (json.count("time")) {
    float seconds = json.at("time");
    animation->setTimePerFrame(sf::seconds(seconds));
  }

  if (json.count("repeat")) {
    bool repeat = json.at("repeat");
    animation->setRepeat(repeat);
  }

  if (json.count("play")) {
    bool play = json.at("play");
    animation->setPlay(play);
  }
}