/*
 * EHR.h
 *
 *  Created on: May 14, 2023
 *      Author: dell
 */

#ifndef EHR_H_
#define EHR_H_
#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
#include"Encryption.h"
using namespace std;

string generate_name() ;
string generate_gender() ;
string generate_address();
string generate_email(string name);
string generate_date() ;
string generate_prescriptions() ;
string generate_recommendations();
string generate_dob();
void generate_chronic(int & num,ofstream &);
void generate_appointment_history(ofstream &);
void generate_data(ofstream& file) ;



class EHR {
	static int x;
public:
	EHR()
	{
		ofstream n;
		generate_data(n);
	}

	void EditEHR()
	{
		ofstream output("EHR.dat", ios::binary | ios::app);
		    if (!output) {
		        cerr << "Failed to open file" << endl;
		        return ;
		    }
		string input , encr_input;
		cout << "\n Enter the desired input you want to add in the Cloud (The Data will be stored in string, Stopping Characeter is '.') : " << endl;
		getline(cin,input,'.');
		Encryptor_Str hola;
		hola.Encrypt(input, encr_input);
		output.write(encr_input.c_str(), encr_input.size() + 1);
		output.close();
		cout << "\n ThankYou for using the servive Doc. , Your data has been encrypted and saved into the Cloud. Bye" << endl;
		x++;

	}
	void read_EHR()
	{
		ifstream file("EHR.dat", ios::binary);

		    if (!file.is_open()) {
		        cout << "Failed to open file\n";
		        return ;
		    }
//		    cout << "\n Successful func" << endl;

//		    char byte;
//		    while (file.get(byte)) {
//		        cout << static_cast<int>(byte) << " ";
//		    }

		    Encryptor_Str S;
		    Encryptor<int> I;

		    string dec_str;
//		    int dec_int;

		    char read_chr;
		    string read_str="";
		    file.read(reinterpret_cast<char*>(&read_chr), sizeof(read_chr));
		    getline(file,read_str,'\n');
//		    cout << "\n Read 0 : " << read_str << endl;
		    S.Decrypt(read_str, dec_str);
		    cout << "\n Name : " << dec_str << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Patient ID : " << dec_str  << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Age : " << dec_str << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Gender : " << dec_str << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Date of Birth : " << dec_str << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Address : " << dec_str << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Email : " << dec_str << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Prescriptions : " << dec_str << endl;

		    getline(file,read_str,'\n');
		    S.Decrypt(read_str, dec_str);
			cout << "\n Chronic Health Conditions : " << endl << dec_str << endl ;

		    getline(file,read_str);
		    S.Decrypt(read_str, dec_str);
			cout << "\n Appointments History : " << endl << dec_str << endl;

		    getline(file,read_str);
		    S.Decrypt(read_str, dec_str);
			cout << "\n Recommendations : " << endl << dec_str << endl;

			if(x != 0)
			{
			    getline(file,read_str,'.');
			    S.Decrypt(read_str, dec_str);
				cout << "\n Added Data : " << endl << dec_str << endl;
			}

		   // file.close();
	}

	~EHR()
	{

	}
};
int EHR::x = 0;


string generate_name() {
	    string names[] = {"Abdullah", "John", "Sarah", "Alex", "Emma", "Ethan", "Emily", "William", "Olivia", "Ava"};
	    int index = rand() % 10;
	    return names[index];
	}

	string generate_gender() {
	    string genders[] = {"Male", "Female", "Other"};
	    int index = rand() % 3;
	    return genders[index];
	}

	string generate_address() {
	    string addresses[] = {"123 Main Street", "456 Oak Avenue", "789 Elm Boulevard", "1011 Pine Road", "1213 Maple Lane"};
	    int index = rand() % 5;
	    return addresses[index];
	}

	string generate_email(string name) {
	    string email_domains[] = {"gmail.com", "yahoo.com", "hotmail.com", "outlook.com", "aol.com"};
	    string domain = email_domains[rand() % 5];
	    return name + "@" + domain;
	}

	string generate_date() {
	    string months[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
	    int year = rand() % 20 + 2000;
	    int month = rand() % 12;
	    int day = rand() % 28 + 1;
	    return to_string(year) + "-" + months[month] + "-" + to_string(day);
	}

	string generate_prescriptions() {
	    string prescriptions[] = {"\n\t Aspirin (81 mg) - Take 1 tablet by mouth every day.",
	                              "\n\t Ibuprofen (800 mg) - Take 1 or 2 tablets by mouth every 6 to 8 hours as needed for pain.",
	                              "\n\t Tylenol (325 mg) - Take 1 or 2 tablets by mouth every 6 to 8 hours as needed for pain.",
	    							"\n\t Clopidogrel (75 mg) - Take 1 tablet by mouth every day. ",
									"\n\t Atorvastatin (10 mg) - Take 1 tablet by mouth every day. ",
	    							"\n\t Metformin (500 mg) - Take 1 tablet by mouth twice a day. "};
	    string result;
	    int count = rand() % 6 + 1;
	    for (int i = 0; i < count; i++) {
	        result += prescriptions[rand() % 6] + "\n ";
	    }
	    return result;
	}

	string generate_recommendations() {
	    string recommendations[] = {"Continue to see your primary care doctor for annual checkups.",
	                                "Continue to see your cardiologist for follow-up on hypertension.",
	                                "Continue to see your endocrinologist for follow-up on high cholesterol.",
	                                "See a dietician for help with weight loss.",
	                                "Make lifestyle changes to improve your health, such as eating a healthy diet, exercising regularly, and not smoking.",
	    							"Practice good sleep hygiene by maintaining a regular sleep schedule, avoiding caffeine and electronic devices before bedtime, and creating a dark, quiet, and comfortable sleep environment to improve sleep quality and overall health.",
	    							"Wear sunscreen with an SPF of at least 30 when spending time outdoors to protect your skin from sun damage and reduce the risk of skin cancer.",
									"Eat a balanced diet that includes plenty of fruits, vegetables, lean protein, and whole grains, and limit processed foods, saturated fat, and added sugars to maintain a healthy weight and reduce the risk of chronic diseases.",
									"Get at least 30 minutes of moderate exercise per day, such as brisk walking, cycling, or swimming, to improve cardiovascular health and reduce the risk of chronic diseases.",
									"Drink at least 8 glasses of water per day to stay hydrated and help flush toxins from your body."};
	    string result;
	    int count = rand() % 10 + 1;
	    for (int i = 0; i < count; i++) {
	        result += recommendations[rand() % 10] + "\n ";
	    }
	    return result;
	}

	string generate_dob()
	{
		string months[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
		    int year = rand() % 20 + 1900;
		    int month = rand() % 12;
		    int day = rand() % 28 + 1;
		    return to_string(year) + "-" + months[month] + "-" + to_string(day);
	}

	void generate_chronic(int &num,ofstream& y)
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
	   // cout << "\n c= " << checker;
//		cout << "\n Res:" << result;
		App1.Encrypt(result,encr_str1);
		y.write(encr_str1.data(), encr_str1.size());
		y.write(&separator, sizeof(separator)); // Use "\n"
//		cout << endl;
	}

	void generate_appointment_history(ofstream &f)
	{
		srand(time(0));
		int x=0;
		generate_chronic(x,f);
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
//		cout <<"\n\n Chronic Conditions = " << endl << app;
//		cout << "\n\n Past Appointment History : " << endl << endl;
		Encryptor_Str App;
		string encr_str;
		char separator = '\n';
		for(int i =12 ; i > 12-x ; i--)
		{
//			cout << appointments[i] << endl;
			App.Encrypt(appointments[i],encr_str );
			f.write(encr_str.data(), encr_str.size());
		}
		f.write(&separator, sizeof(separator)); // Use "\n"
	}



	void generate_data(ofstream& file)
	{
		srand(time(0));
		file.open("EHR.dat",ios::binary);
		if (!file) {
		    cerr << "Error opening file for writing\n";
		    return;
		}
	    int patient_id = rand() % 10000000000; // generate a 10-digit patient ID
	    string id = to_string(patient_id);
	    string name = generate_name();
	    int age = rand() % 80 + 20; // generate an age between 20 and 99
	    string a = to_string(age);
	    string gender = generate_gender();
	    string address = generate_address();
	    string email = generate_email(name);
	    string dob = generate_dob();
	    string date = generate_date();
	    string prescription = generate_prescriptions();
	    string recommendations = generate_recommendations();

		Encryptor_Str str1;
//		Encryptor<int> int1;
		string str_encr; // , dec;
//		char int_encr;

//	    file.write((char*)&name, sizeof(name));
//	    int1.Encrypt(patient_id, int_encr);
//	    cout << "\n PatientId " << patient_id << endl ;
//	    cout << "\n int_encr 1 : " << int_encr << endl;
//		file.write(&int_encr, sizeof(int_encr));
//		//file.write((char*)&patient_id, sizeof(patient_id));
//		cout << "\n hi";
//	    int1.Encrypt(age, int_encr);
//		file.write(reinterpret_cast<const char*>(&int_encr), sizeof(int_encr));
	    //file.write((char*)&age, sizeof(age));

//	    cout << "\n name : " << name << endl;
		char separator = '\n';
		file.write(&separator, sizeof(separator)); // Use "\n"
		str1.Encrypt(name, str_encr);
//	    cout << "\n str_encr 1 : " << str_encr << endl;
//	    str1.Decrypt(str_encr, dec);
//	    cout << "\n dec 1 : " << dec << endl;
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"

		str1.Encrypt(id, str_encr);
		file.write(str_encr.data(), str_encr.size());
//		cout << "\n id " << id << endl;
		file.write(&separator, sizeof(separator)); // Use "\n"

		str1.Encrypt(a, str_encr);
//		cout << a;
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"

	    str1.Encrypt(gender, str_encr);
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"
	    //file.write((char*)&gender, sizeof(gender));

	    str1.Encrypt(dob, str_encr);
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"
	    //file.write((char*)&dob, sizeof(dob));


	    str1.Encrypt(address, str_encr);
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"
	    //file.write((char*)&address, sizeof(address));


	    str1.Encrypt(email, str_encr);
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"
	    //file.write((char*)&email, sizeof(email));


	    str1.Encrypt(prescription, str_encr);
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"
		//file.write((char*)&prescription, sizeof(prescription));


		generate_appointment_history(file);
//	    str1.Encrypt(appointments, str_encr);
//		file.write(reinterpret_cast<const char*>(&str_encr), str_encr.size());
//	    //file.write((char*)&appointments, sizeof(appointments));

//	    cout << "\n Successful last " << endl;
	    str1.Encrypt(recommendations, str_encr);
		file.write(str_encr.data(), str_encr.size());
		file.write(&separator, sizeof(separator)); // Use "\n"
//		file.write((char*)&recommendations, sizeof(recommendations));

		if (file.fail()) {
		    cerr << "Error writing data to file\n";
		}

		file.close();


	}



#endif /* EHR_H_ */
