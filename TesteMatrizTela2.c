#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

int sortearCasa();
void gotoxy(int x, int y);
void TelaJogo();

// VARIAVEIS GLOBAIS (FUNCIONAM EM TODO O CÓDIGO)				    
int linhatela = 0;
int colunatela = 0;
int linha,coluna = 0;
int casas[4][4];					// MATRIZ DE CASAS (INT) E SEM VALOR. OS VALORES SERÃO ADICIONADOS NA FUNÇÃO MAIN


// FUNCAO PRINCIPAL
main(){
	int opcao = 0;

	TelaJogo(); // Tela matriz e jogo junto
	
	
	for (linhatela = 0; linhatela < 4; linhatela++){  
		for(colunatela = 0; colunatela < 4; colunatela++){
			casas[linhatela][colunatela] = 0; //definindo as casas em branco
		}
	}

	do{
		printf("\n\n\n\n");
		printf("\t\t\t\t\tDigite qualquer numero: ");			
		scanf("%i", &opcao);					// CAPTURA A TECLA DIGITADA

		if (opcao != 9999){						// SE A TECLA DIGITADA NAO FOR 9999
			sortearCasa();						// SORTEIA CASA
			system("cls");						// LIMPA A TELA
			TelaJogo();							// CRIA NOVA TELA COM OS VALORES ATUALIZADOS
		}

	} while (opcao != 9999);			// REPETE ENQUANTO OPCAO NAO FOR 9999

	
	/*
	if (casas[sorteialinha][sorteiacoluna] = 0){   //conferindo se est� em branco e se s�o iguais e somando 
		if(casas[linhatela][colunatela] == casas[linhatela][colunatela]){
			casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna-1];
			casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna+1];
			casas[linha][coluna] = casas[linha][coluna] + casas[linha-1][coluna];
			casas[linha][coluna] = casas[linha][coluna] + casas[linha+1][coluna];
		}
	}
	*/
}

// FUNCOES SECUNDÁRIAS

TelaJogo(){  // criando matriz casas e juntando com TelaJogo
	
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
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |                    |                     |                    |                   |\n");
	printf("               |____________________|_____________________|____________________|___________________|\n");

	colunatela = 24;  //posicionando com gotoxy
    linhatela = 12;
	for(linha = 0;linha < 4; linha++){
		for(coluna = 0;coluna < 4; coluna++){
			gotoxy(colunatela, linhatela);
			if (casas[linha][coluna] != 0){
				printf("%i ", casas[linha][coluna]);
				colunatela = colunatela + 21;
			}
		}
		printf("\n");
		linhatela  =  linhatela + 7;
		colunatela = 24;
	}
	
}




sortearCasa(){
	int	confirm, sorteiacoluna, sorteialinha = 0;

	do 												
	{ 
	   	sorteiacoluna = rand() & 3;							// SORTEIA POSIÇÃO PARA A COLUNA
		sorteialinha = rand() & 3;							// SORTEIA POSIÇÃO PARA A LINHA

		if (casas[sorteialinha][sorteiacoluna] == 0){		// VERIFICA SE O NUMERO DENTRO DA CASA CONFIRMADA É 0
			casas[sorteialinha][sorteiacoluna] = 2;			// SE FOR 0, PASSA A VALER 2
			confirm = 0;									// CONFIRMA
		} else {											// SE NAO FOR 0
			confirm = 1;									// NAO CONFIRMA
		}													
	}	while (confirm != 0);								// REPETE

}

gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
