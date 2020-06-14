#pragma once
#include<vector>
#include<string>

namespace SPA {

	struct Opcija {
		std::string Naziv;
		std::string Description;
	};
	
	class Izbornik {

		std::vector<SPA::Opcija> VektorOpcija;
		std::string NazivIzbornika;

	public:
		Izbornik(std::string Title);

		SPA::Izbornik& SetTitle(std::string Title);
		SPA::Izbornik& AddOption(SPA::Opcija Option);
		SPA::Izbornik& AddOption(std::string OptionTitle, std::string OptionDesc);

		std::string GetTitle();
		std::string GetOptionTitle(int OptionIndex);
		std::string GetOptionDesc(int OptionIndex);

		int GetOptionCount();

		void RemoveIndexedOption(int OptionIndex);
		void RemoveAllOptions();

		int ExecuteMenu();
	};

}