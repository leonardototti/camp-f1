#include <stdio.h>
#include <windows.h>
#include <locale.h>

// Declaração das funções.
void Topo();
int Menu();
bool CadastraResultados(int pontPilotos[], bool hasData, int vitoriasPilotos[]);
void AtualizaEquipes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]);
void ListaPilotos(int pontPilotos[], int vitoriasPilotos[]);
void ListaEquipes(int pontEquipes[], int vitoriasEquipes[]);
void ListaCampeoes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]);

// Função só para simplificar o uso da parte superior do programa que se repete várias vezes.
void Topo() {
	printf("-----------------------------------------\n");
    printf("-        CAMPEONATO DE FORMULA 1        -\n");
    printf("-----------------------------------------\n");
}

// Função para gerenciar o menu do programa, sempre que o usuário entra em alguma opção retorna ao menu inicial.
int Menu() {
	int opc = 0, erro;

	do {
		erro = 0;
		printf("\n(1) - Cadastrar Resultado. \n");
		printf("(2) - Listar pontuação acumulada do campeonato de pilotos. \n");
		printf("(3) - Listar pontuação acumulada do campeonato de construtores. \n");
		printf("(4) - Listar quem foi o campeão de pilotos e qual equipe campeão de construtores. \n");
		printf("(5) - Sair. \n");
		printf("Informe a opção desejada: ");
		scanf("%d", &opc);
		
		if(opc == 1 || opc == 2 || opc == 3 || opc == 4 || opc == 5) {
			erro = 0;
		} else {
			system("cls");
			Topo();
			printf("\nOpção invalida, por favor selecione novamente!\n");
			erro = 1;
			fflush(stdin);
		}
	} while(erro == 1);
	
	return opc;
}

// Função para efetuar o cadastro dos resultados das corridas
bool CadastraResultados(int pontPilotos[], bool hasData, int vitoriasPilotos[]) {
	// A função recebe como parâmetros o vetor de pontos dos pilotos, a variavel hasData e o vetor de vitórias de pilotos.
	
	int i, piloto, erro = 0; // Variáveis locais, i para o for, piloto para ler do usuário e erro para controlar a entrada de dados.
	
	static int corrida = 0; // Varíavel do tipo static pra fazer a contagem de quantas corridas já foram cadastradas.
	  
	corrida += 1; // A cada execução da função corrida++
	system("cls");
	Topo();
	printf("\nCadastro das informacoes do campeonato.\n");
	printf("Corrida numero %d de 21\n", corrida);

	for(i = 1; i < 6; i++) { // Executa 5 vezes para ler do usuário quais pilotos ficaram em quais posições da corrida
		do {
			erro = 0;
			printf("\n===== %d posicao no campeonato =====", i);
			printf("\nInforme o número do piloto que ocupou essa posição: ");
			scanf("%d", &piloto);
			
			if(piloto > 20 || piloto <= 0) { // Condição para verificar se o número do piloto informado está entre 1 a 20.
				erro = 1;
				printf("\nO piloto informado não existe! Informe um numero de 1 a 20!\n");
				fflush(stdin);
			} else if(i == 1) {
				pontPilotos[piloto] = pontPilotos[piloto] + 25;
				vitoriasPilotos[piloto] = vitoriasPilotos[piloto] + 1; // Piloto em primeiro lugar, recebe uma vitória
			} else if(i == 2) {
				pontPilotos[piloto] = pontPilotos[piloto] + 18;
			} else if(i == 3) {
				pontPilotos[piloto] = pontPilotos[piloto] + 15;
			} else if(i == 4) {
				pontPilotos[piloto] = pontPilotos[piloto] + 12;
			} else if(i == 5) {
				pontPilotos[piloto] = pontPilotos[piloto] + 10;
			}
		} while(erro == 1);
	}
	
	hasData = 1; // Se saiu do laço while, o registro da pontuação funcionou, e hasData agora é 1, liberando o acesso as opções que precisam desses dados
	
	system("cls");

	return hasData;
	
}

void AtualizaEquipes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]) {
	// Função utilizada para atualizar as informações, juntando os pontos de cada piloto e colocando na equipe, assim como
	// as vitórias. (É executada logo após o registro de uma corrida, deixando os dados nos vetores sempre atualizados)
	
	int i; // Varíavel local i para usar no for
	
	for(i = 1; i < 21; i++) { // Executa 
		if(i % 2 == 0) { // Verifica se o número é par ou ímpar, já que as equipes são definidas em números ímpares
		} else {
			pontEquipes[i] = pontPilotos[i] + pontPilotos[i + 1];
			vitoriasEquipes[i] = vitoriasPilotos[i] + vitoriasPilotos[i + 1];
		}
	}
	
}

void ListaPilotos(int pontPilotos[], int vitoriasPilotos[]) {
	// Função para listar pontuação e vitórias dos pilotos, recebe como parâmetros o vetor de pontuação dos pilotos e o vetor de vitórias dos pilotos.
	
	int i; // Varíavel local i para usar no for
	
	system("cls");
	Topo();
	printf("Pontuações individuais de cada piloto: \n");
	
	for(i = 0; i < 20; i++) { // Executa 20 vezes para escrever na tela cada piloto com sua respectiva pontuação e vitórias.
		printf("\nPiloto (%d)\n", i+1);
		printf("Pontuação atual: %d pontos.\n", pontPilotos[i+1]);
		printf("Vitórias individuais: %d\n", vitoriasPilotos[i+1]);
	}
	
}

void ListaEquipes(int pontEquipes[], int vitoriasEquipes[]) {
	// Função para listar pontuação e vitórias da equipe, recebe como parâmetros o vetor de pontuação e de vitórias das equipes.
	
	int i; // Varíavel local i para usar no for
	
	system("cls");
	Topo();
	printf("Pontuações de construtores: \n");
	
	for(i = 1; i < 21; i++) { // Executa 20 vezes para escrever na tela cada equipe com suas respectivas pontuações e vitórias.
		if(i % 2 == 0) {
		} else {
			printf("\nEquipe (%d)\n", i);
			printf("Pontuação atual: %d pontos.\n", pontEquipes[i]);
			printf("Vitórias da equipe: %d\n", vitoriasEquipes[i]);
		}
	}
	
}

void ListaCampeoes(int pontPilotos[], int pontEquipes[], int vitoriasPilotos[], int vitoriasEquipes[]) {
	// Função para listar o piloto campeão e a equipe campeã, recebe como parâmetro todos os vetores,
	// pontuação de pilotos e equipes, e vitórias de pilotos e equipes.
	
	int i, maior = 0, pmaior = 0, posicaoPMaior = 0, posicaoMaior = 0; 
	// Varíaveis locais, i para o for, maior para salvar a maior pontuação atual, pmaior para salvar a penúltima pontuação
	// maior, posicaoMaior para salvar a posição no vetor onde a maior pontuação está, e posicaoPMaior, para salvar a posição
	// no vetor onde a penúltima maior pontuação está.
	
	system("cls");
	Topo();
	
	for(i = 1; i < 21; i++) { // Executa 20 vezes para passar por todos os valores do vetor de pontos dos pilotos e ver qual o maior valor.
		if(pontPilotos[i] >= maior && pontPilotos[i] != 0) { // Condição para ver se os pontos do piloto que o for está executando é maior do que o valor maior já registrado, tendo que ser diferente de zero pontos.
			// Todas essas variáveis começam com zero, mas isso só é executado caso os pontos de algum piloto
			// seja diferente de zero
			
			pmaior = maior; // Penúltimo maior, recebe o valor do valor maior atual antes que seja alterado.
            posicaoPMaior = posicaoMaior; // Posição do penúltimo maior, recebe a posição do maior valor antes que seja alterado.
            
			// A partir daqui os valores já são atualizados pro novo valor maior
			maior = pontPilotos[i]; // O maior valor, armazena os pontos do piloto que possui mais pontos até o momento. 
            posicaoMaior = i; // A posição desse maior valor, armazena em que índice do vetor está esses pontos.
		}
		if(i == 20) { // Condição para verificar se o i é igual a 20, que é a ultima execução do laço for
			printf("\n      Resultado campeão de pilotos      \n");
			if(maior == pmaior){ // Verifica se o maior valor e o penúltimo maior valor são iguais, havendo empate de pontos.
				if(pmaior != 0) {
					if(vitoriasPilotos[posicaoMaior] > vitoriasPilotos[posicaoPMaior]) { // Verifica se o número de vitórias de um é maior que a do outro.
						printf("\nPiloto vencedor individual: \n");
						printf("Piloto (%d)\n", posicaoMaior);
						printf("Pontuação: %d pontos.\n", pontPilotos[posicaoMaior]);
					} else if(vitoriasPilotos[posicaoMaior] < vitoriasPilotos[posicaoPMaior]) { // Verifica se o número de vitórias de um é menor que a do outro.
						printf("\nPiloto vencedor individual: \n");
						printf("Piloto (%d)\n", posicaoPMaior);
						printf("Pontuação: %d pontos.\n", pontPilotos[posicaoPMaior]);
					} else if(vitoriasPilotos[posicaoMaior] == vitoriasPilotos[posicaoPMaior]) { // Verifica se o número de vitórias dos dois pilotos é igual, causando empate.
						printf("\nEmpate!");
						printf("\nDois pilotos obtiveram a mesma quantidade de pontos e de vitórias.");
						
						printf("\n\nPilotos vencedores:");
						printf("\nPiloto (%d) e Piloto(%d)", posicaoPMaior, posicaoMaior);
						printf("\n\nPontuação dos pilotos (%d e %d): %d pontos.", posicaoPMaior, posicaoMaior, pontPilotos[posicaoMaior]);
						if(vitoriasPilotos[posicaoMaior] == 1) { // Apenas muda pro singular caso seja só uma vitória
							printf("\nVitórias dos pilotos (%d e %d): %d vitória.", posicaoPMaior, posicaoMaior, vitoriasPilotos[posicaoMaior]);
						} else {
							printf("\nVitórias dos pilotos (%d e %d): %d vitórias.", posicaoPMaior, posicaoMaior, vitoriasPilotos[posicaoMaior]);
						}
					}
				} else {
					printf("\nPiloto vencedor individual: \n");
					printf("Piloto %d\n", posicaoMaior);
					printf("Pontuação: %d pontos.\n", pontPilotos[posicaoMaior]);
				}
			} else { // Se as duas maiores pontuações não forem iguais, apenas declara vencedor o piloto com mais pontos.
				printf("\nPiloto vencedor individual: \n");
				printf("Piloto %d\n", posicaoMaior);
				printf("Pontuação: %d pontos.\n", pontPilotos[posicaoMaior]);
			}
		}
	}
	
	// Define todas as variáveis para seus valores iniciais
	maior = 0;
    pmaior = 0;
    posicaoPMaior = 0;
    posicaoMaior = 0;
    i = 1;
    
    for(i = 1; i < 21; i++) { // Executa 20 vezes para passar por todos os valores do vetor de pontos das equipes e ver qual o maior valor.
        if(i % 2 == 0) { // Filtra para apenas índices ímpares serem considerados
        } else {
            if(pontEquipes[i] >= maior && pontEquipes[i] != 0) { // Condição para ver se os pontos da equipe que o for está executando é maior do que o valor maior já registrado, tendo que ser diferente de zero pontos.
                // Todas essas variáveis começam com zero, mas isso só é executado caso os pontos de alguma equipe
				// seja diferente de zero
				
				pmaior = maior; // Penúltimo maior, recebe o valor do valor maior atual antes que seja alterado.
                posicaoPMaior = posicaoMaior; // Posição do penúltimo maior, recebe a posição do maior valor antes que seja alterado.
                
				// A partir daqui os valores já são atualizados pro novo valor maior
				maior = pontEquipes[i]; // O maior valor, armazena os pontos da equipe que possui mais pontos até o momento.
                posicaoMaior = i; // A posição desse maior valor, armazena em que índice do vetor está esses pontos.
            } 
        if(i == 19) { // Condição para verificar se o i é igual a 19, que é a ultima equipe dentro do vetor
        	printf("\n\n      Resultado campeão de construtores      \n");
                if(maior == pmaior){ // Verifica se o maior valor e o penúltimo maior valor são iguais, havendo empate de pontos.
                	if(pmaior != 0) {
						if(vitoriasEquipes[posicaoMaior] > vitoriasEquipes[posicaoPMaior]) { // Verifica se o número de vitórias de um é maior que a do outro.
	                        printf("\nEquipe vencedora: \n");
	                        printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoMaior, posicaoMaior, posicaoMaior + 1);
	                        printf("Pontuação da equipe: %d pontos.\n", pontEquipes[posicaoMaior]);
	                    } else if(vitoriasEquipes[posicaoMaior] < vitoriasEquipes[posicaoPMaior]) { // Verifica se o número de vitórias de um é menor que a do outro.
	                        printf("\nEquipe vencedora: \n");
	                        printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoPMaior, posicaoPMaior, posicaoPMaior + 1);
	                        printf("Pontuação da equipe: %d pontos.\n", pontEquipes[posicaoPMaior]);
	                    } else if(vitoriasEquipes[posicaoMaior] == vitoriasEquipes[posicaoPMaior]) { // Verifica se o número de vitórias das duas equipes é igual, causando empate.
	                        printf("\nEmpate!");
	                        printf("\nDuas equipes obtiveram a mesma quantidade de pontos e de vitórias.");
	                        
	                        printf("\n\nEquipes vencedoras:");
	                        printf("\nEquipe (%d) e Equipe(%d)", posicaoPMaior, posicaoMaior);
	                        printf("\n\nPontuação das equipes (%d e %d):: %d pontos.", posicaoPMaior, posicaoMaior, pontEquipes[posicaoMaior]);
	                        if (vitoriasEquipes[posicaoMaior] == 1) { // Apenas muda pro singular caso seja só uma vitória
	                        	printf("\nVitórias das equipes (%d e %d): %d vitória.\n", posicaoPMaior, posicaoMaior, vitoriasEquipes[posicaoMaior]);
							} else {
								printf("\nVitórias das equipes (%d e %d): %d vitórias.\n", posicaoPMaior, posicaoMaior, vitoriasEquipes[posicaoMaior]);
							}
	                    }
					} else {
						printf("\nEquipe vencedora: \n");
                        printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoMaior, posicaoMaior, posicaoMaior + 1);
                        printf("Pontuação da equipe: %d pontos.\n", pontEquipes[posicaoMaior]);
					}
                }  else { // Se as duas maiores pontuações não forem iguais, apenas declara vencedor o piloto com mais pontos.
                    printf("\nEquipe vencedora: \n");
                    printf("Equipe (%d) // Piloto %d e Piloto %d\n", posicaoMaior, posicaoMaior, posicaoMaior + 1);
                    printf("Pontuação da equipe: %d pontos.\n", pontEquipes[posicaoMaior]);
                }
            }
        }
    }
}

int main() {
	
	setlocale(LC_ALL,""); // Define a linguagem de execução do programa, arrumando os acentos. (Biblioteca locale.h)
	
	int opc, x, i; // Variáveis locais, opc para receber a opção do usuário pela função menu, x e i para usar em laços for
	static int corrida = 0; // Uma variável static para armazenar quantas corridas já foram registradas
	bool hasData = 0; // Variável para verificar se alguma corrida já foi registrada na opção 1
	int pontPilotos[20], pontEquipes[20], vitoriasPilotos[20], vitoriasEquipes[20]; // Vetores
	
	for(i; i <= 20; i++){ // Executa 20 vezes para iniciar todos os vetores com 0 em todas as suas posições.
		pontPilotos[i] = 0;
		pontEquipes[i] = 0;
		vitoriasPilotos[i] = 0;
		vitoriasEquipes[i] = 0;
	}
	
	Topo();
	
	do{
		opc = Menu(); // Executa a função do menu
		if(opc == 1) {
			if(corrida > 21) {
				system("cls");
				Topo();
				printf("\nErro, já foram informadas o número máximo de corridas! %d de 21 corridas!\n", corrida);
			} else {
				hasData = CadastraResultados(pontPilotos, hasData, vitoriasPilotos); // Executa a função de cadastro dos resultados e armazena o retorno da varíavel hasData.
				corrida += 1;
				AtualizaEquipes(pontPilotos, pontEquipes, vitoriasPilotos, vitoriasEquipes); // Atualiza as informações das equipes, juntando os pontos e vitórias de cada piloto a sua equipe.
				Topo();
				printf("\nResultado cadastrado com sucesso!\n"); // Informa ao usuário que o resultado foi cadastrado
			}
		} else if(opc == 2) {
			if(hasData == 0) { // Verifica se alguma corrida já foi cadastrada na opção 1.
				system("cls");
				Topo();
				printf("\nEssa opção requer que ao menos um registro de dados seja informado na opção 1.\n");	
			} else if(hasData == 1) {
				ListaPilotos(pontPilotos, vitoriasPilotos); // Executa a função de listar os pilotos passando os vetores de pontuação e vitórias.
				printf("\nPressione qualquer tecla para voltar ao menu principal!\n.");
				system("pause > nul"); // Função da biblioteca windows.h que pausa o programa e só volta a executar quando o usuário aperta alguma tecla. (> nul faz com que a mensagem padrão dessa função não seja exibida)
				system("cls");
				Topo();
			}
		} else if(opc == 3) {
			if(hasData == 0) { // Verifica se alguma corrida já foi cadastrada na opção 1.
				system("cls");
				Topo();
				printf("\nEssa opção requer que ao menos um registro de dados seja informado na opção 1.\n");	
			} else if(hasData == 1) {
				ListaEquipes(pontEquipes, vitoriasEquipes); // Executa a função de listar as equipes passando os vetores de pontuação e vitórias.
				printf("\nPressione qualquer tecla para voltar ao menu principal!\n.");
				system("pause > nul"); // Função da biblioteca windows.h que pausa o programa e só volta a executar quando o usuário aperta alguma tecla. (> nul faz com que a mensagem padrão dessa função não seja exibida)
				system("cls");
				Topo();
			}
		} else if(opc == 4) {
			if(hasData == 0) { // Verifica se alguma corrida já foi cadastrada na opção 1.
				system("cls");
				Topo();
				printf("\nEssa opção requer que ao menos um registro de dados seja informado na opção 1.\n");	
			} else if(hasData == 1) {
				ListaCampeoes(pontPilotos, pontEquipes, vitoriasPilotos, vitoriasEquipes);
				printf("\n\nPressione qualquer tecla para voltar ao menu principal!\n.");
				system("pause > nul"); // Função da biblioteca windows.h que pausa o programa e só volta a executar quando o usuário aperta alguma tecla. (> nul faz com que a mensagem padrão dessa função não seja exibida)
				system("cls");
				Topo();
			}
		} else if(opc == 5) {
			return 0;
		}	
	} while(opc != 5); // Faz com que todas as opções retornem ao menu principal, pois será executado novamente, até que que o usuário escolha 5 para sair.
	
}
