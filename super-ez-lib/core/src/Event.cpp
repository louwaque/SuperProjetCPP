#include "../include/Event.hpp"

std::ostream &operator<<(std::ostream &os, const Event &event)
{
  return event.write(os);
}
