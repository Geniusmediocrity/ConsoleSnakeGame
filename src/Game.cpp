#include "../inc/Game.hpp"	// Where it's gone

#include <ncurses.h>

#include <chrono>  // chrono_literals || steady_clock::now()
#include <thread>  // this_thread::sleep()

#include "../inc/Field.hpp"		// m_field
#include "../inc/Food.hpp"		// m_food
#include "../inc/Renderer.hpp"	// m_renderer
#include "../inc/Snake.hpp"		// m_snake || Snake::Point || Snake::Direction

Game::Game()
	: m_field(std::make_unique<Field>()),
	  m_snake(std::make_unique<Snake>()),
	  m_food(std::make_unique<Food>(*m_field, *m_snake, m_rdgen)),
	  m_renderer(std::make_unique<Renderer>())
// Initialize game
{
	resetGame();
}

void Game::run() {
	// needed to use the `2s` literal instead of a long wxpression
	using namespace std::chrono_literals;

	m_renderer->init();

	try {
		while (m_state != State::GameOver) {
			const auto frameStart = std::chrono::steady_clock::now();

			process_Input();
			if (m_state == State::Running) update();
			render();

			const auto frameEnd = std::chrono::steady_clock::now();
			const auto elapsed = frameEnd - frameStart;

			if (elapsed < kFrameDelay) std::this_thread::sleep_for(kFrameDelay - elapsed);
		}

		m_renderer->showGameOver();
		std::this_thread::sleep_for(2s);
	} catch (...) {
		m_renderer->showGameOver();
		std::this_thread::sleep_for(2s);
		m_renderer->shutdown();
		throw;
	}
	m_renderer->shutdown();
}

void Game::process_Input() {
	const int key = m_renderer->getChar();

	switch (key) {
		case 'q':
		case 'Q':
			m_state = State::GameOver;
			break;

		case 'p':
		case 'P':
			m_state = (m_state == State::Paused) ? State::Running : State::Paused;
			break;

		case KEY_UP:
		case 'w':
			m_snake->setDirection(Snake::Direction::Up);
			break;
		case KEY_DOWN:
		case 's':
			m_snake->setDirection(Snake::Direction::Down);
			break;
		case KEY_LEFT:
		case 'a':
			m_snake->setDirection(Snake::Direction::Left);
			break;
		case KEY_RIGHT:
		case 'd':
			m_snake->setDirection(Snake::Direction::Right);
			break;

		default:
			break;
	}
}

void Game::update() {
	m_snake->move();

	// Eat food condition
	if (m_snake->head() == m_food->position()) {
		m_snake->grow();
		m_food->relocate(*m_field, *m_snake, m_rdgen);
	}

	// Collisions condition
	if (m_field->isOutOfBounds(m_snake->head()) || m_snake->isSelfColliding())
		m_state = State::GameOver;
}

void Game::render() {
	m_renderer->clear();

	m_renderer->drawField();
	m_renderer->drawFood();
	m_renderer->drawSnake();

	m_renderer->drawStats({{"Score", std::to_string(m_snake->length() - Snake::kInitialLength)},
						   {"State", m_state == State::Paused ? "PAUSED" : "RUNNING"}});

	m_renderer->refresh();
}

void Game::resetGame() {
	m_snake->reset();
	m_food->relocate(*m_field, *m_snake, m_rdgen);
	m_state = State::Running;
}
