//============================================================================
// Name        : Driver.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
#include"PMAPP.h"
#include"RMCC.h"
#include"IoT.h"
#include"EHR.h"
#include"HPAPP.h"
using namespace std;



int main()
{
	srand(time(0));

	RMCC P1; //Data for 10 patients
	//Start
	cout << "\n Welcome to Remote Health Monitoring System !" ;
	cout << "\n First tell us are you a Patient or Doctor (P or D respectively) : ";
	char person;
	cin >> person;
	if(person == 'P')
	{
		cout << "\n You are being logged in as a Patient ... " << endl;
		cout << "\n Done. " << endl;
		cout << "\n\n This is your profile : " << endl;
		EHR E;
		E.read_EHR();
		cout << "\n Which one do you want to do first? (1 or 2)" << endl;
		cout << "\n 1- Check out your IoT Devices data. ";
		cout << "\n 2- Search for Doctor to have an appointment." << endl;
		char choice;
		cin >> choice;
		if(choice == '1')
		{
			P1.DecryptingData();
			PM_APP x;
			string n;
			cout << "\n Now, Enter the name of Doctor you want to search ? " << endl;
			//"Dr. Maria Gomez"
			//"Dr. James Lee"
			//"Dr. Fatima Khan"
			//"Dr. William Chen"
			//"Dr. Sarah Patel"
			cin.ignore();
			getline(cin,n);
			x.search_doctor(n);
		}
		if(choice == '2')
		{
			PM_APP x;
			string n;
			cout << "\n Enter the name of Doctor you want to search : " ;
			//"Dr. Maria Gomez"
			//"Dr. James Lee"
			//"Dr. Fatima Khan"
			//"Dr. William Chen"
			//"Dr. Sarah Patel"
			cin.ignore();
			getline(cin,n);
			x.search_doctor(n);
			cout << "\n Now this is your IoT device Data." << endl;
			P1.DecryptingData();
		}

		string n;
		cout << "\n\n NOW, You are being logged in as a Doctor ... " << endl;
		cout << "\n Done. " << endl;
		cout << "\n Enter you doctor name : ";
		cin.ignore();
		getline(cin,n);
		HP_APP H;
		int i=1;
		if ( i != H.Login(n))
		{
			cout << "\n Now  this is the past appointment history of the Patient. "<< endl;
			H.past_appoint();
			cout << "\n Now do you want to edit the EHR Data ? (y/n)";
			char s;
			cin >> s;
			if(s== 'y')
				H.EditEHR();
			else
				cout << "\n I had a great time serving you. Be srue to rate us down in the cloud. See You Next Time Doc. ! " << endl;
		}

//		cout << "\n Now do you want to add anything in the cloud or just continue (y/n) : ";
//		char c;
//		cin >> c;
//		switch(c)
//		{
//		case 'y':
//			P1.ADD_INTO_Cloud();
//			break;
//		case 'n':
//			cout << "\n GoodBye Patient, Hope you have Wonderful day :) " << endl;
//			break;
//		}
	}
	if(person == 'D')
	{
		string n;
		cout << "\n Enter you doctor name : ";
		cin.ignore();
		getline(cin,n);
		HP_APP H;
		int i=1;
		if ( i != H.Login(n))
		{
			cout << "\n Now  this is the past appointment history of the Patient. "<< endl;
			H.past_appoint();
			cout << "\n Now do you want to edit the EHR Data ? (y/n)";
			char s;
			cin >> s;
			if(s== 'y')
				H.EditEHR();
			else
				cout << "\n I had a great time serving you. Be srue to rate us down in the cloud. See You Next Time Doc. ! " << endl;
		}

		cout << "\n\n NOW, You are being logged in as a Patient ... " << endl;
		cout << "\n Done. " << endl;
		cout << "\n\n This is your profile : " << endl;
		EHR E;
		E.read_EHR();
		cout << "\n Which one do you want to do first? (1 or 2)" << endl;
		cout << "\n 1- Check out your IoT Devices data. ";
		cout << "\n 2- Search for Doctor to have an appointment." << endl;
		char choice;
		cin >> choice;
		if(choice == '1')
		{
			P1.DecryptingData();
			PM_APP x;
			string n;
			cout << "\n Now, Enter the name of Doctor you want to search ? " << endl;
			//"Dr. Maria Gomez"
			//"Dr. James Lee"
			//"Dr. Fatima Khan"
			//"Dr. William Chen"
			//"Dr. Sarah Patel"
			cin.ignore();
			getline(cin,n);
			x.search_doctor(n);
		}
		if(choice == '2')
		{
			PM_APP x;
			string n;
			cout << "\n Enter the name of Doctor you want to search : " ;
			//"Dr. Maria Gomez"
			//"Dr. James Lee"
			//"Dr. Fatima Khan"
			//"Dr. William Chen"
			//"Dr. Sarah Patel"
			cin.ignore();
			getline(cin,n);
			x.search_doctor(n);
			cout << "\n Now this is your IoT device Data." << endl;
			P1.DecryptingData();
		}
	}

//Done
//	IoT I;
//	I.UpdateApp();
//	cout  << "\n" << I.getFalls()  << "\n" << I.getHandTremors()  << "\n" << I.getOxySat()  << "\n" << I.getPosition() << "\n" << I.getPulse();
//Done
//	PM_APP P;
//	P.UpdatingApp();


// DOneeee
//	string n;
//	cout << "\n Enter you doctor name : ";
//	getline(cin,n);
//	HP_APP H;
//	H.Login(n);
//	H.past_appoint();
//	H.EditEHR();


/////////////////////////////////////
//Done THIS CORRECT
//	RMCC R;
//	R.Authorization(123);
	string l;
//Done Toooo
//	RMCC t;
//    cout << "\n Successful main" << endl;
//	t.read_EHR();
//	t.EditEHR();
//	t.read_EHR();
//Done
//A.past_appoint();
//l = generate_appointment_history();
//Done
//R.ADD_INTO_Cloud();
//	R.read_cloud();

//PM_APP A;
//A.search_doctor("Dr. Maria Gomez");
//A.add_note("I have school next week so pls hurry up.");


return 0;
}



