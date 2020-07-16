#ifndef LINE_HPP
#define LINE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <optional>

struct Line {
public:
    const sf::Vector2f origin;
    const std::optional<sf::Vector2f> end;
    const float angle;
    const float m;
    const float b;

    Line(const sf::Vector2f& origin, float angle)
    : origin(origin)
    , angle(angle)
    , m(std::tan(angle * 3.1415926f / 180.f))
    , b(origin.y - m * origin.x) {}

    Line(const sf::Vector2f& start, const sf::Vector2f& end)
    : origin(start)
    , end(end)
    , angle(180.f * 3.1415926f * std::atan2(end.y - start.y, end.x - start.x))
    , m((end.y - start.y) / (end.x - start.x))
    , b(origin.y - m * origin.x) {}

    std::optional<sf::Vector2f> computeIntersection(const Line& line) const {
        const float xInt = (b - line.b) / (line.m - m);

        if (end.has_value()) {
            if (xInt < std::min(origin.x, end.value().x) ||
                xInt > std::max(origin.x, end.value().x))
                return {};
        }
        else {
            if (angle < 90 || angle > 270) {
                if (xInt < origin.x) return {};
            }
            else {
                if (xInt > origin.x) return {};
            }
        }

        return sf::Vector2f(xInt, m * xInt + b);
    }
};

#endif