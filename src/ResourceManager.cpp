#include "ResourceManager.hpp"

const std::string ResourceManager::kTexturePath = "res/textures/";

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {
  unloadTextures();
}

sf::Texture* ResourceManager::texture(const std::string& name) {
  if (!isTextureLoaded(name))
    loadTexture(name);

  return mTextures[name];
}

bool ResourceManager::isTextureLoaded(const std::string& name) const {
  return mTextures.count(name) != 0;
}

void ResourceManager::loadTexture(const std::string& name) {
  unloadTexture(name);

  sf::Texture* texture = new sf::Texture();

  if (texture->loadFromFile(kTexturePath + name))
    mTextures[name] = texture;
  else
    delete texture;
}

void ResourceManager::unloadTexture(const std::string& name) {
  if (isTextureLoaded(name)) {
    delete mTextures[name];
    mTextures.erase(name);
  }
}

void ResourceManager::unloadTextures() {
  for (auto& element : mTextures)
    delete element.second;

  mTextures.clear();
}