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
void Organizar(int **p, int **q, int **r, int **s, int **t)
{
	*p=pBuffer+0;
	*q=pBuffer+sizeof(int);
	*r=pBuffer+2*sizeof(int);
	*s=pBuffer+3*sizeof(int);
	*t=pBuffer+4*sizeof(int);
}

void InsertionSort()
{
    int *tmp=pBuffer+0*sizeof(int),*i=pBuffer+3*sizeof(int),*j=pBuffer+4*sizeof(int), *n=pBuffer+2*sizeof(int);
    char aux[30];
    Pessoa *pessoa=pBuffer+5*sizeof(int);

    for (*j=1; *j<*n; *j=*j+1)
    {
        *i=*j-1;
        strcpy(aux,(pessoa+*j)->nome);
        *tmp=(pessoa+*j)->identidade;
        while ((*i>=0) && (*tmp < (pessoa+*i)->identidade))
        {
            strcpy((pessoa+*i+1)->nome,(pessoa+*i)->nome);
            (pessoa+*i+1)->identidade = (pessoa+*i)->identidade;
            *i=*i-1;
        }//while
        strcpy((pessoa+*i+1)->nome,aux);
    (pessoa+*i+1)->identidade = *tmp;
    }//for
}//Insertionsort


//------------------------------Métodos
void incluirPessoa()
{
    int /**p=pBuffer+0, */*q=pBuffer+sizeof(int), *r=pBuffer+2*sizeof(int);
    Pessoa *pessoa=pBuffer+sizeof(int)*5;
    pessoa=pessoa+*r;

	printf("Digite o nome: ");
	getchar();
    fgets(pessoa->nome, 30, stdin);
	pessoa->identidade=(int)*pessoa->nome;
	//printf("Digite a identidade: ");
	//scanf("%d", &pessoa->identidade);

    *r=*r+1;
    *q=(*r+1)*sizeof(Pessoa)+5*sizeof(int);
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
	Pessoa *pessoa;
	for (*i=0; *i<=*r; *i=*i+1)
	{
		pessoa=pBuffer+5*sizeof(int);
		if (*i == *r)
			break;
		else
		{
			pessoa=pessoa+*i;
			printf("%s", pessoa->nome);
			printf("Código de identificação: %d\n", pessoa->identidade);
		}
	}
}

void Sair()
{
	free(pBuffer);
	printf("\nObrigado! Um dia esta agenda irá salvar todos os nomes em um arquivo. Volte sempre!");
	exit(1);
}

//------------------------------Main
void main()
{
	printf("Bem-vindo a Agenda de KDOXG. \nCarregando...");
	int *p, *q, *r, *s, *t;//, *j, *k, *l, *v, *w;
	//char *a, **b, *c, *d, *e;
    pBuffer=malloc(sizeof(int)*5+sizeof(Pessoa));
	Organizar(&p,&q,&r,&s,&t);
	*p=0;
	*q=0;
	*r=0;

	printf("\n------------------------------");
	printf("\n\nDigite sua escolha...\n1 para incluir...\n2 para excluir...\n3 para buscar...\n4 para listar...\n5 para sair...\nCaso escolha outro valor, esta mensagem se repetirá.");
	Inicio: Organizar(&p,&q,&r,&s,&t);
	printf("\n\nDigite: ");
	scanf("%d", s);

	switch (*s)
	{
		case 1:
			incluirPessoa();
			InsertionSort();
			printf("Pessoa incluída! Use o 'Listar' para ver seu código de identificação.\n");
			goto Inicio;
			printf("");
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
			printf("");
		break;
		case 5:
			Sair();
		break;
		default:
			goto Inicio;
			printf("");
        break;
	}
}
