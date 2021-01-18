#include "../../stdafx.h";
#include <chrono>
#include "gameloop.h";


double Application::MS_PER_UPDATE = 60.0f;

void Application::run() {
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	double lag = 0.0f;

	while (true) {
		std::chrono::system_clock::time_point current = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed = current - start;
		lag += elapsed.count();
		start = current;

		while (lag >= MS_PER_FRAME) {
			// update(elapsedTime);
			lag -= MS_PER_FRAME;
		}

		render(lag / MS_PER_FRAME);
	}
}