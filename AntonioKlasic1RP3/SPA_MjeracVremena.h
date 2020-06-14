#pragma once
#include<chrono>

namespace SPA {
	
	class MjeracVremena {
		std::chrono::time_point<std::chrono::steady_clock> begin;
		std::chrono::time_point<std::chrono::steady_clock> end;
	public:
		void Start();
		void End();

		double Count();
		double CountMilis();
	};

}