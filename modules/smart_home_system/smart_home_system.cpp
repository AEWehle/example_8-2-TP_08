//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "smart_home_system.h"

#include "alarm.h"
#include "user_interface.h"
#include "fire_alarm.h"
#include "intruder_alarm.h"
#include "pc_serial_com.h"
#include "event_log.h"
#include "motion_sensor.h"
#include "motor.h"
#include "gate.h"
#include "light_system.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

// aca queremos prender y apagar un led sin usar las interrupciones
static int tickcounter = 0;
static int dutycycle = 3; //30ms
DigitalOut led_aux(D7);


//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void smartHomeSystemInit()
{
    userInterfaceInit();
    alarmInit();
    fireAlarmInit();
    intruderAlarmInit();
    pcSerialComInit();
    motorControlInit();
    gateInit();
    lightSystemInit();
    led_aux =  ON;
}


void smartHomeSystemUpdate()
{
    userInterfaceUpdate();
    fireAlarmUpdate();
    intruderAlarmUpdate();
    alarmUpdate();
    eventLogUpdate();
    pcSerialComUpdate();
    motorControlUpdate();
    lightSystemUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);

    // un led que se prende a lo bruto
    // Esto tiene la contra de que es muy dependiente del resto del código 
    //y no es preciso
    //es por etso que es mas comodo y seguro usar interrupciones, y pwm para mas precision
    tickcounter++;
    if (tickcounter > dutycycle) { // paso 0.03 segundos
        led_aux =  OFF;
        if (tickcounter == 10)  tickcounter = 0;
    } else {
        led_aux =  ON;
    }
}

//=====[Implementations of private functions]==================================
