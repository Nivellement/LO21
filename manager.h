#include <cstddef>
#include <string>
#include <vector>
#include "jeu.h"
#include "player.h"
#include "pioche.h"
#include "iA.h"

namespace Codex {

	class ManagerException {
		std::string info;
	public:
		ManagerException(const std::string& i) : info(i) {}
		const std::string& getInfo() const { return info; }
	};


	// Ou piocher en fin de tour (type dorure ou ressource, face visible ou cachee)
	enum class SourcePioche { CacheeRessource, CacheeDorure, VisibleRessource, VisibleDorure };

	struct ChoixPioche {
		SourcePioche source;
		size_t indice;
	};

	// Une action de pose, decidee par le joueur (ou l'IA) puis verifiee et executee par le Manager
	struct Coup {
		size_t indiceMain;
		size_t i;//Position sur le plateau visé
		size_t j;
		Face face;// Face::Recto ou Face::Verso
	};


	class Manager {
	protected:
		Jeu jeu;// declaré AVANT les pioches: elles se construisent a partir de lui
		std::vector<std::string> nomsJoueurs;// un Joueur ne peut etre cree qu'une fois sa carte depart connue: on garde les noms
		std::vector<Joueur*> joueurs;// crees dans distribuer(), detruits dans ~Manager()
		PiocheRessource* piocheRessource;
		PiocheObjectif* piocheObjectif;
		PiocheDorure* piocheDorure;
		PiocheDepart* piocheDepart;

		std::vector<const CarteRessource*> cartesRessourceVisibles;// 2 cartes face visible
		std::vector<const CarteDorure*> cartesDorureVisibles;// 2 cartes face visible
		std::vector<const CarteObjectif*> objectifsCommuns;// 2 objectifs communs

		size_t joueurCourant;// indice dans joueurs
		size_t tour;// numero du tour (commence a 1), augmente quand tous les joueurs ont joue
		bool finDeclenchee;// un joueur a atteint SEUIL_FIN points ou les pioches sont epuisees
		size_t dernierTour;// numero du dernier tour a jouer, n'a de sens que si finDeclenchee

		static const size_t SEUIL_FIN = 20;

		// Cree les pioches a partir du Jeu. noms : de 1 a 4 noms, sinon ManagerException
		explicit Manager(const std::vector<std::string>& noms);

	public:
		virtual ~Manager();// detruit les joueurs et les pioches
		Manager(const Manager&) = delete;
		Manager& operator=(const Manager&) = delete;

		virtual void distribuer();// mise en place complete (voir README)
		virtual void jouerTour() = 0;
		virtual bool verifierFinPartie() const;// true quand le dernier tour est termine

		void jouerPartie();// distribuer(), boucle de jouerTour(), calculerScoresFinaux()
		void calculerScoresFinaux();// ajoute aux scores les points des objectifs communs et secrets
		std::vector<const Joueur*> getGagnants() const;// plusieurs joueurs en cas d'egalite

		// LECTURE:
		const Jeu& getJeu() const { return jeu; }
		size_t getNbJoueurs() const { return joueurs.size(); }
		const Joueur& getJoueur(size_t i) const { return *joueurs.at(i); }
		const Joueur& getJoueurCourant() const { return *joueurs.at(joueurCourant); }
		size_t getIndiceJoueurCourant() const { return joueurCourant; }
		size_t getTour() const { return tour; }
		bool isFinDeclenchee() const { return finDeclenchee; }
		const std::vector<const CarteRessource*>& getCartesRessourceVisibles() const { return cartesRessourceVisibles; }
		const std::vector<const CarteDorure*>& getCartesDorureVisibles() const { return cartesDorureVisibles; }
		const std::vector<const CarteObjectif*>& getObjectifsCommuns() const { return objectifsCommuns; }

	protected:

		//Mise en place (appelees par distribuer(), dans cet ordre)
		void creerJoueurs();// par joueur : carte depart piochee, face choisie, Joueur cree
		void distribuerMains();// 2 cartes ressource + 1 carte dorure par joueur
		void initialiserCartesVisibles();// 2 ressource + 2 dorure face visible
		void distribuerObjectifs();// 2 objectifs communs ; par joueur : 2 piochees, 1 gardee (secret), l'autre au fond de la pioche

		//Tour d'un joueur : poser 1 carte puis piocher 1 carte
		void jouerTourJoueur(Joueur& j);
		bool coupValide(const Joueur& j, const Coup& c) const;// emplacement (Plateau) + cout de pose si carte dorure
		void appliquerCoup(Joueur& j, const Coup& c);// pose la carte et ajoute ses points au score
		bool sourceDisponible(const ChoixPioche& choix) const;// pioche non vide / carte visible presente
		const CartePlacement& piocherCarte(const ChoixPioche& choix);// si visible: remplacee par une cachee du meme type

		//Decisions du joueur
		virtual Face choisirFaceDepart(const std::string& nom, const CarteDepart& carte) const;
		virtual const CarteObjectif& choisirObjectifSecret(const std::string& nom, const CarteObjectif& a, const CarteObjectif& b) const;
		virtual Coup choisirCoup(const Joueur& j) const;
		virtual ChoixPioche choisirPioche(const Joueur& j) const;

		//Truc pour avancer la partie
		void passerAuJoueurSuivant();// joueurCourant + 1 ; tour + 1 apres le dernier joueur
		void majFinDePartie();// a appeler apres chaque tour de joueur ! : declenche la fin
		bool piochesEpuisees() const;// pioches ressource ET dorure vides
	};


	class ManagerMulti : public Manager {
	public:
		explicit ManagerMulti(const std::vector<std::string>& noms);    // 2 a 4 joueurs, sinon ManagerException
		void jouerTour() override;
	};


	class ManagerSolo : public Manager {
	private:
		IA* ia;// Tybor : cree et detruit par ManagerSolo (composition)
	public:
		explicit ManagerSolo(const std::string& nom);
		~ManagerSolo();
		void distribuer() override;// Manager::distribuer() + mise en place de Tybor
		void jouerTour() override;
		bool verifierFinPartie() const override;// le score de Tybor compte aussi
	};

}

#endif
