#include "str.h"

String::String()
    : cstring(nullptr) {
    assign_cstring("");
}

String::String(const char* cstring)
    : cstring(nullptr) {
    assign_cstring(cstring);
}

String::String(const String& str)
    : cstring(nullptr) {
    assign_cstring(str.cstring);
}

String::~String(){
    delete[] cstring;
}

void String::assign_cstring(const char* copy_from){
    delete[] cstring;
    cstring = new char[strlen(copy_from) + 1];
    strcpy(cstring, copy_from);
}

//TODO FInish this
std::vector<String> String::split(const String& delimeter = ","){
    String copy(cstring);
    std::vector<String> tokens;
    String first_token = strtok(copy.cstring, delimeter.cstring);
    tokens.push_back(first_token);
    while (copy.cstring != NULL){
        String token(strtok(NULL, delimeter.cstring));
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<String> String::split(const char* delimeter = ","){
    return this->split(String(delimeter));
}

String& String::operator= (const String& rhs){
    assign_cstring(rhs.cstring);
    return *this;
}

String& String::operator= (const char* rhs){
    assign_cstring(rhs);
    return *this;
}

bool String::operator== (const String& rhs) const{
    return (strcmp(cstring, rhs.cstring) == 0);
}

bool String::operator== (const char* rhs) const{
    return *this == String(rhs);
}

bool String::operator< (const String& rhs) const{
    return (strcmp(cstring, rhs.cstring) < 0);
}

bool String::operator< (const char* rhs) const{
    return *this < String(rhs);
}

bool String::operator<= (const String& rhs) const{
    return (strcmp(cstring, rhs.cstring) <= 0);
}

bool String::operator<= (const char* rhs) const{
    return *this <= String(rhs);
}

bool String::operator> (const String& rhs) const{
    return !(*this <= rhs.cstring);
}

bool String::operator> (const char* rhs) const{
    return !(*this <= String(rhs));
}

bool String::operator>= (const String& rhs) const{
    return !(*this < rhs);
}

bool String::operator>= (const char* rhs) const{
    return !((*this < String(rhs)));
}

