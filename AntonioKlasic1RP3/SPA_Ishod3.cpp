#include "SPA_Ishod3.h"
#include "SPA_MjeracVremena.h"
#include "SPA_Izbornik.h"
#include "SPA_GenericFunc.h"

#include<map>
#include<iostream>
#include<string>
#include<conio.h>
#include<chrono>
#include<list>
#include<queue>

bool UsporedbaStringova(const std::string& S1, const std::string& S2) {
	int len = std::min(S1.length(), S2.length());
	for (int i = 0; i < len; ++i) {
		if (S1[i] != S2[i]) {
			return S1[i] > S2[i];
		}
	}

	return S1.length() > S2.length();
}

struct UsporedbaHerojaNajbrzi {
	bool operator() (SPA::SuperHero H1, SPA::SuperHero H2){
		return H1.Speed < H2.Speed;
	}
};

struct UsporedbaHerojaNajsporiji {
	bool operator() (SPA::SuperHero H1, SPA::SuperHero H2) {
		return H1.Speed > H2.Speed;
	}
};

struct UsporedbaHerojaPoStrani {
	bool operator() (SPA::SuperHero H1, SPA::SuperHero H2) {
		if (H1.Alignment == H2.Alignment) return UsporedbaStringova(H1.Name, H2.Name);
		else return !UsporedbaStringova(H1.Alignment, H2.Alignment);
	}
};

void Fill(std::map<std::string, SPA::SuperHero>& mh, SPA::SuperHeroHolder& h) {

	int c = h.GetHeroCount();

	for (int i = 0; i < c; ++i) {
		mh.emplace(h.GetHeroName(i), h.GetHero(i));
	}

}

void SPA::Funkcionalnost_PretragaPoImenu(SPA::SuperHeroHolder& Heroes) {

	std::map<std::string, SPA::SuperHero> MapaHeroja;
	Fill(MapaHeroja, Heroes);

	SPA::IspisiTitleCard("Pretraga po imenu");

	std::string ImeHeroja;
	std::cout << "Upisite ime heroja: ";
	getline(std::cin, ImeHeroja);

	double BrojacVremena[3];
	SPA::MjeracVremena Timer;

	//Pretraga po mapi
	Timer.Start();
	auto H = MapaHeroja.find(ImeHeroja);
	Timer.End();
	BrojacVremena[0] = Timer.Count();

	//Pretraga po vekotru
	std::vector<SPA::SuperHero> VektorHeroja;
	int BrojHeroja = Heroes.GetHeroCount();
	for (int i = 0; i < BrojHeroja; ++i) {
		VektorHeroja.push_back(Heroes.GetHero(i));
	}

	Timer.Start();
	for (int i = 0; i < VektorHeroja.size(); ++i) {
		if (ImeHeroja == VektorHeroja[i].Name) break;
	}
	Timer.End();
	BrojacVremena[1]= Timer.Count();

	//Pretraga po listi
	std::list<SPA::SuperHero> HeroList(VektorHeroja.begin(), VektorHeroja.end());
	Timer.Start();
	for (auto it = HeroList.begin(); it != HeroList.end(); ++it) {
		if (ImeHeroja == it->Name) break;
	}
	Timer.End();
	BrojacVremena[2] = Timer.Count();


	std::cout << "================================\n";
	if (H != MapaHeroja.end()) {
		//Heroj postoji u listi
		std::cout << SPA::GetHeroDetails(H->second) << std::endl;
	}
	else {
		//Heroj nije pronaden
		std::cout << "Heroj kojeg ste upisali ne postoji u listi" << std::endl;
	}

	KontainerItrajanje KIT[3]{
		{"[Mapa]", BrojacVremena[0]},
		{"[Vektor]", BrojacVremena[1]},
		{"[Lista]", BrojacVremena[2]},
	};

	SoritrajKontejnerePoTrajanju(KIT, 3);

	std::cout << "================================\n";
	for (int i = 0; i < 3; ++i) {
		std::cout << KIT[i].ImeKontejnjera << " -> " << KIT[i].Trajanje << "us!" << std::endl;
	}
	SPA::IspisiPauzu();
}

void SPA::Funkcionalnost_PrikazPoBrzini(SPA::SuperHeroHolder& Heroes) {

	SPA::Izbornik Iz("Prikaz po brzini");
	Iz.AddOption("Prvo najbrzi", "Prikazuje heroje po brzini pocevsi od najbrzih");
	Iz.AddOption("Prvo najsporiji", "Prikazuje heroje po brzini pocevsi od najsporijih");

	int Opcija = Iz.ExecuteMenu();

	system("cls");
	SPA::IspisiTitleCard("Prikaz po brzini");
	if (Opcija == 0) {
		std::priority_queue<SPA::SuperHero, std::vector<SPA::SuperHero>, UsporedbaHerojaNajbrzi> pq;

		int c = Heroes.GetHeroCount();
		for (int i = 0; i < c; ++i) {
			pq.push(Heroes.GetHero(i));
		}

		int num = 1;
		while (!pq.empty()) {
			std::cout << "[" << num++ << "]" << pq.top().Name << ", " << pq.top().Speed << std::endl;
			pq.pop();
		}

	}
	else {

		std::priority_queue<SPA::SuperHero, std::vector<SPA::SuperHero>, UsporedbaHerojaNajsporiji> pq;

		int c = Heroes.GetHeroCount();
		for (int i = 0; i < c; ++i) {
			pq.push(Heroes.GetHero(i));
		}

		int num = 1;
		while (!pq.empty()) {
			std::cout << "[" << num++ << "]" << pq.top().Name << ", " << pq.top().Speed << std::endl;
			pq.pop();
		}
		
	}
	SPA::IspisiPauzu();
}

void SPA::Funkcionalnost_KopiranjeUNoviVektor(SPA::SuperHeroHolder& Heroes) {

	std::multimap<double, SPA::SuperHero> MapaHeroja;

	int Count = Heroes.GetHeroCount();
	for (int i = 0; i < Count; ++i) {
		MapaHeroja.emplace(Heroes.GetHeroTotal(i), Heroes.GetHero(i));
	}

	bool provjera;

	do {

		system("cls");
		SPA::IspisiTitleCard("Koprianje u novi vektor");

		int maxTotal;
		int minTotal;

		std::cout << "Upisite maksimalnu vrijednost za total: ";
		std::cin >> maxTotal;
		std::cin.ignore();
		std::cout << "Upisite minimalnu vrijednost za total: ";
		std::cin >> minTotal;
		std::cin.ignore();

		std::vector<SPA::SuperHero> VektorHeroja;

		for (auto it = MapaHeroja.begin(); it != MapaHeroja.end(); ++it) {
			if (it->first >= minTotal && it->first <= maxTotal) {
				VektorHeroja.push_back(it->second);
			}
		}

		std::cout << "================================\n";
		int redniBroj = 1;
		for (auto& element : VektorHeroja) {
			std::cout << "[" << redniBroj++ << "]" << element.Name << ", " << element.Total << std::endl;
		}
		if (VektorHeroja.empty()) std::cout << "Nije pronaden heroj u to rasponu!" << std::endl;
		std::cout << "================================\n";

		std::cout << "Zelite li ponovno pretrazivati (1 - da, 0 - ne): ";
		std::cin >> provjera;
		std::cin.ignore();

	} while (provjera);

}

void SPA::Funkcionalnost_PrikazPoStrani(SPA::SuperHeroHolder& Heroes) {

	std::priority_queue<SPA::SuperHero, std::vector<SPA::SuperHero>, UsporedbaHerojaPoStrani> pqHeroja(Heroes.begin(), Heroes.end());
	
	SPA::IspisiTitleCard("Prikaz po strani");

	int Counter = 1;
	while (!pqHeroja.empty()) {
		std::cout << "[" << Counter++ << "]" << pqHeroja.top().Name << ", " << pqHeroja.top().Alignment << std::endl;
		pqHeroja.pop();
	}

	SPA::IspisiPauzu();
}
