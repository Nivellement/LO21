#include "carte/carte.h"


namespace Codex {


	class Jeu {
	private:
		const CarteRessource* cartesRessource[40];
		const CarteDorure* cartesDorure[40];
		const CarteDepart* cartesDepart[6];
		const CarteObjectif* cartesObjectif[16];
	public:

	// A REMPLIR : Forme canonique
		Jeu();
		Jeu(const Jeu&);
		~Jeu();
		Jeu& operator=(const Jeu&);

		Jeu()
		const size_t getNbCartesRessource() const { return 40 };
		const size_t getNbCartesDorure() const { return 40 };
		const size_t getNbCartesDepart() const { return 6 };
		const size_t getNbCartesObjectif() const { return 16 };

		const CarteRessource* getCarteRessource(size_t i) const;
		const CarteDorure* getCarteDorure(size_t i) const;
		const CarteDepart* getCarteDepart(size_t i) const;
		const CarteObjectif* getCarteObjectif(size_t i) const;
	};


}