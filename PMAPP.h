/*
 * PMAPP.h
 *
 *  Created on: May 14, 2023
 *      Author: dell
 */

#ifndef PMAPP_H_
#define PMAPP_H_
#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
#include"IoT.h"
#include"Encryption.h"
#include"EHR.h"
using namespace std;

class PM_APP:public EHR
{
	IoT I;
	float o,p,h,f,pos;
public:
	char o_encr , p_encr , h_encr , f_encr , pos_encr;
	PM_APP(float O=0 ,float P=0 ,float HT=0 ,float f=0 ,float p=0):I(O,P,HT,f,p)
	{}
	void UpdatingApp()
	{
		I.UpdateApp();
		Encryptor<float> float1;
		o = I.getOxySat(), p = I.getPulse() , h = I.getHandTremors() , f = I.getFalls() , pos = I.getPosition();

//		cout << "\n o = " << o;
//		cout << "\n p = " << p;
//		cout << "\n h = " << h;
//		cout << "\n f = " << f;
//		cout << "\n pos = " << pos << endl;

		float1.Encrypt(o, o_encr);
		float1.Encrypt(p,p_encr);
		float1.Encrypt(h,h_encr);
		float1.Encrypt(f,f_encr);
		float1.Encrypt(pos,pos_encr);

//		float o_decr , p_decr , h_decr , f_decr , pos_decr;
//		float1.Decrypt(o_encr, o_decr);
//		float1.Decrypt(p_encr, p_decr);
//		float1.Decrypt(h_encr, h_decr);
//		float1.Decrypt(f_encr, f_decr);
//		float1.Decrypt(pos_encr, pos_decr);
//
//		//Encryption
//
//
//		cout << "\n o_encr : " << o_encr << endl;
//		cout << "\n o_decr : " << o_decr << endl;
//		cout << "\n p_encr : " << p_encr << endl;
//		cout << "\n p_decr : " << p_decr << endl;
//		cout << "\n h_encr : " << h_encr << endl;
//		cout << "\n h_decr : " << h_decr << endl;
//		cout << "\n f_encr : " << f_encr << endl;
//		cout << "\n f_decr : " << f_decr << endl;
//		cout << "\n pos_encr : " << pos_encr << endl;
//		cout << "\n pos_decr : " << pos_decr << endl;

//		ofstream pm_app("PatientMobileApp.dat",ios::binary);
//		char separator1 = '\n';
//	    char separator2 = '\t';
//	    string devices[] = {"OxySat : " , "Pulse : " , "HandTremors : " , "Falls : " , "Position : "};


//		pm_app.write(devices[0].c_str(), devices[0].size() + 1);
//		pm_app.write(reinterpret_cast<const char*>(&o), sizeof(o));
//		pm_app.write(&separator1, sizeof(separator1)); // Use "\n"
//
//		pm_app.write(devices[1].c_str(), devices[1].size() + 1);
//		pm_app.write(reinterpret_cast<const char*>(&p), sizeof(p));
//		pm_app.write(&separator1, sizeof(separator1)); // Use "\n"
//
//		pm_app.write(devices[2].c_str(), devices[2].size() + 1);
//		pm_app.write(reinterpret_cast<const char*>(&h), sizeof(h));
//		pm_app.write(&separator1, sizeof(separator1)); // Use "\n"
//
//		pm_app.write(devices[3].c_str(), devices[3].size() + 1);
//		pm_app.write(reinterpret_cast<const char*>(&f), sizeof(f));
//		pm_app.write(&separator1, sizeof(separator1)); // Use "\n"
//
//		pm_app.write(devices[4].c_str(), devices[4].size() + 1);
//		pm_app.write(reinterpret_cast<const char*>(&pos), sizeof(pos));
//		pm_app.write(&separator1, sizeof(separator1)); // Use "\n"
//
//		pm_app.write(&separator2, sizeof(separator2)); // Use "\t"
//
//		pm_app.close();

	}
	void DecryptingData()
	{
		ifstream dec("Cloud.dat", ios::binary);

		int i=0;
		dec.read(reinterpret_cast<char*>(&i), sizeof(i));

	    char device_name[50] , seperator;
	    char value1;
//	    dec.read(device_name);
//	    const int numChars = 8;
//	    char buffer[numChars + 1] = {0}; // +1 for null terminator
//	    int x = 0;
//	    while (x < numChars && dec.get(buffer[i])) {
//	        x++;
//	    }
//	    inputFile.close();
//	    buffer[x] = '\0';
//	    string str(50, ':');
//	    dec.read(&str[0], 50);
	    dec.getline(device_name, 50, '\0');
	    dec.read(reinterpret_cast<char*>(&value1), sizeof(char));
//	    dec.read(reinterpret_cast<char*>(&seperator), sizeof(char));

	    // Read the second device and its corresponding value
	    char device_name2[50];
	    char value2;
	    dec.getline(device_name2, 50, '\0');
	    dec.read(reinterpret_cast<char*>(&value2), sizeof(value2));
//	    dec.read(reinterpret_cast<char*>(&seperator), sizeof(char));

	    // Read the third device and its corresponding value
	    char device_name3[50];
	    char value3;
	    dec.getline(device_name3, 50, '\0');
	    dec.read(reinterpret_cast<char*>(&value3), sizeof(value3));
//	    dec.read(reinterpret_cast<char*>(&seperator), sizeof(char));

	    // Read the fourth device and its corresponding value
	    char device_name4[50];
	    char value4;
	    dec.getline(device_name4, 50, '\0');
	    dec.read(reinterpret_cast<char*>(&value4), sizeof(value4));
//	    dec.read(reinterpret_cast<char*>(&seperator), sizeof(char));

	    // Read the fifth device and its corresponding value
	    char device_name5[50];
	    char value5;
	    dec.getline(device_name5, 50, '\0');
	    dec.read(reinterpret_cast<char*>(&value5), sizeof(value5));
//	    dec.read(reinterpret_cast<char*>(&seperator), sizeof(char));

	    Encryptor<float> float1;
	    float decr_v1 , decr_v2 , decr_v3 ,decr_v4 , decr_v5;

	    float1.Decrypt(value1,decr_v1);
	    float1.Decrypt(value2,decr_v2);
	    float1.Decrypt(value3,decr_v3);
	    float1.Decrypt(value4,decr_v4);
	    float1.Decrypt(value5,decr_v5);

//	    cout << "\n The data of the Patient is as follows : " << endl;

	    cout << "\n The authentication password : " << i << endl;

	    //cout << device_name << decr_v1 << endl;
//	    cout << str << endl;
	    cout << "\n Device Name 1 : " << device_name << "\t Data  :" << decr_v1 << " %" << endl;
	    cout << "\n Device Name 2 : " << device_name2 << "\t\t Data  :" << decr_v2 << " bpm" << endl;
	    cout << "\n Device Name 3 : " << device_name3 << "\t Data  :" << decr_v3 << " Hz" << endl;
	    cout << "\n Device Name 4 : " << device_name4 << "\t\t Data  :" << decr_v4 << " /yr"<< endl;
	    cout << "\n Device Name 5 : " << device_name5 << "\t Data  :" << decr_v5 << " m" << endl;

	}
	void search_doctor(string n)
	{
		int c=0;
		string x[5] = {"Dr. Maria Gomez","Dr. James Lee","Dr. Fatima Khan","Dr. William Chen","Dr. Sarah Patel"} ;
		for(int i=0; i< 5 ; i++)
		{
			if( x[i] == n)
			{
				string temp;
				cout << "\n The " << n << " has been found, Now tell to when make an appointment : "<< endl;
				cin >> temp;
				cout << "\n WellDone. The doctor will contact you further in some time." << endl;
			}
			else
			{
				c++;
				continue;
			}
		}
		if(c==5)
		{
			cout << "\n I am sorry the doctor is not registerd with this association . " << endl;
		}
	}
	void add_note(string x)
	{
		cout << "\n The added note is : " << x;
	}
	~PM_APP()
	{

	}

	float getF() const {
		return f;
	}

	void setF(float f) {
		this->f = f;
	}

	char getFEncr() const {
		return f_encr;
	}

	void setFEncr(char fEncr) {
		f_encr = fEncr;
	}

	float getH() const {
		return h;
	}

	void setH(float h) {
		this->h = h;
	}

	char getHEncr() const {
		return h_encr;
	}

	void setHEncr(char hEncr) {
		h_encr = hEncr;
	}

	const IoT& getI() const {
		return I;
	}

	void setI(const IoT &i) {
		I = i;
	}

	float getO() const {
		return o;
	}

	void setO(float o) {
		this->o = o;
	}

	char getOEncr() const {
		return o_encr;
	}

	void setOEncr(char oEncr) {
		o_encr = oEncr;
	}

	float getP() const {
		return p;
	}

	void setP(float p) {
		this->p = p;
	}

	char getPEncr() const {
		return p_encr;
	}

	void setPEncr(char pEncr) {
		p_encr = pEncr;
	}

	float getPos() const {
		return pos;
	}

	void setPos(float pos) {
		this->pos = pos;
	}

	char getPosEncr() const {
		return pos_encr;
	}

	void setPosEncr(char posEncr) {
		pos_encr = posEncr;
	}
};

#endif /* PMAPP_H_ */
