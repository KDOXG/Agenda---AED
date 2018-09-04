#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Pessoa
{
    char *nome, end[2];
}P;

void *pBuffer;
/*
void reOrganizar();
{
//tô vendo que vou tomar muito na jabiraca com isso aqui p_p
//update: ja tô tomando.
}
*/
void incluirPessoa()
/*{
    P *q;
    q=(P *)pBuffer;
    scanf("%s", q->nome);
    printf("%s\n", q->nome);
}
*/
{
    char *c;
    c=(char *)pBuffer;
    scanf("%s", c);
    printf("%s\n", (char *)pBuffer);
}
/*
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
	int *p;//, *q, *i, *j, *k, *l, *v, *w;
	//char *a, **b, *c, *d, *e;

    pBuffer=malloc(sizeof(int)+sizeof(char)*30);
    p=pBuffer;
//    pBuffer=realloc(pBuffer,sizeof(char)*34);

	printf("Digite sua escolha...");
	scanf("%d", p);

	switch (*p)
	{
		case 1:
			incluirPessoa();
		break;/*
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
		break;*/
	}

	return;

}
