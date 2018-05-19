//	POPIS:
//	Subor obsahujuci implementacie pouzivatelskych funkcii.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include <Windows.h>


void zobraz(char(*osemsmerovka)[SIRKA]) {
	int i, j;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("\n    Osemsmerovka:\n");
	for (i = 0;i < VYSKA;i++) {
		printf("\t");
		for (j = 0;j < SIRKA;j++) {
			if (matica[i][j] == 1) {
				SetConsoleTextAttribute(hConsole, 5);
				printf("%2c", osemsmerovka[i][j]);
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
				printf("%2c", osemsmerovka[i][j]);
		}
		
		printf("\n");
	}
	printf("\n");
}

void zobrazZoznamSlov(char (*zoznamSlov)[MAX_DLZKA_SLOVA] ,int pocet_slov, int poradie) {
	int i;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("    Zoznam slov: \n");
	printf("\t");
	for (i = 0;i < pocet_slov;i++) {
		if (poradie == i) {
			SetConsoleTextAttribute(hConsole, 5);
			printf("%s, ", zoznamSlov[i]);
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			printf("%s, ", zoznamSlov[i]);
	}
	printf("\n");
}
char *vpravoHore(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1), sizeof(char));
	int i;

	for (i = 0;i < dlzka;i++)
		slovo[i] = osemsmerovka[x - i][y + i];
	return slovo;
}
char *hore(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1), sizeof(char));
	int i;
	
	for (i = 0;i < dlzka;i++)
		slovo[i] = osemsmerovka[x-i][y];
	return slovo;
}
char *vlavoHore(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1), sizeof(char));
	int i;

	for (i = 0;i < dlzka;i++)
		slovo[i] = osemsmerovka[x - i][y - i];
	return slovo;
}
char *vpravo(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1) , sizeof(char));
	int i;
	
	for (i = 0;i < dlzka;i++) 
		slovo[i] = osemsmerovka[x][y+i];
	return slovo;
}
char *vlavo(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1), sizeof(char));
	int i;
	
	for (i = 0;i < dlzka;i++)
		slovo[i] = osemsmerovka[x][y - i];
	return slovo;
}
char *vpravoDole(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1), sizeof(char));
	int i;

	for (i = 0;i < dlzka;i++)
		slovo[i] = osemsmerovka[x + i][y + i];

	return slovo;
}
char *dole(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1), sizeof(char));
	int i;

	for (i = 0;i < dlzka;i++)
		slovo[i] = osemsmerovka[x + i][y];
	return slovo;
}
char *vlavoDole(int dlzka, char(*osemsmerovka)[SIRKA], int x, int y)
{
	char *slovo = calloc((dlzka + 1), sizeof(char));
	int i;

	for (i = 0;i < dlzka;i++)
		slovo[i] = osemsmerovka[x + i][y - i];

	return slovo;
}
int matica[VYSKA][SIRKA];
void zapis(int (*matica)[SIRKA], int dlzka, int smer, int x, int y)
{
	int i;
	
	switch (smer) {
	case 1:
		for (i = 0;i < dlzka;i++) {
			matica[x + i][y + i] = 1;
		}
		break;
	case 2:
		for (i = 0;i < dlzka;i++) {
			matica[x + i][y] = 1;
		}
		break;
	case 3:
		for (i = 0;i < dlzka;i++) {
			matica[x + i][y - i] = 1;
		}
		break;
	case 4:
		for (i = 0;i < dlzka;i++) {
			matica[x][y + i] = 1;
		}
		break;
	case 6:
		for (i = 0;i < dlzka;i++) {
			matica[x][y - i] = 1;
		}
		break;
	case 7:
		for (i = 0;i < dlzka;i++) {
			matica[x - i][y + i] = 1;
		}
		break;
	case 8:
		for (i = 0;i < dlzka;i++) {
			matica[x - i][y] = 1;
		}
		break;
	case 9:
		for (i = 0;i < dlzka;i++) {
			matica[x - i][y - i] = 1;
		}
		break;
	default:printf("Error!\n");
	
	}
}

void najdiSlovo(char *slovo,char (*osemsmerovka)[SIRKA]) {
	int i, j, x, y, i2, j2, i3, j3;
	int smer = 0, n, dlzka = strlen(slovo);
	char *pomocne_slovo;
	
	
	
	for (x = 0;x < VYSKA;x++) {
		for (y = 0;y < SIRKA;y++) {
			if (osemsmerovka[x][y] == slovo[0])
			{
				n = 9;
				for (i2 = x - 1;i2 <= x + 1;i2++)                           
					for (j2 = y - 1;j2 <= y + 1;j2++) {
						if (osemsmerovka[i2][j2] == slovo[1])
							smer = n;                                     // 9 = ↖, 8 = ↑, 7 = ↗, 6 = ←, 4 = →, 3 = ↙,  2 = ↓, 1 = ↘, 0 = 2. pismeno nie je v okoli
						n--;
						if (smer != 0) {
							//printf("%d", smer);
							switch (smer) {
							case 9:pomocne_slovo = vlavoHore(dlzka, osemsmerovka, x, y);
								break;
							case 8:pomocne_slovo = hore(dlzka, osemsmerovka, x, y);
								break;
							case 7:pomocne_slovo = vpravoHore(dlzka, osemsmerovka, x, y);
								break;
							case 6:pomocne_slovo = vlavo(dlzka, osemsmerovka, x, y);
								break;
							case 4:pomocne_slovo = vpravo(dlzka, osemsmerovka, x, y);
								break;
							case 3:pomocne_slovo = vlavoDole(dlzka, osemsmerovka, x, y);
								break;
							case 2:pomocne_slovo = dole(dlzka, osemsmerovka, x, y);
								break;
							case 1:pomocne_slovo = vpravoDole(dlzka, osemsmerovka, x, y);
								break;
							default: pomocne_slovo = "Oopsie Woopsie!.\n";
								break;

							}
							//printf("%s-%s ", pomocne_slovo, slovo);
							if (strcmp(pomocne_slovo, slovo) == 0) 
								zapis(matica, dlzka, smer,x,y);
							smer = 0;
						}
					}
			}
		}
	}

	//printf("\n");
}

void vylusti(char (*zoznamSlov)[MAX_DLZKA_SLOVA], char (*osemsmerovka)[SIRKA]){
	int i;

	for (i = 0;i < POCET_SLOV;i++) {
		CLEAR_SCREEN();
		najdiSlovo(zoznamSlov[i], osemsmerovka, SIRKA, VYSKA);
		zobraz(osemsmerovka);
		zobrazZoznamSlov(zoznamSlov, POCET_SLOV,i);
		Sleep(500);

	}
}
char tjn[50];
void tajnicka(int(*matica)[SIRKA], char(*osemsmerovka)[SIRKA], char *tjn) {
	int i, j, n = 0;
	printf("    Tajnicka:\n");
	for (i=0;i<VYSKA;i++)
		for (j = 0;j < SIRKA;j++) {
			if (matica[i][j] == 0) {
				tjn[n] = osemsmerovka[i][j];
				n++;
			}
		}
	printf("\t%s", tjn);
	printf("\n\n    ");
}


