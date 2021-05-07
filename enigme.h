typedef struct 
{
char Quest[100];
int etat;
}enigme;
/*********************************************************/

void afficher_enigme(enigme e);
enigme genererEnigme(char *fichier_enigme.txt);
void resolution(enigme e);
