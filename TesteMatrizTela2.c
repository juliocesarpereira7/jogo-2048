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
int colunatela = 0;
int linha,coluna = 0;
int casas[4][4];					// MATRIZ DE CASAS (INT) E SEM VALOR. OS VALORES SER�O ADICIONADOS NA FUN��O MAIN





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
		printf("\t\t\t\t\tJOGUE UTILIZANDO W, A, S, D ");			

			tecla = getch();					// CAPTURA A TECLA DIGITADA

	
		if ((tecla == 68) || (tecla == 100)){ // TECLA D
	
			for (linhatela = 0; linhatela < 4; linhatela++){
				for(colunatela = 0; colunatela < 4; colunatela++){
			
				if((casas[linha][coluna+1] == 0) && (casas[linha][coluna] != 0)){
					casas[linha][coluna+1] = casas[linha][coluna];
					casas[linha][coluna] = 0;
				}
			
				}
			}
				sortearCasa();
		}
	
	
	
		else if ((tecla == 65) || (tecla == 97)){ // TECLA A 
	
			for (linhatela = 0; linhatela < 4; linhatela++){
				for(colunatela = 0; colunatela < 4; colunatela++){
			
			
				casas[linha][coluna] = casas[linha][coluna] + casas[linha-1][coluna];
			
				casas[linha][coluna] = casas[linha][coluna] + casas[linha-2][coluna];
				
				casas[linha][coluna] = casas[linha][coluna] + casas[linha-3][coluna];
			
				}
			}
				sortearCasa();
		}
	
		else if ((tecla == 87) || (tecla == 119)){ //TECLA W
	
			for (linhatela = 0; linhatela < 4; linhatela++){
				for(colunatela = 0; colunatela < 4; colunatela++){
			
				
				casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna+1];
			
				casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna+2];
			
				casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna+3];
			
				}
			}
				sortearCasa();
		}
	
		else if ((tecla == 83) || (tecla == 115)){ //TECLA S
	
			for (linhatela = 0; linhatela < 4; linhatela++){
				for(colunatela = 0; colunatela < 4; colunatela++){
			
			
				casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna-1];
			
				casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna-2];
			
				casas[linha][coluna] = casas[linha][coluna] + casas[linha][coluna-3];
			
				}
			}
				sortearCasa();	
		}
		
		system("cls");						// LIMPA A TELA
		TelaJogo();	
	}while(tecla != 999);
		
	
}

	





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


