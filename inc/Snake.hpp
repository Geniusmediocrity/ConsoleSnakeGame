#pragma once

#include <deque>  // Snake's bosy

class Field;

class Snake
{
  public:
	struct Point
	{
		int x;
		int y;

		constexpr bool operator==(const Point& rhs) const {
			return this->x == rhs.x && this->y == rhs.y;
		}
		constexpr bool operator!=(const Point& rhs) const {
			return this->x != rhs.x || this->y != rhs.y;
		}
	};

	enum class Direction
	{
		Up,
		Down,
		Left,
		Right
	};

	// Constructor
	Snake(Field& field);

	// Constants
	static constexpr int kInitialLength = 3;
	static constexpr char kHeadChar = '@';
	static constexpr char kBodyChar = 'o';

	// Direction methods
	void setDirection(Direction dir);
	Direction direction() const { return m_direction; }

	// Moving and growing(main sense)
	void grow();
	void move();

	void reset(Field& field);

	// Data permissions
	[[nodiscard]] const std::deque<Point>& body() const { return m_body; }
	[[nodiscard]] Point head() const { return m_body.front(); }
	[[nodiscard]] size_t length() const { return m_body.size(); }

	// Collisions check
	[[nodiscard]] bool isSelfColliding() const;

  private:
	Direction m_direction = Direction::Right;

	std::deque<Point> m_body;

	bool m_shloudGrow{false};

	[[nodiscard]] Point nextHead() const;
};
