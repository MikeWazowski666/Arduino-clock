#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define S_LATCH 11
#define S_CLK 12
#define S_DATA 10
#define SDA A4
#define SCL A5

byte one1[]   = {0, 0, 1, 0}; 
byte one2[]   = {0, 0, 0, 1}; 
byte two1[]   = {0, 1, 1, 0}; 
byte two2[]   = {0, 0, 1, 1}; 
byte three1[] = {0, 1, 1, 0}; 
byte three2[] = {1, 0, 1, 1}; 
byte four1[]  = {0, 1, 0, 0}; 
byte four2[]  = {1, 1, 0, 1}; 
byte five1[]  = {0, 1, 1, 0}; 
byte five2[]  = {1, 1, 1, 0}; 
byte six1[]   = {0, 1, 1, 1}; 
byte six2[]   = {1, 1, 1, 0}; 
byte seven1[] = {0, 1, 0, 0}; 
byte seven2[] = {0, 0, 1, 1}; 
byte eight1[] = {0, 1, 1, 1}; 
byte eight2[] = {1, 1, 1, 1}; 
byte nine1[]  = {0, 1, 0, 0}; 
byte nine2[]  = {1, 1, 1, 1};
byte null1[]  = {1, 1, 1, 0};
byte null2[]  = {0, 1, 1, 1};

/*
void dataToClock(array val1){
    for (int i = 0; i < sizeof(val1); i++){
        //Serial.print(one1[i]); //use for debugging
        if (one1[i] == 1){
            digitalWrite(S_DATA, HIGH);
            //Serial.print('works'); //use for debugging
        } else {
            digitalWrite(S_DATA, LOW);
        }
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        delay(300);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
    }
}

void toDigits(int number) {
  if (number >= 0 && number < 10) {
    int a = 0 + number;
    return a;
  }
  return number;
}
*/


void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

void setup(){
    pinMode(S_CLK, OUTPUT);
    pinMode(S_LATCH, OUTPUT);
    pinMode(S_DATA, OUTPUT);
    Serial.begin(9600);

    // clearing all registers
    for (int i = 0; i < 33; i++){
        digitalWrite(S_DATA, LOW);
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
    }
    for (int i = 0; i < 4; i++){
        //dataToClock(null1[]);
    }
    for (int i = 0; i < 4; i++){
        //dataToClock(null2[]);
    }
}  


void loop(){

    tmElements_t tm;

    if (RTC.read(tm)) {
        Serial.print("Time = ");
        print2digits(tm.Hour);
        Serial.write(':');
        print2digits(tm.Minute);
        Serial.write(':');
        print2digits(tm.Second);
        Serial.print(", Date (D/M/Y) = ");
        Serial.print(tm.Day);
        Serial.write('/');
        Serial.print(tm.Month);
        Serial.write('/');
        Serial.print(tmYearToCalendar(tm.Year));
        Serial.println();
    } else {
        if (RTC.chipPresent()) {
            Serial.println('================================================');
            Serial.println("The DS1307 is stopped.");
            Serial.println('================================================');
            Serial.println();
        } else {
            Serial.println('================================================');
            Serial.println("DS1307 read error!  Please check the circuitry.");
            Serial.println('================================================');
            Serial.println();
        }
        delay(9000);
    }
    delay(1000);
}
/*
    if (RTC.read(tm)){

        if (tm.Hour == 1){
            dataToClock(one1);
        }
    }
}
/*
void aa(int a){
    for (int i = 0; i < length(toBin(a); i++){
        if (toBin(a)[i] == 1){
            digitalWrite(S_DATA, HIGH);
            digitalWrite(S_LATCH, HIGH);
            digitalWrite(S_LATCH, LOW);
        } else {
            digitalWrite(S_DATA, LOW);
            digitalWrite(S_LATCH, HIGH);
            digitalWrite(S_LATCH, LOW);
        }
    }
}

int one1 = 2;
int one2 = 8;
int two1 = 6;
int two2 = 12;
int three1 = 6;
int three2 = 13;
int four1 = 2;
int four2 = 11;
int five1 = 6;
int five2 = 7;
int six1 = 14;
int six2 = 7;
int seven1 = 2;
int seven2 = 12;
int eight1 = 14;
int eight2 = 16;
int nine1 = 2;
int nine2 = 16;

    //String a = String(13, BIN); // convert string to binary
    
    // output
    /*
    for (int g = 0; g < a.length(); g++){
        //Serial.println(a.substring(g, g + 1));
        String b = a.substring(g, g + 1);
        delay(300);
        digitalWrite(S_DATA, LOW);
        if (b == '1'){
            digitalWrite(S_DATA, HIGH);
        } else {
            digitalWrite(S_DATA, LOW);
        }
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
    }
}
*/


/* NOTES:
vaata üle `toInt()`
> case statements? -> goto statement? (to instructions, after goes to the start of the loop)
```switch (phase) {
   case 0: Lo(); break;
   case 1: Mid(); break;
   case 2: Hi(); break;
   default: Message("Invalid state!");
}```
> push data: 2nd segment(down) + 1st segment(down) + 3rd segment (down) + 4th segment(down) + 1st segment(up) + 2nd segment(up) + 3rd segment(up) + 4th segment(up)
*/