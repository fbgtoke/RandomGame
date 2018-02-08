#ifndef _INPUT_HPP
#define _INPUT_HPP

#include "Utils.hpp"

class Input {
public:
  Input();
  ~Input();

  void processEvent(const sf::Event& event);

  enum Button {
    Left = 0,
    Right,
    Up,
    Down,
    Accept,
    Cancel,
    NUM_BUTTONS,
    NO_BUTTON
  };
  void addKeyboardBinding(sf::Keyboard::Key key, Button button);
  void addJoystickBinding(unsigned int key, Button button);

  void addOnPressedListener(Button button, std::function<void(void)> callback);
  void addOnReleasedListener(Button button, std::function<void(void)> callback);

  Button keyboard2button(sf::Keyboard::Key key) const;
  Button joystick2button(unsigned int key) const;

private:
  std::map<sf::Keyboard::Key, Button> mKeyboardBindings;
  std::map<unsigned int, Button> mJoystickBindings;

  std::list<std::function<void(void)>> mOnPressed[NUM_BUTTONS];
  std::list<std::function<void(void)>> mOnReleased[NUM_BUTTONS];

  void triggerOnPressed(Button button);
  void triggerOnReleased(Button button);
};

#endif // _INPUT_HPP