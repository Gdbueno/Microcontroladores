#include <LiquidCrystal.h>  // Libreria para lcd.
LiquidCrystal lcd(7,6,5,4,3,2);  // Asigno pines
const int TMP36Pin=A0; //Conexion de pin central.
const int LedRojo =9; // Asigno pin para led de rojo.
const int LedVerde =10; // Asigno pin para led verde.
const int Rele =11; // Asigno pin para rele de salida.
const int PotenciometroPin=A1; // Potenciometro.
float temperatura = 0; // Variable para la temperatura medida.
float temperaturaselec=0; // Variable para temperatura seleccionada.
// Configuracion
void setup(){
  lcd.begin(16,2); // Inicializaciòn lcd.
  Serial.begin(9600); // Configuro la conexion con la pc.
  pinMode(LedRojo,OUTPUT); // Configuro led como salida.
  pinMode(LedVerde,OUTPUT); // Configuro led como salida.
  pinMode(Rele,OUTPUT); // Configuro rele como salida.
}
// Bucle del programa.
void loop() {
  int lectura = analogRead(TMP36Pin); // Valor 0 - 1023.
  float voltaje= lectura * 5.0/1024.0; // Voltaje 0 - 5V.
    temperatura = (voltaje - 0.5) * 100; // Temperatura en centigrados.
  	int valorpotenciometro = analogRead(PotenciometroPin); // 0 - 1023.
  	float voltajepotenciometro= valorpotenciometro * 5.0 / 1024.0; // Voltaje 0 -5V.
  	temperaturaselec = (voltajepotenciometro - 0.5) * 30; // Rango seleccionable -15/130°C.
    Serial.print("Temperatura:");
    Serial.print(temperatura); // Muestro el valor de temperatura.
    Serial.print("C");
  	Serial.print("temperaturaSelec:");
  	Serial.print(temperaturaselec); // Muestro temperatura seleccionada.
  	Serial.print("C");
	if (temperatura>temperaturaselec) { //Si la temp. supera la temp. selec.
  	digitalWrite(LedRojo,LOW); // Apago led rojo.
    digitalWrite(LedVerde,HIGH); // Enciendo led verde.
    digitalWrite(Rele,HIGH);  // Activo rele.
  	Serial.print("ACTIVADO");
	}else {
  	digitalWrite(LedRojo,HIGH); // Enciendo led rojo.
    digitalWrite(LedVerde,LOW); // Apago led verde.
    digitalWrite(Rele,LOW);  // Desactivo rele.
  	Serial.println("DESACTIVADO");
	}
  	lcd.setCursor(0,0);
  	lcd.print("Set:");
  	lcd.print(temperaturaselec); // Muestro en lcd temp. selec.
  lcd.setCursor (15,0);
  	lcd.print ("C");
  	lcd.setCursor(0,2);
  	lcd.print("Act:");
  	lcd.print(temperatura); // Muestro en lcd temp. actual.
  	lcd.setCursor(15,2);
  	lcd.print ("C");
}
// Realizado por Bueno Guillermo - Pto. Mardryn - Chubut.
// guillermodavidbueno@gmail.com
