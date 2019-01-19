#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, 6, NEO_GRB + NEO_KHZ800);
int ENA=9; //Connecté à Arduino pin 9(sortie PWM) 
int IN1=4; //Connecté à Arduino pin 4 
int IN2=5; //Connecté à Arduino pin 5
int i=0;
int n=25;
void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  Serial.begin(9600);
  pinMode(ENA,OUTPUT); // Configurer 
 // les broches 
  pinMode(IN1,OUTPUT); // comme sortie 
  pinMode(IN2,OUTPUT);  
}

void loop() {
  analogWrite(ENA,200);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  delay(1000);   
  while(i < n) { // On fait une boucle pour définir la couleur de chaque led
        // setPixelColor(n° de led, Rouge, Vert, Bleu)
    strip.setPixelColor(i, random(0, 223), random(0, 223), random(0, 223));       
    strip.show(); // on affiche 
    delay(100);
    i=i+2;
    
  }
}
