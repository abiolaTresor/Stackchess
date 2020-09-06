#include<math.h>
/*@requires:une reference vers une case_piece non NULL.@assigns: modifie l'element à l'adresse p en enlevant la tête.@ensures: retourne l'element enlever à la tête de *p*/
case_piece depiece(case_piece* p);

/*@requires:une case_piece non NULL @assigns:rien @ensures: rien n'est reourné*/
case_piece retour_entete(case_piece p) ;

/*@requires:un echiquier, une case_piece,  deux entiers l et c. @assigns: ajoute à la case_piece en postion (l-1,c-1) de l'echiquier l'element casep_piece @ensures: rien*/
void enpiecer(case_piece* echiquier[], case_piece p, int l, int c);


 				/*fonctions pour tester si la mobilité des pièces est possible. les obstacles (présence d'autres pièces) sur le chemin ne sont pas pris en compte. D'autres fonctions s'en chargeront. */



/*@requires:des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 1 si on peut bouger la piece à (l1,c1) à (c2,l2). 0 sinon @Uses: sert pour tester la mobilité du roi*/
int test_move_roi(int l1, int c1, int l2, int c2);

/*@requires:des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 1 si on peut bouger la piece à (l1,c1) à (c2,l2). 0 sinon @Uses: sert pour tester la mobilité de Dame*/
int test_move_dame(int l1, int c1, int l2, int c2);

/*@requires:des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 1 si on peut bouger la piece à (l1,c1) à (c2,l2). 0 sinon @Uses: sert pour tester la mobilité de fou*/
int test_move_fou(int l1, int c1, int l2, int c2);

/*@requires:des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 1 si on peut bouger la piece à (l1,c1) à (c2,l2). 0 sinon @Uses: sert pour tester la mobilité de tour*/
int test_move_tour(int l1, int c1, int l2, int c2);

/*@requires:un echiquier,sa taille, des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 1 si on peut bouger la piece à (l1,c1) à (c2,l2). 0 sinon @Uses: sert pour tester la mobilité de pion noir*/
int test_move_pionN(case_piece* echiquier[], int n, int l1, int c1, int l2, int c2);

/*@requires:un echiquier, des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 1 si on peut bouger la piece à (l1,c1) à (c2,l2). 0 sinon @Uses: sert pour tester la mobilité de pion blanc*/
int test_move_pionB(case_piece* echiquier[],int l1, int c1, int l2, int c2);



				/* fonctions pour tester si chemin (exluant point d'arrivée) libre. Lorsque le chemin n'est pas libre, on renvoie 0. 1 sinon*/



/*@requires:un echiquier, des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 0 ou 1 */
int test_libre_dame (case_piece* echiquier[], int l1, int c1, int l2, int c2);

/*@requires:un echiquier, des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 0 ou 1 */
int test_libre_fou(case_piece* echiquier[], int l1, int c1, int l2, int c2);

/*@requires:un echiquier, des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 0 ou 1 */
int  test_libre_tour(case_piece* echiquier[], int l1, int c1, int l2, int c2);

/*@requires:un echiquier, des entiers l1,c1,l2,c2 < taille de l'echiquier @assigns:rien @ensures: 0 ou 1 */
int test_libre_pion(case_piece* echiquier[],int size, int l1, int c1, int l2, int c2);


                /*FIN*/


/*@requires: un pointeur sur case_piece donc un echiquier, et un entier size qui représente sa taille @assigns: rien @ensures: 1 si l'echiquier contient au moins une pièce noire; 0 sinon*/
int test_reste_noir(case_piece* echiquier[], int size);

/*@requires: un pointeur sur case_piece donc un echiquier, et un entier size qui représente sa taille @assigns: rien @ensures: 1 si l'echiquier contient au moins une pièce blanche; 0 sinon*/
int test_reste_blanc(case_piece* echiquier[], int size);

/*@requires:une chaine de caracteres de longueur 3 ou 4, deux references l et c vers resp. numero de ligne et de colonne. @assigns: modifie l'emplacement mémoire aux adresses indiquées avec le num de ligne et de colonne @ensures: rien @Uses: lorsque l'utilisateur va entrer les coordonnees , il faudra les transcrire en coordonnees utilisables par le programme. les coordonnées obtenues seront sauvegardées à des adresses memoires pour pouvoir etre utilisees plus 
tard*/
void convert_to_coordonnees( char* str, int* l, int* c);

/*@requires: prend une haine de caracteres str @assigns:nothing @ensures: retourne la longueur de la chaine*/
int longueur_str(char* str);

/*@requires: prend un echiquier,  un nuero de ligne l, de colonne c. @assigns: rien. @ensures: nombre de pieces contenues dans la case*/
int longueur_case(case_piece* echiquier[], int l, int c);

/*@requires: prend un echiquier, un numéro de ligne et un numéro de colonne. @assigns: rien @ensures: 1 si la case (l,c) contient une piece noire, et 0 sinon*/
int test_contient_noir( case_piece* echiquier[], int l , int c); 


/*@requires: prend un echiquier, un numéro de ligne et un numéro de colonne. @assigns: rien @ensures: 1 si la case (l,c) contient une piece blanche, et 0 sinon*/
int test_contient_blanc( case_piece* echiquier[], int l , int c); 

/*@requires: prend un echiquier, la taille size de l'echiquier, quatres entiers l1, c1, l2, c2 @assigns: rien @ensures: 1 si on peut ajouter p situé à (l1,c1) à la case (l2,c2) et 0 sinon*/
int test_move_single(case_piece* echiquier[], int size, case_piece p, int l1, int c1, int l2, int c2);

/*@requires: un echiquier et sa taille size, un entier quant inférieur ou égal à la longeur de (l1,c1), deux entiers l1, c1 et deux autres entiers l2, c2. @assigns: rien. @ensures: 1 si on peut deplacer les quant premiers pieces de la case (l1,c1) vers la case l2*/
int test_move_bloc(case_piece* echiquier[], int size , int quant,int l1, int  c1,int l2,int c2);

/*@requires : un echiquier, deux entiers l et c, un entier quant plus petits que la longueur de la case (l,c) @assigns: modifie l'emplacement (l,c) en en levant ces quants premiers elements. @ensures: retourne une case_piece contenat les quant elements précédemment supprimés. Ces éléments sont dans le case_piece renvoyé en sens inversé par rapport à leur sens initial*/ 
case_piece depile_temp(case_piece* echiquier[], int l, int c, int quant);

/*@requires: un echiquier et sa taille size, quatres entiers l1, c1, l2, c2, un entier quant. @assigns modifie l'emplacement case (l1,c1) en supprimant ses quant premiers elements. Ces q premiers elements sont déplacés puis ajoutés à l'emplacement case (l2,c2).on veille à ce que l'ordre qu bloc est concervé @ensures rien. PS: quant doit etre plus grand que la longueueur de la case (l1,c1). et que le déplacement du bloc est possible*/
void faire_move(case_piece* echiquier[], int l1, int c1, int l2, int c2, int quant);

