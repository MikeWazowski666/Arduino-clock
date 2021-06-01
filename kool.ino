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

void loop(){}
    
    // crates a nice small loop

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


byte one1 = 0b




vaata üle `toInt()`


*/