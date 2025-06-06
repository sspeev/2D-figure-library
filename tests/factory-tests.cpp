#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "factory/interfaces/figure_factory.hpp"
#include "factory/interfaces/random_figure_factory.hpp"
#include "factory/interfaces/stream_figure_factory.hpp"
#include "contracts/figure.hpp"
#include "contracts/circle.hpp"
#include "contracts/triangle.hpp"
#include "utilities/string_to_figure.hpp"

#include <sstream>
#include <string>
#include <vector>
#include <memory>
#define PI 3.14159265358979323846

// Helper function to check if a string starts with a prefix
bool startsWith(const std::string &str, const std::string &prefix)
{
    return str.size() >= prefix.size() && str.substr(0, prefix.size()) == prefix;
}

TEST_CASE("figure_factory interface", "[factory]")
{
    SECTION("figure_factory is an abstract class")
    {
        // Can't instantiate directly, but we can check derived classes implement the interface

        // This line won't compile, confirming figure_factory is abstract:
        // figure_factory factory;

        // The real test is if derived classes compile correctly
        random_figure_factory random_factory;
        std::istringstream iss("circle 5");
        stream_figure_factory stream_factory(iss);

        // Both should be usable as figure_factory pointers
        figure_factory *factory1 = &random_factory;
        figure_factory *factory2 = &stream_factory;

        REQUIRE(factory1 != nullptr);
        REQUIRE(factory2 != nullptr);
    }
}

TEST_CASE("random_figure_factory creates valid figures", "[factory][random]")
{
    random_figure_factory factory;

    SECTION("Multiple creations should produce valid figures")
    {
        std::vector<figure *> figures;

        const int num_figures = 3;
        for (int i = 0; i < num_figures; ++i)
        {
            figure *fig = factory.create();
            REQUIRE(fig != nullptr);
            figures.push_back(fig);
        }

        bool has_circle = false;
        bool has_triangle = false;

        for (const auto &fig : figures)
        {
            std::string description = fig->toString();
            if (startsWith(description, "circle"))
            {
                has_circle = true;
            }
            else if (startsWith(description, "triangle"))
            {
                has_triangle = true;
            }

            bool isValid = fig->perimeter() > 0.0;
            REQUIRE(isValid);
        }
        WARN(has_circle);
        WARN(has_triangle);

        for (auto fig : figures)
        {
            delete fig;
        }
    }

    SECTION("Created figures satisfy their constraints")
    {
        // Create 20 figures to increase chance of testing both types
        for (int i = 0; i < 20; ++i)
        {
            std::unique_ptr<figure> fig(factory.create());
            REQUIRE(fig != nullptr);

            std::string description = fig->toString();
            if (startsWith(description, "circle"))
            {
                REQUIRE(fig->perimeter() > 0.0); // Ensure circle has valid radius (implied by non-zero perimeter)
            }
            else if (startsWith(description, "triangle"))
            {
                // For triangles, we need to verify triangle inequality
                double perimeter = fig->perimeter();
                REQUIRE(perimeter > 0.0);

                std::string desc = fig->toString();
                std::istringstream iss(desc.substr(9)); // Skip "triangle " prefix
                double a, b, c;
                if (iss >> a >> b >> c)
                {
                    REQUIRE(a + b > c);
                    REQUIRE(a + c > b);
                    REQUIRE(b + c > a);
                }
            }
        }
    }
}

TEST_CASE("stream_figure_factory creates figures from input", "[factory][stream]")
{
    SECTION("Creating circle from stream")
    {
        std::istringstream iss("circle 5");
        stream_figure_factory factory(iss);

        std::unique_ptr<figure> fig(factory.create());
        REQUIRE(fig != nullptr);
        REQUIRE(startsWith(fig->toString(), "circle"));
        REQUIRE(fig->perimeter() > 0);
    }

    SECTION("Creating triangle from stream")
    {
        std::istringstream iss("triangle 3 4 5");
        stream_figure_factory factory(iss);

        std::unique_ptr<figure> fig(factory.create());
        REQUIRE(fig != nullptr);
        REQUIRE(startsWith(fig->toString(), "triangle"));
        REQUIRE(fig->perimeter() == 12);
    }

    SECTION("Invalid input handling")
    {
        std::istringstream empty_iss("");
        stream_figure_factory empty_factory(empty_iss);
        std::unique_ptr<figure> empty_fig(empty_factory.create());
        REQUIRE(empty_fig == nullptr);

        // Invalid figure type
        std::istringstream invalid_type_iss("square 4");
        stream_figure_factory invalid_type_factory(invalid_type_iss);
        std::unique_ptr<figure> invalid_type_fig(invalid_type_factory.create());
        if (invalid_type_fig != nullptr)
        {
            REQUIRE(invalid_type_fig->perimeter() == 0);
        }

        // Invalid parameters
        std::istringstream invalid_params_iss("circle -5");
        stream_figure_factory invalid_params_factory(invalid_params_iss);
        std::unique_ptr<figure> invalid_params_fig(invalid_params_factory.create());
        if (invalid_params_fig != nullptr)
        {
            REQUIRE(invalid_params_fig->perimeter() == 0);
        }
    }

    SECTION("Multiple reads from stream")
    {
        std::istringstream iss("circle 3\ntriangle 3 4 5\ncircle 7");
        stream_figure_factory factory(iss);

        std::unique_ptr<figure> fig1(factory.create());
        REQUIRE(fig1 != nullptr);
        REQUIRE(startsWith(fig1->toString(), "circle"));

        std::unique_ptr<figure> fig2(factory.create());
        REQUIRE(fig2 != nullptr);
        REQUIRE(startsWith(fig2->toString(), "triangle"));
        REQUIRE(fig2->perimeter() == 12);

        std::unique_ptr<figure> fig3(factory.create());
        REQUIRE(fig3 != nullptr);
        REQUIRE(startsWith(fig3->toString(), "circle"));
    }
}

TEST_CASE("factory integration tests", "[factory][integration]")
{
    SECTION("Using factory polymorphically")
    {
        std::istringstream iss("circle 10");
        stream_figure_factory stream_factory(iss);
        random_figure_factory random_factory;

        // Use factories through the base interface
        figure_factory *factories[] = {&stream_factory, &random_factory};

        for (auto factory : factories)
        {
            std::unique_ptr<figure> fig(factory->create());
            REQUIRE(fig != nullptr);

            // A valid figure should have a non-zero perimeter
            REQUIRE(fig->perimeter() > 0);
        }
    }

    SECTION("Factory creates correct figure types")
    {
        std::istringstream circle_iss("circle 7");
        stream_figure_factory circle_factory(circle_iss);
        std::unique_ptr<figure> figCircle(circle_factory.create());
        REQUIRE(startsWith(figCircle->toString(), "circle"));

        // We can test if it's really a circle by dynamic_cast
        circle *c = dynamic_cast<circle *>(figCircle.get());
        REQUIRE(c != nullptr);

        std::istringstream triangle_iss("triangle 5 6 7");
        stream_figure_factory triangle_factory(triangle_iss);
        std::unique_ptr<figure> figTriangle(triangle_factory.create());
        REQUIRE(startsWith(figTriangle->toString(), "triangle"));

        // We can test if it's really a triangle by dynamic_cast
        triangle *t = dynamic_cast<triangle *>(figTriangle.get());
        REQUIRE(t != nullptr);
    }
}

TEST_CASE("string_to_figure handles invalid inputs", "[string_to_figure]")
{
    string_to_figure converter;

    SECTION("empty string")
    {
        std::unique_ptr<figure> fig(converter.create_from(""));
        REQUIRE(fig == nullptr);
    }

    SECTION("missing parameters")
    {
        std::unique_ptr<figure> fig(converter.create_from("triangle 3 4"));
        REQUIRE(fig == nullptr);
    }

    SECTION("invalid figure type")
    {
        std::unique_ptr<figure> fig(converter.create_from("square 4"));
        REQUIRE(fig == nullptr);
    }

    SECTION("non-numeric parameters")
    {
        std::unique_ptr<figure> fig(converter.create_from("circle abc"));
        REQUIRE(fig == nullptr);
    }

    SECTION("negative parameters for circle")
    {
        std::unique_ptr<figure> fig(converter.create_from("circle -5"));
        REQUIRE(fig == nullptr);
    }

    SECTION("invalid triangle (negative sides)")
    {
        std::unique_ptr<figure> fig(converter.create_from("triangle -3 4 5"));
        REQUIRE(fig == nullptr);
    }

    SECTION("invalid triangle (violates triangle inequality)")
    {
        std::unique_ptr<figure> fig(converter.create_from("triangle 1 2 10"));
        REQUIRE(fig == nullptr);
    }
}