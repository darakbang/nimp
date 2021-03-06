﻿// main.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "stdafx.h"
#include "./pattern/singleton/singleton.h"
#include "./pattern/singleton/singleton_call_once.h"


class A : public singleton<A>{
	friend class singleton<A>;	
public:
	int a;
	std::wstring b;

private:
	A(){}
};

class B : public singleton_call_once<B> {
	friend class singleton_call_once<B>;
public:
	int a;
	std::wstring b;

private:
	B(){}
};

const int fps = 60;
using frame = std::chrono::duration<int32_t, std::ratio<1, fps>>;
using ms = std::chrono::duration<float, std::milli>;

int main()
{
	std::cout << "start test.." << std::endl;
	A::instance().a = 10;
	A::instance().b = L"singleton test...";

	B::instance().a = 11;
	B::instance().b = L"singleton call once test";

	std::cout << "A::A value: " << A::instance().a << std::endl;
	std::wcout << "A::B value: " << A::instance().b.c_str() << std::endl;
	std::cout << "B::A value: " << B::instance().a << std::endl;
	std::wcout << "B::B value: " << B::instance().b.c_str() << std::endl;
    std::cout << "Hello World!\n" << std::endl;

	/*using miliseconnds = std::chrono::milliseconds;
	using std::chrono::duration_cast;*/
	

	/// <summary>
	/// chrono를 이용한 game loop fixed framerate(60fps)
	/// 박제
	/// </summary>
	/// <returns></returns>
	std::chrono::time_point<std::chrono::high_resolution_clock> fpsTimer(std::chrono::high_resolution_clock::now());
	frame FPS{};
	
	while (true) {
		FPS = std::chrono::duration_cast<frame>(std::chrono::high_resolution_clock::now() - fpsTimer);

		if (FPS.count() >= 1) {
			fpsTimer = std::chrono::high_resolution_clock::now();
			std::cout << "LastFrame: " << std::chrono::duration_cast<ms>(FPS).count() << "ms | FPS: " << FPS.count() * fps << std::endl;
		}
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
