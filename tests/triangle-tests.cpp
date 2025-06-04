#include <catch2/catch_test_macros.hpp>
#include "contracts/triangle.hpp"

TEST_CASE("triangle perimeter calculation", "[triangle]")
{
    SECTION("valid triangle")
    {
        triangle t(3, 4, 5);
        REQUIRE(t.perimeter() == 12);
    }
}

TEST_CASE("triangle constructor validation", "[triangle]")
{
    SECTION("negative side")
    {
        REQUIRE_THROWS_AS(triangle(-1, 4, 5), std::invalid_argument);
    }

    SECTION("zero side")
    {
        REQUIRE_THROWS_AS(triangle(0, 4, 5), std::invalid_argument);
    }

    SECTION("triangle inequality violation - first case")
    {
        REQUIRE_THROWS_AS(triangle(1, 2, 10), std::invalid_argument);
    }

    SECTION("triangle inequality violation - second case")
    {
        REQUIRE_THROWS_AS(triangle(10, 1, 2), std::invalid_argument);
    }

    SECTION("triangle inequality violation - third case")
    {
        REQUIRE_THROWS_AS(triangle(1, 10, 2), std::invalid_argument);
    }
}

TEST_CASE("triangle string representation", "[triangle]")
{
    triangle t(3, 4, 5);
    REQUIRE(t.toString() == "triangle 3 4 5");
}