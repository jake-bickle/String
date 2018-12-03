#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

class String{
    private:
        char* cstring;

        void assign_cstring(const char* copy_from);
        int lower_case_ascci_value(const char& letter) const;
    public:

        typedef String::iterator iterator;
        typedef String::const_iterator const_iterator;

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

        String operator[] (const int index);

        class iterator;
        iterator begin() const;
        iterator end() const;

        class iterator : public iterator<random_iterator_tag, int>{
            private:
                char* ptr;

            public:
                iterator(char* ptr);
                char& operator* ();
                iterator& operator++ ();   // Prefix ++ 
                iterator operator++ (int); // Postfix ++
                iterator& operator-- ();
                iterator operator-- (int);
                bool operator == (const String::iterator& rhs) const;
                bool operator != (const String::iterator& rhs) const;
        };
    };

#endif
