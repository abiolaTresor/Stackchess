#include"initialisation.h"
 void initialisation_echiquier( case_piece* echiquier[], int n,couleur_piece couleur, int a, int b){
	int place_roi=n/2 -1;
	ajouter_piece(echiquier, creation_piece(roi, couleur), a, place_roi);
	int place_dame=place_roi+1;
	ajouter_piece(echiquier,creation_piece(dame,couleur), a,place_dame);
	int ecart_dame=n-n/2-1+(n%2); /* nombre de cases séparant la dame du bord*/
	int ecart_roi=n-n/2-1;
	int i=0; /* nombre de cases separant le roi du bord*/
	for(i=1;i<=ecart_dame;i++) {
		if (i%2==1) ajouter_piece(echiquier,creation_piece(fou,couleur), a, place_dame+i);
		else ajouter_piece(echiquier,creation_piece(tour,couleur), a, place_dame+i);

	}
	int k=0;
	for(k=1;k<=ecart_roi;k++) { 
		if (k%2==1) ajouter_piece(echiquier,creation_piece(fou,couleur), a, place_roi-k);
		else ajouter_piece(echiquier,creation_piece(tour,couleur), a, place_roi-k);
	}
	int j=0;
	for(j=0; j<n; j++) {
		ajouter_piece(echiquier, creation_piece(pion,couleur), b, j);
	}
}

case_piece creation_piece(nom_piece nom, couleur_piece couleur) {
	case_piece nv=NULL;
	nv=malloc(sizeof(piece));
	if (nv==NULL) {
		printf("probleme lors de l'installation des pieces dans votre echiquier");
		exit(0);
	} /*ce "if" permet de vérifier si l'allocation a marché, on affiche un message d'erreur et on sort du jeu si l'allocation n'a pas fonctionné*/
	else {
		nv->nom=nom; nv->couleur=couleur; nv->suivant=NULL;
	}
	
	return nv;
}

void ajout(case_piece* l, case_piece p) {
	case_piece nv=NULL;
	nv=malloc(sizeof(*nv));
	if (nv==NULL) {
		printf("probleme lors de l'installation des pieces dans votre echiquier");
		exit(0);
	} /*ce "if" permet de vérifier si l'allocation a marché, on affiche un message d'erreur et on sort du jeu si l'allocation n'a pas fonctionné*/
	else {
		nv->nom=p->nom; nv->couleur=p->couleur; nv->suivant=*l; *l=nv;
	}
}
void ajouter_piece( case_piece* echiquier[], case_piece p, int ligne, int colonne) {
	ajout(&(echiquier[ligne][colonne]),  p);
}

void affichage1 ( int size) {
	int i;
	for (i=0; i<size; i++) {
		int r=i%26;
		int m=97+r;
		int q=i/26;
		char str[3]={' ',' ','\0'};
		str[0]=m; str[1]=q;
		if (i==0) { printf("   %c%d",str[0],str[1]);} /*on laisee un espace de 3 caracteres à gauche. Le plus à gauche ne sera jamais occupé i.e colonne vide à gauche de l'écran. le 2iem sera occupé par un chiffre et le 3iem par un |*/
		
		else if (i < size-1) { printf(" %c%d",str[0],str[1]);}
	    else if (i==size-1) {
	    	printf(" %c%d\n",str[0],str[1]);
	    }
	}
	for (i=0; i<size; i++) {
		if (i==0) {printf("  +--");}
		else if(i<size-1) {
			printf("+--");
		}
		else if(i==size-1) {
			printf("+--+\n");
		}
	}   
	}

void affichage2(case_piece* echiquier[], int size) {
	int i;
	for (i=size; i>=1; i--) {
		if (i/10 >0) {printf("%d|",i);} /*si nombre à deux chiffres on evite le decalage que celà pourrait créer*/
		else {
		printf(" %d|",i); /* on libere l'espace d'un caractere à gauche de l'écran lors de l'affichage de ligne. le i et le | occupe les deux autres espaces laisés avant l'affichage de a0*/
		}
		int j;
		for(j=0; j<size; j++) {
			if (echiquier[i-1][j]==NULL) {
				if(j<size-1) {
					printf("  |");
				}
				else if(j==size-1) { printf("  |\n");}
			}
			else {
				nom_piece nom_tmp=echiquier[i-1][j]->nom;
				couleur_piece couleur_tmp=echiquier[i-1][j]->couleur;
                 if(j<size-1) {
					printf("%c%c|",nom_tmp,couleur_tmp);
				}
				else if(j==size-1) { printf("%c%c|\n",nom_tmp, couleur_tmp);}
			}
		}
		int k; /*après affichae d'une ligne, on affiche toujours les +--+--- qui le sous tendent* */
		for(k=0; k<size; k++) {
			if(k==0) {printf("  +--");}
			else if(k<size-1) {printf("+--");}
			else if(k==size-1) {printf("+--+\n");}
		}
		
}
}


void affichage3(case_piece* echiquier[], char str[], int l, int c) {
	printf("%s :", str);
	case_piece p =echiquier[l-1][c-1];
	while(p!=NULL){
		couleur_piece couleur=p->couleur;
		nom_piece nom=p->nom;
		printf("[%c%c]->", nom, couleur);
		p=p->suivant;
	}
	printf("[NULL]\n\n");
}
