#include "AnimatedSpriteReader.hpp"

const std::string AnimatedSpriteReader::kPrefix = "res/animations/";

void AnimatedSpriteReader::read(AnimatedSprite* sprite, const std::string& filename) {
  std::ifstream file(kPrefix + filename);

  std::string content;
  std::stringstream ss;
  Json json;

  if (file.is_open()) {
    content.assign( (std::istreambuf_iterator<char>(file) ),
                    (std::istreambuf_iterator<char>()    ) );
    
    ss << content;
    ss >> json;
    read(sprite, json);

    file.close();
  } else {
    std::cout << "Could not load sprite " << filename << std::endl;
  }
}

void AnimatedSpriteReader::read(AnimatedSprite* sprite, const Json& json) {
  std::string line;

  if (json.count("texture") != 0) {
    std::string textureName = json.at("texture");
    sf::Texture* texture = getResource().texture(textureName);
    sprite->setTexture(*texture);
  }

  if (json.count("animations") != 0) {
    std::vector<Json> animations = json.at("animations");
    for (unsigned int i = 0; i < animations.size(); ++i) {
      Json child = animations[i];

      sprite->addAnimation();
      AnimationReader::read(sprite->getAnimation(i), child);
    }
  }
}