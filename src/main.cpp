#include <cstdlib>	// EXIT_SUCCESS || EXIT_FAILURE
#include <iostream>

#include "Game.hpp"

int main() {
	try {
		Game game;
		game.run();
		return EXIT_SUCCESS;
	} catch (const std::exception& e) {
		std::cerr << "❌ Fatal error: " << e.what() << '\n';
		return EXIT_FAILURE;
	} catch (...) {
		std::cerr << "❌ Unknown fatal error occurred.\n";
		return EXIT_FAILURE;
	}
}
