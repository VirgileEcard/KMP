#include "fonctions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string seq, txt, fichTxt;
	bool spefSeq=0, spefTxt=0, aff=0;
	
	//on parcourt les arguments 
	for(int i=0; i<argc; i++){
		
		//affichage du texte d'aide
		if ((string)argv[i]=="help"){
			help();
			return 0;
		}
		
		//définition de la séquence
		if ((string)argv[i]=="s"){
			spefSeq=1;
			try{
				seq=(string)argv[i+1];
			}
			catch(const logic_error & e){
				cout<<"Entrez la sequence a rechercher apres le 's'"<<endl;
			}
		}
		
		//définition du fichier texte dans lequel effectuer la recherche
		if ((string)argv[i]=="t"){
			spefTxt=1;
			try{
				fichTxt=(string)argv[i+1];
			}
			catch(const logic_error & e){
				cout<<"Entrez le nom du fichier apres le 't'"<<endl;
			}
		}		
		
		//option d'affichage du texte avec les occurences de la séquence colorées après la recherche
		if ((string)argv[i]=="a"){
			aff=1;
		}
	}
	
	
	//S'ils n'ont pas été définis dans les arguments, on demande la séquence et/ou le fichier source
	if(!spefSeq){
		cout<<"Entrez la sequence a chercher : ";
		getline(cin, seq);
	}
	
	if(!spefTxt){
		cout<<"Entrez le fichier dans lequel effecture la recherche : ";
		getline(cin, fichTxt);
	}
	
	txt = setTxt(fichTxt);
	
	
	
	//on met en place le tableau des correspondances
	int Tab[seq.length()];
	chevauchement(Tab, seq); 
	
	
	//on effectue la recherche et on stocke la position des occurences de la séquence dans un vector
	vector<int> res = recherche(Tab, seq, txt); 
	
	//on affiche ces occurences
	for(int i=0; i<res.size(); i++){
		cout<<"La sequence est presente a la position "<<res[i]<<endl;;
	}
	
	//si ça a été demandé dans les arguments, on affiche le texte avec les occurences de la séquence colorées en rouge
	if(aff) affichageResultat(txt, res, seq.length());
	
	cout<<endl;
	
	return 0;
}