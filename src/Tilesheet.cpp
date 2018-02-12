#include "Tilesheet.hpp"

Tilesheet::Tilesheet() {
  mTexture = nullptr;

  mTileSize = 0;
  mTilesPerRow = 0;
  mTileOffset = sf::Vector2i(0, 0);
  mTileMargin = sf::Vector2i(0, 0);
}

Tilesheet::~Tilesheet() {}

void Tilesheet::useTexture(const std::string& name) {
  mTexture = getResource().texture(name);
}

void Tilesheet::setTileSize(unsigned int tileSize) { mTileSize = tileSize; }
void Tilesheet::setTilesPerRow(unsigned int tilesPerRow) { mTilesPerRow = tilesPerRow; }
void Tilesheet::setTileOffset(const sf::Vector2i& offset) { mTileOffset = offset; }
void Tilesheet::setTileOffset(int x, int y) { setTileOffset({x, y}); }
void Tilesheet::setTileMargin(const sf::Vector2i& margin) { mTileMargin = margin; }
void Tilesheet::setTileMargin(int x, int y) { setTileMargin({x, y}); }

const sf::Texture* Tilesheet::getTexture() const { return mTexture; }

unsigned int Tilesheet::getTileSize() const { return mTileSize; }
unsigned int Tilesheet::getTilesPerRow() const { return mTilesPerRow; }
sf::Vector2i Tilesheet::getTileOffset() const { return mTileOffset; }
sf::Vector2i Tilesheet::getTileMargin() const { return mTileMargin; }

sf::IntRect Tilesheet::getTileRect(unsigned int index) const {
  sf::IntRect rect;
  rect.left = (index%mTilesPerRow) * (mTileSize + mTileMargin.x) + mTileOffset.x;
  rect.top = (index/mTilesPerRow) * (mTileSize + mTileMargin.y) + mTileOffset.y;
  rect.width = mTileSize;
  rect.height = mTileSize;

  return rect;
}