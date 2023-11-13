/*
 * RMCC.h
 *
 *  Created on: May 14, 2023
 *      Author: dell
 */

#ifndef RMCC_H_
#define RMCC_H_
#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
#include"EHR.h"
#include"PMAPP.h"
using namespace std;

class RMCC:public EHR,public PM_APP
{
	PM_APP P;
public:
	static int count;

	void setclassPM(class PM_APP P)
	{
		this -> P = P;
	}
	RMCC(float O=0 ,float x=0 ,float HT=0 ,float f=0 ,float p=0):P(O,x,HT,f,p)
	{
		P.UpdatingApp();
		int y=1;
		ofstream cl_app("Cloud.dat",ios::binary); //Cloud App
		char separator1 = '\n';
		char separator2 = '\t';
		string devices[] = {"OxySat " , "Pulse " , "HandTremors " , "Falls " , "Position "};
		int auth[] = {11,12,13,14,15,16,17,18,19,110};
//		cout << "\n In RMCC Constructor " << endl;
//		cout << "\n Count : " << count << endl;

//ENDDDDDDD
//Indexing and storing the encrypted data from IoT in the Cloud
//		cout << "\n i= " << auth[count];
		cl_app.write(reinterpret_cast<const char*>(&auth[count]), sizeof(auth[count]));
//		cl_app.write(devices[0].c_str(), devices[0].size() + 1);

//		Encryptor<float> E; float l;
//		E.Decrypt(P.o_encr,l);
//		cout << "\n P.o_encr " << P.o_encr << endl;
//		cout << "\n P.o_decr :" << l << endl;

		cl_app.write(devices[0].c_str(), devices[0].size() + 1);
		cl_app.write(reinterpret_cast<const char*>(&P.o_encr), sizeof(char));
//		cl_app.write(&separator1, sizeof(separator1)); // Use "\n"

		cl_app.write(devices[1].c_str(), devices[1].size() + 1);
		cl_app.write(reinterpret_cast<const char*>(&P.p_encr), sizeof(char));
//		cl_app.write(&separator1, sizeof(separator1)); // Use "\n"

		cl_app.write(devices[2].c_str(), devices[2].size() + 1);
		cl_app.write(reinterpret_cast<const char*>(&P.h_encr), sizeof(char));
//		cl_app.write(&separator1, sizeof(separator1)); // Use "\n"

		cl_app.write(devices[3].c_str(), devices[3].size() + 1);
		cl_app.write(reinterpret_cast<const char*>(&P.f_encr), sizeof(char));
//		cl_app.write(&separator1, sizeof(separator1)); // Use "\n"

		cl_app.write(devices[4].c_str(), devices[4].size() + 1);
		cl_app.write(reinterpret_cast<const char*>(&P.pos_encr), sizeof(char));
//		cl_app.write(&separator1, sizeof(separator1)); // Use "\n"

		//pm_app.write(&separator2, sizeof(separator2)); // Use "\t"

		cl_app.close();
		count++;


	}
	void Authorization()
	{
		ifstream file("Cloud.dat", ios::binary);
		 if (!file) {
		        cerr << "Error: Unable to open file" << endl;
		        return ;
		    }
		 // Read the string from the file
		     int i;
		     file.read(reinterpret_cast<char*>(&i), sizeof(i));
//		     cout << i;

			int input;
			cout << "\n Now enter the authorization password for the user : " << "(" << i << ") : ";
			cin >> input;
		     // Compare the input to the string from the file
		     if (input == i)
		     {
		    	 P.DecryptingData();
		         //file.read(); will have to do in PM_APP
		     } else
		     {
		    	 cout << "\n You are not authorized to check the data !" << endl;
		         cout << "\n Choose one of the following Options Now : ";
		         char choice;
		         cout << "\n 1- Withdraw your request." << endl;
		         cout << " 2- Request the Patient." << endl;
		         cin >> choice;
		         switch(choice)
		         {
		         case '1':
		        	 cout << "\n Your request has been WithDrawed !" << endl;
		        	 break;
		         case '2':
		        	 cout << "\n Your have requested the Patient !" << endl;
		        	 break;
		         }
		         exit(1);
		     }

		     // Close the file
		     file.close();

	}
	void ADD_INTO_Cloud()
	{
		EHR x;
		x.EditEHR();
	}

	~RMCC()
	{

	}

	const PM_APP& getP() const {
		return P;
	}

	void setP(const PM_APP &p) {
		P = p;
	}
};

int RMCC::count = 0;

#endif /* RMCC_H_ */
