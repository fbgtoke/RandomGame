#include "Tilemap.hpp"
#include "TilemapReader.hpp"

Tilemap::Tilemap() {}
Tilemap::~Tilemap() {}

void Tilemap::create(unsigned int width, unsigned int height) {
  mWidth = width;
  mHeight = height;

  mMap = std::vector<std::vector<unsigned int>> (height, std::vector<unsigned int>(width));
}

void Tilemap::loadFromFile(const std::string& filename) {
  TilemapReader::read(*this, filename);
}

void Tilemap::setTile(unsigned int x, unsigned int y, unsigned int value) {
  if (!outOfBounds(x, y))
    mMap[y][x] = value;
}

unsigned int Tilemap::getWidth() const { return mWidth; }
unsigned int Tilemap::getHeight() const { return mHeight; }

unsigned int Tilemap::getValue(unsigned int x, unsigned int y) const {
  if (outOfBounds(x, y)) return 0;
  return mMap[y][x];
}

bool Tilemap::outOfBounds(unsigned int x, unsigned int y) const {
  return x >= mWidth || y >= mHeight;
}

Tilesheet& Tilemap::getTilesheet() { return mTilesheet; }

sf::Vector2i Tilemap::pixel2tile(const sf::Vector2f& px) const {
  sf::Vector2i tile;

  tile.x = (int)floor(px.x/mTilesheet.getTileSize());
  tile.y = (int)floor(px.y/mTilesheet.getTileSize());

  return tile;
}

sf::Vector2f Tilemap::tile2pixel(const sf::Vector2i& tile) const {
  sf::Vector2f px;

  px.x = (float)(tile.x * mTilesheet.getTileSize());
  px.y = (float)(tile.y * mTilesheet.getTileSize());

  return px;
}

void Tilemap::draw(sf::RenderTarget& window, sf::RenderStates states) const {
  const sf::Texture* texture;
  sf::Sprite sprite;

  texture = mTilesheet.getTexture();
  sprite.setTexture(*texture);

  unsigned int value;
  sf::Vector2f position;
  sf::IntRect rect;
  for (unsigned int i = 0; i < mHeight; ++i) {
    for (unsigned int j = 0; j < mWidth; ++j) {
      value = getValue(j, i);
      position = tile2pixel({(int)j, (int)i});
      rect = mTilesheet.getTileRect(value);

      sprite.setPosition(position);
      sprite.setTextureRect(rect);

      window.draw(sprite);
    }
  }
}