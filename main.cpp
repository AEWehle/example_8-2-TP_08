/*
PwmOut RGBLed[] = {(PB_4), (PA_0), (PD_12)};
ahora esta usando pwm}
por lo que ls clase pwmout le permite definir el periodo y dc mas comodo en el 
modulo brightcontrol

periodo 10ms dc 50%

es lo unico que cambia con respecto al 8.1
lightcontrol usa lightlevel para leer a0 y setear el dc con brightcontrol


en smarthomesystem agregamos un pin que este prendido 30ms de 100ms
usando  el delay de smarthomesystemupdate para comparar
un led que se prende a lo bruto
Esto tiene la contra de que es muy dependiente del resto del código 
y no es preciso
es por esto que es mas comodo y seguro usar interrupciones, y pwm para mas precision
*/

//=====[Libraries]=============================================================

#include "smart_home_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartHomeSystemInit();
    while (true) {
        smartHomeSystemUpdate();
    }
}