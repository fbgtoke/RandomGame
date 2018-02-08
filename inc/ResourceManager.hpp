#ifndef _RESOURCE_MANAGER_HPP
#define _RESOURCE_MANAGER_HPP

#include "Utils.hpp"

class ResourceManager {
public:
  ResourceManager();
  ~ResourceManager();

  sf::Texture* texture(const std::string& name);

  bool isTextureLoaded(const std::string& name) const;
  void loadTexture(const std::string& name);
  void unloadTexture(const std::string& name);
  void unloadTextures();

private:
  static const std::string kTexturePath;
  std::map<std::string, sf::Texture*> mTextures;
};

#endif // _RESOURCE_MANAGER_HPP