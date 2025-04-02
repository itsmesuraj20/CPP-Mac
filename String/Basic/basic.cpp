//String Implementation
#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

//Default constructor
String::String() {
    str = new char[1];
    str[0] = '\0';
}

//Parameterized constructor
String::String(const char* s) {
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}
//Copy constructor
String::String(const String& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}
//Destructor
String::~String() {
    delete[] str;
}
//Assignment operator
String& String::operator=(const String& s) {
    if (this != &s) {
        delete[] str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    return *this;
}

//Concatenation operator
String String::operator+(const String& s) const {
    String result;
    result.str = new char[strlen(str) + strlen(s.str) + 1];
    strcpy(result.str, str);
    strcat(result.str, s.str);
    return result;
}

//Comparison operator
bool String::operator==(const String& s) const {
    return strcmp(str, s.str) == 0;
}

//Output operator
ostream& operator<<(ostream& os, const String& s) {
    os << s.str;
    return os;
}
//Input operator
istream& operator>>(istream& is, String& s) {
    char buffer[1000];
    is >> buffer;
    delete[] s.str;
    s.str = new char[strlen(buffer) + 1];
    strcpy(s.str, buffer);
    return is;
}
//Length function
int String::length() const {
    return strlen(str);
}
//Get string function
const char* String::getString() const {
    return str;
}
//Set string function
void String::setString(const char* s) {
    delete[] str;
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}
//Get character function
char String::getChar(int index) const {
    if (index < 0 || index >= strlen(str)) {
        return '\0'; // Return null character if index is out of bounds
    }
    return str[index];
}

//Set character function
void String::setChar(int index, char c) {
    if (index < 0 || index >= strlen(str)) {
        return; // Do nothing if index is out of bounds
    }
    str[index] = c;
}
//Find function
int String::find(const char* s) const {
    char* pos = strstr(str, s);
    if (pos != nullptr) {
        return pos - str; // Return the index of the first occurrence
    }
    return -1; // Return -1 if not found
}

//Replace function
void String::replace(const char* oldStr, const char* newStr) {
    int index = find(oldStr);
    if (index != -1) {
        int oldLen = strlen(oldStr);
        int newLen = strlen(newStr);
        char* temp = new char[strlen(str) - oldLen + newLen + 1];
        strncpy(temp, str, index);
        strcpy(temp + index, newStr);
        strcpy(temp + index + newLen, str + index + oldLen);
        delete[] str;
        str = temp;
    }
}

//Substring function
String String::substring(int start, int length) const {
    if (start < 0 || start >= strlen(str) || length <= 0) {
        return String(); // Return empty string if invalid parameters
    }
    char* temp = new char[length + 1];
    strncpy(temp, str + start, length);
    temp[length] = '\0';
    String result(temp);
    delete[] temp;
    return result;
}

//ToUpper function
void String::toUpper() {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32; // Convert to uppercase
        }
    }
}

//ToLower function
void String::toLower() {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; // Convert to lowercase
        }
    }
}

//Reverse function
void String::reverse() {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

//Trim function
void String::trim() {
    int start = 0;
    while (str[start] == ' ') {
        start++;
    }
    int end = strlen(str) - 1;
    while (end >= start && str[end] == ' ') {
        end--;
    }
    int len = end - start + 1;
    char* temp = new char[len + 1];
    strncpy(temp, str + start, len);
    temp[len] = '\0';
    delete[] str;
    str = temp;
}

//Split function
void String::split(const char* delimiter, String* result, int& count) const {
    count = 0;
    char* token = strtok(str, delimiter);
    while (token != nullptr) {
        result[count++] = String(token);
        token = strtok(nullptr, delimiter);
    }
}

//ReplaceAll function

void String::replaceAll(const char* oldStr, const char* newStr) {
    int index = find(oldStr);
    while (index != -1) {
        replace(oldStr, newStr);
        index = find(oldStr);
    }
}


//Count function
int String::count(const char* s) const {
    int count = 0;
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);
    char* token = strtok(temp, s);
    while (token != nullptr) {
        count++;
        token = strtok(nullptr, s);
    }
    delete[] temp;
    return count - 1; // Subtract 1 to get the number of occurrences
}

//FindAll function
void String::findAll(const char* s, int* indices, int& count) const {
    count = 0;
    char* pos = strstr(str, s);
    while (pos != nullptr) {
        indices[count++] = pos - str;
        pos = strstr(pos + 1, s);
    }
}

//ReplaceAll function
void String::replaceAll(const char* oldStr, const char* newStr) {
    int index = find(oldStr);
    while (index != -1) {
        replace(oldStr, newStr);
        index = find(oldStr);
    }
}

//Count function
int String::count(const char* s) const {
    int count = 0;
    char* temp = new char[strlen(str) + 1];
    strcpy(temp, str);
    char* token = strtok(temp, s);
    while (token != nullptr) {
        count++;
        token = strtok(nullptr, s);
    }
    delete[] temp;
    return count - 1; // Subtract 1 to get the number of occurrences
}


