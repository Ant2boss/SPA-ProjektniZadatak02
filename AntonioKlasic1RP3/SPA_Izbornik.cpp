#include "SPA_Izbornik.h"

#define LINE "================================\n"

#include<iostream>
#include<sstream>
#include<conio.h>

SPA::Izbornik::Izbornik(std::string Title) {
    this->NazivIzbornika = Title;
}

SPA::Izbornik& SPA::Izbornik::SetTitle(std::string Title) {
    this->NazivIzbornika = Title;
    return *this;
}

SPA::Izbornik& SPA::Izbornik::AddOption(SPA::Opcija Option) {
    this->VektorOpcija.push_back(Option);
    return *this;
}

SPA::Izbornik& SPA::Izbornik::AddOption(std::string OptionTitle, std::string OptionDesc) {
    SPA::Opcija T;
    T.Naziv = OptionTitle;
    T.Description = OptionDesc;
    return this->AddOption(T);
}

std::string SPA::Izbornik::GetTitle() {
    return this->NazivIzbornika;
}

std::string SPA::Izbornik::GetOptionTitle(int OptionIndex) {
    return this->VektorOpcija[OptionIndex].Naziv;
}

std::string SPA::Izbornik::GetOptionDesc(int OptionIndex) {
    return this->VektorOpcija[OptionIndex].Description;
}

int SPA::Izbornik::GetOptionCount() {
    return this->VektorOpcija.size();
}

void SPA::Izbornik::RemoveIndexedOption(int OptionIndex) {
    this->VektorOpcija.erase(this->VektorOpcija.begin() + OptionIndex);
}

void SPA::Izbornik::RemoveAllOptions() {
    this->VektorOpcija.clear();
}

int SPA::Izbornik::ExecuteMenu() {
    int pok = 0;
    
    while (1) {
        std::stringstream ssOut;

        system("cls");

        ssOut << LINE << this->NazivIzbornika << std::endl << LINE << std::endl;

        int BrojOpcija = this->GetOptionCount();
        for (int i = 0; i < BrojOpcija; ++i) {
            if (i == pok) ssOut << " >> ";
            else ssOut << "   ";

            ssOut << this->VektorOpcija[i].Naziv;

            if (i == pok) ssOut << " <<";
            ssOut << std::endl;
        }

        ssOut << std::endl << LINE;

        for (int i = 0; i < BrojOpcija; ++i) {
            if (i == pok) {
                ssOut << this->VektorOpcija[i].Description;
                break;
            }
        }

        ssOut << std::endl << LINE;
        ssOut << "[W]   -Pomicanje gore" << std::endl;
        ssOut << "[S]   -Pomicanje dolje" << std::endl;
        ssOut << "[space]   -Odabir opcije" << std::endl;

        std::cout << ssOut.str();

        char com = _getwch();
        if (com == 'w' || com == 'W') {
            pok--;
            if (pok < 0) pok = this->GetOptionCount() - 1;
        }
        else if (com == 's' || com == 'S') {
            pok++;
            if (pok >= this->GetOptionCount()) pok = 0;
        }
        else if (com == ' ') {
            return pok;
        }
    }

    return 0;
}
