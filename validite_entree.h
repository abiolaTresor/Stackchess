/*@requires: une chaine de caracteres @assigns: rien @ensures: -1 si taille differente de 1, 0 si bonne taille mais caracteres non 'c' et non 'c'. 1 si toutes les conditions precedentes ne sont pas verifiees*/
int test_entree_changement(char str[]);

/*@requires:une chaine de caracteres(qui représente l'entree de l'utilisateur, un entier qui représente la taille de l'echiquier. @assigns: rien. @ensures: -1 si entree de mauvaise taille; 0 si entree de bonne taille mais saisie incorrecte. 1 si entree de bonne taille et saisie valide.  */
int test_entree_case(char str[], int size);

/*@requires: deux chaines de caracteres str1 et str2 de même longueur. @assign: rien. @ensures: recopie la chaine de caracteres str1 dans la  chaine str2*/
void recopiage (char str1[], char str2[]);

/*@requires: une chaine de caracteres. @assigns: rien. @ensures: retourne:
0 si chaine vide
1 si chaine de longueur 1 et str[0] est un nombre(un chiffre du coup)
2 si chaine de longueur 1 mais str[0] n'est pas un chiffre
3 si chaine de longueur 2 et str[0]srt[1] est un nombre
2 si chaine de longueur >=2 et str[0]str[1]n'est pas un nombre */
int test_entree_taille(char str[]);

/*@requires: une chaine de caracteres. @assigns: rien. @ensures: 
0 si aucun caractère saisi
1 si tout les caracteres sont des nombres (1 chiffre)
3 si tout les caracteres sont des nombres (1 chiffre)
2 si un des caracteres sasis n'est pas un chiffre
@Use: va nous permettre de tester si l'entree en matiere de quantité de pla à déplacer est acceptable.  */
int test_entree_quant(char str[]);

/*@requires: une chaine de caracteres dont tous les carateres sont des entiers. @assigns: rien. retourn le combre associé en collan les caracteres côte à côte de la droite vers la gauche*/
int convert_to_quant(char str[]);

/*@requires: deux entiers. @assigns rien. @ensures retourne le 1er entier à la puissance le 2iem entier*/
int puiss(int n, int b);

/*@requires:une chaine de caractere @assigns: rien @ensures:
1 si la chaine est "a"
0 sinon*/
int test_quit(char str[]);