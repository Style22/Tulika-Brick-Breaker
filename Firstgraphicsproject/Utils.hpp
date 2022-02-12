#include <SFML/Graphics.hpp>

class Utils
{
public:
	//calculates dot product of 2 vectors
	static float dot(const sf::Vector2f& lv, const sf::Vector2f& rv)
	{
		return lv.x * rv.x + lv.y * rv.y;
	}

	//Returns length of a given vector
	static float length(const sf::Vector2f& source)
	{
		return std::sqrt(dot(source, source));
	}

	//Returns a given vector with its length normalized to 1
	static sf::Vector2f normalize(sf::Vector2f source)
	{
		float length = std::sqrt(dot(source, source));
		if (length != 0) source /= length;
		return source;
	}
};