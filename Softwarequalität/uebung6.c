/*
 * Musterlösung zu Übung 6: Typischerheit durch Strukturdefinition
 */
#include <stdio.h>

typedef struct {
    int t;
} temp_f;

typedef struct {
    int t;
} temp_c;

/* gibt 0 zurück, wenn kein Frost vorherrscht, ansonsten eine 1 */
unsigned int isFrost( temp_f temperature )
{
    /* gets the temperature and returns frost condition */
    /* when temperature is below 32degFahrenheit */
    if( temperature.t <= 32 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main( void )
{
    temp_c temperatur;
    temperatur.t = 32; /* Temperatur in GradCelsius */
 
    if( isFrost( temperatur ) == 1 )
    {
        printf("Wir haben Frost!");
    }
}
