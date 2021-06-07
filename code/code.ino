#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define S_LATCH 11
#define S_CLK 12
#define S_DATA 10

tmElements_t tm;

String lastValue = "";     

bool getTime(const char *str){
  int Hour, Min, Sec;
  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;

  tm.Hour = Hour;
  tm.Minute = Min;
  tm.Second = Sec;
  return true;
}

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

void sendBit(int var1){
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

String substituteTo7Seg(String num, bool clockUpState, bool dotNeeded){
    // this function returns binary value of the called number
    for (int a = 0; a < (num.length()); a++){  
        if (clockUpState == true){  
            if (dotNeeded == true){
                switch (num.substring(a, a + 1).toInt()){
                case 1:
                return "0011";
                break;
                
                case 2:
                return "1101";
                break;

                case 3:
                return "0111";
                break;

                case 4:
                return "0011";
                break;

                case 5:
                return "0111";
                break;

                case 6:
                return "1111"; 
                break;

                case 7:
                return "0011";
                break;

                case 8:
                return "1111"; 
                break;

                case 9:
                return "0111";
                break;

                case 0: 
                return "1111";
                break;
                }
            } else {
                switch (num.substring(a, a + 1).toInt()){
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
                break;}
            
            }
        } else {
            switch (num.substring(a, a + 1).toInt()){
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

String createCode(int var_hourTen, int var_hour, int var_minTen, int var_min){

    String hourTenUp = substituteTo7Seg(String(var_hourTen), true, false);
    String hourTenDown = substituteTo7Seg(String(var_hourTen), false, false);

    String hourUp = substituteTo7Seg(String(var_hour), true, true);
    String hourDown = substituteTo7Seg(String(var_hour), false, true);
    
    String minUp =  substituteTo7Seg(String(var_min), true, false);
    String minDown =  substituteTo7Seg(String(var_min), false, false);
    
    String minTenUp = substituteTo7Seg(String(var_minTen), true, false);
    String minTenDown = substituteTo7Seg(String(var_minTen), false, false);
    
    // create the binary code for 7 segment display
    String code = hourDown + hourTenDown + minDown + minTenDown + minTenUp + minUp + hourTenUp + hourUp;
    return code;
}

void setup(){

    pinMode(S_CLK, OUTPUT);
    pinMode(S_LATCH, OUTPUT);
    pinMode(S_DATA, OUTPUT);
    Serial.begin(115200);


    // get the date and time the compiler was run
    if (getTime(__TIME__)){
        RTC.write(tm);
    }
    
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

    if (RTC.read(tm)) {
    
        String currentValue = createCode((int)(tm.Hour/10)%10, (int)(tm.Hour)%10, (int)(tm.Minute/10)%10, (int)(tm.Minute)%10);
        
        if (lastValue.toInt() != currentValue.toInt()){
            dataToClock(currentValue);
            sendBit(0);
            lastValue = currentValue;
        }

        delay(15000);

    } else {
        if (RTC.chipPresent()) {
            Serial.println("======================================================");
            Serial.println("                 The DS1307 has stopped.              ");
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
