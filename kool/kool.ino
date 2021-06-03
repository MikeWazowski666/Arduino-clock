#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define S_LATCH 11
#define S_CLK 12
#define S_DATA 10
#define SDA A4
#define SCL A5

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
byte concat(byte a, byte b){
    String s1 = String(a);
    String s2 = String(b);
    Serial.println("s1 = " + s1);
    Serial.println("s2 = " + s2);
    String s3 = s1 + s2;
    Serial.println("s3 = " + s3);
    byte c = s3.toInt();
    return c;
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


byte one[]   = {0, 0, 1, 0, 1, 0, 0, 0};
byte two[]   = {1, 1, 0, 0, 1, 1, 0, 1};
byte three[] = {0, 1, 1, 0, 1, 1, 0, 1}; 
byte four[]  = {0, 0, 1, 0, 1, 0, 1, 1}; 
byte five[]  = {0, 1, 1, 0, 0, 1, 1, 1}; 
byte six[]   = {1, 1, 1, 0, 0, 1, 1, 1}; 
byte seven[] = {0, 0, 1, 0, 1, 1, 0, 0}; 
byte eight[] = {1, 1, 1, 0, 1, 1, 1, 1}; 
byte nine[]  = {0, 1, 1, 0, 1, 1, 1, 1}; 
byte null[]  = {1, 1, 1, 0, 1, 1, 1, 1};

byte toBytes(int var1){
    String a = String(var1);
//    Serial.println(var1);
//    Serial.println(a.length());
//    Serial.println(sizeof(a));
    for (int t = 0; t < (a.length()); t++){
//        Serial.println(a.substring(t, t + 1)); 
        switch (a.substring(t, t + 1).toInt()){
            case 1:
            byte extVal = {0, 0, 1, 0, 1, 0, 0, 0};
            break;
            
            case 2:
            byte extVal = {1, 1, 0, 0, 1, 1, 0, 1};
            break;

            case 3:
            byte extVal = {0, 1, 1, 0, 1, 1, 0, 1};
            break;

            case 4:
            byte extVal = {0, 0, 1, 0, 1, 0, 1, 1}; 
            break;

            case 5:
            byte extVal = {0, 1, 1, 0, 0, 1, 1, 1};
            break;

            case 6:
            byte extVal = {1, 1, 1, 0, 0, 1, 1, 1}; 
            break;

            case 7:
            byte extVal = {0, 0, 1, 0, 1, 1, 0, 0};
            break;

            case 8:
            byte extVal = {1, 1, 1, 0, 1, 1, 1, 1}; 
            break;

            case 9:
            byte extVal = {0, 1, 1, 0, 1, 1, 1, 1}; 
            break;

            case 0: 
            byte extVal = {1, 1, 1, 0, 1, 1, 1, 0};
            break;
        }
    }
    return extVal;
}

void pushData(int hourTen[], int hour[], int minTen[], int min[]){
    int data[];
    data = {hour[0], hour[1], hour[2], hour[3], hourTen[0], hourTen[1], hourTen[2], hourTen[3], min[0], min[1], min[2], min[3], minTen[0], minTen[1], minTen[2], minTen[3], minTen[4], minTen[5], minTen[6], minTen[7], min[4], min[5], min[6], min[7], hourTen[4], hourTen[5], hourTen[6], hourTen[7], hour[4], hour[5], hour[6], hour[7]};
}

void setup(){
    pinMode(S_CLK, OUTPUT);
    pinMode(S_LATCH, OUTPUT);
    pinMode(S_DATA, OUTPUT);
    Serial.begin(115200);

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
            tempFunc(nine[a]);
        }
    }

    Serial.println("------------");
   // Serial.print(toBytes(10));
    Serial.print(toBytes(10));
   // Serial.println(concat(0x10, 0x01));

    tempFunc(0);
    delay(1000);
    Serial.println("endl");
}  


void loop(){}
/*
    tmElements_t tm;

    if (RTC.read(tm)) {
        //print2digits(tm.Hour);
        Serial.print(tm.Hour);
        Serial.write('(');
        toBytes(tm.Hour);
        Serial.print(toBytes(tm.Hour));
        Serial.write(')');
        Serial.write(':');
        //print2digits(tm.Minute);
        Serial.print(tm.Minute);
        Serial.write(':');
        //print2digits(tm.Second);
        Serial.print(tm.Second);
        Serial.write('(');
        toBytes(tm.Second);
        Serial.print(toBytes(tm.Second));
        Serial.write(')');
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

void get_time(){

    tmElements_t tm;
    if (RTC.read(tm)) {
        //print2digits(tm.Hour);
        Serial.print(tm.Hour);
        Serial.write('(');
        toBytes(tm.Hour);
        Serial.print(toBytes(tm.Hour));
        Serial.write(')');
        Serial.write(':');
        //print2digits(tm.Minute);
        Serial.print(tm.Minute);
        Serial.write(':');
        //print2digits(tm.Second);
        Serial.print(tm.Second);
        Serial.write('(');
        toBytes(tm.Second);
        Serial.print(toBytes(tm.Second));
        Serial.write(')');
        Serial.println();
}

/* NOTES:

1. get time
2. time to byte array (7-segment code)
3. byte array to byte
4. sorting for output
` output = {array1[0], array[1],...}`
5. push data

> case statements? -> goto statement? (to instructions, after goes to the start of the loop)
```switch (phase) {
   case 0: Lo(); break;
   case 1: Mid(); break;
   case 2: Hi(); break;
   default: Message("Invalid state!");
}```
> push data: 2nd segment(down) + 1st segment(down) + 4th segment (down) + 3rd segment(down) + 2nd segment(up) + 1st segment(up) + 4th segment(up) + 3rd segment(up)
*/