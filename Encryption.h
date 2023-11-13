/*
 * Encryption.h
 *
 *  Created on: May 14, 2023
 *      Author: dell
 */

#ifndef ENCRYPTION_H_
#define ENCRYPTION_H_
#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;


class Encryptor_Str //(String Default)
{
	int key=3;
public:
  void Encrypt(const string& data, string& encrypted_data)
  {
	    encrypted_data = "";

	    for (char c : data) {
	        // Convert the ASCII value of the character to an integer and add the key
	        int encrypted_ascii = static_cast<int>(c) + key;

	        // Convert the encrypted integer back to a character and append it to the output string
	        encrypted_data += static_cast<char>(encrypted_ascii);
	    }
  }

  void Decrypt(const string& encrypted_data, string& decrypted_data)
  {
	  decrypted_data = "";

	    for (char c : encrypted_data) {
	        // Convert the ASCII value of the character to an integer and add the key
	        int decrypted_ascii = static_cast<int>(c) - key;

	        // Convert the encrypted integer back to a character and append it to the output string
	        decrypted_data += static_cast<char>(decrypted_ascii);
	    }


  }

	int getKey() const {
		return key;
	}

	void setKey(int key = 3) {
		this->key = key;
	}
};
template <typename T>
class Encryptor //(Default for int and float)
{
	int key=3;
public:
  void Encrypt(const T& data, char& encrypted_data)
  {
	    encrypted_data = (data + key);
  }

  void Decrypt(const char& encrypted_data, T& data)
  {
	        data = (encrypted_data - key);
  }

	int getKey() const {
		return key;
	}

	void setKey(int key = 3) {
		this->key = key;
	}
};

#endif /* ENCRYPTION_H_ */
