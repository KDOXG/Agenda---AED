#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Pessoa
{
    char nome, end[2];
}P;

void *pBuffer;
/*
void reOrganizar();
{
//tô vendo que vou tomar muito na jabiraca com isso aqui p_p
}

void incluirPessoa()
{

}

void apagarPessoa()
{

}

void buscarPessoa()
{

}

void listarPessoa()
{

}

void Sair()
{

}
*/
void main()
{
    int a=0;
    P b; //Nas linhas seguintes estarei realizando alguns testes de memória.
    strcat(b.end,"\0");
    a=sizeof(P);
    printf("%d\n", a);
    a=sizeof(int);
    printf("%d\n", a);
    printf("Aqui:%c\n", b.end);
    printf("E aqui:%s", b.end);
/*
	int *p, *q, *i, *j, *k, *l, *v, *w;
	char *a, **b, *c, *d, *e;

	scanf("%d", p);

	switch (*p)
	{
		case 1:
			incluirPessoa();
		break;
		case 2:
			apagarPessoa();
		break;
		case 3:
			buscarPessoa();
		break;
		case 4:
			listarPessoa();
		break;
		case 5:
			Sair();
		break;
	}
*/
	return;

}
