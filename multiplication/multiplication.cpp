#include <iostream>
#include "grandentier.hpp"
#include "cmath"

GrandEntier GrandEntier::operator*(const GrandEntier& grand_entier) const {

  int size = fmax(m_bits.size(), grand_entier.m_bits.size());

  std::vector<bool> grand_entier_copie(grand_entier.m_bits), gauche_copie(m_bits);
  if (grand_entier_copie.size() > gauche_copie.size()) {
    while (grand_entier_copie.size() != gauche_copie.size()) {
      gauche_copie.push_back(false);
    }
  }
  else if (grand_entier_copie.size() < gauche_copie.size()) {
    while (grand_entier_copie.size() != gauche_copie.size()) {
      grand_entier_copie.push_back(false);
    }
  }

  if (size == 0 || grand_entier.m_bits.empty() || m_bits.empty()) {
    return GrandEntier();
  }
  else if (size == 1) {
    return grand_entier.m_bits[0] * m_bits[0];
  }


  std::vector<bool> a_inferieur_vect, a_superieur_vect, b_superieur_vect, b_inferieur_vect;
  for(int i = 0; i< size; i++) {
    if (i < floor(size/2)) {
      a_inferieur_vect.push_back(gauche_copie[i]);
    }
    else if (i >= floor(size/2)) {
      a_superieur_vect.push_back(gauche_copie[i]);
    }
  }

  for(int i = 0; i< size; i++) {
      if (i < floor(size/2)) {
        b_inferieur_vect.push_back(grand_entier_copie[i]);
      }
      else if (i >= floor(size/2)) {
        b_superieur_vect.push_back(grand_entier_copie[i]);
      }
  }

  GrandEntier a_inferieur(a_inferieur_vect), a_superieur(a_superieur_vect), b_inferieur(b_inferieur_vect), b_superieur(b_superieur_vect);


  GrandEntier a_superieur_b_superieur = a_superieur * b_superieur;
  GrandEntier a_inferieur_b_inferieur = a_inferieur * b_inferieur;
  GrandEntier somme_inferieur_superieur = ((a_superieur + a_inferieur) * (b_superieur + b_inferieur)) - a_superieur_b_superieur - a_inferieur_b_inferieur;

  a_superieur_b_superieur.shiftBits(2 * floor(size/2));
  somme_inferieur_superieur.shiftBits(floor(size/2));

  return a_superieur_b_superieur + somme_inferieur_superieur + a_inferieur_b_inferieur;
}
