#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

namespace SPA {

	template<typename T>
	T Convert(std::string Text);

	struct SuperHero {

		std::string Name;
		std::string Alignment;
		double Inteligence = 0;
		double Strenght = 0;
		double Speed = 0;
		double Durability = 0;
		double Power = 0;
		double Combat = 0;
		double Total = 0;

	};

	class SuperHeroHolder {
		std::vector<SuperHero> VektorHeroja;

		void LoadDoubleFromStream(std::stringstream& ss, double& DataToLoad, char BreakChar = '\n');

	public:
		SuperHeroHolder(std::ifstream& FileStream);

		std::string GetHeroName(int Heroindex);
		std::string GetHeroAlignemt(int Heroindex);
		double GetHeroInteligence(int Heroindex);
		double GetHeroStrenght(int Heroindex);
		double GetHeroSpeed(int Heroindex);
		double GetHeroDurability(int Heroindex);
		double GetHeroPower(int Heroindex);
		double GetHeroCombat(int Heroindex);
		double GetHeroTotal(int Heroindex);

		std::vector<SuperHero>::iterator begin();
		std::vector<SuperHero>::iterator end();

		SPA::SuperHero GetHero(int HeroIndex);

		int GetHeroCount();
	};

	template<typename T>
	T Convert(std::string Text) {
		std::stringstream ss(Text);
		T temp = 0;
		if (ss >> temp) return temp;
		else return 0;
	}

	std::string GetHeroDetails(SPA::SuperHero MyHero);
}