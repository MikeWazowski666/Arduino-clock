#define S_LATCH 11
#define S_CLK 12
#define S_DATA 10
#define SDA A4
#define SCL A5

/*
void toBin(String b){
    String a = String(b, BIN);
    return a
}
*/
char myStr[] = "this is a test";

void setup(){
    pinMode(S_CLK, OUTPUT);
    pinMode(S_LATCH, OUTPUT);
    pinMode(S_DATA, OUTPUT);
    Serial.begin(9600);
    String a = String(13, BIN); // convert string to binary
    //Serial.println(a.length());
    
    // clearing all registers
    
    for (int i = 0; i < 32; i++){
        digitalWrite(S_DATA, LOW);
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
    }
    
    for (byte i = 0; i < sizeof(myStr) - 1; i++) {
      Serial.print(i, DEC);
        Serial.print(" = ");
        Serial.write(myStr[i]);
        Serial.println();
    }

        /*
    digitalWrite(S_DATA, LOW);
    digitalWrite(S_LATCH, HIGH);
    digitalWrite(S_LATCH, LOW);
    digitalWrite(S_CLK, HIGH);
    digitalWrite(S_CLK, LOW);
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
    */
}

byte one1 = 0b0010;
byte one2 = 0b1000;
byte two1 = 0b0110;
byte two2 = 0b1100;
byte three1 = 0b0110;
byte three2 = 0b1101;
byte four1 = 0b0010;
byte four2 = 0b1011;
byte five1 = 0b0110;
byte five2 = 0b0111;
byte six1 = 0b1110;
byte six2 = 0b0111;
byte seven1 = 0b0010;
byte seven2 = 0b1100;
byte eight1 = 0b1110;
byte eight2 = 0b1111;
byte nine1 = 0b0010;
byte nine2 = 0b1111;


void loop(){}
    /*
    // crates a nice small loop

    for (int i = 0; i < 32; i++){
        digitalWrite(S_DATA, HIGH);
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
        delay(400);
    }
    for (int l = 0; l < 32; l++){
        digitalWrite(S_DATA, LOW);
        digitalWrite(S_LATCH, HIGH);
        digitalWrite(S_LATCH, LOW);
        digitalWrite(S_CLK, HIGH);
        digitalWrite(S_CLK, LOW);
        delay(400);
    }
}
/*

esimene nr = 0b0011 + offset + 0b1000



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





vaata üle `toInt()`


*/