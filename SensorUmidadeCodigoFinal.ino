

// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x3F // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2
#define led 13
int valor;
int valor2;

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  

  lcd.clear(); // LIMPA O DISPLAY
  pinMode(led,OUTPUT);
  
  
  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
  Serial.begin(9600);
  
}

void loop() {

  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("");

   //Le o valor do pino A0 do sensor
  valor = analogRead(A0);
  int novo_valor = map(valor,240,400,30,15);
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica A0: ");
  Serial.println(valor);
   Serial.print("Map A0: ");
  Serial.println(novo_valor);

  
   //Le o valor do pino A2 do sensor
  valor2 = analogRead(A2);
  int novo_valor2 = map(valor2,240,400,30,15);
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica A2: ");
  Serial.println(valor2);
   Serial.print("Map A2: ");
  Serial.println(novo_valor2);

    Serial.println(" Status Solo: ");
    lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
    lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
    lcd.clear(); // LIMPA O DISPLAY
    lcd.print("Sensor 1:");
    lcd.print(novo_valor);
    lcd.print("%");
    lcd.setCursor(2, 1);
    lcd.print(valor);
    delay(2000);
    
    Serial.println(" Status Solo: ");
    lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
    lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
    lcd.clear(); // LIMPA O DISPLAY
    lcd.print("Sensor 2:");
    lcd.print(novo_valor2);
    lcd.print("%");
    lcd.setCursor(2, 1);
    lcd.print(valor2);
    delay(2000);
 
}
