#include<iostream>
#include<ctime>

#include"SPA_Izbornik.h"
#include"SPA_Heroj.h"
#include"SPA_Ishod3.h"
#include"SPA_Ishod4.h"
#include"SPA_Ishod5.h"

using namespace std;

int main() {

	srand(time(nullptr));

	SPA::Izbornik MainMenu("Probni Izbornik");
	MainMenu.AddOption("Pretraga po imenu", "Pretrazuje super junake po njihovim imenima!");
	MainMenu.AddOption("Prikaz po brzini", "Prikazuje sve super junake u ovisnosti o njihovim brzinama");
	MainMenu.AddOption("Kopiranje u novi vektor", "Prekopirajte odabrane junake u novi vektor");
	MainMenu.AddOption("Prikaz po strani", "Ispis junaka ovisno o njihovim stranama");
	MainMenu.AddOption("Insertion vs Shell", "Provijerite i usporedite trajanje sortiranja ovih dva sorta");
	MainMenu.AddOption("Lets play guess", "Pokusajte pogoditi koliko vremena ce trebati da se pronade broj 13");
	MainMenu.AddOption("Monkey Play", "Izraduje soritrani popis 6 super junaka, koji su sortirani bogo sortom");
	MainMenu.AddOption("The Quick Dance", "Quick sort radi na nekom broju super junaka");
	MainMenu.AddOption("Pretraga po imenu [HASH]", "Pretrazite super junake po imenu, pretraga po hash tablici!");
	MainMenu.AddOption("Vizualiziraj", "Prikaz hash tablice super junaka");
	MainMenu.AddOption("Izrada imena iz imena", "Vidite ako se ime junaka moze stvoriti iz imena junaka");
	MainMenu.AddOption("Izlaz", "Gasi aplikaciju");
	
	ifstream inStream("SPA_PROJ_003_HEROES_data_1.csv");

	if (!inStream) {
		cout << "Datoteka nije pronadena!" << endl;
		return 404;
	}

	SPA::SuperHeroHolder HeroContain(inStream);

	inStream.close();

	while (1) {
		int a = MainMenu.ExecuteMenu();
		system("cls");

		switch (a) {
		case 0:
			SPA::Funkcionalnost_PretragaPoImenu(HeroContain);
			break;
		case 1:
			SPA::Funkcionalnost_PrikazPoBrzini(HeroContain);
			break;
		case 2:
			SPA::Funkcionalnost_KopiranjeUNoviVektor(HeroContain);
			break;
		case 3:
			SPA::Funkcionalnost_PrikazPoStrani(HeroContain);
			break;
		case 4:
			SPA::Funkcionalnost_InsertionVsShell(HeroContain);
			break;
		case 5:
			SPA::Funkcionalnost_LetsPlayGuess(HeroContain);
			break;
		case 6:
			SPA::Funkcionalnost_MonkeyPlay(HeroContain);
			break;
		case 7:
			SPA::Funkcionalnost_TheQuickDance(HeroContain);
			break;
		case 8:
			SPA::Funkcionlanost_PretragaHash(HeroContain);
			break;
		case 9:
			SPA::Funkcionalnost_Vizualiziraj(HeroContain);
			break;
		case 10:
			SPA::Funkcionalnost_ImeIzImena(HeroContain);
			break;
		default:
			return 0;
		}
	}
}