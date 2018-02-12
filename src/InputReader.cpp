#include "InputReader.hpp"

const std::string InputReader::kPrefix = "res/input/";

void InputReader::read(Input& input, const std::string& filename) {
  std::ifstream file(kPrefix + filename);

  if (file.is_open()) {
    read(input, file);
    file.close();
  } else {
    std::cout << "Could not load input " << filename << std::endl;
  }
}

void InputReader::read(Input& input, std::ifstream& stream) {
  std::string line;

  while (getline(stream, line)) {
    readBinding(input, line);
  }
}

void InputReader::readBinding(Input& input, const std::string& line) {
  std::stringstream stream(line);
  unsigned int key;
  unsigned int button;
  
  stream >> key >> button;

  sf::Keyboard::Key sfmlKey = static_cast<sf::Keyboard::Key>(key);
  Input::Button inputButton = static_cast<Input::Button>(button);
  input.addKeyboardBinding(sfmlKey, inputButton);
}