#ifndef _INPUT_READER_HPP
#define _INPUT_READER_HPP

#include "GameObject.hpp"

class InputReader : public GameObject {
public:
  static void read(Input& input, const std::string& filename);
  static void read(Input& input, std::ifstream& stream);

private:
  static const std::string kPrefix;

  static void readBinding(Input& input, const std::string& line);
};

#endif // _INPUT_READER_HPP