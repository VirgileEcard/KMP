#ifndef __FONCTIONS_H
#define __FONCTIONS_H

#include <string>
#include <vector>
using namespace std;

void help();

void chevauchement (int* Tab, string seq);
string setTxt(string fichTxt);
vector<int> recherche(int Tab[], string seq, string txt);
void affich(int Tab[], int l);
void affichageResultat(string txt, vector<int> res, int l);


#endif
