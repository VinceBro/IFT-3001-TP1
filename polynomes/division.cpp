#include "division.hpp"

#include <assert.h>

void division(const Polynome& dividende, // Le polynome qui est divise
	      const Polynome& diviseur,  // Le polynome qui divise
	      Polynome& quotient,	   // Parametre de sortie: le resultat de la division
	      Polynome& reste) {	   // Parametre de sortie: le reste de la division
  assert(diviseur.degre() > 0 || diviseur.coefficient(0).numerateur() != 0); // Pas de division par zero

  Polynome reste_courant, dividende_intermediaire, terme_courant;
  Polynome dividende_courant(dividende);
  Rationnel coefficient_terme_courant;
  int degre_diviseur = diviseur.degre();
  int degre_dividende_courant = dividende_courant.degre();

  while (degre_dividende_courant >= degre_diviseur) {

      coefficient_terme_courant = dividende_courant.coefficient(degre_dividende_courant) / diviseur.coefficient(degre_diviseur);
      Polynome terme_courant(coefficient_terme_courant, degre_dividende_courant - degre_diviseur);

      dividende_intermediaire = terme_courant * diviseur;
      reste_courant = dividende_courant - dividende_intermediaire;
      dividende_courant = reste_courant;

      degre_dividende_courant = dividende_courant.degre();

      quotient = quotient + terme_courant;
  }

  reste = Polynome(reste_courant);
}

Polynome plus_grand_commun_diviseur(const Polynome& a, const Polynome& b) {
  assert(a >= b);
  assert(a.degre() > 0 || a.coefficient(0).numerateur() != 0);

  //m = a, n = b

  // implémenter le tour de passe passe pour améliorer l'éxécution? -> m mod n
  Polynome qx, rx, ax(a), bx(b);

  while (bx.degre() > 0) {
    division(ax, bx, qx, rx);
    ax = Polynome(bx);
    bx = Polynome(rx);
  }

  return ax;
}
