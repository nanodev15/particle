#include <cstdlib>
#include <iostream>
using namespace std;
/***
    Pour compiler tapez :
    g++ exo1bTD1.cpp -o exo1bTD1
*/
int main(int argc, char **argv) {
  int age;
  cout << "Quel est ton âge ?" << endl;
  cin >> age;
  if (age>0)
    cout << "Ok" << endl;
  else
    cout << "Erreur de saisie" << endl;
  return EXIT_SUCCESS;
}
