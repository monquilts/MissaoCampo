/*
Sistema operacional: Windows 10
Programa em C que implementa um jogo de RPG
*/
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
//Definicao de constantes
#define NOME_ARQUIVO_ENTRADA "entrada.txt"
#define NOME_ARQUIVO_SAIDA "saida.txt"
#define NOME_ARQUIVO_TEXTOS "textos.txt"

//Definicao de Enums
typedef enum _TIPO_NO {
	RAIZ,TERMINAL,NAO_TERMINAL
} TIPO_NO;

typedef struct No{
	int numNo;
	int tipo;
	int numOpcoes;
	int addHabilidadeS, addHabilidadeB, addHabilidadeP;
	bool temRandom; char **opcoesRandom;
	struct No *prox[3]; // numero maximo de aresta (opcao)
} No;


/////Variaveis globais
FILE *arquivoTextos;
FILE *arquivoSaida;

char *nomeDoJogador;
No *noAtual;
int habilidadeSorte = 4, habilidadeBizonhice=3, habilidadeProgramacao=2, ataque=3;
//Prototipos
char* replaceWord(char* linha,char* subst,char* novo);
void printaNo(int numNo); //comeco na raiz
void inicializaNos();
void atualizaNo();
void fechaNos();
void desenhadado();
int executa_dado();
void carinhaTriste();
int dadoBatle();
void batle();
void desenhaBarata();
void atualizaTabela();
void getcr();
void cls();

int main(){
	arquivoTextos = fopen(NOME_ARQUIVO_TEXTOS,"r");
	arquivoSaida = fopen(NOME_ARQUIVO_SAIDA,"w");
	FILE *arquivoEntrada = fopen(NOME_ARQUIVO_ENTRADA,"r");
	if (arquivoTextos == NULL || arquivoEntrada == NULL) {
		printf("ERRO AO ABRIR OS ARQUIVOS!");
		fprintf(arquivoSaida,"ERRO AO ABRIR OS ARQUIVOS!");
		exit(1);
	}
	nomeDoJogador = (char*) malloc(100*sizeof(char));
	fgets(nomeDoJogador,100,arquivoEntrada);
	fclose(arquivoEntrada);
	inicializaNos();
	bool naoTermina = true;
	printf("Para uma melhor experiencia, abra em TELA CHEIA.");
	fprintf(arquivoSaida,"Para uma melhor experiencia, abra em TELA CHEIA.");
	getcr();
	while(naoTermina){
		printaNo(noAtual->numNo);
		if(noAtual->tipo == TERMINAL){
			naoTermina=false;
			getchar();
		}
		else{
		atualizaNo();
		cls();}
	}
	fechaNos(noAtual);
	fclose(arquivoTextos);
	fclose(arquivoSaida);
	return 0;
}
void inicializaNos(){
	No *noUm,*noDois,*noTres,*noQuatro, *noCinco, *noSeis, *noSete, *noOito, *noNove, *noDez, *noOnze, *noDoze, *noTreze, *noQuatorze, *noQuinze, *noDezesseis, *noDezessete, *noDezoito, *noDezenove; //...
	noAtual = (No*) malloc(1*sizeof(No));
	noUm = (No*) malloc(1*sizeof(No));
	noDois = (No*) malloc(1*sizeof(No));
	noTres = (No*) malloc(1*sizeof(No));
	noQuatro = (No*) malloc(1*sizeof(No));
	noCinco = (No*) malloc(1*sizeof(No));
	noSeis = (No*) malloc(1*sizeof(No));
	noSete = (No*) malloc(1*sizeof(No));
	noOito = (No*) malloc(1*sizeof(No));
	noNove = (No*) malloc(1*sizeof(No));
	noDez = (No*) malloc(1*sizeof(No));
	noOnze = (No*) malloc(1*sizeof(No));
	noDoze = (No*) malloc(1*sizeof(No));
	noTreze = (No*) malloc(1*sizeof(No));
	noQuatorze = (No*) malloc(1*sizeof(No));
	noQuinze = (No*) malloc(1*sizeof(No));
	noDezesseis = (No*) malloc(1*sizeof(No));
	noDezessete = (No*) malloc(1*sizeof(No));
	noDezoito = (No*) malloc(1*sizeof(No));
	noDezenove = (No*) malloc(1*sizeof(No));

	//raiz
	noAtual->numNo = 0; noAtual->tipo = RAIZ; noAtual->numOpcoes = 3; noAtual->temRandom = false; noAtual->addHabilidadeS = 0; noAtual->addHabilidadeB = 0; noAtual->addHabilidadeP = 0; // noatual->pipi popopo pras 3
	noAtual->prox[0] = noUm; noAtual->prox[1] = noDois; noAtual->prox[2] = noTres; // arestas

    // no 1
	noUm->numNo = 1; noUm->tipo = NAO_TERMINAL; noUm->numOpcoes = 3; noUm->temRandom = false; noUm->addHabilidadeS = 0; noUm->addHabilidadeB = 0; noUm->addHabilidadeP = 0;
	noUm->prox[0] = noQuatro; noUm->prox[1] = noCinco; noUm->prox[2] = noSeis;

	// no 2
	noDois->numNo = 2; noDois->tipo = NAO_TERMINAL; noDois->numOpcoes = 2; noDois->temRandom = false; noDois->addHabilidadeS = 0; noDois->addHabilidadeB = 0; noDois->addHabilidadeP = 0;
	noDois->prox[0] = noNove; noDois->prox[1] = noDez;

	// no3
	noTres->numNo = 3; noTres->tipo = NAO_TERMINAL; noTres->numOpcoes = 2; noTres->temRandom = false; noTres->addHabilidadeS = 0; noTres->addHabilidadeB = 0; noTres->addHabilidadeP = 0;
	noTres->prox[0] = noQuatorze; noTres->prox[1] = noQuinze;

	// no 4
	noQuatro->numNo = 4; noQuatro->tipo = NAO_TERMINAL; noQuatro->numOpcoes = 2; noQuatro->temRandom = false; noQuatro->addHabilidadeS = 0; noQuatro->addHabilidadeB = 0; noQuatro->addHabilidadeP = 0;
	noQuatro->prox[0] = noSete; noQuatro->prox[1] = noOito;

	// no 5
	noCinco->numNo = 5; noCinco->tipo = NAO_TERMINAL; noCinco->numOpcoes = 1; noCinco->temRandom = true; noCinco->addHabilidadeS = 2; noCinco->addHabilidadeB = 0; noCinco->addHabilidadeP = 0;
	noCinco->opcoesRandom = (char**) malloc(2*sizeof(char*));
	noCinco->opcoesRandom[0] = (char*) malloc(10000 * sizeof(char));
	noCinco->opcoesRandom[0] = "Voce fica extremamente zangado pois sempre acaba antes de voce conseguir comprar, mas isso fica pra depois, foco na missao...\n";
	noCinco->opcoesRandom[1] = (char*) malloc(10000 * sizeof(char));
	noCinco->opcoesRandom[1] = "Voce compra um kit kat e sai.\n";
	noCinco->prox[0] = noSeis;

	// no 6
	noSeis->numNo = 6; noSeis->tipo = NAO_TERMINAL; noSeis->numOpcoes = 1; noSeis->temRandom = false; noSeis->addHabilidadeS = 1; noSeis->addHabilidadeB = 0; noSeis->addHabilidadeP = 0;
	noSeis->prox[0] = noDezoito;

    // no 7
	noSete->numNo = 7; noSete->tipo = NAO_TERMINAL; noSete->numOpcoes = 2; noSete->temRandom = true; noSete->addHabilidadeS = 1; noSete->addHabilidadeB = 0; noSete->addHabilidadeP = 0;
	noSete->opcoesRandom = (char**) malloc(2*sizeof(char*));
	noSete->opcoesRandom[0] = (char*) malloc(10000 * sizeof(char));
	noSete->opcoesRandom[0] = "Voce segue correndo, mas a Major eh tranquila e compreendeu que voce estava no sanha. Mas, talvez, ela lhe questione sobre isso na aula seguinte...\n";
	noSete->opcoesRandom[1] = (char*) malloc(10000 * sizeof(char));
	noSete->opcoesRandom[1] = "Voce diminui o passo, presta continencia e volta a correr.\n";
	noSete->prox[0] = noCinco; noSete->prox[1] = noSeis;

    // no 8
	noOito->numNo = 8; noOito->tipo = NAO_TERMINAL; noOito->numOpcoes = 1; noOito->temRandom = true; noOito->addHabilidadeS = 0; noOito->addHabilidadeB = 0; noOito->addHabilidadeP = 2;
	noOito->opcoesRandom = (char**) malloc(2*sizeof(char*));
	noOito->opcoesRandom[0] = (char*) malloc(10000 * sizeof(char));
	noOito->opcoesRandom[0] = "#JOGADOR: Ehhh.. realmente estou atrasado, tenho que ir agora, pode me mandar pelo WhatsApp para eu tentar resolver pra voce novamente (provavelmente vou continuar sem saber resolver). Aqui,voce sabe onde a Evelyn esta?\n";
	noOito->opcoesRandom[1] = (char*) malloc(10000 * sizeof(char));
	noOito->opcoesRandom[1] = "#JOGADOR: Prontinho Camila! Agora, deixa eu te perguntar, sabe onde a Evelyn esta?\n";
	noOito->prox[0] = noSeis;

	// no 9
	noNove->numNo = 9; noNove->tipo = NAO_TERMINAL; noNove->numOpcoes = 1; noNove->temRandom = false; noNove->addHabilidadeS = 0; noNove->addHabilidadeB = 3; noNove->addHabilidadeP = 0;
	noNove->prox[0] = noDezenove;

	// no 10
	noDez->numNo = 10; noDez->tipo = NAO_TERMINAL; noDez->numOpcoes = 2; noDez->temRandom = false; noDez->addHabilidadeS = 0; noDez->addHabilidadeB = (-3); noDez->addHabilidadeP = 0;
	noDez->prox[0] = noOnze; noDez->prox[1] = noDoze;

	// no 11
	noOnze->numNo = 11; noOnze->tipo = NAO_TERMINAL; noOnze->numOpcoes = 1; noOnze->temRandom = true; noOnze->addHabilidadeS = 3; noOnze->addHabilidadeB = 0; noOnze->addHabilidadeP = 0;
	noOnze->opcoesRandom = (char**) malloc(2*sizeof(char*));
	noOnze->opcoesRandom[0] = (char*) malloc(10000 * sizeof(char));
	noOnze->opcoesRandom[0] = "Por sorte ele nao avistou voce, porem o Cap Guimaraes avistou voce varando continencia e chama sua atencao. Que azar aluno...\n";
	noOnze->opcoesRandom[1] = (char*) malloc(10000 * sizeof(char));
	noOnze->opcoesRandom[1] = "Entao diminui o passo e  presta a continencia, e voce comemora por ter avistado, pois seu colega semana passada foi torrado por varar continencia...\n";
	noOnze->prox[0] = noDezoito;

	// no 12
	noDoze->numNo = 12; noDoze->tipo = NAO_TERMINAL; noDoze->numOpcoes = 2; noDoze->temRandom = false; noDoze->addHabilidadeS = 0; noDoze->addHabilidadeB = 0; noDoze->addHabilidadeP = 0;
	noDoze->prox[0] = noTreze; noDoze->prox[1] = noOnze;

	// no 13
	noTreze->numNo = 13; noTreze->tipo = NAO_TERMINAL; noTreze->numOpcoes = 1; noTreze->temRandom = false; noTreze->addHabilidadeS = (-1); noTreze->addHabilidadeB = (-2); noTreze->addHabilidadeP = 0;
	noTreze->prox[0] = noDezenove;

	// no 14
	noQuatorze->numNo = 14; noQuatorze->tipo = NAO_TERMINAL; noQuatorze->numOpcoes = 2; noQuatorze->temRandom = false; noQuatorze->addHabilidadeS = 0; noQuatorze->addHabilidadeB = 2; noQuatorze->addHabilidadeP = 0;
	noQuatorze->prox[0] = noDezesseis; noQuatorze->prox[1] = noDezessete;

	// no 15
	noQuinze->numNo = 15; noQuinze->tipo = NAO_TERMINAL; noQuinze->numOpcoes = 1; noQuinze->temRandom = true; noQuinze->addHabilidadeS = 2; noQuinze->addHabilidadeB = 0; noQuinze->addHabilidadeP = 0;
	noQuinze->opcoesRandom = (char**) malloc(2*sizeof(char*));
	noQuinze->opcoesRandom[0] = (char*) malloc(10000 * sizeof(char));
	noQuinze->opcoesRandom[0] = "Voce rapidamente avista a tenente e muda de rota. Porem, da de cara com o Major Euclides na porta. PLOTADO!!\n";
	noQuinze->opcoesRandom[1] = (char*) malloc(10000 * sizeof(char));
	noQuinze->opcoesRandom[1] = "Ten Taiana Maria: Voce nao pode entrar no alojamento feminino, ARREGO aluno! TORRADO, DUVIDAS?\n";
	noQuinze->prox[0] = noDezenove;

	// no 16
	noDezesseis->numNo = 16; noDezesseis->tipo = NAO_TERMINAL; noDezesseis->numOpcoes = 1; noDezesseis->temRandom = true; noDezesseis->addHabilidadeS = 2; noDezesseis->addHabilidadeB = 0; noDezesseis->addHabilidadeP = 0;
	noDezesseis->opcoesRandom = (char**) malloc(2*sizeof(char*));
	noDezesseis->opcoesRandom[0] = (char*) malloc(10000 * sizeof(char));
	noDezesseis->opcoesRandom[0] = "Voce nao o ve e ele chama sua atencao, anota seu nome e diz que SOMENTE dessa vez voce nao ira ser torrado. Porem, vai ser cobrado nas aulas... acabou sua moita!\n";
	noDezesseis->opcoesRandom[1] = (char*) malloc(10000 * sizeof(char));
	noDezesseis->opcoesRandom[1] = "Voce presta continencia, o cumprimenta e segue seu objetivo.\n";
	noDezesseis->prox[0] = noDezoito;

	// no 17
	noDezessete->numNo = 17; noDezessete->tipo = NAO_TERMINAL; noDezessete->numOpcoes = 1; noDezessete->temRandom = false; noDezessete->addHabilidadeS = 0; noDezessete->addHabilidadeB = 0; noDezessete->addHabilidadeP = 0;
	noDezessete->prox[0] = noDezenove;

	// no 18
	noDezoito->numNo = 18; noDezoito->tipo = TERMINAL; noDezoito->numOpcoes = 0; noDezoito->temRandom = false; noDezoito->addHabilidadeB = 0; noDezoito->addHabilidadeS = 0; noDezoito->addHabilidadeP = 0;

	// no 19
	noDezenove->numNo = 19; noDezenove->tipo = TERMINAL; noDezenove->numOpcoes = 0; noDezenove->temRandom = false; noDezenove->addHabilidadeB = 0; noDezenove->addHabilidadeS = 0; noDezenove->addHabilidadeP = 0;
}
void atualizaNo(){ // atualiza o no atual de acordo com a entrada
	int opcao = 0;
	do{
		scanf("%d",&opcao);
		getchar();
		if(opcao > noAtual->numOpcoes || opcao <= 0){
			printf("Opcao Invalida! Digite um opcao valida:\n");
			fprintf(arquivoSaida,"Opcao Invalida! Digite um opcao valida:\n");
		}
	}while(opcao > noAtual->numOpcoes || opcao <= 0);
	opcao--;
	noAtual = noAtual->prox[opcao];
}
void fechaNos(No *cur){ //da free nos nos
	if(cur == NULL) return;
	for(int i=0;i<cur->numOpcoes;i++){
		fechaNos(cur->prox[i]);
	}
	free(cur);
}
void printaNo(int numNo){
	fseek(arquivoTextos, 0, SEEK_SET);
	int noPrintar = 0;
	int numLinhas = 0;
	fscanf(arquivoTextos,"#%d-%d\n",&noPrintar,&numLinhas);
	while(noPrintar != numNo){
		for(int i=0;i<numLinhas;i++){
			char skip[100000];
			fgets(skip,100000,arquivoTextos);
		}
		fscanf(arquivoTextos,"#%d-%d\n",&noPrintar,&numLinhas);
	}
	if(noAtual->tipo!=TERMINAL){
	atualizaTabela();}
	printf("\n\n\n");
	for(int i=0;i<numLinhas;i++){
		char *skip;
		skip = (char*) malloc(100000*sizeof(char));
		fgets(skip,100000,arquivoTextos);
		if(strcmp(skip,"#RANDOM\n") == 0 || strcmp(skip,"#RANDOM\r\n") == 0){
			printf("\n");
			int resultado = executa_dado();
			if(resultado > habilidadeSorte && noAtual->addHabilidadeS!=0){
				skip = noAtual->opcoesRandom[0];
				printf("\nVoce perdeu:\n%d PONTOS SORTE\n",noAtual->addHabilidadeS);
				fprintf(arquivoSaida,"\nVoce perdeu:\n%d PONTOS SORTE\n",noAtual->addHabilidadeS);
				habilidadeSorte -= (noAtual->addHabilidadeS);
				getcr();
			}
			else if(resultado > habilidadeBizonhice && noAtual->addHabilidadeB!=0){
				skip = noAtual->opcoesRandom[0];
				printf("\nVoce perdeu:\n%d PONTOS BISONHICE\n",noAtual->addHabilidadeB);
				fprintf(arquivoSaida,"\nVoce perdeu:\n%d PONTOS BISONHICE\n",noAtual->addHabilidadeB);
				habilidadeBizonhice -= (noAtual->addHabilidadeB);
				getcr();
			}
			else if( resultado > habilidadeProgramacao && noAtual->addHabilidadeP!=0){
				skip = noAtual->opcoesRandom[0];
				printf("\nVoce perdeu:\n%d PONTOS PROGRAMACAO\n",noAtual->addHabilidadeP);
				fprintf(arquivoSaida,"\nVoce perdeu:\n%d PONTOS PROGRAMACAO\n",noAtual->addHabilidadeP);
				habilidadeProgramacao -= (noAtual->addHabilidadeP);
				getcr();
			}
			else if(resultado <= habilidadeSorte && noAtual->addHabilidadeS!=0){
				skip = noAtual->opcoesRandom[1];
			}
			else if(resultado <= habilidadeBizonhice && noAtual->addHabilidadeB!=0){
				skip = noAtual->opcoesRandom[1];
			}
			else if( resultado <= habilidadeProgramacao && noAtual->addHabilidadeP!=0){
				skip = noAtual->opcoesRandom[1];
			}
		}
		if(strcmp(skip,"#FACE\n")==0 || strcmp(skip,"#FACE\r\n") == 0){
			carinhaTriste();
			printf("\n\n");
		}
		else if(strcmp(skip,"#BATLE\n")==0 || strcmp(skip,"#BATLE\r\n") == 0){
			printf("\nVoce avista uma barata e voce tem pavor, mas voce estava na frente da ala inteira e decide dar uma de corajoso, entao tem que decidir lutar ou nao com a barata...\n\n");
			fprintf(arquivoSaida,"\nVoce avista uma barata e voce tem pavor, mas voce estava na frente da ala inteira e decide dar uma de corajoso, entao tem que decidir lutar ou nao com a barata...\n\n");
			getcr();
			batle();
		}
		else{
			skip = replaceWord(skip,"#JOGADOR",nomeDoJogador);
			printf("%s",skip);
			fprintf(arquivoSaida,"%s",skip);
		}
	}
}
void carinhaTriste(){
    char cara[][12] ={"    ***    ",
	                   " **     ** ",
                       "**  0 0  **",
                       "**   ^   **",
                       "  * *** *  "};

     int i,j;
      for(i=0;i<=4;i++)
      {
        for(j=0;j<=11;j++)
        printf("%c",cara[i][j]);
		if (i<4)
        printf("\n");
      }
      printf("\n");
	  getcr();
}
char* replaceWord(char* linha,char* subst,char* novo){
    char* result;
    int i, cnt = 0;
    int x = strlen(novo);
    int y = strlen(subst);
    for(i = 0; i < strlen(linha); i++) {
        if(strstr(&linha[i],subst)==&linha[i]) {
            cnt++;
            i += x - 1;
        }
    }
    result = (char*)malloc(i + cnt * (x - y) + 1);
    i = 0;
    while(*linha){
        if (strstr(linha, subst) == linha) {
            strcpy(&result[i], novo);
            i+=x;
            linha+=y;
        }
        else result[i++] = *linha++;
    }
    result[i] = '\0';
    return result;
}
void desenhadado(){
    char dado [][40] ={"   ***********      *********** ",
                       "  *         **     *         **",
                       " *         * *    *         * *",
                       "***********  *   ***********  *",
                       "*  TESTE  *  *   *         *  *",
                       "*   SUA   *  *   *   SE    *  *",
                       "*  SORTE  *  *   *  PUDER  *  * ",
                       "*         * *    *         * *  ",
                       "***********      ***********"};
     int i,j;
      for(i=0;i<=8;i++)
      {
        for(j=0;j<=30;j++)
        printf("%c",dado[i][j]);
        printf("\n");
      }
}
int executa_dado(){
	if(noAtual->addHabilidadeS!=0){
		printf("Essa acao exigira de voce habilidade em SORTE.\n");
		getcr();
	}
	else if(noAtual->addHabilidadeP!=0){
		printf("Essa acao exigira de voce habilidade em PROGRAMACAO.\n");
		getcr();
	}
    printf("\nTeste sua sorte...\n");
	fprintf(arquivoSaida,"\nTeste sua sorte...");
    desenhadado();
	getcr();
	fprintf(arquivoSaida,"\nTeste sua sorte...");
    srand(time(NULL));
	int resultado = rand()%6 + 1;
    printf("O dado resultou... %d\n", resultado);
	fprintf(arquivoSaida,"O dado resultou... %d\n", resultado);
	getcr();
	return resultado;
}
int dadoBatle(){
	srand(time(NULL));
	int resultadox = rand()%6 + 1;
	printf("O ataque do seu inimigo sera: %d\n\n", resultadox);
	fprintf(arquivoSaida,"O ataque do seu inimigo sera: %d\n\n", resultadox);
	return resultadox;
}
void batle(){
	int ataqueInimigo=dadoBatle(), rsp;
	printf("\n\n");
	getcr();
	cls();
	if(ataqueInimigo>ataque){
        desenhaBarata();
		printf("O ataque da baratinha Zulu eh maior que o seu. Voce quer atacar mesmo assim?\n1-SIM\n2-NAO\n\n");
		fprintf(arquivoSaida,"O ataque da baratinha Zulu eh maior que o seu. Voce quer atacar mesmo assim?\n1-SIM\n2-NAO\n\n");
		scanf("%d", &rsp);
		getchar();
		cls();
		desenhaBarata();
		printf("\n\n");
		if(rsp==2){
			printf("Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...  \n\n");
			fprintf(arquivoSaida,"Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...  \n\n");
		}
		else if(rsp==1){
			printf("Voce perdeu a briga e a ala inteira riu de voce. Triste dia. Voce perde 1 ponto em SORTE por conta disso.  \n\n");
			fprintf(arquivoSaida,"Voce perdeu a briga e a ala inteira riu de voce. Triste dia. Voce perde 1 ponto em SORTE por conta disso.  \n\n");
			habilidadeSorte--;
		}
		else{
			do{
				scanf("%d",&rsp);
				getchar();
				if(rsp > 2 || rsp <= 0){
						printf("Opcao Invalida! Digite um opcao valida:\n");
						fprintf(arquivoSaida,"Opcao Invalida! Digite um opcao valida:\n");
				}
			}while(rsp > 2 || rsp <= 0);
		}
	}
	else if(ataqueInimigo==ataque){
	    desenhaBarata();
		printf("O ataque da baratinha Zulu eh igual ao seu. Voce quer atacar mesmo assim?\n1-SIM\n2-NAO\n\n");
		printf("\n\n");
		fprintf(arquivoSaida,"O ataque da baratinha Zulu eh igual ao seu. Voce quer atacar mesmo assim?\n1-SIM\n2-NAO\n\n");
		scanf("%d", &rsp);
		getchar();
		cls();
		desenhaBarata();
		printf("\n\n");
		if(rsp==2){
			printf("Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...\n\n");
			fprintf(arquivoSaida,"Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...\n\n");
		}
		else if(rsp==1){
			int rsp2;
			printf("Voce ataca a baratinha e ela voa em voce, o ataque dela diminui em 1 ponto.Ainda deseja continuar essa briga?\n1-SIM\n2-NAO\n\n");
			fprintf(arquivoSaida,"Voce ataca a baratinha e ela voa em voce, o ataque dela diminui em 1 ponto.Ainda deseja continuar essa briga?\n1-SIM\n2-NAO\n\n");
			scanf("%d", &rsp2);
			getchar();
			ataqueInimigo--;
			if(rsp2==1){
				printf("Foi uma luta ardua, mas voce venceu, parabens!\n\n");
				fprintf(arquivoSaida,"Foi uma luta ardua, mas voce venceu, parabens!\n\n");
			}
			else if(rsp2==2){
				printf("Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...\n\n");
				fprintf(arquivoSaida,"Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...\n\n");
			}
			else{
				do{
					scanf("%d",&rsp2);
					getchar();
					if(rsp2 > 2 || rsp2 <= 0){
							printf("Opcao Invalida! Digite um opcao valida:\n");
							fprintf(arquivoSaida,"Opcao Invalida! Digite um opcao valida:\n");
					}
				}while(rsp2 > 2 || rsp2 <= 0);
			}

		}
		else{
			do{
				scanf("%d",&rsp);
				getchar();
				if(rsp > 2 || rsp <= 0){
						printf("Opcao Invalida! Digite um opcao valida:\n");
						fprintf(arquivoSaida,"Opcao Invalida! Digite um opcao valida:\n");
				}
			}while(rsp > 2 || rsp <= 0);
		}
	}
	else{
        desenhaBarata();
		printf("O ataque da baratinha Zulu eh menor que o seu. Voce quer atacar?\n1-SIM\n2-NAO\n\n");
		fprintf(arquivoSaida,"O ataque da baratinha Zulu eh menor que o seu. Voce quer atacar?\n1-SIM\n2-NAO\n\n");
		scanf("%d", &rsp);
		getchar();
		cls();
		desenhaBarata();
		printf("\n\n");
		if(rsp==1){
		printf("Voce ja sabia que era uma luta garantida. Que pena que Zulu morreu.\n A ala inteira vibra e isso eleva ate sua moral, por conta disso voce ganha 1 ponto em SORTE. \n\n");
		fprintf(arquivoSaida,"Voce ja sabia que era uma luta garantida. Que pena que Zulu morreu.\n A ala inteira vibra e isso eleva ate sua moral, por conta disso voce ganha 1 ponto em SORTE. \n\n");
		habilidadeSorte++;
		}
		else if(rsp==2){
			printf("Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...  \n\n");
			fprintf(arquivoSaida,"Voce decidiu deixar pra la essa ideia e foi terminar de resolver seu sanha...  \n\n");
		}
		else{
			do{
				scanf("%d",&rsp);
				getchar();
				if(rsp > 2 || rsp <= 0){
						printf("Opcao Invalida! Digite um opcao valida:\n");
						fprintf(arquivoSaida,"Opcao Invalida! Digite um opcao valida:\n");
				}
			}while(rsp > 2 || rsp <= 0);
		}
	}
	}
void desenhaBarata(){
	char barata[][60] ={"     *         *",
                       "      *       *	",
                       "	*   *",
                       "	  *",
                       "        ** **",
                       "        *   *",
                       "	*   *",
                       "    ** *     * **",
                       "  *   *       *  *",
                       "     *         *",
                       " ** *	        * **",
                       "*   *	        *   *",
                       "     *         *",
                       "   **  *     *  **",
                       "  *	  *	  *    "
                       };
     int i,j;
      for(i=0;i<=14;i++)
      {
        for(j=0;j<=40;j++)
        printf("%c",barata[i][j]);
		if(i<14)
		printf("\n");
      }
      printf("\n");
}
void atualizaTabela(){
	char tab[][115] ={"***********************              AQUI EH UMA TABELA COM SUAS HABILIDADES",
                       "*   HABILIDADES       *              TODAS SUAS ACOES DEVERAO SER PENSADAS COM BASE NELA",
                       "***********************              MUITAS VEZES VOCE CAIRA EM SITUACOES QUE EXIGIRAO",
                       "* BISONHICE:  B       *              O ROLAR DADO, ATENTE-SE A ISSO DURANTE TODO O JOGO",
                       "*                     *              REGRAS:",
                       "* SORTE:  B           *              1) VOCE SO GANHA O JOGO SE NAO FOR TORRADO ",
                       "*                     *              2) CADA VEZ QUE O DADO ROLAR, ELE DEFINE A HABILIDADE NECESSARIA ",
                       "* PROGRAMACAO:  P     *              PARA QUE VOCE TENHA SUCESSO OU NAO NA SITUACAO ",
                       "*                     *              EX: SE O DADO DIZ QUE TAL SITUACAO EXIGE 5 DE HABILIDADE    ",
                       "* ATAQUE:  A          *              E VOCE POSSUI 4, ALGO NEGATIVO LHE ACONTECERA, QUE PODE LHE CAUSAR DANOS",
                       "***********************              OU NAO. BOA SORTE E BOM JOGO!!! ",
                       "                                                                     ",
                       "K                                                                               "};

     int i,j;
      for(i=0;i<=12;i++){
        for(j=0;j<=108;j++){
			if(i==12 && j==0){
				if(noAtual->temRandom == false){
					if(noAtual->addHabilidadeS<0){
						printf("Por consequencias de suas acoes, voce perde %d em SORTE.", (-1)*noAtual->addHabilidadeS);
						fprintf(arquivoSaida,"Por consequencias de suas acoes, voce perde %d em SORTE.", noAtual->addHabilidadeS);
					}
					else if(noAtual->addHabilidadeB<0){
						printf("Por consequencias de suas acoes, voce perde %d em BISONHICE.", (-1)*noAtual->addHabilidadeB);
						fprintf(arquivoSaida,"Por consequencias de suas acoes, voce perde %d em BISONHICE.", noAtual->addHabilidadeB);
					}
					else if(noAtual->addHabilidadeP<0){
						printf("Por consequencias de suas acoes, voce perde %d em PROGRAMACAO.", (-1)*noAtual->addHabilidadeP);
						fprintf(arquivoSaida,"Por consequencias de suas acoes, voce perde %d em PROGRAMACAO.", noAtual->addHabilidadeP);
					}
					else if(noAtual->addHabilidadeS>0){
						printf("Por consequencias de suas acoes, voce ganha %d em SORTE.", noAtual->addHabilidadeS);
						fprintf(arquivoSaida,"Por consequencias de suas acoes, voce ganha %d em SORTE.", noAtual->addHabilidadeS);
					}
					else if(noAtual->addHabilidadeB>0){
						printf("Por consequencias de suas acoes, voce ganha %d em BISONHICE. ", noAtual->addHabilidadeB);
						fprintf(arquivoSaida,"Por consequencias de suas acoes, voce ganha %d em BISONHICE.", noAtual->addHabilidadeB);
					}
					else if(noAtual->addHabilidadeP>0){
						printf("Por consequencias de suas acoes, voce ganha %d em PROGRAMACAO.", noAtual->addHabilidadeP);
						fprintf(arquivoSaida,"Por consequencias de suas acoes, voce ganha %d em PROGRAMACAO.", noAtual->addHabilidadeP);
					}
					habilidadeSorte += noAtual->addHabilidadeS;
					habilidadeBizonhice += noAtual->addHabilidadeB;
					habilidadeProgramacao += noAtual->addHabilidadeP;
				}
				if(habilidadeBizonhice==0){
					printf(" 0 bisonhice! Brabo! Pegue mais 2 pontos!");
					fprintf(arquivoSaida,"0 bisonhice! Brabo! Pegue mais 2 pontos!");
					habilidadeBizonhice+=2;
				}
        }
		else if(i==3 && j==14){
			if(habilidadeBizonhice>=0) printf("%d", habilidadeBizonhice);
			else printf("%d", 0);
		}
		else if(i==5 && j==10){
			if(habilidadeSorte>=0) printf("%d", habilidadeSorte);
			else printf("%d", 0);
		}
		else if(i==7 && j==16){
			if(habilidadeProgramacao>=0) printf("%d", habilidadeProgramacao);
			else printf("%d", 0);
		}
		else if(i==9 && j==11){
			if(ataque>=0) printf("%d", ataque);
			else printf("%d",0);
		}
		else{
            printf("%c",tab[i][j]);}}
            printf("\n");
        }
}
void getcr(){
    printf("Pressione ENTER para continuar...\n");
    getchar();
}
void cls(){
    for(int i=0;i<=100;i++){
        printf("\n");
    }
}
