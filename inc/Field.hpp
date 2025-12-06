#pragma once

#include "Snake.hpp"  // Snake::Point

class Field
{
  public:
	static constexpr int kDefaultWidth{30}, kDefaultHeight{30};

	explicit Field(int initHeigth = kDefaultHeight, int initWidth = kDefaultWidth);

	[[nodiscard]] const int height() const { return m_height; }
	[[nodiscard]] const int width() const { return m_width; }

	[[nodiscard]] bool isOutOfBounds(const Snake::Point& snakeHeadPoint);

  private:
	int m_height, m_width;
};
