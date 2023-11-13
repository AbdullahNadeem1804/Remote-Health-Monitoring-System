/*
 * HPAPP.h
 *
 *  Created on: May 14, 2023
 *      Author: dell
 */

#ifndef HPAPP_H_
#define HPAPP_H_
#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
#include"RMCC.h"
using namespace std;

string generate_chronic(int &num)
	{
		srand(time(0));
		string chronic[] = {"\n Arthritis","\n Asthma","\n Back pain","\n Cancer","\n Cardiovascular disease","\n Chronic obstructive pulmonary disease (COPD)",
							"\n Diabetes","\n Chronic kidney disease","\n Mental health conditions","\n Osteoporosis","\n Hypertension", "\n High cholesterol",  "\n Obesity" };
		string result; int j=0 , checker =0;
		Encryptor_Str App1;
		string encr_str1;
		char separator = '\n';
		for(j =rand()%13+1 ; j< 13 ; j++)
		{
			result += chronic[j];
			checker ++;
		}
		num = checker;
		return result;
	}
	void generate_appointment_history()
	{
		srand(time(0));
		int x=0;
		string cond = generate_chronic(x);
		string appointments[] = {"\n Arthritis: Visited Rheumatologist, to diagnose and treat the condition",
			"\n Asthma: Visited Allergist or pulmonologist, to diagnose and manage the condition",
			"\n Back pain: Visited Orthopedist, to diagnose and treat the condition",
			"\n Cancer: Visited Oncologist, to diagnose and treat the condition",
			"\n Cardiovascular disease: Visited Cardiologist, to diagnose and manage the condition",
			"\n COPD: Visited Pulmonologist, to diagnose and manage the condition",
			"\n Diabetes: Visited Endocrinologist, to diagnose and manage the condition",
			"\n Chronic kidney disease: Visited Nephrologist, to diagnose and manage the condition",
			"\n Mental health conditions: Visited Psychiatrist or psychologist, to diagnose and treat the condition",
			"\n Osteoporosis: Visited Endocrinologist or rheumatologist, to diagnose and treat the condition",
			"\n Hypertension: Visited Cardiologist or internist, to diagnose and manage the condition",
			"\n High cholesterol: Visited Cardiologist or internist, to diagnose and manage the condition",
			"\n Obesity: Visited Dietician or endocrinologist, to help you lose weight and manage the condition"};
		cout <<"\n\n Chronic Conditions = " << endl << cond;
		cout << "\n\n Past Appointment History : " << endl ;
		for(int i =12 ; i > 12-x ; i--)
		{
			cout << appointments[i] << endl;
		}
	}


class HP_APP:public EHR
{
	RMCC R;
private:
	string log[5] = {"Dr. Maria Gomez","Dr. James Lee","Dr. Fatima Khan","Dr. William Chen","Dr. Sarah Patel"};
public:
	HP_APP()
	{}
	int Login(string n)
	{
		int c=0;
		for(int i=0; i< 5 ; i++)
		{
			if(log[i] == n)
			{
				cout << "\n Welcome " << n << endl;
				R.Authorization();
			}
			else
			{
				c++;
				continue;
			}
		}
		if(c==5)
		{
			cout << "\n I am sorry you are not registerd with this association . " << endl;
			return 1;
		}
	}
	void past_appoint()
	{

		generate_appointment_history();
	}
	~HP_APP()
	{

	}

	const string* getLog() const {
		return log;
	}

	const RMCC& getR() const {
		return R;
	}

	void setR(const RMCC &r) {
		R = r;
	}
};

#endif /* HPAPP_H_ */
