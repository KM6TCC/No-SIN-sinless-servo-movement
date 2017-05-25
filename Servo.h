#include <Servo.h>


Servo servo1;
int lectura;

void setup(){
  servo1.attach(3);
  Serial.begin(9600);
}

void loop() {
//Se lee la señal del potenciómetro.
  lectura = analogRead(A0);
// Se escala la señal de 1024 niveles a 180 grados.
  lectura = map(lectura, 0, 1023, 0, 179);
//  Se establece el valor del servo. 
  servo1.write(lectura);
//Se envia la lectura por el puerto serial
  Serial.println(lectura, DEC);
//  Reardo que establece la frecuencia de muestreo.
  delay(30);
}
