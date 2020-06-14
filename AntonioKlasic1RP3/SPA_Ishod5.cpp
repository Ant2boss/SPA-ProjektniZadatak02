#include "SPA_Ishod5.h"
#include"SPA_MjeracVremena.h"

#include<unordered_map>
#include<iostream>

void Fill(std::unordered_map<std::string, SPA::SuperHero>& mh, SPA::SuperHeroHolder& h) {

	int c = h.GetHeroCount();

	for (int i = 0; i < c; ++i) {
		mh.emplace(h.GetHeroName(i), h.GetHero(i));
	}

}

void SPA::Funkcionlanost_PretragaHash(SPA::SuperHeroHolder& Heroes) {

	std::unordered_map<std::string, SPA::SuperHero> MapaHeroja;
	Fill(MapaHeroja, Heroes);

	SPA::IspisiTitleCard("Pretraga po imenu [hash tablica]");

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
	BrojacVremena[1] = Timer.Count();

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
		{"[Unordered_map]", BrojacVremena[0]},
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

void SPA::Funkcionalnost_Vizualiziraj(SPA::SuperHeroHolder& Heroes) {

	SPA::IspisiTitleCard("Vizualiziraj");

	std::unordered_multimap<std::string, SPA::SuperHero> MultimapaHeroja;

	int c = Heroes.GetHeroCount();
	for (int i = 0; i < c; ++i) {
		MultimapaHeroja.emplace(Heroes.GetHeroName(i), Heroes.GetHero(i));
	}

	int BucketCount = MultimapaHeroja.bucket_count();
	for (int i = 0; i < BucketCount; ++i) {
		std::cout << "Bucket [" << i << "]: ";
		if (MultimapaHeroja.begin(i) == MultimapaHeroja.end(i)) std::cout << "[EMPTY]";

		for (auto it = MultimapaHeroja.begin(i); it != MultimapaHeroja.end(i); ++it) {

			if(it != MultimapaHeroja.begin(i)) std::cout << " -- ";
			std::cout << it->first;

		}
		std::cout << std::endl;
	}

	SPA::IspisiPauzu();
}

void SPA::Funkcionalnost_ImeIzImena(SPA::SuperHeroHolder& Heroes) {
	SPA::IspisiTitleCard("Ime iz imena");
	std::string S1;
	std::string S2;

	std::cout << "Upisite prvo ime: ";
	getline(std::cin, S1);

	std::cout << "Upisite drugo ime: ";
	getline(std::cin, S2);


	std::unordered_map<char, int> mapaPotrebnihSlova;
	std::unordered_map<char, int> mapaPrebrojanihSlova;
	for (auto& el : S1) {
		std::tolower(el);
		mapaPrebrojanihSlova[el]++;	//Prebrojimo slova u ponudi
	}
	for (auto& el : S2) {
		std::tolower(el);
		mapaPotrebnihSlova[el]++;	//Prebrojimo slova koja su potrebna
	}

	bool imeJeIspravno = true;
	for (auto it = mapaPotrebnihSlova.begin(); it != mapaPotrebnihSlova.end(); ++it) {
		auto BrojSlovaUPrvomImenu = mapaPrebrojanihSlova.find(it->first);
		if (BrojSlovaUPrvomImenu == mapaPrebrojanihSlova.end()) continue;
		if (BrojSlovaUPrvomImenu->second < it->second) {
			imeJeIspravno = false;
			break;
		}
	}

	if (imeJeIspravno) std::cout << "Moguce je konstruirati ime " << S2 << " sa imenom " << S1 << "!" << std::endl;
	else std::cout << "Nije moguce konstruirati ime " << S2 << " sa imenom " << S1 << "!" << std::endl;

	SPA::IspisiPauzu();
}

