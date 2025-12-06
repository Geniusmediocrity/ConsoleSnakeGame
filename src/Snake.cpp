#include "../inc/Snake.hpp"	 // Where it's gone

Snake::Snake() { reset(); }

void Snake::setDirection(Direction dir) {
	const bool isOpposite = (m_direction == Direction::Up && dir == Direction::Down) ||
							(m_direction == Direction::Down && dir == Direction::Up) ||
							(m_direction == Direction::Left && dir == Direction::Right) ||
							(m_direction == Direction::Right && dir == Direction::Left);
	if (!isOpposite) m_direction = dir;
}

void Snake::grow() { m_shloudGrow = true; }

void Snake::move() {
	const Point newHead = nextHead();
	m_body.push_front(newHead);

	if (!m_shloudGrow)
		m_body.pop_back();
	else
		m_shloudGrow = false;
}

void Snake::reset() {
	m_body.clear();
	m_direction = Direction::Right;
	m_shloudGrow = false;

	// TODO: start position
	const Point start{13, 13};
	m_body.push_front(start);
}

bool Snake::isSelfColliding() const {
	const Point& head = m_body.front();

	for (auto i = m_body.begin() + 1; i < m_body.end(); ++i)
		if (*i == head) return false;

	return true;
}

Snake::Point Snake::nextHead() const {
	Point head = m_body.front();
	switch (m_direction) {
		case Direction::Up:
			--head.y;
			break;
		case Direction::Down:
			++head.y;
			break;
		case Direction::Right:
			++head.x;
			break;
		case Direction::Left:
			--head.y;
			break;
		default:
			break;
	}
	return head;
}
