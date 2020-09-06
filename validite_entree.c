#include"validite_entree.h"
#include"deplacement.h"
int test_entree_changement(char str[]) {
	if (longueur_str(str)!=1) { return -1;}
	else if (str[0]!='c' && str[0]!='d' ) {return 0;}
	else return 1;
}

int test_entree_case(char str[], int n) {
	int a=n/10; /* cette ligne nous permet d'avoir le nombre de chiffres dans n, taille de l'echiquier. C'est le seul moyen d'étudier efficacement la validité de l'entree car la longueur de cette derniere depend du nombre de chiffre dans n*/
	if(a==0) {
		if(longueur_str(str)!=3) {return -1;}
		else {/*si la longueur est bonne on va étudier chaque caractere. Pour celà, on utilise le caractere bijectif de la table de correspondance ASCII*/
			int a=1;
			int b=(n-1)%26+97;/*pour avoir l'equivalent entier de la  plus grande lettre referencee dans l'echiquier*/
			if (n<=26) {/* la condition sur le 2iem caractere depent de la position de n par rapport à 26*/
				a=(str[0]>=49 && str[0]<= n+48)*(str[1]>=97 && str[1]<=b);/*si le premier caractere est dan [1;n] et le second a une lettre referencee dans l'echiquier, a vaut toujours1. Sinon, il devient nul*/
			}
			else {
				a=(str[0]>=49 && str[0]<= n+48)*(str[1]>=97 && str[1]<=122);/*si le premier caractere est dan [1;n] et le second a une lettre referencee dans l'echiquier, a vaut toujours1. Sinon, il devient nul*/
			}
			b=n/26+48;/*pour tester le 3iem caractere. Il depend du nombre de multiple de 26 plus petit que n. On ajoute 48 pour translater en équivalent ASCII*/
			a=a*(str[2]>=48 && str[2]<=b);/*a vaut 1 si le 3iem caractere est valide et 0 sinon*/
			return a;
		}
	}
	else  {
		if(longueur_str(str)!=4) {return -1;}
		else {/*si la longueur est bonne on va vérifier la validité de chaque caractere*/
			int a=1;
			int b=(n-1)%26+97;
			int c1=str[0]-48;/*on cherche l'equivalent entier du premier caractere en ASCII qu'on translate dans la normale. Ce chiffre est sensé représenté le chiffre de dizaine du numero de ligne entrée*/
			int c2=str[1]-48;/*on cherche l'equivalent entier du 2iem caractere en ASCII qu'on translate dans la normale. Ce chiffre est sensé représenté le chiffre des unités du  numero de colonne ligne entrée*/
			int c=10*c1+c2;/*si entree bonne c1 est le numéro de ligne entrée*/
			a=a*(1<=c && c<=n);/*a vaut 1 si numero de ligne valide i.e lignedans [1;n]. a vaut 0 sinon*/
			if (n<=26) {/*on separe selon n pour traiter le second caractere*/
				a=a*(str[2]>=97 && str[2]<=b);/*a vaut 1 si 3iem caractere valide i.e c'est une lettre referencee dans l'echiquiet*/
			}
			else a=a*(str[2]>=97 && str[2]<=122);/*a vaut 1 si 3iem caractere valide i.e c'est une lettre referencee dans l'echiquier. a vaut 0 sinon*/
			b=n/26+48;/*comme au cas précédent*/
			a=a*(str[3]>=48 && str[3]<=b);/*a vaut 1 si le 4iem caractere est valide et 0 sinon */
			return a; /*si un des criteres de validité d'entree a échoué, a prendra la valeur 0. sinon a restera 1*/

		}
	}
}


int test_entree_taille(char str[]) {
	if(longueur_str(str)==0) {
		return 0;
	}
	else if(longueur_str(str)==1) {
		if(50<= str[0] && 57>= str[0]) {return 1;}
		else return 2;
	}
	else {
		if(50<= str[0] && 57>= str[0] && 50<= str[1] &&  57>= str[0]) {
			if (longueur_str(str)==2) {return 3;}
			else return 2;
		}
		else return 2;
	} 
}


int test_entree_quant(char str[] ) {
	int i;
	for(i=0; i < longueur_str(str); i++){
		if ( 48>str[i] || 57 < str[i] ) { return 0;}
		}
	return 1;
	}

int convert_to_quant(char str[]) {
	int l=longueur_str(str);
	int i=0;
	int a=0;
	while(str[i]!='\0') {
		int tmp=l-i-1;
		a=a+(str[i]-48)*puiss(10,tmp);
		i++;
	}
	return a;
}

int puiss(int n, int b) {
	if(n==0) return 0;
	else if (b==0) return 1;
	else return n*puiss(n, b-1);
}

int test_quit(char str[]) {
	if(longueur_str(str)==1 && str[0]=='a') return 1;
	else return 0;
}