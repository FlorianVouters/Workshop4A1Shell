#include <stdio.h> /*bibliothèque standard du C déclarant les macros, les constantes et les définitions de fonctions utilisées dans les opérations d'entrée/sortie.*/
#include <stdlib.h> /*stdlib contient les fonctions d'allocation mémoire et d'autres fonctions basique du langage C*/
#include <fcntl.h> /* C'est la bibliothèque contenant les fonctions relative à la manipulation des fichiers et dossier */
#include <sys/types.h> /* Bilbiothèque relative aux types de fichiers */
#include <unistd.h> /* Il définit les constantes et les types symboliques divers, et déclare fonctions diverses */
#define BUF_SIZE 512

int main(int argc, char* argv[]) /* argc s'occupe de donner le nombre de chaine de caractère qu'il y a dans argv */
{				/* Tandis que argv s'occupe de prendre les informations complémentaires au lancement du programme, en général, */
				/* argc = 1 car argv comprend toujours l'adresse entière d'où se trouve le programme dans l'ordinateur*/
	int idFichierLu, idFichierEcrit;
	int byteLu, byteEcrit;
	char buffer[BUF_SIZE];
	char nomFichier[255];
	
	if (argc == 2)
	{
		idFichierLu = open (argv [1], O_RDONLY);
		if (idFichierLu == -1)
		{
			printf("Erreur de lecture");
			return -1;
		}
		sprintf(nomFichier, "/home/exia/save/%s", argv[1] );
		idFichierEcrit = open(nomFichier, O_WRONLY | O_CREAT, 0777);
		if(idFichierEcrit == -1)
		{
			printf("Erreur d'ecriture");
			return -2;
		}
		while((byteLu = read (idFichierLu, &buffer, BUF_SIZE)) > 0)
		{
			byteEcrit = write (idFichierEcrit, &buffer, byteLu);
			if(byteEcrit != byteLu) 
			{
				printf("Erreur d'écriture dans le fichier");
				return -3;
			}
			else{
				printf("%d byte(s) lu(s), %d byte(s) écrit(s)\n", byteLu, byteEcrit);
			}
		}
		close(idFichierLu);
		close(idFichierEcrit);
	}
	else
	{
		printf("Nombre de paramètre incorrect");
	}
}
