#include<stdio.h>
#include<stdlib.h>
/*implémentation du type des cases: une case est une pile de pieces: implémentée ici avec une structure de liste chainée*/
typedef struct piece* case_piece;
/*implémentation du type des "pièces" du jeu*/
typedef struct piece piece;
typedef enum nom_piece nom_piece;
typedef enum couleur_piece couleur_piece;
enum nom_piece {roi='R', dame='D', fou='F', tour='T', pion='P'};
enum couleur_piece {noir='N', blanc='B'};
struct piece {nom_piece nom; couleur_piece couleur; case_piece suivant;};/*une piece c'est un nom et une couleur*/
/*@requires: un nom, une couleur de piece  @assigns:alloue un espace mémoire  où est enregistrée la piece @ensures:renvoie  la piece*/
case_piece creation_piece(nom_piece nom, couleur_piece couleur);
/*@requires: reference vers une case, une piece p @assigns:la case est allongé avec p qui occupe son sommet @ensures: affiche un message d'erreur lors de l'initialisation si erreur rencontrée*/
void ajout(case_piece* l, case_piece p);
/*@requires: un echiquier, une piece, un numéro de ligne, et un numéro de colonne @ensures: ne renvoie rien */
void ajouter_piece(case_piece* echiquier[], case_piece p, int ligne, int colonne);
/*initialisation de l'echiquier. la fonction initialisation_echiquier @requires: un echiquier, deux numeros de lignes a et b @assigns: initialise les lignes a et b de l'echiquier aux bons pions @ensures: nothing @use: a,b=1,2 puis a,b=N,N-1 */
void initialisation_echiquier( case_piece* echiquier[],int n,couleur_piece couleur, int a, int b);
/* @requires: taille de  l'echiquier @ssigns: nothing @ensures: affiche le haut du plateau*/
void affichage1 (int size);
/*@requires taille de l'échiquier @assigns: rien @ensures: rerourne le reste du plateau vu de haut*/
void affichage2 (case_piece* echiquier[], int size);

/*@requires: un tableau de case_piece c-a-d un echiquier, une chaine de carateres, et deux entiers l et c ici respectivement numero de ligne et de colonne. @assigns: rien @ensures: affiche la chaine str et ensuites la liste chainée echiquier[l-1][c-1] @Uses: servira pour afficher la case sélectionnée pa le joueur*/
void affichage3(case_piece* echiquier[], char str[], int l, int c);
