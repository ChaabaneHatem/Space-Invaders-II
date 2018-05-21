#pragma once
#include <Windows.h>
#include <conio.h>
#include <time.h>

class Timer {
private:
	long timer;
	long delai;

public:
	Timer(long delai);
	void start();
	bool estPret();
};
