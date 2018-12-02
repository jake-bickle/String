#include "str.h"

String::String()
    : cstring(nullptr) {
    *this = "";
}

String::String(const char* cstring)
    : cstring(nullptr) {
    *this = cstring;
}

String::String(const String& str)
    : cstring(nullptr) {
    *this = str;
}

String::~String(){
    delete[] cstring;
}

void String::assign_cstring(const char* copy_from){
    delete[] cstring;
    cstring = new char[strlen(copy_from) + 1];
    strcpy(cstring, copy_from);
}

unsigned int String::size() const{
    return strlen(cstring);
}

std::vector<String> String::split(const String& delimeter) const{
    String copy(cstring);
    std::vector<String> tokens;
    char* ctoken = strtok(copy.cstring, delimeter.cstring);
    String token(ctoken); 

    if (!ctoken)
        return tokens;

    while (ctoken != NULL){
        tokens.push_back(token);
        ctoken = strtok(NULL, delimeter.cstring); 
        token = ctoken;
    }

    return tokens;
}

std::vector<String> String::split(const char* delimeter) const{
    return this->split(String(delimeter));
}

bool String::contains(const String& characters) const{
    return this->contains(characters.cstring);
}

bool String::contains(const char* characters) const{
    return !(strcspn(cstring, characters) == size());
}

String& String::operator= (const String& rhs){
    assign_cstring(rhs.cstring);
    return *this;
}

String& String::operator= (const char* rhs){
    if (rhs)
        assign_cstring(rhs);
    else
        assign_cstring("");
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

