#include "AnimatedSpriteReader.hpp"

const std::string AnimatedSpriteReader::kPrefix = "res/animations/";

void AnimatedSpriteReader::read(AnimatedSprite& sprite, const std::string& filename) {
  std::ifstream file(kPrefix + filename);

  if (file.is_open()) {
    read(sprite, file);
    file.close();
  } else {
    std::cout << "Could not load animated sprite " << filename << std::endl;
  }
}

void AnimatedSpriteReader::read(AnimatedSprite& sprite, std::ifstream& stream) {
  std::string line;

  while (getline(stream, line)) {
    if (line.find("animation") != std::string::npos) readAnimation(sprite, stream);
    else if (line.find("texture") != std::string::npos) readTexture(sprite, line);
  }
}

void AnimatedSpriteReader::readAnimation(AnimatedSprite& sprite, std::ifstream& stream) {
  sprite.addAnimation();
  AnimationReader::read(sprite.getAnimation(sprite.getNumberOfAnimations()-1), stream);
}

void AnimatedSpriteReader::readTexture(AnimatedSprite& sprite, const std::string& line) {
  std::stringstream stream(line);
  std::string command;
  std::string textureName;
  
  stream >> command >> textureName;

  sf::Texture* texture = getResource().texture(textureName);
  sprite.setTexture(*texture);
}