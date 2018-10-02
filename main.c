#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <ctype.h>
#include <locale.h>

/**	Índices do buffer virtual:
 * pBuffer+0 = variável de auxílio
 * pBuffer+sizeof(int) = tamanho do buffer
 * pBuffer+2*sizeof(int) = quantidade de nomes cadastrados na agenda
 * pBuffer+3*sizeof(int) = variável de índice para laços de repetição
 * pBuffer+4*sizeof(int) = segunda variável de índice para laços de repetição
 * pBuffer+5*sizeof(int) = começo dos dados da agenda
 * */
=======
#include <ctype.h>
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4

//------------------------------Vari�veis e Tipos
typedef struct P
{
	int identidade;
    char nome[30];
}Pessoa;

void *pBuffer;

<<<<<<< HEAD
//------------------------------Funções
=======
//------------------------------Fun��es
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
void Organizar(int **p, int **q, int **r, int **s, int **t)
{
	*p=pBuffer+0;
	*q=pBuffer+sizeof(int);
	*r=pBuffer+2*sizeof(int);
<<<<<<< HEAD
	*s=pBuffer+3*sizeof(int);
	*t=pBuffer+4*sizeof(int);
}

void InsertionSort()
{
    int *tmp=pBuffer+0*sizeof(int),*i=pBuffer+3*sizeof(int),*j=pBuffer+4*sizeof(int), *n=pBuffer+2*sizeof(int);
    Pessoa *pessoa=pBuffer+5*sizeof(int);
	char *aux=(char*)pessoa+*n;

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
        }
        strcpy((pessoa+*i+1)->nome,aux);
    (pessoa+*i+1)->identidade = *tmp;
    }
}


//------------------------------Métodos
=======
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


//------------------------------M�todos
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
void incluirPessoa()
{
    int /**p=pBuffer+0, */*q=pBuffer+sizeof(int), *r=pBuffer+2*sizeof(int);
    Pessoa *pessoa=pBuffer+sizeof(int)*5;
    pessoa=pessoa+*r;

<<<<<<< HEAD
	printf("Digite o nome: ");
	getchar();
=======
	printf("Digite o nome: ");
	getchar();
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
    fgets(pessoa->nome, 30, stdin);
	pessoa->identidade=(int)*pessoa->nome;
	//printf("Digite a identidade: ");
	//scanf("%d", &pessoa->identidade);

    *r=*r+1;
    *q=(*r+1)*sizeof(Pessoa)+5*sizeof(int);
    pBuffer=realloc(pBuffer,*q);
}

<<<<<<< HEAD

=======
/*
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
void apagarPessoa()
{
	int *aux=pBuffer+0, *i=pBuffer+3*sizeof(int), *r=pBuffer+2*sizeof(int);
	Pessoa *pessoa=pBuffer+5;
	char *alguem=(char*)pessoa+*r;
	printf("Digite o nome: ");
	getchar();
	fgets(alguem, 30, stdin);
	for (*i=0; *i<=*r; (*i)++)
	{
		if (*i == *r)
			printf("Não há ninguém com este nome.\n");
		else
			if (strcmp(alguem,(pessoa+*i)->nome) == 0)	//Aparentemente o problema está neste strcmp
			{
				pessoa->identidade=999;
				InsertionSort();	//inserir aquele algoritmo que é mais rápido para chamadas já quase ordenadas
				*r=*r-1;
				return;
			}
	}
}
/*
void buscarPessoa()
{

}
*/
void listarPessoa()
{
	int *i=pBuffer+3*sizeof(int), *r=pBuffer+2*sizeof(int);
	Pessoa *pessoa;
<<<<<<< HEAD
	for (*i=0; *i<=*r; (*i)++)
=======
	for (*i=0; *i<=*r; *i=*i+1)
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
	{
		pessoa=pBuffer+5*sizeof(int);
		if (*i == *r)
			break;
		else
		{
			pessoa=pessoa+*i;
			printf("%s", pessoa->nome);
<<<<<<< HEAD
			printf("Código de identificação: %d\n", pessoa->identidade);
=======
			printf("C�digo de identifica��o: %d\n", pessoa->identidade);
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
		}
	}
}

void Sair()
{
	free(pBuffer);
<<<<<<< HEAD
	printf("\nObrigado! Um dia esta agenda irá salvar todos os nomes em um arquivo, portanto fique atento. Volte sempre!");
=======
	printf("\nObrigado! Um dia esta agenda ir� salvar todos os nomes em um arquivo. Volte sempre!");
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
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
<<<<<<< HEAD
	printf("\n\nDigite sua escolha...\n1 para incluir...\n2 para excluir...\n3 para buscar...\n4 para listar...\n5 para sair...\nCaso escolha outro valor, esta mensagem se repetirá.");
=======
	printf("\n\nDigite sua escolha...\n1 para incluir...\n2 para excluir...\n3 para buscar...\n4 para listar...\n5 para sair...\nCaso escolha outro valor, esta mensagem se repetir�.");
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
	Inicio: Organizar(&p,&q,&r,&s,&t);
	printf("\n\nDigite: ");
	scanf("%d", s);

	switch (*s)
	{
		case 1:
<<<<<<< HEAD
			incluirPessoa();
			Organizar(&p,&q,&r,&s,&t);
			if (*r > 1)
				InsertionSort();	//inserir aquele algoritmo que é mais rápido para chamadas já quase ordenadas
			else
				InsertionSort();
			printf("Pessoa incluída! Use o 'Listar' para ver seu código de identificação.\n");
			goto Inicio;
			printf("");
		break;
=======
			incluirPessoa();
			InsertionSort();
			printf("Pessoa inclu�da! Use o 'Listar' para ver seu c�digo de identifica��o.\n");
			goto Inicio;
			printf("");
		break;/*
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
		case 2:
			apagarPessoa();
    		*q=(*r+1)*sizeof(Pessoa)+5*sizeof(int);
    		pBuffer=realloc(pBuffer,*q);
			printf("Excluído com sucesso!\n");
			goto Inicio;
			printf("");
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
<<<<<<< HEAD
			printf("");
=======
			printf("");
>>>>>>> bba90387b1fb3c86821e379aa8cb1f2309a4f1b4
        break;
	}
}
