#include "Renderer.hpp"	 // Where is it from

#include <ncurses.h>

#include "Field.hpp"
#include "Food.hpp"	 // position() || kCahr

// === RAII Wrapper ===

Renderer::Renderer() : m_initialized(true) { init(); }
Renderer::~Renderer() { shutdown(); }

// === Basic functions implementation from *curses.h ===

void Renderer::clear() { ::clear(); }
void Renderer::refresh() { ::refresh(); }

// === Get a button pressed by the user ===

int Renderer::getChar() { return ::getch(); }

// === Draw TUI elements ===

void Renderer::showGameOver() {
	const int centerY = COLS / 2;
	const int centerX = LINES / 2;

	const std::string msg = "GAME OVER";
	const int msgX = centerX - static_cast<int>(msg.size()) / 2;

	drawString(centerY, msgX, msg);
	drawString(centerY + 1, centerX - 8, "Press Q to quit");
}

void Renderer::drawFood(const Food& food) {
	Snake::Point position = food.position();
	drawChar(position.y, position.x, food.kChar);
}

void Renderer::drawSnake(const Snake& snake) {
	const auto& body = snake.body();  // deque(snakes body)
	const auto& head = snake.head();

	drawChar(head.y, head.x, snake.kHeadChar);
	for (auto it = body.begin() + 1; it != body.end(); ++it)
		drawChar(it->y, it->x, snake.kBodyChat);
}

void Renderer::drawStats(const int score, const std::string& gameState) {
	int x = 27;	 // Basic border width + 2
	int y = 1;

	drawString(y, x, "Score: " + std::to_string(score));
	drawString(++y, x, "State: " + gameState);
}

void Renderer::drawField(const Field& field) {
	const int w = field.width();
	const int h = field.height();

	drawChar(0, 0, '+');
	drawChar(w - 1, 0, '+');
	drawChar(0, h - 1, '+');
	drawChar(w - 1, h - 1, '+');

	for (int y = 1; y < w - 1; ++y) {
		drawChar(y, 0, '|');	  // left
		drawChar(y, h - 1, '|');  // right
	}
	for (int x = 1; x < h - 1; ++x) {
		drawChar(0, x, '-');	  // top
		drawChar(w - 1, x, '-');  // bottom
	}
}

// === Draw chars ===

void Renderer::drawChar(const int& y, const int& x, const char& ch) const {
	// Protection against going abroad
	if (y < 0 || y >= LINES || x < 0 || x >= COLS) return;

	mvaddch(y, x, ch);
}
void Renderer::drawString(const int& y, const int& x, const std::string& str) const {
	// Protection against going abroad
	if (y < 0 || y >= LINES || x < 0 || x >= COLS) return;

	for (auto ch : str)
		mvaddch(y, x, ch);
}

// === Private ===

void Renderer::init() {
	::initscr();
	::cbreak();				  // Symbols in time(without the Enter-key)
	::noecho();				  // Do not show input
	::nodelay(stdscr, TRUE);  // non-overlapping getchar
	::keypad(stdscr, TRUE);	  // Enable special buttons(F-keys, arrows ...)
	::curs_set(0);			  // Disable cursor
}
void Renderer::shutdown() {
	::endwin();
	m_initialized = false;
}
