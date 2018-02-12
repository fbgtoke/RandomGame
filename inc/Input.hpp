#ifndef _INPUT_HPP
#define _INPUT_HPP

#include "Utils.hpp"

class GameObject;

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

  struct Listener {
    GameObject* listener;
    std::function<void(void)> callback;
  };
  void addOnPressedListener(Button button, Listener listener);
  void addOnReleasedListener(Button button, Listener listener);

  void removeOnPressedListener(Button button, GameObject* object);
  void removeOnReleasedListener(Button button, GameObject* object);

  Button keyboard2button(sf::Keyboard::Key key) const;
  Button joystick2button(unsigned int key) const;

  void loadFromFile(const std::string& filename);

private:
  std::map<sf::Keyboard::Key, Button> mKeyboardBindings;
  std::map<unsigned int, Button> mJoystickBindings;

  std::list<Listener> mOnPressed[NUM_BUTTONS];
  std::list<Listener> mOnReleased[NUM_BUTTONS];

  void triggerOnPressed(Button button);
  void triggerOnReleased(Button button);
};

#endif // _INPUT_HPP