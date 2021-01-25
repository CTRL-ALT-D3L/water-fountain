
#include "RELAY.h"

RELAY relays;

void setup()
{
  relays.begin();
}

void loop()
{
  relays.backAndForth();
}
