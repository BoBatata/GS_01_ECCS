//Bibliotecas Utilizadas
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

//LiquidCystal - Variáveis
#define col 16
#define lin 2
#define ende 0x27

LiquidCrystal_I2C lcd(ende, col, lin);

//DHT - Variáveis
#define DHTPIN 2
#define DHTYPE DHT22

DHT dht(DHTPIN, DHTYPE);

float h = dht.readHumidity();
float t = dht.readTemperature();

//Distance Sensor - Variáveis
int trigger = 1;
int echo = 0;
int distance = 0;

//LEDs - Variáveis
int greenPin = 11;
int yellowPin = 12;
int redPin = 13;

//Buzzer - Variáveis
int buzzer = 7;


void setup() {
  //Definições de Pin Mode, Iniciação de DHT e LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  dht.begin();

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  //Chamada das Funções
  DistanceCheck();

  DhtHandler();

  DisplayHandler();
}

void DistanceCheck(){
  //Pulso do Sensor para medição de distancia
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  Serial.println(distance);
  distance = pulseIn(echo, HIGH);
  delay(200);
  //Conversão de distancia em Centimetros.
  distance = distance/58;
  //Chamada da função de controle das LEDs
  LevelLed();
}

void LevelLed(){
  //Condição das LEDs por distancia, quando acima de 300cm é chamado a função do Buzzer para ativar o alerta.
  if(distance > 300){
    digitalWrite(greenPin, 1);
    digitalWrite(yellowPin, 1);
    digitalWrite(redPin, 1);
    BuzzerAlert();
  }
  else if(distance > 200){
    digitalWrite(greenPin, 1);
    digitalWrite(yellowPin, 1);
    digitalWrite(redPin, 0);
  }
  else if(distance > 100){
    digitalWrite(greenPin, 1);
    digitalWrite(yellowPin, 0);
    digitalWrite(redPin, 0);
  }
  else if(distance < 100){
    digitalWrite(greenPin, 0);
    digitalWrite(yellowPin, 0);
    digitalWrite(redPin, 0);
  }
}

void BuzzerAlert(){
  //Ativação do buzzer(Alarme)
  tone(buzzer, 262, 250);
  Serial.println("Aviso Enviado!");
  delay(300);
}

void DisplayHandler(){
  //Display monstando as informações pegas pelo DHT, humidade, temperatura e distancia.
  lcd.setCursor(0,0);
  lcd.print(t);
  lcd.print(" -Celsius");

  lcd.setCursor(0,1);
  lcd.print("Humidade:");
  lcd.print(h);

  lcd.setCursor(0,2);
  lcd.print("Profundidade:");
  lcd.print(distance);
  delay(1000);
  lcd.clear();
}


void DhtHandler(){
  //Informações pega pela DHT e guardadas em váriaveis.
  h = dht.readHumidity();
  t = dht.readTemperature();
}