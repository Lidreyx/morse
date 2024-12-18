

int ledPin= ; //the pin where the led is connected

void setup()
{
    pinMode(ledPin, OUTPUT); //sets digital as output
}

void loop()
{
    digitalWrite(ledPin, HIGH);//Led on
    delay(1000);
    digitalWrite(ledPin, LOW);//Led off
    delay(1000);
}

led_new(const char* name) : led_t*

led_light_short(led_t)
led_light_long(led_t)
