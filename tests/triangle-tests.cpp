#include <catch2/catch_test_macros.hpp>
#include "contracts/triangle.hpp"
#include <sstream>

TEST_CASE("Triangle constructor with valid input", "[triangle]") {
    SECTION("Valid triangle creation") {
        triangle t("3 4 5");
        REQUIRE(t.perimeter() == 12);
    }
    
    SECTION("Valid triangle with decimal values") {
        triangle t("2.5 3.5 4.5");
        REQUIRE(t.perimeter() == 10.5);
    }
}

TEST_CASE("Triangle constructor with invalid input", "[triangle]") {
    SECTION("Empty input") {
        triangle t("");
        REQUIRE(t.perimeter() == 0);
    }
    
    SECTION("Missing sides") {
        triangle t1("3");
        REQUIRE(t1.perimeter() == 0);
        
        triangle t2("3 4");
        REQUIRE(t2.perimeter() == 0);
    }
    
    SECTION("Extra data") {
        triangle t("3 4 5 6");
        REQUIRE(t.perimeter() == 0);
    }
    
    SECTION("Non-positive sides") {
        triangle t1("-1 4 5");
        REQUIRE(t1.perimeter() == 0);
        
        triangle t2("3 0 5");
        REQUIRE(t2.perimeter() == 0);
        
        triangle t3("3 4 -2");
        REQUIRE(t3.perimeter() == 0);
    }
    
    SECTION("Invalid triangle inequalities") {
        triangle t1("1 2 10");
        REQUIRE(t1.perimeter() == 0);
        
        triangle t2("10 2 3");
        REQUIRE(t2.perimeter() == 0);
        
        triangle t3("3 10 2");
        REQUIRE(t3.perimeter() == 0);
    }
    
    SECTION("Non-numeric input") {
        triangle t("a b c");
        REQUIRE(t.perimeter() == 0);
    }
}

TEST_CASE("Triangle toString method", "[triangle]") {
    triangle t("3 4 5");
    REQUIRE(t.toString() == "triangle 3 4 5");
}

TEST_CASE("Default constructor", "[triangle]") {
    triangle t;
    // Default constructor should initialize, but we don't have a specific requirement
    // for its behavior in the provided code
}