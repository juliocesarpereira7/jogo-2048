#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>


void gotoxy(int x, int y)
	{
		COORD coord;
  		coord.X = x;
  		coord.Y = y;
  		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
		

void TelaJogo (char casas2[4][4]) {  // criando matriz casas2 e juntando com TelaJogo
	system ("cls");
	
	printf("                ___________________________________________________________________________________ \n");
	printf("               |                                                       |         RANKING           |\n");
	printf("               |    SCORE:                 RETORNAR                    |___________________________|\n");
	printf("               |                                                       |                           |\n");
	printf("               |                                                       |___________________________|\n");
	printf("               |                                                       |                           |\n");
	printf("               |                                                       |___________________________|\n");
	printf("               |                                                       |                           |\n");
	printf("               |_______________________________________________________|___________________________|\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n", casas2[0][0], casas2[0][1], casas2[0][2], casas2[0][3]);
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n", casas2[1][0], casas2[1][1], casas2[1][2], casas2[1][3]);
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n", casas2[2][0], casas2[2][1], casas2[2][2], casas2[2][3]);
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n", casas2[3][0], casas2[3][1], casas2[3][2], casas2[3][3]);
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");
	
}

main(){
	char casas[4][4]= { { '0','0','0','0'}, //criando matriz e testando se o número entra 
	                    { '0','0','0','0'},       
					    { '0','0','0','0'},		
					    { '0','0','0','0'} };
					    
	int	confirm = 0;			    			    
	int sorteialinha = 0;
	int sorteiacoluna = 0;				    
	int linhatela = 0;
	int colunatela =0;
	int linha,coluna = 0;
	
	TelaJogo(casas); // Tela matriz e jogo junto
	
	
	for (linhatela = 0; linhatela < 4; linhatela++){  
		for(colunatela = 0; colunatela < 4; colunatela++){
			casas[linhatela][colunatela] = 0; //definindo as casas em branco
		}
	}
	
	do 
	{ 
	   sorteiacoluna = rand() & 3;
		sorteialinha = rand() & 3;
	if (casas[sorteialinha][sorteiacoluna] == 0){
		casas[sorteialinha][sorteiacoluna] = 2;
		confirm = 0;
	} else {
		confirm = 1;
	}
	}	while (confirm !=0);
	
	
	
	if (casas[sorteialinha][sorteiacoluna] = 0){   //conferindo se está em branco e se são iguais e somando 
		if(casas[linhatela][colunatela] == casas[linhatela][colunatela]){
			casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna-1];
			casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna+1];
			casas[linha][coluna] = casas[linha][coluna] + casas[linha-1][coluna];
			casas[linha][coluna] = casas[linha][coluna] + casas[linha+1][coluna];
		}
	}
			
			
	
	colunatela = 24;  //posicionando com gotoxy
    linhatela = 12;
	for(linha = 0;linha < 4; linha++){
		for(coluna = 0;coluna < 4; coluna++){
			gotoxy(colunatela,linhatela);
			printf("%c ", casas[linha][coluna]);
			colunatela = colunatela + 21;
		}
		printf("\n");
		linhatela  =  linhatela + 7;
		colunatela =24;
	}
	
	
	 

getch();
return 0;	
}
