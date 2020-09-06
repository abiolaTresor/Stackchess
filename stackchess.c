#include<stdlib.h>
#include<stdio.h>
#include"initialisation.c"
#include"deplacement.c"
#include"validite_entree.c"
int main(){
	char taille_prov[100]; /*récupère la saisie de taille de l'échiquier. Après traitement de l'acceptabilité, entree convertit et entré dans n*/
	int n;/*Pour contenir la taille de l'échiquier*/
	int test_entree=0;/*va être la condition de while. permet de s'assurer qu'une entree est correcte avant de continuer: il vaut zéro à l'entree d'une boucle while et 1 quan l'entree est valide. On le remet à 0 àprès chaque entree valide*/
	printf("\n     		&&&____BIENVENUE AU STACKCHESS____&&&\n\n");
	char nom1[100]; char nom2[100];
	printf("ENTREZ VOTRE NOM POUR LES PIECES BLANCHES:  ");
	scanf("%s", nom1);
	if(test_quit(nom1)==1) {
		printf("\n A bientot.\n");
		exit(0);
	}
	printf("%s", nom1);
	printf("\n");
	printf("ENTREZ VOTRE NOM POUR LES PIECES NOIRES:  ");
	scanf("%s", nom2);
	if(test_quit(nom2)==1) {
		printf("\n A bientot.\n");
		exit(0);
	}
	while (test_entree==0) {/*finit quand l'utilisateur entre une taille valide.on teste si la taille entrée par les joueurs est un nombre. Si c'est un nombre on passe. Autrement on retape.*/
		printf("\nENTREZ LA TAILLE D'ECHIQUIER SOUHAITEE:  ");
		scanf("%s", taille_prov);
		if(test_quit(taille_prov)==1) {
		printf("\n A bientot.\n");
		exit(0);
		}
		if (test_entree_taille(taille_prov)==0) {
			test_entree=1;
			n=6;
		}
		else if (test_entree_taille(taille_prov)==1){
			test_entree=1;
			n=taille_prov[0]-48;
		}
		else if (test_entree_taille(taille_prov)==3) {
			test_entree=1;
			n=10*(taille_prov[0]-48)+taille_prov[1]-48;
			}
			else {
				
				printf("\nVotre entree est trop longue ou contient des caracteres invalides. Il faut un entier >= 2\n");

			}
		}  /*finit dès que l'utilisateur parvient à entrer une taille valide*/ 
	
	test_entree=0; /*remis à 0 pour d'éventuels futurs tests d'entree*/
	case_piece* echiquier[n];
	int k=0;
	for(k=0; k<n; k++){
	echiquier[k]=malloc(n*sizeof(case_piece*));
	}
	int i =0;
	for(i=0; i<n; i++){
		echiquier[i]=malloc(n*sizeof(case_piece));
		int j=0;
		for(j=0; j<n; j++){
			echiquier[i][j]=NULL;
		}
	 }
	initialisation_echiquier(echiquier ,n,noir, n-1, n-2);
	initialisation_echiquier(echiquier ,n,blanc, 0, 1);

	
	printf("\n                     VOILA! VOTRE ECHIQUIER EST PRET! \n\n");
	affichage1(n);
	affichage2(echiquier, n);
	int indicateur_tour=1;
	while(test_reste_noir(echiquier,n) && test_reste_blanc(echiquier,n)) { /*finit dès que plus de noirs ou de blancs*/
		if (indicateur_tour==1){
			printf("\n\n%s,C'EST VOTRE TOUR\n", nom1);
			int l1; int c1; int l2; int c2; /* entiers qui permettront de stocker les valeurs de lignes et colonnes de cases à vider ou remplir*/
			char indicateur_changement_prov[100];/*_prov pour dire provisoire. la demande d'occuper une telle taille en mémoire nous permettra de reccueillir n'importe qu'elle entrée et de la traiter en interne*/
			indicateur_changement_prov[0]='c';
			char case_choisie_prov[100];/*pareil*/
			char case_cible_prov[100];/*Pareil*/
			/*Pour la case choisie et la case cible, on va créer une vraie case poutér récupérer l'entrée lorsqu'elle aura passé tous les test de validi*/
			char quant_prov[100];/*permet de récupérer la quantité que veut déplacer le joueur. Cette entree sera traitée et enregistrer dans quant si elle passe test d'entree*/
			int quant;
			int test_move_possible=0;/*va etre la condition de while. Permet de s'assurer qu'une entree valide permet un déplacement */
			while(indicateur_changement_prov[0]=='c') { /*finit dès qu'on saist 'c'*/
				test_entree=0;
				while(test_entree==0){/*boucle permettant de vérifier l'entrée de case potentiellement à déplacer*/
					printf("\nENTREZ UNE CASE:  ");
					scanf("%s",case_choisie_prov);
					if(test_quit(case_choisie_prov)==1) {
						printf("\n A bientot.\n");
						exit(0);
					}
					if (n/10==0) {/* ce cas correspond au cas où n est fait d'un seul chiffre*/
						if (test_entree_case(case_choisie_prov, n)==-1) printf("\nVotre entree est trop longue ou trop courte\n.");
						else if(test_entree_case(case_choisie_prov, n)==0) printf("\nVotre entree contient des caracteres invalides.\n");
						else {
							test_entree=1; /*une entree valide étant obtenu, on fait passer le test de l'entrée*/
						}
					}
					else { /* si n contient 2 chiffres*/
						if (test_entree_case(case_choisie_prov, n)==-1) printf("\nVotre entree est trop longue ou trop courte.\n");
						else if(test_entree_case(case_choisie_prov, n)==0) printf("\nVotre entree contient des caracteres invalides.\n");
						else {
						test_entree=1; /*une entree valide étant obtenu, on fait passer le test de l'entrée*/
						}
					}
				}
				convert_to_coordonnees( case_choisie_prov, &l1, &c1);
				test_entree=0; /*on remet test_entree à 0 au cas où il doit re-servir*/
				affichage1(n);
				affichage2(echiquier, n);
				affichage3(echiquier, case_choisie_prov, l1, c1);
				while (test_entree==0){ /*finit dès que l'entrée est est bonne. on veille bien dans ce cas à mettre tes_entree à 1*/
					printf("\n ENTREZ 'c' POUR CHANGER OU 'd' POUR DEPLACER:  ");
					scanf("%s", indicateur_changement_prov);
					if(test_quit(indicateur_changement_prov)==1) {
						printf("\n A bientot.\n");
						exit(0);
					}
					if(test_entree_changement(indicateur_changement_prov)==-1) printf("\nVotre entree est trop longue ou trop courte. Essayez encore.\n");
					else if(test_entree_changement(indicateur_changement_prov)==0) printf("\nVotre entree contient des caracteres invalides. Essayez encore.\n");
					else {
						if(indicateur_changement_prov[0]=='d' && echiquier[l1-1][c1-1]==NULL) printf("\nIl n'existe aucune piece dans cette case. Essayez encore.\n");
						else if (indicateur_changement_prov[0]=='d' && echiquier[l1-1][c1-1]->couleur==noir) printf("\nVous ne pouvez pas deplacer les pieces de %s. Essayez Encore.\n", nom2);/*cette ligne permet de s'assurer que lorsque l'utilisateur décide de faire des opérations de déplacement sur une piece il en a bien le droit*/
						else test_entree=test_entree+1;
					}
				}
				/*on remet test_entree à 0 au cas où il doit re-servir*/
			}
			test_entree=0;
			while(test_move_possible==0){/*cette condition permet de se rassurer que le déplacement depuis la case initiale est possible. Le déplacement effectif dépendra aussi de la case d'arriver*/
				while(test_entree==0){
					printf("\nENTREZ UN NOMBRE DE PIECES A DEPLACER:  ");
					scanf("%s", quant_prov);
					if(test_quit(quant_prov)==1) {
						printf("\n A bientot.\n");
						exit(0);
					}
					if(test_entree_quant(quant_prov)==0){
						printf("\nL'entree est invalide. Vous devez entrer un nombre.\n");
					}
					else {
						quant=convert_to_quant(quant_prov);
						test_entree=1;
					}
				}
				printf("%d\n", quant);
				test_entree=0;/*remis à 0 pour d'enventuels futurs tests d'entree.*/
				if (quant > longueur_case(echiquier, l1, c1)) printf("\nVous ne pouvez pas deplacer plus de %d pieces. Essayez encore.\n", longueur_case(echiquier, l1, c1));
				else if(quant<=0) printf("\nVous devez deplacer au moins une piece\n");
				else test_move_possible=1;
			}
			test_move_possible=0;
			while(test_entree==0 || test_move_possible==0){ /* On vérifiera dans cette boucle que non seulement l'entree est valide c--a-d les coordonnees referencees dans l'echiquier mais aussi que le mouvement est possible*/
				while(test_entree==0) {
					printf("\nENTREZ UNE CASE CIBLE:    ");
					scanf("%s", case_cible_prov );
					if(test_quit(case_cible_prov)==1) {
						printf("\n A bientot.\n");
						exit(0);
					}
					if (test_entree_case(case_cible_prov, n)==-1) printf("\nVotre entree est trop longue ou trop courte.\n");
					else if(test_entree_case(case_cible_prov, n)==0) printf("\nVotre entree contient des caracteres invalides.\n");
					else {
						convert_to_coordonnees(case_cible_prov, &l2, &c2);
						test_entree=1; /*une entree valide étant obtenu, on fait passer le test de l'entrée*/
						}
					}

				/* A ce stade on a une entree de case cible valide. On va à present vérifier si avec la quantité quant le deplacement est possible.*/
				if (echiquier[l2-1][c2-1]==NULL) {/* si la case cible est vide*/
				 	if (test_move_bloc(echiquier, n, quant, l1, c1,l2,c2)==0) {
				 		test_entree=0; /*la mobilité étant invalidée, il faut permettre au joueur de saisir une nouvelle case*/
				 		printf("\nUne des cases que vous essayez de faire passer ne passe pas. Essayez encore.\n");
				 	}/*On ne passe pas. Le bloc ne peut pas sedéplacer*/
				 	else test_move_possible=1;/* on passe; le bloc peut se déplacer*/
				}
				else if(echiquier[l2-1][c2-1]->couleur==noir) {/*la case cible n'est pas vide mais on a présence d'une pièce de l'adversiare.*/
				if(quant <= longueur_case(echiquier,l2,c2)) {
					test_entree=0; /*la mobilité étant invalidée, il faut permettre au joueur de saisir une nouvelle case*/
					printf("\nLa case cible contient plus (ou exactement) de %d pieces de %s. Essayez encore.\n", quant, nom2);
					}/*on ne passe pas car on déplace moins de piecesque l'adversaire*/
				else if (test_move_bloc(echiquier, n, quant, l1, c1,l2,c2)==0) {
					test_entree=0; /*la mobilité étant invalidée, il faut permettre au joueur de saisir une nouvelle case*/
				 	printf("\nUne des pieces que vous essayez de faire passer ne passe pas. Essayez encore.\n");/*on deplace plus de pieces que l'adversaire mais le bloc ne passe pas*/
				}
				else test_move_possible=1;/* toutes les conditions sont réunies pour passer*/
				}
				else {
					if (test_move_bloc(echiquier, n, quant, l1, c1,l2,c2)==0) {
						test_entree=0;
						printf("\nUne des pieces que vous essayez de faire passer ne passe pas. Essayez encore.\n");}	
					else test_move_possible=1;
				}
			}
			test_move_possible=0; test_entree=0; /* remis à 0 pour de prochains test. Ici, celà sert eventuellement pouur e prochain tour vu que à ce stade, plus besoin d'entree aucours du tour en cours.*/
			if(echiquier[l2-1][c2-1]==NULL || echiquier[l2-1][c2-1]->couleur==blanc) {
				faire_move(echiquier, l1, c1, l2, c2, quant);/*case cible vide ou contenant les pieces du joueur. On déplace les pièces en les ajoutant tout simplement*/
			}
			else {
				echiquier[l2-1][c2-1]=NULL;/*case cible non vide et contient les pieces de l'adversaire. Les pieces de l'adveraires dans la case cible sont retirées du jeu*/
				faire_move(echiquier, l1, c1, l2, c2, quant); /*on effectue le déplacement*/
			}
			affichage1(n);
			affichage2(echiquier,n);
			indicateur_tour=2;

		}
	

						/*Partie pour l'adversaire ayant les pièces noires*/






	else if(indicateur_tour==2){
				printf("%s,\n\nC'EST VOTRE TOUR\n", nom2);
				int l1; int c1; int l2; int c2; /* entiers qui permettront de stocker les valeurs de lignes et colonnes de cases à vider ou remplir*/
				char indicateur_changement_prov[100];/*_prov pour dire provisoire. la demande d'occuper une telle taille en mémoire nous permettra de reccueillir n'importe qu'elle entrée et de la traiter en interne*/
				indicateur_changement_prov[0]='c';
				char case_choisie_prov[100];/*pareil*/
				char case_cible_prov[100];/*Pareil*/
				/*Pour la case choisie et la case cible, on va créer une vraie case poutér récupérer l'entrée lorsqu'elle aura passé tous les test de validi*/
				char quant_prov[100];/*permet de récupérer la quantité que veut déplacer le joueur. Cette entree sera traitée et enregistrer dans quant si elle passe test d'entree*/
				int quant;
				int test_move_possible=0;/*va etre la condition de while. Permet de s'assurer qu'une entree valide permet un déplacement */
				while(indicateur_changement_prov[0]=='c') {
					test_entree=0;
					while(test_entree==0){/*boucle permettant de vérifier l'entrée de case potentiellement à déplacer*/
						printf("\nENTREZ UNE CASE:  ");
						scanf("%s",case_choisie_prov);
						if(test_quit(case_choisie_prov)==1) {
							printf("\nMerci d'avoir joué. A bientot.\n");
							exit(0);
						}
						if (n/10==0) {/* ce cas correspond au cas où n est fait d'un seul chiffre*/
							if (test_entree_case(case_choisie_prov, n)==-1) printf("\nVotre entree est trop longue ou trop courte\n.");
							else if(test_entree_case(case_choisie_prov, n)==0) printf("\nVotre entree contient des caracteres invalides.\n");
							else {
								test_entree=1; /*une entree valide étant obtenu, on fait passer le test de l'entrée*/
							}
						}
						else { /* si n contient 2 chiffres*/
							if (test_entree_case(case_choisie_prov, n)==-1) printf("\nVotre entree est trop longue ou trop courte.\n");
							else if(test_entree_case(case_choisie_prov, n)==0) printf("\nVotre entree contient des caracteres invalides.\n");
							else {
							test_entree=1; /*une entree valide étant obtenu, on fait passer le test de l'entrée*/
							}
						}
					}
					test_entree=0; /*on remet test_entree à 0 au cas où il doit re-servir*/
					convert_to_coordonnees(case_choisie_prov, &l1, &c1);
					affichage1(n);
					affichage2(echiquier, n);
					affichage3(echiquier, case_choisie_prov, l1, c1);
					while (test_entree==0){
						printf("\n ENTREZ 'c' POUR CHANGER OU 'd' POUR DEPLACER:  ");
						scanf("%s", indicateur_changement_prov);
						if(test_quit(indicateur_changement_prov)==1) {
							printf("\n A bientot.\n");
							exit(0);
						}
						if(test_entree_changement(indicateur_changement_prov)==-1) printf("\nVotre entree est trop longue ou trop courte. Essayez encore.\n");
						else if(test_entree_changement(indicateur_changement_prov)==0) printf("\nVotre entree contient des caracteres invalides. Essayez encore.\n");
						else {
							if (indicateur_changement_prov[0]=='d' && echiquier[l1-1][c1-1]==NULL) printf("\nIl n'existe aucune piece dans cette case. Essayez encore.\n");
							else if (indicateur_changement_prov[0]=='d' && echiquier[l1-1][c1-1]->couleur==blanc) printf("\nVous ne pouvez pas deplacer des pieces de %s. Essayez Encore.\n", nom1);/*cette ligne permet de s'assurer que lorsque l'utilisateur décide de faire des opérations de déplacement sur une piece il en a bien le droit*/
							else test_entree=test_entree+1;
						}
					}
					/*on remet test_entree à 0 au cas où il doit re-servir*/
				}
				test_entree=0;
				printf("%d \n",  longueur_str(case_choisie_prov));
				printf("%s\n", case_choisie_prov);
				printf("%d %d\n",l1, c1);
				while(test_move_possible==0){/*cette condition permet de se rassurer que le déplacement depuis la case initiale est possible. Le déplacement effectif dépendra aussi de la case d'arriver*/
					while(test_entree==0){
						printf("\nENTREZ UN NOMBRE DE PIECES A DEPLACER:  ");
						scanf("%s", quant_prov);
						if(test_quit(quant_prov)==1) {
							printf("\n A bientot.\n");
							exit(0);
						}
						if(test_entree_quant(quant_prov)==0){
							printf("\nL'entree est invalide. Vous devez entrer un nombre.\n");
						}
						else {
							quant=convert_to_quant(quant_prov);
							test_entree=1;
						}
					}
					printf("%d\n", quant);
					test_entree=0;/*remis à 0 pour d'enventuels futurs tests d'entree.*/
					if (quant > longueur_case(echiquier, l1, c1)) printf("\nVous ne pouvez pas deplacer plus de %d pieces. Essayez encore.\n", longueur_case(echiquier, l1, c1));
					else if(quant<=0) printf("\nVous devez deplacer au moins une piece\n");
					else test_move_possible=1;
				}
				test_move_possible=0;
				while(test_entree==0 || test_move_possible==0){ /* On vérifiera dans cette boucle que non seulement l'entree est valide c--a-d les coordonnees referencees dans l'echiquier mais aussi que le mouvement est possible*/
					while(test_entree==0) {
						printf("\nENTREZ UNE CASE CIBLE:    ");
						scanf("%s", case_cible_prov );
						if(test_quit(case_cible_prov)==1) {
							printf("\n A bientot.\n");
							exit(0);
						}
						if (test_entree_case(case_cible_prov, n)==-1) printf("\nVotre entree est trop longue ou trop courte.\n");
						else if(test_entree_case(case_cible_prov, n)==0) printf("\nVotre entree contient des caracteres invalides.\n");
						else {
							convert_to_coordonnees(case_cible_prov, &l2, &c2);
							test_entree=1; /*une entree valide étant obtenu, on fait passer le test de l'entrée*/
							}
						}

					/* A ce stade on a une entree de case cible valide. On va à present vérifier si avec la quantité quant le deplacement est possible.*/
					if (echiquier[l2-1][c2-1]==NULL) {/* si la case cible est vide*/
					 	if (test_move_bloc(echiquier, n, quant, l1, c1,l2,c2)==0) {
					 		test_entree=0; /*la mobilité étant invalidée, il faut permettre au joueur de saisir une nouvelle case*/
					 		printf("\nUne des pieces que vous essayez de faire passer ne passe pas. Essayez encore.\n");
					 	}/*On ne passe pas. Le bloc ne peut pas sedéplacer*/
					 	else test_move_possible=1;/* on passe; le bloc peut se déplacer*/
					}
					else if(echiquier[l2-1][c2-1]->couleur==blanc) {/*la case cible n'est pas vide mais on a présence d'une pièce de l'adversiare.*/
					if(quant <= longueur_case(echiquier,l2,c2)) {
						test_entree=0; /*la mobilité étant invalidée, il faut permettre au joueur de saisir une nouvelle case*/
						printf("\nLa case cible contient plus (ou exactement) de %d pieces de %s. Essayez encore.\n", quant, nom1);
						}/*on ne passe pas car on déplace moins de piecesque l'adversaire*/
					else if (test_move_bloc(echiquier, n, quant, l1, c1,l2,c2)==0) {
						test_entree=0; /*la mobilité étant invalidée, il faut permettre au joueur de saisir une nouvelle case*/
					 	printf("\nUne des pieces que vous essayez de faire passer ne passe pas. Essayez encore.\n");/*on deplace plus de pieces que l'adversaire mais le bloc ne passe pas*/
					}
					else test_move_possible=1;/* toutes les conditions sont réunies pour passer*/
					}
					else {
						if (test_move_bloc(echiquier, n, quant, l1, c1,l2,c2)==0) {
							test_entree=0;
							printf("\nUne des cases que vous essayez de faire passer ne passe pas. Essayez encore.\n");}	
						else test_move_possible=1;
					}
				}
				test_move_possible=0; test_entree=0; /* remis à 0 pour de prochains test. Ici, celà sert eventuellement pouur e prochain tour vu que à ce stade, plus besoin d'entree aucours du tour en cours.*/
				if(echiquier[l2-1][c2-1]==NULL || echiquier[l2-1][c2-1]->couleur==noir) {
					faire_move(echiquier, l1, c1, l2, c2, quant);/*case cible vide ou contenant les pieces du joueur. On déplace les pièces en les ajoutant tout simplement*/
				}
				else {
					echiquier[l2-1][c2-1]=NULL;/*case cible non vide et contient les pieces de l'adversaire. Les pieces de l'adveraires dans la case cible sont retirées du jeu*/
					faire_move(echiquier, l1, c1, l2, c2, quant);/*on effectue le déplacement*/
				}
				affichage1(n);
				affichage2(echiquier,n);
				indicateur_tour=1;

			}
}
	if (test_reste_noir(echiquier,n)) {printf("Partie finie. %s est victorieux et %s est perdant. A bientot.", nom2, nom1);}
	else {printf("\n\nPartie finie. %s est victorieux et %s est perdant. A bientot", nom1, nom2);}
int r;
	for(r=0; r<n; r++) {
	free(echiquier[r]);
	}
	
return 0; } 
