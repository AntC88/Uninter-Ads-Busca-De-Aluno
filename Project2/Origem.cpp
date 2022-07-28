#include <stdio.h> //Inclui cabeçalho de biblioteca e funções de entrada/saída, respectivamente.
#include <stdlib.h> //Inclui cabeçalho de biblioteca e funções de uso geral, respectivamente.
#include <string.h> //Inclui cabeçalho de biblioteca e funções de manipulação de strings, respectivamente.

int menu(); //Declaração das funções: int (variável para armazenar números inteiros, void (variável para armazenar nada).
void adicionarAluno(struct Lista* Lista, char* nome, char* email, int ru, int posicao); //Função que insere caracteres na variável especial struct que armazena outras variáveis.
struct Lista* CriarLista(int qtd); //Variável especial para armazenar outras variáveis e dados na playlist
void buscar(struct Lista* Lista);
struct Aluno { //Variável especial para armazenar outras variáveis e dados na playlist dentro da estrutura(struct).
	char nome[50], email[50];
	int ru;
	struct Aluno* prox;
};
struct Lista { //Lista de alunos
	int qtd;
	struct Aluno** total;
};
typedef struct Lista Lista;
struct Lista* CriarLista(int qtd);
void adicionarAluno(struct Lista* Lista, char* nome, char* email, int ru, int posicao);
int main()
{
	//armazenar o nome do aluno, e- mail e RU
	Lista* ListaTemp = CriarLista(10);
	char nome1[20] = "Andre";
	char email1[30] = "andre.gamer122@gmail.com";
	char nome2[20] = "Junior";
	char email2[30] = "junior@gmail.com";
	char nome3[20] = "Alfredo";
	char email3[30] = "Alfredo@gmail.com";
	char nome4[20] = "Carla";
	char email4[30] = "carla@gmail.com";
	char nome5[20] = "Roberta";
	char email5[30] = "roberta@gmail.com";
	char nome6[20] = "Ricardo";
	char email6[30] = "ricardo@gmail.com";
	char nome7[20] = "Mateus";
	char email7[30] = "mateus@gmail.com";
	char nome8[20] = "Rebeca";
	char email8[30] = "rebeca@gmail.com";
	char nome9[20] = "ivonir";
	char email9[30] = "ivonir@gmail.com";
	adicionarAluno(ListaTemp, nome1, email1, 3587534, 0);
	adicionarAluno(ListaTemp, nome2, email2, 2132131, 1);
	adicionarAluno(ListaTemp, nome3, email3, 5213452, 2);
	adicionarAluno(ListaTemp, nome4, email4, 4712351, 3);
	adicionarAluno(ListaTemp, nome5, email5, 8711232, 4);
	adicionarAluno(ListaTemp, nome6, email6, 2151213, 5);
	adicionarAluno(ListaTemp, nome7, email7, 4156542, 6);
	adicionarAluno(ListaTemp, nome8, email8, 7951481, 7);
	adicionarAluno(ListaTemp, nome9, email9, 2315631, 8);
	int continuar = 1;
	do
	{
		printf("1 - Pesquisar \n");
		printf("0 - Sair\n");
		scanf_s("%d", &continuar);
		system("cls || clear"); //sempre limpar
		switch (continuar) //menu
		{
		case 1:
			buscar(ListaTemp);
			break;
		case 0:
			return 0;
			break;
		default:
			printf("Digite uma opcao valida \n");
		}
	} while (continuar);
}
struct Lista* CriarLista(int qtd) //inicializa a lista
{
	Lista* Lista = (struct Lista*)malloc(sizeof(struct Lista));
	Lista->qtd = qtd;
	Lista->total = (struct Aluno**)malloc(qtd * sizeof(struct Aluno*));
	for (int i = 0; i < qtd; i++)
		Lista->total[i] = NULL;
	return Lista;
}
void adicionarAluno(struct Lista* Lista, char* nome, char* email, int ru, int
	posicao)
{ //adiciona alunos na lista
	struct Aluno* NovoElemento;
	NovoElemento = (struct Aluno*)malloc(sizeof(struct Aluno));
	strcpy_s(NovoElemento->nome, nome);
	strcpy_s(NovoElemento->email, email);
	NovoElemento->ru = ru;
	NovoElemento->prox = NULL;
	NovoElemento->prox = Lista->total[posicao];
	Lista->total[posicao] = NovoElemento;
}
int menu() {//funcao menu
	int op, c;
	system("Cls");
	printf("1 - Pesquisar \n");
	printf("0 - Sair\n");
	printf("Digite sua escolha: ");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // limpar o buffer do teclado.
	system("Cls");
	return op;
}
void buscar(struct Lista* Lista) //funcao buscar
{
	int num, c;
	printf("Digite o RU que deseja buscar: ");
	scanf_s("%d", &num);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
	int v;
	for (v = 0; v < Lista->qtd; v++)
	{
		struct Aluno* ElementoVarredura = Lista->total[v];
		while (ElementoVarredura != NULL)
		{
			if (ElementoVarredura->ru == num) { // mostra o aluno digitado na busca
				printf(" Nome: %s\n ", ElementoVarredura->nome);
				printf("E-mail: %s\n ", ElementoVarredura->email);
				printf("RU: %d\n ", ElementoVarredura->ru);
				system("pause");
				system("Cls ");
			}
			ElementoVarredura = ElementoVarredura->prox;
		} printf("\n");
	}
}