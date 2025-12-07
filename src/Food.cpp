#include "Food.hpp"	 // Where is it from

#include "Field.hpp"  // Field

Food::Food(const Field& field, const Snake& snake, std::mt19937& rndgen) {
	relocate(field, snake, rndgen);
}

void Food::relocate(const Field& field, const Snake& snake, std::mt19937& rndgen) {
	constexpr static int minX = 1;
	const static int maxX = field.width() - 2;
	constexpr static int minY = 1;
	const static int maxY = field.height() - 2;

	static std::uniform_int_distribution<int> distX(minX, maxX);
	static std::uniform_int_distribution<int> distY(minY, maxY);

	constexpr static int kMaxAttempts = 1000;
	for (int att{0}; att < kMaxAttempts; ++att) {
		const Snake::Point candidate{distX(rndgen), distY(rndgen)};

		if (isPosFree(candidate, snake)) {
			m_position = candidate;
			return;
		}
	}
}

bool Food::isPosFree(const Snake::Point& pos, const Snake& snake) {
	for (auto snakeElPos : snake.body())
		if (pos == snakeElPos) return false;
	return true;
}
