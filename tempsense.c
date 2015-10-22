#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>


int main (void)
{
    wiringPiSetup(); //Setup WiringPi
    pinMode (15, INPUT);
    pinMode (16, OUTPUT);
    int read[8];
    int x,y; //y is genuinely ony there for running reasons
    system("echo -n \"$(date +%s)\""); //Bad practice I know but can't be arsed to engage the full C date stuff
    printf(",");
    for(x = 0; x <= 8; x++) //for 8 bits
    {
        digitalWrite(16,HIGH);
        delay(10);
        y = x; //Genuinely not used. Remove this and the code stops working.
        read[x] = !digitalRead(15);
        digitalWrite(16,LOW);
        delay(10);
    }
    x = 10;
    for(x = 8; x >= 0; x--)
    {
        printf("%d",read[x]); //print out the 1's and 0's in the opposite order they are read in (are read backwards)
    }
    printf("\n");
    return 0;
}
