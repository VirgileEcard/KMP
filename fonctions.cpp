#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include "fonctions.h"

using namespace std;

void help(){
	cout<<"Les arguments suivants sont reconnus par le programme :"<<endl
	<<" help : pour afficher le message d'aide"<<endl
	<<" s : suivi de la séquence à rechercher, sinon elle sera demandée a l'éxecution"<<endl
	<<" t : suivi du nom du fichier texte dans lequel effectuer la recherche, sinon il sera demandé à l'éxecution"<<endl
	<<" a : pour afficher le texte dans lequel les résultats de la recherche sont colorés"<<endl
	<<"Exemple d'utilisation : KMP.exe s ABC t test.txt a"<<endl<<endl;
}

void chevauchement (int* Tab, string seq){
	int l=seq.length();
	
	Tab[0]=0;
	
	for(int i=1; i<l; i++){
		if(seq.at(i)==seq.at((unsigned int)Tab[i-1]))
			Tab[i]=Tab[i-1]+1;
		else
			Tab[i]=0;
		
	}
	
}

string setTxt(string fichTxt){
	string txt="";
	ifstream fichier(fichTxt);
	
	if (fichier){
		string ligne;
		
		while(getline(fichier, ligne)){
			txt+=ligne;
		}
	}
	
	else cout<<"Impossible d'ouvrir le fichier : "<<fichTxt<<endl;
	
	return txt;
}

vector<int> recherche(int Tab[], string seq, string txt){
	int p= 0;
	vector<int> res;
	
	for(int i=0; i<txt.length(); i++){
		while((p>0)&&(seq.at(p)!=txt.at(i))){
			p=Tab[p-1];
		}
		if((seq.at(p))==(txt.at(i))){
			p++;
		}
		if(p==seq.length())
		{
			res.push_back(i-seq.length()+2);
			p=Tab[p-1];
		}
	}
	
	return res;

}


void affich(int Tab[], int l){
	for(int i=0; i<l; i++){
		cout<<Tab[i]<<" ";
	}
}

void affichageResultat(string txt, vector<int> res, int l){
	int i=0, k=0;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 86);
	while(k<res.size()){
		while (i<(res.at(k)-1)){
			cout<<txt.at(i);
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 84);
		while (i<((res.at(k)-1))+l){
			cout<<txt.at(i);
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 86);
		k++;
	}
	
	while(i<txt.length()){
		cout<<txt.at(i);
		i++;
	}
	
	cout<<endl;
}