#include <iostream>
#include "division.hpp"

int main() {
  Polynome ax, bx, qx, rx;

  ax = Polynome(Rationnel(1, 1), 6) + Polynome(Rationnel(5, 1), 5) + Polynome(Rationnel(4, 1), 4) + Polynome(Rationnel(2, 1), 0);
  bx = Polynome(Rationnel(1, 1), 5) + Polynome(Rationnel(3, 1), 4) + Polynome(Rationnel(4, 1), 3);
//  ax = Polynome(Rationnel(1, 1), 2) + Polynome(Rationnel(2, 1), 1) - Polynome(Rationnel(-1, 1), 0);
//  bx = Polynome(Rationnel(1, 1), 2) + Polynome(Rationnel(-1, 1), 0);

  std::cout << "ax : " << ax << std::endl;
  std::cout << "bx : " << bx << std::endl;

  division(ax, bx, qx, rx);

  std::cout << "qx : " << qx << std::endl;
  std::cout << "rx : " << rx << std::endl;
  std::cout << "pgcd : " << plus_grand_commun_diviseur(ax, bx) << std::endl;
  return 0;
}

