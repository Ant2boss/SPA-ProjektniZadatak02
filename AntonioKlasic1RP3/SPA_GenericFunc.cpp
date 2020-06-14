#include "SPA_GenericFunc.h"
#include<iostream>
#include<conio.h>

void SPA::IspisiTitleCard(std::string Text) {
	std::cout << "================================\n";
	std::cout << Text << std::endl;
	std::cout << "================================\n";
}

void SPA::IspisiPauzu() {
	std::cout << "================================\n";
	std::cout << "Pritisnite bilo koju tipku za povratak..." << std::endl;
	_getwch();
}

void SPA::SoritrajKontejnerePoTrajanju(KontainerItrajanje* K, int N) {
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i; j < N; ++j) {
			if (K[i].Trajanje > K[j].Trajanje) std::swap(K[i], K[j]);
		}
	}
}
