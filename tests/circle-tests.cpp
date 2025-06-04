#include "contracts/circle.hpp"
#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("Circle constructor with valid input", "[circle]")
{
    circle c("5");

    REQUIRE(c.perimeter() > 0);
    REQUIRE(c.toString() == "circle 5");
}

TEST_CASE("Circle constructor with invalid inputs", "[circle]")
{
    SECTION("Empty input")
    {
        circle c("");
        REQUIRE(c.perimeter() == 0);
    }

    SECTION("Non-numeric input")
    {
        circle c("abc");
        REQUIRE(c.perimeter() == 0);
    }

    SECTION("Negative radius")
    {
        circle c("-5");
        REQUIRE(c.perimeter() == 0);
    }

    SECTION("Zero radius")
    {
        circle c("0");
        REQUIRE(c.perimeter() == 0);
    }

    SECTION("Extra data")
    {
        circle c("5 extra");
        REQUIRE(c.perimeter() == 0);
    }
}
