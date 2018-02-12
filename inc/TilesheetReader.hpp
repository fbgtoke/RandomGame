#ifndef _TILESHEET_READER_HPP
#define _TILESHEET_READER_HPP

#include "GameObject.hpp"
#include "Tilesheet.hpp"

class TilesheetReader : public GameObject {
public:
  static void read(Tilesheet& tilesheet, const std::string& filename);
  static void read(Tilesheet& tilesheet, const Json& json);
};

#endif // _TILESHEET_READER_HPP