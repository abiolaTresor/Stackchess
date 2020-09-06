#include"deplacement.h"
case_piece depiece(case_piece* p) {
	case_piece tmp;
	tmp=*p;
	(*p)=(*p)->suivant;
	return tmp;
}
case_piece retour_entete(case_piece p) {
	return p;
}

int test_move_roi(int l1, int c1, int l2, int c2) {
	if((fabs(l2-l1)==1 && c1==c2) || (fabs(c1-c2)==1 && l1==l2) || (fabs(c1-c2)==1 && fabs(l1-l2)==1) || (l1==l2 && c1==c2)) return 1;
	return 0;
}

int test_move_dame(int l1, int c1, int l2, int c2){
	if(l1==l2 || c1==c2 || fabs(c1-c2)==fabs(l1-l2) || (l1==l2 && c1==c2) ) return 1;
	return 0;	
}

int test_move_fou(int l1, int c1, int l2, int c2) {
	if(fabs(c1-c2)==fabs(l1-l2) || (l1==l2 && c1==c2)) return 1;
	return 0;
}

int test_move_tour(int l1, int c1, int l2, int c2) {
	if (c1==c2 || l1==l2 ) return 1;
	return 0;
}

int test_move_pionN(case_piece* echiquier[],int N,int l1, int c1, int l2, int c2) {
	if (test_contient_blanc(echiquier,l2,c2)==0) {
		if(l1<N-1) {
			if((l2==l1-1 && c1==c2) || (l1==l2 && c1==c2)) return 1;
			return 0;
		}
		else {
			if((l1-l2<=2 && l1> l2 && (c1==c2)) || (l1==l2 && c1==c2) ) return 1;
			return 0;
		}
	}
	else {
		if( (l2==l1-1 && fabs(c1-c2)==1) || (l1==l2 && c1==c2)  ) return 1;
		return 0;
	}
}

int test_move_pionB(case_piece* echiquier[], int l1, int c1, int l2, int c2) {
	if (test_contient_noir(echiquier, l2,c2)==0) {
		if(l1>2) {
			if((l1==l2-1 && c1==c2) || (l1==l2 && c1==c2)) return 1;
			return 0;
		}
		else {
			if((l1-l2<=2 && l2> l1 && c1==c2) || (l1==l2 && c1==c2)) return 1;
			return 0;
		}
	}
	else {
		if((l1==l2-1 && fabs(c1-c2)==1) || (l1==l2 && c1==c2)) return 1;
		return 0;
	}
}

int test_libre_dame (case_piece* echiquier[], int l1, int c1, int l2, int c2) {
			int a=1;
			if (l1==l2 && fabs(c1-c2)>1) {
				int b;
				if (c1 < c2) b=c1;
				else b=c2;
				int i =0;
				for(i=0; i< fabs(c1-c2)-1; i++){
					a=a*(  echiquier[l1-1][b+i]==NULL );
				}
			}

			else if (c1==c2 && fabs(l1-l2)>1) {
				int b;
				if (l1 < l2) b=l1;
				else b=l2;
				int i =0;
				for(i=0; i< fabs(l1-l2)-1; i++){
					a=a*(  echiquier[b+i][c1-1]==NULL);
				}

			}
			else if (fabs(c1-c2)==fabs(l1-l2) && fabs(c1-c2)> 1) {
				int i=0;
				for(i=0; i< fabs(c1-c2)-1; i++) {
					if(l1<l2 && c1 < c2) {
						a=a*(echiquier[l1+i][c1+i]==NULL);
					}
					else if (l1<l2 && c2<c1 ){
						a=a*(echiquier[l1+i][c1-i]==NULL);
					}
					else if (l1>l2 && c1 > c2){
						a=a*(echiquier[l1-i][c1-i]==NULL);
					}
					else a=a*(echiquier[l1-i][c1+i]==NULL);
				}
			}
			return a;
		}

int test_libre_fou(case_piece* echiquier[], int l1, int c1, int l2, int c2){
	int a=1;
	if (fabs(c1-c2)==fabs(l1-l2) && fabs(c1-c2)> 1) {
		int i=0;
		for(i=0; i< fabs(c1-c2)-1; i++) {
			if(l1<l2 && c1 < c2) {
				a=a*(echiquier[l1+i][c1+i]==NULL);
			}
			else if (l1<l2 && c2<c1 ){
				a=a*(echiquier[l1+i][c1-i]==NULL);
			}
			else if (l1>l2 && c1 > c2){
				a=a*(echiquier[l1-i][c1-i]==NULL);
			}
			else a=a*(echiquier[l1-i][c1+i]==NULL);
		}
	}	
	return a;
}

int test_libre_tour(case_piece* echiquier[], int l1, int c1, int l2, int c2){
	int a=1;
	if (l1==l2 && fabs(c1-c2)>1) {
		int b;
		if (c1 < c2) b=c1;
		else b=c2;
		int i =0;
		for(i=0; i< fabs(c1-c2)-1; i++){
			a=a*(  echiquier[l1-1][b+i]==NULL );
		}
	}

	else if (c1==c2 && fabs(l1-l2)>1) {
		int b;
		if (l1 < l2) b=l1;
		else b=l2;
		int i =0;
		for(i=0; i< fabs(l1-l2)-1; i++){
			a=a*( echiquier[b+i][c1-1]==NULL);
		}

		}
	return a;
}

int test_libre_pion(case_piece* echiquier[],int size, int l1, int c1, int l2, int c2){
	int a=1;
	int test;
	if (echiquier[l1-1][c1-1]->couleur==noir) test=(test_move_pionN(echiquier,size,l1,c1,l2,c2)==1);
	else test=(test_move_pionB(echiquier,l1,c1,l2,c2)==1);
	if (test==1 && fabs(l1-l2>1)){
		int i=0;
		for(i=0; i<fabs(l1-l2)-1; i++){
			a=a*(echiquier[l1+i][c1-1]==NULL);
		}
	}
	return a;
}

int test_contient_noir( case_piece* echiquier[], int l , int c) {
	case_piece tmp=echiquier[l-1][c-1];
	int compteur =0;
	while(tmp!=NULL) {
		if(tmp->couleur==noir) compteur++;
		tmp=tmp->suivant;
	} /* cette boucle est entetamée car tmp est non NULL. à chaque passage dans la boucle tmp se rapproche de plus en plus vers le bout donc de NULL. tmp vaut NULL à un moment donnner et la boucle s'arrête*/
	if (compteur==0) return 0;
	return 1;
}

int test_contient_blanc( case_piece* echiquier[], int l , int c) {
	case_piece tmp=echiquier[l-1][c-1];
	int compteur =0;
	while(tmp!=NULL) {
		if(tmp->couleur==blanc) compteur++;
		tmp=tmp->suivant;
	} /* cette boucle est entetamée car tmp est non NULL. à chaque passage dans la boucle tmp se rapproche de plus en plus vers le bout donc de NULL. tmp vaut NULL à un moment donnner et la boucle s'arrête*/
	if (compteur==0) return 0;
	return 1;
}


void convert_to_coordonnees( char* str, int* l, int* c) {
	if (longueur_str(str)==3) {
		int a;
		a=str[0]-48;
		int b;
		b=26*(str[2]-48)+str[1]-96;
		*l=a; *c=b;
	}

	if(longueur_str(str)==4) {
		int a;
		a=(str[0]-48)*10+(str[1]-48);
		int b;
		b=26*(str[3]-48)+str[2]-96;
		*l=a; *c=b;
	}
}

int longueur_str(char* str) {
	int compteur=0;
	while (str[compteur] != '\0') {
		compteur++;
	} /*la boucle termine car à chaque passage dans la boucle compteur augmente de 1, i.e compteur est strictement croissant et str étant un chaine de caracrteres finie, il existe un compteur>0 tq str[compteur]='\0'. Ce compteur est atteint et à ce moment la boucle s'interrompt.*/
	return compteur;
}

void enpiecer(case_piece* echiquier[], case_piece p, int l, int c) {
	case_piece tmp=malloc(sizeof(piece));
	tmp->nom=p->nom; tmp->couleur=p->couleur;
	tmp->suivant=echiquier[l-1][c-1];
	echiquier[l-1][c-1]=tmp;
}

int longueur_case(case_piece* echiquier[], int l, int c) {
	case_piece tmp;
	tmp=echiquier[l-1][c-1];
	int compteur=0;
	while (tmp!=NULL) {
		compteur++;
		tmp=tmp->suivant;
	}/* cette boucle finit car à chaque passage dans la boucle l se rapproche de NULL. la liste etant finit, l prend la valeur NULL à un moment et là la boucle s'arrête*/
	return compteur;
}

int test_reste_noir(case_piece* echiquier[], int size){
	int i;
	for (i=0; i<size; i++){
		int j;
		for(j=0; j<size; j++){
			if(echiquier[i][j]!=NULL && echiquier[i][j]->couleur==noir) return 1;
		}
	}
	return 0;
}

int test_reste_blanc(case_piece* echiquier[], int size){
	int i;
	for (i=0; i<size; i++){
		int j;
		for(j=0; j<size; j++){
			if(echiquier[i][j]!=NULL && echiquier[i][j]->couleur==blanc) return 1;
		}
	}
	return 0;
}


int test_move_single(case_piece* echiquier[], int size,case_piece p, int l1, int c1, int l2, int c2){
	switch(p->nom)
	{
		case roi: return test_move_roi( l1,  c1,  l2, c2);
		case dame: return test_move_dame( l1,  c1,  l2, c2)*test_libre_dame(echiquier, l1,  c1,  l2, c2); /*le premier facteur renvoie le résultat du test sans tenir compte des obstacles(autres pièces sur le chemin alors que le deuxième confirme le test sauf en cas de présence d'obstacle où il l'invalide*/
		case fou: return  test_move_fou( l1,  c1, l2,  c2)*test_libre_fou(echiquier, l1,  c1,  l2, c2);
		case tour: return test_move_tour( l1,  c1,  l2, c2)*test_libre_tour(echiquier, l1,  c1,  l2, c2);
		default : if (p->couleur==noir) return test_move_pionN( echiquier,  size,  l1, c1, l2, c2)*test_libre_pion(echiquier,size, l1,  c1,  l2, c2); 
				  else return test_move_pionB(echiquier, l1, c1, l2, c2)*test_libre_pion(echiquier,size, l1, c1, l2, c2); 
}
}

int test_move_bloc(case_piece* echiquier[], int size , int quant, int l1, int  c1,int l2,int c2) {
	int a=1;
	int l= 1;
	case_piece tmp;
	tmp=echiquier[l1-1][c1-1];
	while(l<=quant) {
		a=a*test_move_single(echiquier, size,tmp, l1, c1, l2, c2);
		l++;
		tmp=tmp->suivant;
	}
	return a;
}

case_piece depile_temp(case_piece* echiquier[], int l, int c, int quant){
	case_piece tmp=NULL;
	while (quant>0) {
		case_piece p=NULL;
		p= depiece(&echiquier[l-1][c-1]);
		case_piece q = malloc(sizeof(piece));
		q=p;
		q->suivant=tmp;
		tmp=q;
		quant--;
	} /* cette boucle finit car à chaque passage dans la boucle quant diminue de 1. alors quant vaut 0 à un  moment et là, la boucle s'arrête*/
	return tmp;
}

void faire_move(case_piece* echiquier[], int l1, int c1, int l2, int c2, int quant){
	case_piece tmp= depile_temp(echiquier, l1, c1, quant);
	while (quant>0) {
		enpiecer(echiquier,tmp , l2, c2);
		tmp=tmp->suivant;
		quant--;

	}
}


