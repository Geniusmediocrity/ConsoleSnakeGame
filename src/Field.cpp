#include "Field.hpp"  // Where is it from

#include <cassert>	// asseert

Field::Field(int initHeight, int initWidth) : m_height(initHeight), m_width(initWidth) {
	assert(initWidth > 2 && "Width must be more then(>) 2(frame + at least one cell)");
	assert(initHeight > 2 && "Height must be more then(>) 2(frame + at least one cell)");
}

bool Field::isOutOfBounds(const Snake::Point& snakeHdPt) {
	return (snakeHdPt.x <= 0 || snakeHdPt.x >= m_width || snakeHdPt.y <= 0 ||
			snakeHdPt.y >= m_height);
}
