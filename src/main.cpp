//******************************************************************************
// File name:   main.cpp
// Author:      Michelle Duong
// Date:        09/14/2024 
// Class:       CS200-01 
// Assignment:  Base Converter
// Purpose:     Binary, Decimal, and Hexadecimal representations of numbers 
//.             and conversions between these representations
// Hours:       0.25
//******************************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int hexCharToInt(char hexDigit);
char getBase(const string& strNumber);
string getNumber(const string& prompt);
void printTitle(const string& myTitle);
string binaryToDecimal(const string& strNumber);
string decimalToBinary(const string& strNumber);
string decimalToHex(const string& strNumber);
string hexToDecimal(const string& strNumber);
string hexToBinary(const string& strNumber);
string binaryToHex(const string& strNumber);


int hexCharToInt(char hexDigit) {
    return (hexDigit >= '0' && hexDigit <= '9') ? (hexDigit - '0') :
           (hexDigit >= 'A' && hexDigit <= 'F') ? (hexDigit - 'A' + 10) : -1;
}

char getBase(const string& strNumber) {
    char base;

    if (strNumber.length() > 2 && strNumber[0] == '0' && strNumber[1] ==
     'b') {
        base = 'B';
    }
    else if (strNumber.length() > 2 && strNumber[0] == '0' &&
     strNumber[1] == 'x') {
        base = 'H';
    }
    else {
      base = 'D';
    }

    return base;
}

string getNumber(const string& prompt) {
    string input;
    cout << prompt;
    cin >> input;
    return input;
}

void printTitle(const string& myTitle) {
  const int borderWidth = 5;
    const int titlePadding = borderWidth; 
    const int totalWidth = myTitle.length() + 2 * titlePadding + 2;

    cout << string(totalWidth, '*') << endl;
    
    cout << "*" << string(titlePadding, '*') << myTitle 
    << string(titlePadding, '*') << "*" << endl;
    
    cout << string(totalWidth, '*') << endl;
}

string binaryToDecimal(const string& strNumber) {
    string binary = strNumber.substr(2); 
    int decimalValue = 0;
    int length = binary.length();
    for (int i = 0; i < length; ++i) {
        if (binary[i] == '1') {
            decimalValue += pow(2, length - 1 - i); 
        }
    }
    return to_string(decimalValue);
}

string decimalToBinary(const string& strNumber) {
    int decimalValue = 0;
    for (char c : strNumber) {
        decimalValue = decimalValue * 10 + (c - '0');
    }
    
    if (decimalValue == 0) return "0b0";
    string binary;
    while (decimalValue > 0) {
        binary = char((decimalValue % 2) + '0') + binary;
        decimalValue /= 2;
    }
    return "0b" + binary;
}

string decimalToHex(const string& strNumber) {
    string hex;
    int decimalValue = 0;
    for (char c : strNumber) {
        decimalValue = decimalValue * 10 + (c - '0');
    }
    
    if (decimalValue == 0) {
      return "0x0";
    }
    
    while (decimalValue > 0) {
        int remainder = decimalValue % 16;
        if (remainder < 10) {
            hex = char(remainder + '0') + hex;
        } else {
            hex = char(remainder - 10 + 'A') + hex;
        }
        decimalValue /= 16;
    }
    return "0x" + hex;
}

string hexToDecimal(const string& strNumber) {
    string hex = strNumber.substr(2); 
    int decimalValue = 0;
    for (char c : hex) {
        decimalValue = decimalValue * 16 + hexCharToInt(c);
    }
    return to_string(decimalValue);
}

string hexToBinary(const string& strNumber) {
    string decimalValue = hexToDecimal(strNumber);
    return decimalToBinary(decimalValue);
}

string binaryToHex(const string& strNumber) {
    string decimalValue = binaryToDecimal(strNumber);
    return decimalToHex(decimalValue);
}

int main () {

  printTitle("HEX-DECIMAL-BINARY CONVERTER");

  while (true) {
    string input;
    input = getNumber("Enter your string to convert (q to quit): ");
    if (input == "q") {
      break;
    }

    char base = getBase(input);

    if (base == 'D') {
        cout << "The binary conversion is: " << decimalToBinary(input) 
        << endl;
        cout << "The hexadecimal conversion is: " << decimalToHex(input) 
        << endl << "\n";
    } else if (base == 'H') {
        cout << "The decimal conversion is: " << hexToDecimal(input) << endl;
        cout << "The binary conversion is: " << hexToBinary(input) << endl 
        << "\n";
    } else if (base == 'B') {
        cout << "The decimal conversion is: " << binaryToDecimal(input) 
        << endl;
        cout << "The hexadecimal conversion is: " << binaryToHex(input) 
        << endl << "\n";
    }
  }
  
  return EXIT_SUCCESS;
}