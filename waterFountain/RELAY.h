
/*
-When the relay is off COM is connected to NC and disconnected from NO.
-When the relay is on COM is connected to NO and disconnected from NC.
*/

#define RELAY_ON LOW
#define RELAY_OFF HIGH

class RELAY
{

private:
    // had to do 7 cuz there wasnt enough space on the board :(
    uint8_t RELAY_PINS[7] = {2, 3, 4, 5, 6, 7, 8};
    uint16_t DELAY = 100;

public:
    // init:
    void begin()
    {
        // turn relays off on start
        for (uint8_t i = 0; i < 7; i++)
            pinMode(RELAY_PINS[i], OUTPUT);
            digitalWrite(RELAY_PINS[i], RELAY_OFF);
    }

    // patterns:
    void waveltr();
    void wave();
    void backAndForth();
};

void RELAY::waveltr()
{
    // left to right
    for (uint8_t i = 0; i < 7; i++)
    {
        digitalWrite(RELAY_PINS[i], RELAY_ON);
        delay(DELAY);
        digitalWrite(RELAY_PINS[i], RELAY_OFF);
    }
}

void RELAY::wave()
{
    // middle to out
    for (uint8_t i = 0; i < 4; i++)
    {
        digitalWrite(RELAY_PINS[3 + i], RELAY_ON);
        digitalWrite(RELAY_PINS[3 - i], RELAY_ON);
        delay(DELAY);
        if (i == 0)
            delay(DELAY);
        digitalWrite(RELAY_PINS[3 + i], RELAY_OFF);
        digitalWrite(RELAY_PINS[3 - i], RELAY_OFF);
    }
}

void RELAY::backAndForth()
{
    // left to right
    for (uint8_t i = 0; i < 7; i++)
    {
        digitalWrite(RELAY_PINS[i], RELAY_ON);
        delay(DELAY);
        digitalWrite(RELAY_PINS[i], RELAY_OFF);
    }
    //right to left
    for (uint8_t i = 7; i > 0; i--)
    {
        digitalWrite(RELAY_PINS[i], RELAY_ON);
        delay(DELAY);
        digitalWrite(RELAY_PINS[i], RELAY_OFF);
    }
}
