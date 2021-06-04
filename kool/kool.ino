#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define S_LATCH 11
#define S_CLK 12
#define S_DATA 10
#define SDA A4
#define SCL A5
#define LEN 8



void dataToClock(String val1){
    for (int i = 0; i < (int) val1.length(); i++){
        String charecter = val1.substring(i, i + 1);
        if (charecter == "1"){
            digitalWrite(S_DATA, HIGH);
        } else {
            digitalWrite(S_DATA, LOW);
        }
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
    }
    return;
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

int concat(int a, int b){
    String s1 = String(a);
    String s2 = String(b);
    Serial.println("s1 = " + s1);
    Serial.println("s2 = " + s2);
    String s3 = s1 + s2;
    Serial.println("s3 = " + s3);
    int c = s3.toInt();
    return c;
}


String substituteTo7Seg(String a, bool clockDown){
    for (int t = 0; t < (a.length()); t++){  
        if (clockDown == true){  
            switch (a.substring(t, t + 1).toInt()){
                case 1:
                return "0010";
                break;
                
                case 2:
                return "1100";
                break;

                case 3:
                return "0110";
                break;

                case 4:
                return "0010";
                break;

                case 5:
                return "0110";
                break;

                case 6:
                return "1110"; 
                break;

                case 7:
                return "0010";
                break;

                case 8:
                return "1110"; 
                break;

                case 9:
                return "0110";
                break;

                case 0: 
                return "1110";
                break;
            }
        } else {
            switch (a.substring(t, t + 1).toInt()){
                case 1:
                return "1000";
                break;
                
                case 2:
                return "1101";
                break;

                case 3:
                return "1101";
                break;

                case 4:
                return "1011";
                break;

                case 5:
                return "0111";
                break;

                case 6:
                return "0111"; 
                break;

                case 7:
                return "1100";
                break;

                case 8:
                return "1111"; 
                break;

                case 9:
                return "1111";
                break;

                case 0: 
                return "1110";
                break;
            }
        }
    }  
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
byte null[]  = {1, 1, 1, 0, 1, 1, 1, 0};



String createCode( int var_hourTen, int var_hour, int var_minTen, int var_min ){

    String hourTenUp = substituteTo7Seg(String(var_hourTen), true);
    String hourTenDown = substituteTo7Seg(String(var_hourTen), false);

    String hourUp = substituteTo7Seg(String(var_hour), true);
    String hourDown = substituteTo7Seg(String(var_hour), false);
    
    String minUp =  substituteTo7Seg(String(var_min), true);
    String minDown =  substituteTo7Seg(String(var_min), false);
    
    String minTenUp = substituteTo7Seg(String(var_minTen), true);
    String minTenDown = substituteTo7Seg(String(var_minTen), false);
    
    String code = hourDown + hourTenDown + minDown + minTenDown + minTenUp + minUp + hourTenUp + hourUp;
    
    return code;
    //Serial.println(String(toBytes(var_hourTen, hourTen)));
    //Serial.println(String(toBytes(var_min, min)));
    //Serial.println(String(toBytes(var_minTen, minTen)));
    /*
    for (int t = 0; t < (a.length()); t++){
        
        switch (a.substring(t, t + 1).toInt()){
            case 1:
            byte one[]   = {0, 0, 1, 0, 1, 0, 0, 0};
            /*
            array[0] = 0;
            array[1] = 0;
            array[2] = 1;
            array[3] = 0;
            array[4] = 1;
            array[5] = 0;
            array[6] = 0;
            array[7] = 0;
            
            break;
            
            case 2:
            byte two[]   = {1, 1, 0, 0, 1, 1, 0, 1};
            /*
            array[0] = 1;
            array[1] = 1;
            array[2] = 0;
            array[3] = 0;
            array[4] = 1;
            array[5] = 1;
            array[6] = 0;
            array[7] = 1;
            break;

            case 3:
            byte three[] = {0, 1, 1, 0, 1, 1, 0, 1}; 
            /*
            array[0] = 0;
            array[1] = 1;
            array[2] = 1;
            array[3] = 0;
            array[4] = 1;
            array[5] = 1;
            array[6] = 0;
            array[7] = 1;
            break;

            case 4:
            byte four[]  = {0, 0, 1, 0, 1, 0, 1, 1}; 
            /*
            array[0] = 0;
            array[1] = 0;
            array[2] = 1;
            array[3] = 0;
            array[4] = 1;
            array[5] = 0;
            array[6] = 1;
            array[7] = 1;
            break;

            case 5:
            byte five[]  = {0, 1, 1, 0, 0, 1, 1, 1}; 
            /*
            array[0] = 0;
            array[1] = 1;
            array[2] = 1;
            array[3] = 0;
            array[4] = 0;
            array[5] = 1;
            array[6] = 1;
            array[7] = 1;
            break;

            case 6:
            byte six[]   = {1, 1, 1, 0, 0, 1, 1, 1}; 
            /*
            array[0] = 1;
            array[1] = 1;
            array[2] = 1;
            array[3] = 0;
            array[4] = 0;
            array[5] = 1;
            array[6] = 1;
            array[7] = 1;
            break;

            case 7:
            byte seven[] = {0, 0, 1, 0, 1, 1, 0, 0}; 
            /*
            array[0] = 0;
            array[1] = 0;
            array[2] = 1;
            array[3] = 0;
            array[4] = 1;
            array[5] = 1;
            array[6] = 0;
            array[7] = 0;
            break;

            case 8:
            byte eight[] = {1, 1, 1, 0, 1, 1, 1, 1}; 
            /*
            array[0] = 1;
            array[1] = 1;
            array[2] = 1;
            array[3] = 0;
            array[4] = 1;
            array[5] = 1;
            array[6] = 1;
            array[7] = 1;
            break;

            case 9:
            byte nine[]  = {0, 1, 1, 0, 1, 1, 1, 1}; 
            /*
            array[0] = 0;
            array[1] = 1;
            array[2] = 1;
            array[3] = 0;
            array[4] = 1;
            array[5] = 1;
            array[6] = 1;
            array[7] = 1;
            break;

            case 0: 
            byte null[]  = {1, 1, 1, 0, 1, 1, 1, 1};
            /*
            array[0] = 1;
            array[1] = 1;
            array[2] = 1;
            array[3] = 0;
            array[4] = 1;
            array[5] = 1;
            array[6] = 1;
            array[7] = 0;
            break;
        }
        */
    //{hour[0], hour[1], hour[2], hour[3], hourTen[0], hourTen[1], hourTen[2], hourTen[3], min[0], min[1], min[2], min[3], minTen[0], minTen[1], minTen[2], minTen[3], minTen[4], minTen[5], minTen[6], minTen[7], min[4], min[5], min[6], min[7], hourTen[4], hourTen[5], hourTen[6], hourTen[7], hour[4], hour[5], hour[6], hour[7]};
    //String data = String(hour[0]), String(hour[1]), String(hour[2]), String(hour[3]), String(hourTen[0]), String(hourTen[1]), String(hourTen[2]), String(hourTen[3]), String(hour[0]), String(hour[1]), String(hour[2]), String(hour[3]), String(hourTen[0]), String(hourTen[1]), String(hourTen[2]), String(hourTen[3]), String(hourTen[4]), String(hourTen[5]), String(hourTen[6]), String(hourTen[7]), String(hour[4]), String(hour[5]), String(hour[6]), String(hour[7]), String(hourTen[4]), String(hourTen[5]), String(hourTen[6]), String(hourTen[7]), String(hour[4]), String(hour[5]), String(hour[6]), String(hour[7]);
    //  creates the instructions for 7 segment displays
    //Serial.println(data);
    //dataToClock();
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
}


void loop(){
    tmElements_t tm;
    
    String lastValue = "";

    if (RTC.read(tm)) {
        
        String currentValue = createCode((int)(tm.Hour/10)%10, (int)(tm.Hour)%10, (int)(tm.Minute/10)%10, (int)(tm.Minute)%10);
        delay(1000);
        
        if (lastValue != currentValue){
            dataToClock(currentValue);
            tempFunc(0);
            lastValue = currentValue;
        }else{}
    } else {
        if (RTC.chipPresent()) {
            Serial.println("======================================================");
            Serial.println("                  The DS1307 is stopped.              ");
            Serial.println("======================================================");
            Serial.println();
        } else {
            Serial.println("======================================================");
            Serial.println("    DS1307 read error!  Please check the circuitry.   ");
            Serial.println("======================================================");
            Serial.println();
        }
        delay(1000);
    }
    delay(1000);
}

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
        //toBytes(tm.Hour);
        //Serial.print(toBytes(tm.Hour));
        Serial.write(')');
        Serial.write(':');
        //print2digits(tm.Minute);
        Serial.print(tm.Minute);
        Serial.write(':');
        //print2digits(tm.Second);
        Serial.print(tm.Second);
        Serial.write('(');
        //toBytes(tm.Second);
        //Serial.print(toBytes(tm.Second));
        Serial.write(')');
        Serial.println();
    }
}

/* NOTES:

1. get time
2. time to byte array (7-segment code)
3. byte array to byte
4. sorting for output
` output = {array1[0], array[1],...}`
5. push data

> case statements? -> goto statement? (to instructions, after goes to the start of the loop)
> push data: 2nd segment(down) + 1st segment(down) + 4th segment (down) + 3rd segment(down) + 2nd segment(up) + 1st segment(up) + 4th segment(up) + 3rd segment(up)
*/