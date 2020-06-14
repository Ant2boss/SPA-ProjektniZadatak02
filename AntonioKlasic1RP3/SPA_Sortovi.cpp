#include "SPA_Sortovi.h"

#include<iostream>
#include<fstream>

int SPA::insertion_sort(SPA::SuperHero data[], int n) {
	int BrojZamjena = 0;

	for (int i = 1; i < n; i++) { // Prvog preskaèemo.
		for (int j = i; j > 0; j--) {
			if (data[j - 1].Name < data[j].Name) {
				std::swap(data[j], data[j - 1]);
				BrojZamjena++;
			}
		}
	}

	return BrojZamjena;
}

int SPA::shell_sort(SPA::SuperHero data[], int n) {
	int BrojZamjena = 0;

	for (int step = n / 2; step > 0; step = step / 2) {
		for (int i = step; i < n; i++) { // Izrada potpolja
			for (int j = i - step; j >= 0; j -= step) { // Insertion na potpolju
				if (data[j].Name < data[j + step].Name) {
					std::swap(data[j], data[j + step]);
					BrojZamjena++;
				}
			}
		}
	}

	return BrojZamjena;
}

void SPA::QuickDance::IspisiBrojac(std::ofstream& out) {
	for (int i = 0; i < Brojac; ++i) out << "#";
	out << std::endl;
}

void SPA::QuickDance::QuickSortRec(SPA::SuperHero* data, int left, int right, std::ofstream& out) {
	if (right <= left) {
		return;
	}
	this->Brojac++;
	this->IspisiBrojac(out);

	SPA::SuperHero& pivot = data[left];
	int i = left + 1;
	int j = right;

	while (i <= j && i <= right && j > left) {
		// Pomièemo i u desno dok ne naðemo veæi element.
		while (data[i].Name <= pivot.Name && i <= right) {
			i++;
		}

		// Pomièemo j u lijevo dok ne naðemo manji ili jednak element.
		while (data[j].Name > pivot.Name && j > left) {
			j--;
		}

		// Ako smo našli oba elementa, zamijenimo ih.
		if (i < j) {
			std::swap(data[i], data[j]);
		}
	}

	std::swap(pivot, data[j]);
	this->QuickSortRec(data, left, j - 1, out);
	this->QuickSortRec(data, j + 1, right, out);

	this->Brojac--;
}

SPA::QuickDance::QuickDance(std::vector<SPA::SuperHero>& Heroes) {
	this->MyHero = Heroes;
}

void SPA::QuickDance::Sort(std::ofstream& out) {
	this->QuickSortRec(&this->MyHero[0], 0, this->MyHero.size() - 1, out);
}
