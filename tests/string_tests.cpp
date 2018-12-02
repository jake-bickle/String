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
        REQUIRE(tokens.empty());
        REQUIRE(str == "this is a test");
    }

    SECTION("Split with multiple dilimeters of a string with said dilimeters")
    {
        String str("he/l,lo w$orld");
        std::vector<String> tokens = str.split("/, $");
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
        REQUIRE(tokens.empty());
        REQUIRE(str == "Helloworld!");
    }

    SECTION("Split string with dilimeter of another string")
    {
        String str;
        String dilimeters("/, $");
        std::vector<String> tokens = str.split(dilimeters);
        REQUIRE(tokens.empty());
    }

    SECTION("Split string with no given dilimeters")
    {
        String str("Hello, world!");
        std::vector<String> tokens = str.split("");
        REQUIRE(tokens.empty());
    }

    SECTION("Split string of uninitalized values");
    {
        String str;
        std::vector<String> tokens = str.split("/, $");
        REQUIRE(tokens.empty());
    }

    SECTION("Split string with a string of uninitalized values")
    {
        String str("Hello, world!");
        String uninit;
        std::vector<String> tokens = str.split(uninit);
        REQUIRE(tokens.empty());
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
