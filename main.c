#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
typedef struct Pessoa
{
    char *nome, end[2];
}P;
*/ //Decidir se uso algo a mais além do nome.
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
    char *c=(char*)pBuffer+sizeof(int)*3-1;//, *s;//=(char*)pBuffer;
    //c=(char *)pBuffer;
	printf("Digite o nome...\n");
    scanf("%s", c);
    //s=escreverNome(c);
	realloc(c,strlen(c)*sizeof(char)); /*O que precisa realocar não é o c, e sim o pBuffer*/
    printf("%s\n", (char *)pBuffer);
	printf("%s\t%d\n", c, strlen(c));
}
/*
char * escreverNome(char *c)
{
	realloc(pBuffer,strlen(c)*sizeof(char));
	return (char*)pBuffer;
} //Terminar função*/
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

    pBuffer=malloc(sizeof(int)*3);
    p=pBuffer+0;
	printf("%p\n%p\n%p\n%p\n%p\n", p, pBuffer+sizeof(int)*3, pBuffer+1, pBuffer+2, pBuffer+3);
//    pBuffer=realloc(pBuffer,sizeof(char)*34);

	printf("Digite sua escolha... ");
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
