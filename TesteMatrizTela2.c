#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>

int sortearCasa();
void gotoxy(int x, int y);
void TelaJogo();


// VARIAVEIS GLOBAIS (FUNCIONAM EM TODO O C�DIGO)	
int	confirm = 0;			    
int linhatela = 0;
int tecla = 0;
int gameScore = 0;
int colunatela = 0;
int casas[4][4];					// MATRIZ DE CASAS (INT) E SEM VALOR. OS VALORES SER�O ADICIONADOS NA FUN��O MAIN





// FUNCAO PRINCIPAL
main(){
	
	int t = 0;
	int gameScore,WinGame = 2048;
	int opcao = 0;

	TelaJogo(); // Tela matriz e jogo junto
	
	
	for (linhatela = 0; linhatela < 4; linhatela++){  
		for(colunatela = 0; colunatela < 4; colunatela++){
			casas[linhatela][colunatela] = 0; //definindo as casas em branco
		}
	}
	
	sortearCasa();
	system("cls");
	TelaJogo();
	
	
	//Movimenta��o
    do{
    char tecla = getch();
	if (tecla == 'w' || tecla == 'W') {
        ParaCima();
    }
    else if (tecla == 's' || tecla == 'S') {
        ParaBaixo();
    }
    else if (tecla == 'a' || tecla == 'A') {
        ParaEsquerda();
    }
    else if (tecla == 'd' || tecla == 'D') {
        ParaDireita();
    }

    sortearCasa();
    system("cls");
    TelaJogo();
    } while (tecla != 5000);
    

}
void ParaCima()
{

    for (colunatela = 0; colunatela < 4 ; colunatela++) {
        for (linhatela = 0; linhatela < 4 ; linhatela++) {
                                                              
            if ( (casas[linhatela - 1][colunatela] == 0) && (casas[linhatela - 2][colunatela] == 0) && (casas[linhatela - 3][colunatela] == 0) && linhatela < 1){      // 1, 2 E 3 POSICOES ACIMA
                casas[linhatela - 3][colunatela] = casas[linhatela][colunatela];                        // ESSA PARTE VAI SUBSTITUIR 3 POSICOES ACIMA
                casas[linhatela][colunatela] = 0;
            } else if ( (casas[linhatela - 1][colunatela] == 0) && (casas[linhatela - 2][colunatela] == 0) && linhatela < 2){             // 1 E 2 POSICOES ACIMA
                casas[linhatela - 2][colunatela] = casas[linhatela][colunatela];                        // ESSA PARTE VAI SUBSTITUIR 2 POSICOES ACIMA
                casas[linhatela][colunatela] = 0;
            } else if ( (casas[linhatela - 1][colunatela] == 0) && linhatela < 3 ){                     // ESSE IF VERIFICA 1 POSICAO ACIMA (LINHATELA - 1) OS OUTROS IF'S VERIFICAM 1 E 2 POSICOES ACIMA E 1, 2 E 3 POSICOES ACIMA
                casas[linhatela - 1][colunatela] = casas[linhatela][colunatela];
                casas[linhatela][colunatela] = 0;                                                       // ESSA PARTE VAI SUBSTITUIR 1 POSICAO ACIMA
                
            }                                                                                           // A PARTE DO (&&linhatela < x) serve para restringir o funcionamento dos if's.

            if (casas[linhatela][colunatela] != 0) {                                                    // ESSE IF VERIFICA SE A POSICAO DA MATRIZ É DIFERENTE DE 0
                if ( (casas[linhatela][colunatela] == casas[linhatela - 1][colunatela]) && linhatela < 3 ){
                    gameScore += (casas[linhatela][colunatela])*2;
                    casas[linhatela][colunatela] = casas[linhatela][colunatela]*2;
                    casas[linhatela - 1][colunatela] = 0;
                } else if ( (casas[linhatela][colunatela] == casas[linhatela - 2][colunatela]) && (casas[linhatela - 1][colunatela] == 0) && linhatela < 2 ) {
                    gameScore += (casas[linhatela][colunatela])*2;
                    casas[linhatela][colunatela] = casas[linhatela][colunatela]*2;
                    casas[linhatela - 2][colunatela] = 0;
                } else if ( (casas[linhatela][colunatela] == casas[linhatela - 3][colunatela]) && (casas[linhatela - 1][colunatela] == 0) && (casas[linhatela - 2][colunatela] == 0) && linhatela < 1 ){
                    gameScore += (casas[linhatela][colunatela])*2;
                    casas[linhatela][colunatela] = casas[linhatela][colunatela]*2;
                    casas[linhatela - 3][colunatela] = 0;
                }
            }
        }
    }
}


void ParaBaixo()
{
    for (colunatela = 0; colunatela < 4 ; colunatela++) {
        int t = 3;
        for (linhatela = 5; linhatela >= 0; linhatela--) {
            if (casas[linhatela][colunatela] != 0) {
                casas[t][colunatela] = casas[linhatela][colunatela];
                t--;
            }
        }
        for (linhatela = t; linhatela >= 0; linhatela--) casas[linhatela][colunatela] = 0;
    }

    for (colunatela = 0; colunatela < 4 ; colunatela++) {
        int t = 3;
        for (linhatela = 4; linhatela >= 0; linhatela--) {
            if (casas != 0) {
                if (casas[linhatela][colunatela] == casas[linhatela - 1][colunatela]) {
                    casas[t][colunatela] = 2 * casas[linhatela][colunatela];
                    casas[t][colunatela] = 0;
                    gameScore += casas[t][colunatela];
                    t--;
                    linhatela--;
                }
                else {
                    casas[t][colunatela] = casas[linhatela][colunatela];
                    t--;
                }
            }
        }
        for (linhatela = t; linhatela >= 0; linhatela--) casas[linhatela][colunatela] = 0;
    }
}

void ParaEsquerda()
{
    for (linhatela = 0; linhatela < 4 ; linhatela++) {
        int t = 0;
        for (colunatela = 0; colunatela < 4 ; colunatela++) {
            if (casas[linhatela][colunatela] != 0) {
                casas[linhatela][t] = casas[linhatela][colunatela];
                t++;
            }
        }
        for (colunatela = t; colunatela < 4 ; colunatela++) casas[linhatela][colunatela] = 0;
    }

    for (linhatela = 0; linhatela < 4 ; linhatela++) {
        int t = 0;
        for (colunatela = 0; colunatela < 4 ; colunatela++) {
            if (casas[linhatela][colunatela] != 0) {
                if (casas[linhatela][colunatela] == casas[linhatela][colunatela + 1]) {
                    casas[linhatela][t] = 2 * casas[linhatela][colunatela];
                    casas[t][colunatela] = 0;
                    gameScore += casas[linhatela][t];
                    colunatela++;
                    t++;
                }
                else {
                    casas[linhatela][t] = casas[linhatela][colunatela];
                    t++;
                }
            }
        }
        for (colunatela = t; colunatela < 4 ; colunatela++) casas[linhatela][colunatela] = 0;
    }
}

void ParaDireita()
{
    for (linhatela = 0; linhatela < 4; linhatela++) {
        int t = 3;
        for (colunatela = 4; colunatela >= 0; colunatela--) {
            if (casas[linhatela][colunatela] != 0) {
                casas[linhatela][t] = casas[linhatela][colunatela];
                t--;
            }
        }
        for (colunatela = t; colunatela >= 0; colunatela--) casas[linhatela][colunatela] = 0;
    }


    for (linhatela = 0; linhatela < 4 ; linhatela++) {
        int t = 3;
        for (colunatela = 5; colunatela >= 0; colunatela--) {
            if (casas[linhatela][colunatela] != 0) {
                if (casas[linhatela][colunatela] == casas[linhatela][colunatela - 1]) {
                    casas[linhatela][t] = 2 * casas[linhatela][colunatela];
                    casas[t][colunatela] = 0;
                    gameScore += casas[linhatela][t];
                    colunatela--;
                    t--;
                }
                else {
                    casas[linhatela][t] = casas[linhatela][colunatela];
                    t--;
                }
            }
        }
        for (int colunatela = t; colunatela >= 0; colunatela--) casas[linhatela][colunatela] = 0;
    }
}

TelaJogo(){  // criando matriz casas e juntando com TelaJogo
	int linha, coluna = 0;

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
	
	srand(time(NULL));
	do 												
	{ 
	   	sorteiacoluna = rand() % 4;							// SORTEIA POSIÇÃO PARA A COLUNA
		sorteialinha = rand() % 4;							// SORTEIA POSIÇÃO PARA A LINHA

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


