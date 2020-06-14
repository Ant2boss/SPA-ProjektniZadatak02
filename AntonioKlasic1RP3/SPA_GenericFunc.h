#pragma once
#include <string>

namespace SPA {
	
	void IspisiTitleCard(std::string Text);
	void IspisiPauzu();

	struct KontainerItrajanje {
		std::string ImeKontejnjera;
		double Trajanje;
	};

	void SoritrajKontejnerePoTrajanju(KontainerItrajanje* K, int N);

}