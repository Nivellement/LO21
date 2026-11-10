#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "carte/carte.h"


namespace Codex {

	class Position {
	private:
		int x;
		int y;
	};

	class CartePlacee {
	private:
		const CartePlacement* carte;
		Position position;
		bool estRecto;
	public:
		CartePlacee(const CartePlacement& cp, Position& pos, bool recto) : carte(cp), position(pos), estRecto(recto) {}
		~CartePlacee();
		CartePlacee(const CartePlacee& c);
		CartePlacee& operator=(const CartePlacee& c);
	};


	class Plateau {
	private:
		vector<CartePlacee> cartesPlacees = {};
	public:
		Plateau();
		~Plateau();
		Plateau(const Plateau& p);
		Plateau& operator=(const Plateau& p);
		bool peutAjouter(const CartePlacement& cp, const Position& pos, bool recto);
		void ajouter(const CartePlacement& cp, const Position& pos, bool recto);
	};

	class Joueur {
	private:
		string nom;
		size_t score;
		vector<const CartePlacement*> mainCartes;
		const CarteObjectif* objectifSecret;
		Plateau plateau;
	public:
		const string& getNom() const { return nom; }
		const size_t getScore() const { return score; }
		const Plateau& getPlateau() const { return plateau; }
		const CarteObjectif& getCarteObjectif() const { return *objectifSecret; }
		const CartePlacement& getCarte(size_t numCarte) const { return mainCartes.at(numCarte); }

		// CHANGEMENT PAR RAPPORT A L'UML : jouerCarte se fait à partir d'un indice 0,1, ou 2, désignant l'indice de la carte dans la main, plutôt qu'une carte de placement directement
		// passée en paramètre.
		void jouerCarte(size_t numCarte, const Position& pos, bool recto);
		size_t calculerScore();
		
	};


}

// AFFICHAGE INTERFACE : dépend de la définition de cout<<(CartePlacement)
std::ostream& operator<<(std::ostream& f, const Codex::Plateau);

#endif // PLAYER_H_INCLUDED
