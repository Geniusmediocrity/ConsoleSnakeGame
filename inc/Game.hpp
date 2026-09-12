#pragma once

#include <chrono>  // chrono::milliseconds
#include <memory>  // unique_ptr
#include <random>  // random_device || mt19937

class Field;
class Food;
class Snake;
class Renderer;

class Game
{
  public:
	Game();
	~Game();
	void run();

  private:
	static constexpr std::chrono::milliseconds kFrameDelay{150};

	enum class State
	{
		Running,
		Paused,
		GameOver
	} m_state{State::Running};

	std::mt19937 m_rdgen{std::random_device{}()};

	std::unique_ptr<Field> m_field;
	std::unique_ptr<Snake> m_snake;
	std::unique_ptr<Food> m_food;
	std::unique_ptr<Renderer> m_renderer;

	void process_Input();
	void update();
	void render();
	void resetGame();  // after game over
};
