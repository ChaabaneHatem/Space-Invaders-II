#include"timer.h"

Timer::Timer(long delai) {
	this->delai = delai;
}
void Timer::start() {
	this->timer = clock();
}

bool Timer::estPret() {
	bool pret = false;

	if (clock() >= timer + delai) {
		pret = true;
		timer = clock();
	}

	return pret;
}