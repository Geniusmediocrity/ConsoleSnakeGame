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
	void init();
	void showGameOver();
	void shutdown();
	void clear();
	void refresh();

	[[nodiscard]] int getChar();

	// Draw TUI elements
	void drawFood(Food& food);
	void drawSnake(Snake& snake);
	void drawStats();
	void drawField(Field& field);

	// Draw chars
	void drawChar(int x, int y, char ch) const;
	void drawString(int x, int y, const std::string& str) const;

	~Renderer();

  private:
	bool m_initialized{false};
};
