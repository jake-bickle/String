#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>
#include <vector>

class String{
    private:
        char* cstring;

        void assign_cstring(const char* copy_from);
        int lower_case_ascci_value(const char& letter) const;
        int upper_case_ascci_value(const char& letter) const;
    public:

        String();
        String(const String& str);
        String(const char* cstring);
        ~String();

        unsigned int size() const;

        std::vector<String> split(const String& delimeter) const;
        std::vector<String> split(const char* delimeter) const;
        bool contains(const String& characters) const;
        bool contains(const char* characters) const;
        String lower() const;
        String upper() const;

        String& operator= (const String& rhs);
        String& operator= (const char* rhs);
        String& operator+= (const String& rhs);
        String& operator+= (const char*& rhs);

        String operator+ (const String& rhs);
        String operator+ (const char*& rhs);

        bool operator== (const String& rhs) const;
        bool operator== (const char* rhs) const;
        // TODO Comparison operators below might assume initalized values
        bool operator< (const String& rhs) const;
        bool operator< (const char* rhs) const;
        bool operator<= (const String& rhs) const;
        bool operator<= (const char* rhs) const;
        bool operator> (const String& rhs) const;
        bool operator> (const char* rhs) const;
        bool operator>= (const String& rhs) const;
        bool operator>= (const char* rhs) const;

        friend std::ostream& operator<< (std::ostream& os, const String& str);
        friend std::istream& operator>> (std::istream& is, const String& str);


        class iterator;
        iterator begin() const;
        iterator end() const;

        class iterator{
            private:
                char* ptr;

            public:
                iterator(char* ptr);
                char& operator* ();
                iterator& operator++ ();   // Prefix ++ 
                iterator operator++ (int); // Postfix ++
                iterator& operator-- ();
                iterator operator-- (int);
                iterator& operator+= (int n);
                iterator& operator-= (int n);

                bool operator == (const String::iterator& rhs) const;
                bool operator != (const String::iterator& rhs) const;
        };
};

#endif
