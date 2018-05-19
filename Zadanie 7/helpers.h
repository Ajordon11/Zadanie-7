//	POPIS:
//	Subor obsahujuci:
//		* deklaracie premennych
//		* deklaracie pouzivatelskych funkcii, ktore su implementovane v functions.c
//		* pomocne makra

#ifndef HELPERS_H
#define HELPERS_H

#include "data_info.h"

// deklaracie premennych
extern char osemsmerovka[VYSKA][SIRKA];
extern char zoznamSlov[POCET_SLOV][MAX_DLZKA_SLOVA];
extern int matica[VYSKA][SIRKA];
extern char tjn[50];

// deklaracie pouzivatelskych funkcii
void zobraz(char(*osemsmerovka)[SIRKA]);
void zobrazZoznamSlov(char(*zoznamSlov)[MAX_DLZKA_SLOVA], int pocet_slov);
void najdiSlovo(char *slovo, char(*osemsmerovka)[SIRKA]);
void vylusti(char(*zoznamSlov)[MAX_DLZKA_SLOVA], char(*osemsmerovka)[SIRKA]);
void tajnicka(int(*matica)[SIRKA], char(*osemsmerovka)[SIRKA], char *tjn);

char *vpravoHore(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
char *hore(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
char *vlavoHore(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
char *vpravo(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
char *vlavo(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
char *vpravoDole(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
char *dole(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
char *vlavoDole(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y);
void zapis(char (*matica)[VYSKA], int dlzka, int smer, int x, int y);
// Podmieneny preklad: verzia pre WINDOWS sa lisi od LINUX verzie
// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif


#endif /* HELPERS_H */
