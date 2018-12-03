#include <catch.hpp>
#include "str.h"
#include <vector>

TEST_CASE("Initialize the String", "[string], [constructor]")
{
    SECTION("Default construction")
    {
        String str;
        REQUIRE (str == "");
    }
    SECTION("Initialize with cstring")
    {
        String str("Hello, world!");
        REQUIRE (str == "Hello, world!");
    }
    
    SECTION("Initialize with self type String")
    {
        String str1("Hello, world!");
        String str2(str1);
        REQUIRE (str1 == str2);

        String str3;
        String str4(str3);
        REQUIRE (str3 == str4);
    }
}

TEST_CASE("Size of a string", "[string], [size]")
{
    SECTION("Size of a string with many characters")
    {
        String str("Hello!");
        unsigned int size = str.size();
        REQUIRE(size == 6);
    }

    SECTION("Size of a string with one character")
    {
        String str("1");
        unsigned int size = str.size();
        REQUIRE(size == 1);
    }

    SECTION("Size of a string with no characters")
    {
        String str;
        unsigned int size = str.size();
        REQUIRE(size == 0);
    }
}

TEST_CASE("Splitting a string", "[string], [operations], [split]")
{
    SECTION("Split with one dilimeter comma of a string with commas")
    {
        String str("this,is,test");
        std::vector<String> tokens = str.split(",");
        REQUIRE(tokens[0] == "this");
        REQUIRE(tokens[1] == "is");
        REQUIRE(tokens[2] == "test");
        REQUIRE(str == "this,is,test");
    }

    SECTION("Split with one dilimeter comma of a string with no commas")
    {
        String str("this is a test");
        std::vector<String> tokens = str.split(",");
        REQUIRE(tokens[0] == "this is a test");
        REQUIRE(str == "this is a test");
    }

    SECTION("Split with multiple dilimeters of a string with said dilimeters")
    {
        String str("he/l,lo w$orld");
        std::vector<String> tokens = str.split("/$ ,");
        REQUIRE(tokens[0] == "he");
        REQUIRE(tokens[1] == "l");
        REQUIRE(tokens[2] == "lo");
        REQUIRE(tokens[3] == "w");
        REQUIRE(tokens[4] == "orld");
        REQUIRE(str == "he/l,lo w$orld");
    }

    SECTION("Split with multiple dilimeters of a string without said dilimeters")
    {
        String str("Helloworld!");
        std::vector<String> tokens = str.split("/, $");
        REQUIRE(tokens[0] == "Helloworld!");
        REQUIRE(str == "Helloworld!");
    }

    SECTION("Split string with dilimeters in another string")
    {
        String str("he/l,lo w$orld");
        String dilimeters("/, $");
        std::vector<String> tokens = str.split(dilimeters);
        REQUIRE(tokens[0] == "he");
        REQUIRE(tokens[1] == "l");
        REQUIRE(tokens[2] == "lo");
        REQUIRE(tokens[3] == "w");
        REQUIRE(tokens[4] == "orld");
        REQUIRE(str == "he/l,lo w$orld");
    }

    SECTION("Split string with no given dilimeters")
    {
        String str("Hello, world!");
        std::vector<String> tokens = str.split("");
        REQUIRE(tokens[0] == "Hello, world!");
    }

    SECTION("Split string of uninitialized values");
    {
        String str;
        std::vector<String> tokens = str.split("/, $");
        REQUIRE(tokens.empty());
    }

    SECTION("Split string with a string of uninitialized values")
    {
        String str("Hello, world!");
        String uninit;
        std::vector<String> tokens = str.split(uninit);
        REQUIRE(tokens[0] == "Hello, world!");
    }
}

TEST_CASE("String contains characters", "[string], [operations], [contains]")
{
    SECTION("String contains given cstring characters")
    {
        String str("Hello world!");
        bool contains_characters = str.contains("Hw!$#");
        REQUIRE(contains_characters);
    }

    SECTION("String doesn't contain given cstring characters")
    {
        String str("Hello world!");
        bool contains_characters = str.contains(",$3");
        REQUIRE(!contains_characters);
    }

    SECTION("String contains given string characters")
    {
        String str("Hello world!");
        String chars("Hw!$#");
        bool contains_characters = str.contains(chars);
        REQUIRE(contains_characters);
    }

    SECTION("String doesn't contain given string characters")
    {
        String str("Hello world!");
        String chars(",$3");
        bool contains_characters = str.contains(chars);
        REQUIRE(!contains_characters);
    }
}

TEST_CASE("Lower casing a string", "[string], [operations]")
{
    SECTION("String in all caps is lower-cased")
    {
        String str("HELLO WORLD");
        String lower = str.lower();
        REQUIRE(lower == "hello world");
    }

    SECTION("String in all lower cases is lower-cased")
    {
        String str("hello world");
        String lower = str.lower();
        REQUIRE(lower == "hello world");
    }

    SECTION("String with symbols and numbers is lower-cased")
    {
        String str("HeLlO, WoRlD! 123 %&$*");
        String lower = str.lower();
        REQUIRE(lower == "hello, world! 123 %&$*");
    }
}

TEST_CASE("Upper casing a string", "[string], [operations]")
{

    SECTION("String in all lower cases is upper-cased")
    {
        String str("hello world");
        String lower = str.upper();
        REQUIRE(lower == "HELLO WORLD");
    }

    SECTION("String in all caps is upper-cased")
    {
        String str("HELLO WORLD");
        String upper = str.upper();
        REQUIRE(upper == "HELLO WORLD");
    }

    SECTION("String with symbols and numbers is upper-cased")
    {
        String str("HeLlO, WoRlD! 123 %&$*");
        String lower = str.upper();
        REQUIRE(lower == "HELLO, WORLD! 123 %&$*");
    }
}

TEST_CASE("Comparison operators", "[string], [comparison], [equality]")
{
    SECTION("Strings are equal to each other")
    {
        String str1("Hello, world!");
        String str2("Hello, world!");
        REQUIRE(str1 == str2);
    }

    SECTION("String and Cstring are equal to each other")
    {
        String str("Hello, world!");
        REQUIRE(str == "Hello, world!");
    }

    SECTION("Comparison of uninitialized strings")
    {
        String str1;
        String str2;
        String str3("Hello, world!");
        REQUIRE(str1 == str2);
        REQUIRE(!(str1 == str3));
    }

    SECTION("String is alphabetically lower than other string")
    {
        String str1("ABC");
        String str2("EFG");
        REQUIRE(str1 < str2);
        REQUIRE(!(str2 < str1));
    }

    SECTION("String is alphabetically lower than cstring")
    {
        String str("ABC");
        REQUIRE(str < "EFG");
        REQUIRE(!(str < "ABC"));
    }

    SECTION("String is alphabetically lower or equal to other string")
    {
        String str1("ABC");
        String str2("ABC");
        REQUIRE(str1 <= str2);

        String str4("EFG");
        REQUIRE(str1 <= str4);
        REQUIRE(!(str4 <= str1));
    }

    SECTION("String is alphabetically lower or equal to cstring")
    {
        String str("ABC");
        REQUIRE(str <= "ABC");
        REQUIRE(str <= "EFG");
    }

    SECTION("String is alphabetically higher than other string")
    {
        String str1("EFG");
        String str2("ABC");
        REQUIRE(str1 > str2);
        REQUIRE(!(str2 > str1));
    }

    SECTION("String is alphabetically higher than cstring")
    {
        String str("EFG");
        REQUIRE(str > "ABC");
    }

    SECTION("String is alphabetically higher or equal to other string")
    {
        String str1("EFG");
        String str2(str1);
        String str3("ABC");
        REQUIRE(str1 >= str2);
        REQUIRE(str1 >= str3);
    }

    SECTION("String is alphabetically higher or equal to cstring")
    {
        String str("EFG");
        REQUIRE(str >= "ABC");
        REQUIRE(str >= "EFG");
    }
}

TEST_CASE("Assignment operator", "[string], [assignment]")
{
    SECTION("Assignment of another self type String with data")
    {
        String str1("Hello, world!");
        String str2("Goodbye, cruel world!");
        str2 = str1;
        REQUIRE(str1 == "Hello, world!");
        REQUIRE(str2 == "Hello, world!");
    }

    SECTION("Assignment of another self type String without data")
    {
        String str1;
        String str2;
        str2 = str1;
        REQUIRE(str1 == str2);
        REQUIRE(str2 == str1);
    }

    SECTION("Assignment of a cstring where String has data")
    {
        String str("Hello, world!");
        str = "Goodbye, cruel world!";
        REQUIRE (str == "Goodbye, cruel world!");
    }

    SECTION("Assignment of a cstring where String has no data")
    {
        String str;
        str = "Goodbye, cruel world!";
        REQUIRE (str == "Goodbye, cruel world!");
    }
}


TEST_CASE("Derefrencing an iterator", "[string], [iterator], [dereference]")
{
    SECTION("Derefrencing an iterator at beginning of string")
    {
        String str("Hello, world!");
        String::iterator it = str.begin();
        REQUIRE(*it == 'H');
    }

    SECTION("Derefrencing an iterator in the middle of the string")
    {
        // TODO
    }

    SECTION("Derefrencing an iterator past the end raises error")
    {
        // TODO
    }
}

TEST_CASE("Iterator comparisons", "[string], [itrator], [comparison]")
{
    SECTION("begin() is equal to the first character of the array")
    {
        String str("Hello");
        String::iterator it = str.begin();
        REQUIRE(it == str.begin());
        REQUIRE(*it == 'H');
    }

    SECTION("begin() is equal to end() when array is empty")
    {
        String str;
        String::iterator beg = str.begin();
        String::iterator end = str.end();
        REQUIRE(beg == end);
    }
}

TEST_CASE("Moving iterator forward and backward", "[string], [iterator]")
{
    SECTION("Prefix ++ operator points to correct location from beginning of string")
    {
        String str("Hello!");
        String::iterator it = str.begin();
        ++it;
        REQUIRE(*it == 'e');
    }

    SECTION("Postfix ++ operator creates a copy and points to correct location from beginning of string")
    {
        String str("Hello!");
        String::iterator it = str.begin();
        REQUIRE(*(it++) == 'H');
        REQUIRE(*it == 'e');
    }

    SECTION("Prefix -- operator points to correct location at the beginning of the string")
    {
        String str("Hello!");
        String::iterator it = str.begin();
        ++it;
        --it;
        REQUIRE(*it == 'H');
    }

    SECTION("Postfix -- operator creates a copy and points to correct location at the beginning of the string")
    {
        String str("Hello!");
        String::iterator it = str.begin();
        ++it;
        REQUIRE(*(it--) == 'e');
        REQUIRE(*it == 'H');
    }

    SECTION("Prefix -- operator points to correct location from end of string")
    {
        String str("Hello!");
        String::iterator it = str.end();
        --it;
        REQUIRE(*it == '!');
    }

    SECTION("+= operator points to correct location")
    {
        String str("Hello, world!");
        String::iterator it = str.begin();
        it += 4;
        REQUIRE(*it == 'o');
    }

    SECTION("-= operator points to correct location")
    {
        String str("Hello, world!");
        String::iterator it = str.end();
        it -= 4;
        REQUIRE(*it == 'r');
    }
}

TEST_CASE("Using iterators to modify String", "[string], [iterator], [modifier]")
{
    SECTION("Modifying the first letter of the String")
    {
        String str("Hello, world!");
        String::iterator it = str.begin();
        *it = 'M';
        REQUIRE(str == "Mello, world!");
    }

    SECTION("Modfiying the fourth letter of the String")
    {
        String str("Hello, world!");
        String::iterator it = str.begin();
        it += 3;
        *it = 'M';
        REQUIRE(str == "HelMo, world!");
    }
}
