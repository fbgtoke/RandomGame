#ifndef _TILEMAP_HPP
#define _TILEMAP_HPP

#include "GameObject.hpp"
#include "Tilesheet.hpp"

class Tilemap : public GameObject {
public:
  Tilemap();
  ~Tilemap() override;

  void create(unsigned int width, unsigned int height);
  void loadFromFile(const std::string& filename);

  void setTile(unsigned int x, unsigned int y, unsigned int value);
  void setPermission(unsigned int x, unsigned int y, unsigned int value);

  unsigned int getWidth() const;
  unsigned int getHeight() const;
  unsigned int getTile(unsigned int x, unsigned int y) const;
  unsigned int getPermission(unsigned int x, unsigned int y) const;

  bool outOfBounds(unsigned int x, unsigned int y) const;

  Tilesheet& getTilesheet();

  sf::Vector2i pixel2tile(const sf::Vector2f& px) const;
  sf::Vector2f tile2pixel(const sf::Vector2i& tile) const;

  void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

private:
  unsigned int mWidth;
  unsigned int mHeight;

  std::vector<std::vector<unsigned int>> mMap;
  std::vector<std::vector<unsigned int>> mPermissions;

  Tilesheet mTilesheet;
};

#endif // _TILEMAP_HPP