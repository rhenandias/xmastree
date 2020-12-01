#define size 16

typedef struct led  {
  byte pin;
  int interval;
  long last_time;
};

int pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1};

long current_time;

led leds[size];

void setup()
{
  randomSeed(analogRead(A5));
 
  for(byte i = 0; i < size; i++){
    leds[i] = led{pins[i], random(400, 800), 0};
  }
  
  for(byte i = 0; i < size; i++){
    pinMode(leds[i].pin, OUTPUT); 
  }
  
}

void loop()
{
  current_time = millis();
  
  for(byte i = 0; i < size; i++){
    if(current_time - leds[i].last_time >= leds[i].interval){
      digitalWrite(leds[i].pin, !digitalRead(leds[i].pin));
        leds[i].last_time = current_time;
    }
  }
}
