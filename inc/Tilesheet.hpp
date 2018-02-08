#ifndef _TILESHEET_HPP
#define _TILESHEET_HPP

#include "GameObject.hpp"

class Tilesheet : public GameObject {
public:
  Tilesheet();
  ~Tilesheet() override;

  void useTexture(const std::string& name);
  
  void setTileSize(unsigned int tileSize);
  void setTilesPerRow(unsigned int tilesPerRow);
  void setTileOffset(const sf::Vector2i& offset);
  void setTileMargin(const sf::Vector2i& margin);

  const sf::Texture* getTexture() const;

  unsigned int getTileSize() const;
  unsigned int getTilesPerRow() const;
  sf::Vector2i getTileOffset() const;
  sf::Vector2i getTileMargin() const;

  sf::IntRect getTileRect(unsigned int index) const;

private:
  sf::Texture* mTexture;
  
  unsigned int mTileSize;
  unsigned int mTilesPerRow;
  sf::Vector2i mTileOffset;
  sf::Vector2i mTileMargin;
};

#endif // _TILESHEET_HPP