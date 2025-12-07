#pragma once

#include <curses.h>	 // ncurses or pdcurses

#include <string>  // string

#include "Snake.hpp"  // Snake::Point || Snake

class Snake;
class Food;
class Field;

class Renderer
{
  public:
	Renderer();

	// Basic functions implementation from *curses.h
	void showGameOver();
	void clear();
	void refresh();

	// Get a button pressed by the user
	[[nodiscard]] int getChar();

	// Draw TUI elements
	void drawFood(const Food& food);
	void drawSnake(const Snake& snake);
	void drawStats(const int score, const std::string& gameState);
	void drawField(const Field& field);

	// Draw chars
	void drawChar(const int& y, const int& x, const char& ch) const;
	void drawString(int& y, int& x, const std::string& str) const;

	~Renderer();

  private:
	bool m_initialized{false};

	void init();
	void shutdown();
};
