#include "SPA_Ishod4.h"
#include "SPA_GenericFunc.h"
#include "SPA_Sortovi.h"

#include <iostream>
#include <algorithm>
#include <fstream>

bool UsporedbaHeroja(SPA::SuperHero& H1, SPA::SuperHero& H2) {
	return H1.Name > H2.Name;
}

void SPA::Funkcionalnost_InsertionVsShell(SPA::SuperHeroHolder& Heroes) {

	std::vector<SPA::SuperHero> V1(Heroes.begin(), Heroes.end());
	std::vector<SPA::SuperHero> V2(Heroes.begin(), Heroes.end());

	SPA::MjeracVremena Timer;

	SPA::IspisiTitleCard("Insertion vs Shell");

	std::cout << "Insertion sort: ";
	Timer.Start();
	int BrojZamjena = SPA::insertion_sort(&V1[0], V1.size());
	Timer.End();
	std::cout << Timer.CountMilis() << "ms!" << std::endl;
	std::cout << "Broj zamjena: " << BrojZamjena << std::endl;

	std::cout << "Shell sort: ";
	Timer.Start();
	BrojZamjena = SPA::shell_sort(&V2[0], V2.size());
	Timer.End();
	std::cout << Timer.CountMilis() << "ms!" << std::endl;
	std::cout << "Broj zamjena: " << BrojZamjena << std::endl;
	

	SPA::IspisiPauzu();
}

void SPA::Funkcionalnost_LetsPlayGuess(SPA::SuperHeroHolder& Heroes) {
	SPA::IspisiTitleCard("Lets play guess");

	unsigned BrojElemenata = rand() % 100000000 + 1;
	std::vector<int> VektorBrojeva;
	bool UbaceneJe = false;
	for (int i = 0; i < BrojElemenata; ++i) {
		if (i == 13) UbaceneJe = true;
		VektorBrojeva.push_back(i);
	}
	if (!UbaceneJe) VektorBrojeva[0] = 13;

	double Pogodak;
	std::cout << "Generiran je vekotr sa: " << BrojElemenata << " elemenata!" << std::endl;
	std::cout << "Upisite koliko mislite da ce trajati shuffle, sort, te pretraga za brojem 13 (u mikrosekundama): ";
	std::cin >> Pogodak;
	std::cin.ignore();

	SPA::MjeracVremena Timer;
	Timer.Start();
	std::random_shuffle(VektorBrojeva.begin(), VektorBrojeva.end());
	std::sort(VektorBrojeva.begin(), VektorBrojeva.end());
	std::binary_search(VektorBrojeva.begin(), VektorBrojeva.end(), 13);
	Timer.End();
	auto len = Timer.Count();

	std::cout << "Trajalo je " << len << "us!" << std::endl;
	if (Pogodak == len) std::cout << "Bili ste u pravu!";
	else if (Pogodak > len) std::cout << "Upisali ste previse za: " << Pogodak - len << "us!" << std::endl;
	else std::cout << "Umanjili ste za: " << len - Pogodak << "us!" << std::endl;

	SPA::IspisiPauzu();
}

void SPA::Funkcionalnost_MonkeyPlay(SPA::SuperHeroHolder& Heroes) {
	SPA::IspisiTitleCard("Monkey play");

	std::vector<SPA::SuperHero> VektorHeroja;

	for (int i = 0; i < 6; ++i) {
		int index = rand() % Heroes.GetHeroCount();
		VektorHeroja.push_back(Heroes.GetHero(index));
	}

	//Deterministièka verzija bogo sort-a VVV
	std::ofstream out("MonkeyPlay.txt");
	if (!out) {
		std::cout << "Nije uspjelo stavranje datoteke!" << std::endl;
		exit(1);
	}
	int brojac = 1;
	while (std::next_permutation(VektorHeroja.begin(), VektorHeroja.end(), UsporedbaHeroja)) {
		out << "Permutacija " << brojac++ << ": ";
		for (auto& el : VektorHeroja) out << el.Name << ";";
		out << std::endl;
	}

	out.close();
	std::cout << "Generirana je datoteka 'MonkeyPlay.txt'!" << std::endl;
	SPA::IspisiPauzu();
}

void SPA::Funkcionalnost_TheQuickDance(SPA::SuperHeroHolder& Heroes) {
	SPA::IspisiTitleCard("The quick Dance");
	int N;
	std::cout << "Upisite broj elemenata: ";
	std::cin >> N;
	std::cin.ignore();

	std::vector<SPA::SuperHero> VektorHeroja;
	for (int i = 0; i < N; ++i) {
		int index = rand() % Heroes.GetHeroCount();
		VektorHeroja.push_back(Heroes.GetHero(index));
	}

	std::cout << "Vase polje se soritra!" << std::endl;
	SPA::QuickDance QD(VektorHeroja);

	std::ofstream out("Thequickdance.txt");
	if (!out) {
		std::cout << "Nije uspijelo stvaranje datoteke!" << std::endl;
		exit(1);
	}

	QD.Sort(out);

	out.close();

	std::cout << "Stvorena je datoteka 'Thequickdance.txt' sa rezultatom!" << std::endl;
	SPA::IspisiPauzu();
}
