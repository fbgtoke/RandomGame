#ifndef _TILEMAP_READER_HPP
#define _TILEMAP_READER_HPP

#include "GameObject.hpp"
#include "Tilemap.hpp"
#include "TilesheetReader.hpp"

class TilemapReader : public GameObject {
public:
  static void read(Tilemap& tilemap, const std::string& filename);
  static void read(Tilemap& tilemap, const Json& json);

private:
  static const std::string kPrefix;
};

#endif // _TILEMAP_READER_HPP