#pragma once

//main loop�� ���� ��α� ���� https://kdi5652.tistory.com/entry/GameLoop

class Application {
public:
	void run();
	void render(double deltaTime) {}

private:
	double start;
	double end;
	static double MS_PER_FRAME;
};