#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define S_LATCH 11
#define S_CLK 12
#define S_DATA 10
#define SDA A4
#define SCL A5

byte one1[]   = {0, 0, 1, 0}; 
byte one2[]   = {1, 0, 0, 0}; 
byte two1[]   = {1, 1, 0, 0};
byte two2[]   = {1, 1, 0, 1};
byte three1[] = {0, 1, 1, 0}; 
byte three2[] = {1, 1, 0, 1}; 
byte four1[]  = {0, 0, 1, 0}; 
byte four2[]  = {1, 0, 1, 1}; 
byte five1[]  = {0, 1, 1, 0}; 
byte five2[]  = {0, 1, 1, 1}; 
byte six1[]   = {1, 1, 1, 0}; 
byte six2[]   = {0, 1, 1, 1}; 
byte seven1[] = {0, 0, 1, 0}; 
byte seven2[] = {1, 1, 0, 0}; 
byte eight1[] = {1, 1, 1, 0}; 
byte eight2[] = {1, 1, 1, 1}; 
byte nine1[]  = {0, 1, 1, 0}; 
byte nine2[]  = {1, 1, 1, 1}; 
byte null1[]  = {1, 1, 1, 0};
byte null2[]  = {1, 1, 1, 1};
byte one[]    = {0, 0, 1, 0, 1, 0, 0, 0};
byte nine[]  = {0, 1, 1, 0, 1, 1, 1, 1};

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
    return 0;
}
*/

int toDigits(int number) {
  if (number >= 0 && number < 10) {
    String a = '0' + String(number);
    int b = a.toInt();
    return b;
  }
  return number;
}


void tempFunc(int var1){
    if (var1 == 1){
        digitalWrite(S_DATA, HIGH);
    } else {
        digitalWrite(S_DATA, LOW);
    }
    digitalWrite(S_LATCH, HIGH);
    digitalWrite(S_LATCH, LOW);
    digitalWrite(S_CLK, HIGH);
    digitalWrite(S_CLK, LOW);
    return;
}

void toBytes(int var1){
    switch (var1){
        case 1:
        return (0x28);
        break;
        
        case 2:
        return (0xcd);
        break;

        case 3:
        return (0x6d);
        break;

        case 4:
        return (0x2b);
        break;

        case 5:
        return (0x67);
        break;

        case 6:
        return (0xe7);
        break;

        case 7:
        return (0x2c);
        break;

        case 8:
        return (0xef);
        break;

        case 9:
        return (0x6e);
        break;

        default:
        return (0xee);
        break;
    }
}

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
    for (int i = 0; i < 36; i++){
        digitalWrite(S_DATA, LOW);
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
    }

    // only for demo usage
    for (int i = 0; i < 4; i++){
    
       /*
        for (int a = 0; a < sizeof(one1); a++){
            tempFunc(two2[a]);
        }
    }
    for (int i = 0; i < 4; i++){
    
       for (int a = 0; a < sizeof(one1); a++){
            tempFunc(two1[a]);
        }
        */
        for (int a = 0; a < sizeof(nine); a++){
            tempFunc(nine);
        }
    }
    tempFunc(0);

    delay(1000);
}  


void loop(){

    tmElements_t tm;

    if (RTC.read(tm)) {
        //print2digits(tm.Hour);
        Serial.print(toDigits(tm.Hour));
        Serial.write(':');
        //print2digits(tm.Minute);
        Serial.print(toDigits(tm.Minute));
        Serial.write(':');
        //print2digits(tm.Second);
        Serial.print(toDigits(tm.Second));
        Serial.println();
    } else {
        if (RTC.chipPresent()) {
            Serial.println('======================================================');
            Serial.println("                  The DS1307 is stopped.              ");
            Serial.println('======================================================');
            Serial.println();
        } else {
            Serial.println('======================================================');
            Serial.println("    DS1307 read error!  Please check the circuitry.   ");
            Serial.println('======================================================');
            Serial.println();
        }
        delay(1000);
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

/*
    for (int i = 0; i < 32; i++){
        digitalWrite(S_DATA, HIGH);
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
        delay(400);
    }
    for (int i = 0; i < 32; i++){
        digitalWrite(S_DATA, LOW);
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
        delay(400);
    }
}

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
> push data: 2nd segment(down) + 1st segment(down) + 4th segment (down) + 3rd segment(down) + 2nd segment(up) + 1st segment(up) + 4th segment(up) + 3rd segment(up)
*/