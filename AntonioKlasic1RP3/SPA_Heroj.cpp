#include "SPA_Heroj.h"

void SPA::SuperHeroHolder::LoadDoubleFromStream(std::stringstream& ss, double& DataToLoad, char BreakChar) {
    std::string t;
    getline(ss, t, BreakChar);

    DataToLoad = SPA::Convert<double>(t);
}

SPA::SuperHeroHolder::SuperHeroHolder(std::ifstream& FileStream) {
    std::string t;
    getline(FileStream, t);

    while (getline(FileStream, t)) {
        std::stringstream ss(t);

        SPA::SuperHero TempHero;
        getline(ss, TempHero.Name, ',');
        getline(ss, TempHero.Alignment, ',');

        this->LoadDoubleFromStream(ss, TempHero.Inteligence, ',');
        this->LoadDoubleFromStream(ss, TempHero.Strenght, ',');
        this->LoadDoubleFromStream(ss, TempHero.Speed, ',');
        this->LoadDoubleFromStream(ss, TempHero.Durability, ',');
        this->LoadDoubleFromStream(ss, TempHero.Power, ',');
        this->LoadDoubleFromStream(ss, TempHero.Combat, ',');
        this->LoadDoubleFromStream(ss, TempHero.Total);

        this->VektorHeroja.push_back(TempHero);
    }
}

std::string SPA::SuperHeroHolder::GetHeroName(int Heroindex) {
    return this->VektorHeroja[Heroindex].Name;
}

std::string SPA::SuperHeroHolder::GetHeroAlignemt(int Heroindex) {
    return this->VektorHeroja[Heroindex].Alignment;
}

double SPA::SuperHeroHolder::GetHeroInteligence(int Heroindex) {
    return this->VektorHeroja[Heroindex].Inteligence;
}

double SPA::SuperHeroHolder::GetHeroStrenght(int Heroindex) {
    return this->VektorHeroja[Heroindex].Strenght;
}

double SPA::SuperHeroHolder::GetHeroSpeed(int Heroindex) {
    return this->VektorHeroja[Heroindex].Speed;
}

double SPA::SuperHeroHolder::GetHeroDurability(int Heroindex) {
    return this->VektorHeroja[Heroindex].Durability;
}

double SPA::SuperHeroHolder::GetHeroPower(int Heroindex) {
    return this->VektorHeroja[Heroindex].Power;
}

double SPA::SuperHeroHolder::GetHeroCombat(int Heroindex) {
    return this->VektorHeroja[Heroindex].Combat;
}

double SPA::SuperHeroHolder::GetHeroTotal(int Heroindex) {
    return this->VektorHeroja[Heroindex].Total;
}

std::vector<SPA::SuperHero>::iterator SPA::SuperHeroHolder::begin() {
    return this->VektorHeroja.begin();
}

std::vector<SPA::SuperHero>::iterator SPA::SuperHeroHolder::end() {
    return this->VektorHeroja.end();
}

SPA::SuperHero SPA::SuperHeroHolder::GetHero(int Heroindex) {
    return this->VektorHeroja[Heroindex];
}

int SPA::SuperHeroHolder::GetHeroCount() {
    return this->VektorHeroja.size();
}

std::string SPA::GetHeroDetails(SPA::SuperHero MyHero) {
    std::stringstream ss;

    ss << "Ime: "       << MyHero.Name << std::endl;
    ss << "Strana: "    << MyHero.Alignment << std::endl;
    ss << "Pamet: "     << MyHero.Inteligence << std::endl;
    ss << "Snaga: "     << MyHero.Strenght << std::endl;
    ss << "Brzina: "    << MyHero.Speed << std::endl;
    ss << "Trajnost: "  << MyHero.Durability << std::endl;
    ss << "Snaga: "     << MyHero.Power << std::endl;
    ss << "Borba: "     << MyHero.Combat << std::endl;
    ss << "Ukupno: "    << MyHero.Total << std::endl;

    return ss.str();
}
