//	POPIS:
//	Hlavny subor obsahujuci funkciu main().

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

int main() {
	zobraz(osemsmerovka,SIRKA,VYSKA);
	zobrazZoznamSlov(zoznamSlov,POCET_SLOV,MAX_DLZKA_SLOVA,-1);

	printf("\n  Stlac ENTER pre vylustenie.\n");
	system("pause");

	vylusti(zoznamSlov,osemsmerovka);

	tajnicka(matica,osemsmerovka,tjn);

	return 0;
} 