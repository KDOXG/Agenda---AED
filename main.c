#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//------------------------------Variáveis e Tipos
typedef struct P
{
	int identidade;
    char nome[30];
}Pessoa;

void *pBuffer;

//------------------------------Funções
void Organizar(int **p, int **q, int **r, int **escolha)
{
	*p=pBuffer+0;
	*q=pBuffer+sizeof(int);
	*r=pBuffer+2*sizeof(int);
	*escolha=pBuffer+3*sizeof(int);
}

void incluirPessoa()
{
    int *p=pBuffer+0, *q=pBuffer+sizeof(int), *r=pBuffer+2*sizeof(int);
    Pessoa *pessoa=pBuffer+sizeof(int)*4;
    pessoa=pessoa+*r;

	printf("Digite o nome: ");
	scanf("%s", pessoa->nome);
    //fgets(pessoa->nome, 30, stdin);
	pessoa->identidade=(int)*pessoa->nome;
	//printf("Digite a identidade: ");
	//scanf("%d", &pessoa->identidade);

    *r=*r+1;
    *q=(*r+1)*sizeof(Pessoa)+4*sizeof(int);
    pBuffer=realloc(pBuffer,*q);
}


/*
void apagarPessoa()
{

}

void buscarPessoa()
{

}
*/
void listarPessoa()
{
	int *i=pBuffer+3*sizeof(int), *r=pBuffer+2*sizeof(int);
	Pessoa *pessoa=pBuffer+4*sizeof(int);
	for (*i=0; *i<=*r; *i=*i+1)
	{
		pessoa=pBuffer+4*sizeof(int);
		if (*i == *r)
			break;
		else
		{
			pessoa=pessoa+*i;
			printf("%s\n", pessoa->nome);
			printf("C�digo de identifica��o: %d\n", pessoa->identidade);
		}
	}
}
/*
void Sair()
{

}
*/
//------------------------------Main
void main()
{
	printf("Bem-vindo à Agenda de KDOXG. \nCarregando...");
	int *p, *q, *r, *escolha;//, *j, *k, *l, *v, *w;
	//char *a, **b, *c, *d, *e;
    pBuffer=malloc(sizeof(int)*4+sizeof(Pessoa));
	Organizar(&p,&q,&r,&escolha);
	*p=0;
	*q=0;
	*r=0;
	
	Inicio: Organizar(&p,&q,&r,&escolha);
	printf("\n------------------------------");
	printf("\n\nDigite sua escolha...\n1 para incluir...\n2 para excluir...\n3 para buscar...\n4 para listar...\n5 para sair...\nCaso escolha outro valor, esta mensagem se repetirá.\n\nDigite: ");
	scanf("%d", escolha);

	switch (*escolha)
	{
		case 1:
			incluirPessoa();
			printf("Pessoa incluída!\n");
			goto Inicio;
		break;/*
		case 2:
			apagarPessoa();
		break;/*
		case 3:
			buscarPessoa();
		break;*/
		case 4:
			listarPessoa();
			printf("Total de pessoas: %d", *r);
			goto Inicio;
		break;/*
		case 5:
			Sair();
		break;*/
		default:
			goto Inicio;
	}
}
