#include "Arduino.h"
//The setup function is called once at startup of the sketch
//lien entre l'ordinateur et le shield du SoftwareSerial
//9600 bps 8-N-1 (port série à 9600 bps, 8 bits de données, sans parité et avec 1 bit de stop)
//L'ordinateur est connecté au composant UART
//Le shield du SoftwareSerial est connecté au logiciel UART:D2&D3

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <I2C_LCD.h>

I2C_LCD LCD;
uint8_t I2C_LCD_ADDRESS = 0x51; //Device address configuration, the default value is 0x51.

// The TinyGPS++ object
TinyGPSPlus gps;

SoftwareSerial ss(2, 3);
unsigned char buffer[64]; // Tableau de mémoire tampon (buffer array) pour les données reçues par le port série
int count=0;     // compteur pour le buffer array

static void smartDelay(unsigned long ms);
static void printDateTime(TinyGPSDate &d, TinyGPSTime &t);


void setup()
{
	ss.begin(9600);               // initialisation du débit en bauds du SoftwareSerial à 9 600 bauds
	Serial.begin(9600);            		// initialisation du débit en bauds du port série d'Arduino à 9 600 bauds.
	Wire.begin();         //I2C controller initialization.

	LCD.CleanAll(WHITE);    //Clean the screen with black or white.
	delay(1000);            //Delay for 1s.

	//6*8 font size, auto new line, black character on white back ground.
	LCD.FontModeConf(Font_6x8, FM_ANL_AAA, BLACK_BAC);
}

void loop()
{
	//Set the start coordinate.
	LCD.CharGotoXY(0,0);

	printDateTime(gps.date, gps.time);
	LCD.println(" ");

	if(gps.satellites.isValid())
	{
		LCD.print("Nb de satellites");
		LCD.println(gps.satellites.value(),5);
	}
	if (gps.hdop.isValid())
	{
		LCD.print("Hdop = ");
		LCD.println(gps.hdop.value(),5);
	}
	if (gps.location.isValid())
	{
		LCD.print("Lattitude = ");
		LCD.println(gps.location.lat(),6);
		LCD.print("Longitude = ");
		LCD.println(gps.location.lng(),6);
	}

	if(gps.altitude.isValid())
	{
		LCD.print("Altitude = ");
		LCD.println(gps.altitude.meters());
	}


	smartDelay(1000);

	if (millis() > 5000 && gps.charsProcessed() < 10)
		LCD.println("No GPS data received: check wiring");
}

// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
	unsigned long start = millis();
	do
	{
		while (ss.available())
			gps.encode(ss.read());
	} while (millis() - start < ms);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
	if (!d.isValid())
	{

	}
	else
	{
		char sz[32];
		sprintf(sz, "%02d/%02d/%02d ", d.day(), d.month(), d.year());
		LCD.print(sz);
	}

	if (!t.isValid())
	{

	}
	else
	{
		char sz[32];
		sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
		LCD.println(sz);
	}
	smartDelay(0);
}
