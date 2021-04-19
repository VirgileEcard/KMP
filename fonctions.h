#include "fonctions.cpp" //rappel : essayer de régler ça

#ifndef __FONCTIONS_H
#define __FONCTIONS_H



void chevauchement (int* Tab, std::string seq);

vector<int> recherche(int*Tab, std::string seq, std::string txt);

string setTxt(string fichTxt);

void affich(int* Tab, int l);

void help();

void affichageResultat(string txt, vector<int> res, int l);

#endif
