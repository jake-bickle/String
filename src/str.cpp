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

// TODO : Return to this after creating iterator class
//String String::lower() const{
    //String copy(cstring);
    //for (char& letter : copy.cstring ){
        //letter = lower_case_ascci_value(letter);
    //}
    //return copy;
//}

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
    return !(*this <= rhs);
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

String::iterator String::begin() const{
    return String::iterator(cstring);
}

String::iterator String::end() const{
    unsigned int string_length = this->size();
    char* end = cstring + string_length;
    return String::iterator(end);
}

String::iterator::iterator(char* ptr)
    : ptr(ptr) {}

char& String::iterator::operator* (){
    return *ptr;
}

String::iterator& String::iterator::operator++ (){
    ++ptr;
    return *this;
}

String::iterator String::iterator::operator++ (int){
    String::iterator copy(ptr);
    ++ptr;
    return copy;
} 

String::iterator& String::iterator::operator-- (){
    --ptr;
    return *this;
}

String::iterator String::iterator::operator-- (int){
    String::iterator copy(ptr);
    --ptr;
    return copy;
}

String::iterator& String::iterator::operator+= (int n){
    ptr += n;
    return *this;
}

String::iterator& String::iterator::operator-= (int n){
    ptr -= n;
    return *this;
}

bool String::iterator::operator == (const String::iterator& rhs) const{
    return (ptr == rhs.ptr);
}

bool String::iterator::operator != (const String::iterator& rhs) const{
    return !(*this == rhs);
}
