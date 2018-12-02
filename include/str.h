#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>  
#include <vector>

class String{
    private:
        char* cstring;

        void assign_cstring(const char* copy_from);
    public:
        String();
        String(const String& str);
        String(const char* cstring);
        ~String();

        std::vector<String> split(const String& delimeter);
        std::vector<String> split(const char* delimeter);

        String& operator= (const String& rhs);
        String& operator= (const char* rhs);
        String operator+ (const String& rhs);
        String operator+ (const char*& rhs);
        String& operator+= (const String& rhs);
        String& operator+= (const char*& rhs);


        bool operator== (const String& rhs) const;
        bool operator== (const char* rhs) const;
        // TODO Comparison operators below assume initalized values
        bool operator< (const String& rhs) const;
        bool operator< (const char* rhs) const;
        bool operator<= (const String& rhs) const;
        bool operator<= (const char* rhs) const;
        bool operator> (const String& rhs) const;
        bool operator> (const char* rhs) const;
        bool operator>= (const String& rhs) const;
        bool operator>= (const char* rhs) const;

        String operator[] (const int index);


        };

#endif
