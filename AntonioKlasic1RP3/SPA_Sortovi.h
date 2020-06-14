#pragma once
#include"SPA_Heroj.h"

#include<fstream>

namespace SPA {
	
	int insertion_sort(SPA::SuperHero data[], int n);
	int shell_sort(SPA::SuperHero data[], int n);

	class QuickDance {
		std::vector<SPA::SuperHero> MyHero;
		int Brojac = 0;

		void IspisiBrojac(std::ofstream& out);
		void QuickSortRec(SPA::SuperHero* data, int left, int right, std::ofstream& out);

	public:
		QuickDance(std::vector<SPA::SuperHero>& Heroes);
		void Sort(std::ofstream& out);
	};
}