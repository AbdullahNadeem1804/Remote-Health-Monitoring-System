/*
 * IoT.h
 *
 *  Created on: May 14, 2023
 *      Author: dell
 */

#ifndef IOT_H_
#define IOT_H_
#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;

class IoT {
private:
	float OxySat , Pulse , HandTremors , Falls , Position;
public:
	IoT(float O=0 ,float P=0 ,float HT=0 ,float f=0 ,float p=0)
	{
		OxySat = O;
		Pulse = P;
		HandTremors = HT;
		Falls = f;
		Position = p;
	}


void  UpdateApp()
{
	srand(time(0));
	OxySat = rand() % (100 - 85 +1 )+85; // if less then 90 then alert , it cant be more than 100.
	//cout << "\n 1. OxygenSaturation: " << OxySat;
	Pulse = rand() % (120/*standard 100*/ - 40/*standard 60*/ +1 )+40; //  if greater than 100 then alert same with 60
	//cout << "\n 2. Pulse: " << Pulse;
	HandTremors = rand() % 5 + 1 ;//If they are till 2 then its normal, if more than 2 then abnormal
	//cout << "\n 3. HandTremors: " << HandTremors;
	Falls = rand() % 5;//per year calculated
	//cout << "\n 4. Falls: " << Falls;
	Position = rand() % (25 - 10 + 1 ) + 10; //Patient head with the bed should be from 15 to 20 degrees angle.
	//cout << "\n 5. Position: " << Position;
}
//send the values of devices to the app which then only encrypts them
//and send to rmcc which stores the cnrypted onto the cloud using indexes.
//when doctor wants too see it, rmcc decrypts it and shows him the data of the patient.
//also check authorization too using the static variable to check the patient number.

 ~IoT()
{

}

float  getFalls() const {
	return Falls;
}

void  setFalls(float falls) {
	Falls = falls;
}

float  getHandTremors() const {
	return HandTremors;
}

void  setHandTremors(float handTremors) {
	HandTremors = handTremors;
}

float  getOxySat() const {
	return OxySat;
}

void  setOxySat(float oxySat) {
	OxySat = oxySat;
}

float  getPosition() const {
	return Position;
}

void  setPosition(float position) {
	Position = position;
}

float  getPulse() const {
	return Pulse;
}

void  setPulse(float pulse) {
	Pulse = pulse;
}

};

#endif /* IOT_H_ */
