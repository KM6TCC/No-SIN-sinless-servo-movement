#include <Servo.h>

Servo servo1;
int lectura[5];
int N = 5;

void setup(){
  int i;
  servo1.attach(3);
  Serial.begin(9600);
  for(i=0;i<N;i++)
    lectura[i] = 0;
}

void loop() {
 
  int i,suma,promedio,salida;
 
//Se lee la señal del potenciómetro.
  for(i=0;i<N-1;i++)
    lectura[i] = lectura[i+1]; 
  lectura[N-1] = analogRead(A0);
  suma = 0;
  for(i=0;i<N;i++)
    suma += lectura[i];
  promedio = suma/N;
// Se escala la señal de 1024 niveles a 180 grados.
  salida = map(promedio, 0, 1023, 0, 179);
//  Se establece el valor del servo. 
  servo1.write(salida);
//Se envia la lectura por el puerto serial
  Serial.println(salida, DEC);
//  Reardo que establece la frecuencia de muestreo.
  delay(30);
}
