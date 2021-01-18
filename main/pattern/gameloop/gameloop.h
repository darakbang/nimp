#pragma once

//main loop에 대한 블로그 설명 https://kdi5652.tistory.com/entry/GameLoop

class Application {
public:
	void run();
	void render(double deltaTime) {}

private:
	double start;
	double end;
	static double MS_PER_FRAME;
};