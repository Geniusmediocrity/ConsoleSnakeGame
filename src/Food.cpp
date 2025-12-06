#include "../inc/Food.hpp"	// Where it's gone

#include "../inc/Field.hpp"	 // Field

Food::Food(const Field& field, const Snake& snake, const std::mt19937& rndgen) {
	relocate(field, snake, rndgen);
}

void Food::relocate(const Field& field, const Snake& snake, const std::mt19937& rndgen) {
	constexpr static int minX = 1;
	const static int maxX = field.width() - 1;
	constexpr static int minY = 1;
	const static int maxY = field.height() - 1;

	std::uniform_int_distribution<int> distX(minX, maxX);
	std::uniform_int_distribution<int> distY(minY, maxY);

	constexpr static int kMaxAttempts = 1000;
	for (int att{0}; att < kMaxAttempts; ++att) {
		const Snake::Point candidate{distX(rndgen), distY(rndgen)};

		if (isPosFree(candidate, field, snake)) {
			m_position = candidate;
			return;
		}
	}
}

bool Food::isPosFree(const Snake::Point& pos, const Field& filed, const Snake& snake) {
	for (auto snakeElPos : snake.get())
		if (pos == snakeElPos) return false;
	return true;
}
