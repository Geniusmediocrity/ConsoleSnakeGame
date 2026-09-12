#pragma once

#include <random>  // mt19937

#include "Snake.hpp"  // Snake || Snake::Point

class Field;

class Food
{
  private:
	Snake::Point m_position{0, 0};

	[[nodiscard]] static bool isPosFree(const Snake::Point& pos, const Snake& snake);

  public:
	Food(const Field& field, const Snake& snake, std::mt19937& rndgen);

	static constexpr char kChar = '*';

	[[nodiscard]] const Snake::Point position() const { return m_position; }

	void relocate(const Field& field, const Snake& snake, std::mt19937& rndgen);
};
