#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/**	Índices do buffer virtual:
 * pBuffer+0 = variável de auxílio
 * pBuffer+sizeof(int) = segunda variável de auxílio
 * pBuffer+2*sizeof(int) = tamanho do buffer
 * pBuffer+3*sizeof(int) = quantidade de nomes cadastrados na agenda
 * pBuffer+4*sizeof(int) = variável de índice para laços de repetição
 * pBuffer+5*sizeof(int) = segunda variável de índice para laços de repetição
 * pBuffer+6*sizeof(int) = variável auxiliar de índice para laços de repetição
 * pBuffer+7*sizeof(int) = começo dos dados da agenda
 **/

//------------------------------Variáveis e Tipos
typedef struct P
{
	char nome[30];
	int identidade;
}Pessoa;

void *pBuffer;

//------------------------------Funções
void Organizar(int **p, int **q, int **r, int **s, int **t, int **u, int **v)
{
	*p=pBuffer+0;
	*q=pBuffer+sizeof(int);
	*r=pBuffer+2*sizeof(int);
	*s=pBuffer+3*sizeof(int);
	*t=pBuffer+4*sizeof(int);
	*u=pBuffer+5*sizeof(int);
	*v=pBuffer+6*sizeof(int);
}

void InsertionSort()
{
    int *tmp=pBuffer+0,*i=pBuffer+4*sizeof(int),*j=pBuffer+5*sizeof(int), *n=pBuffer+3*sizeof(int);
    Pessoa *pessoa=pBuffer+7*sizeof(int);
	Pessoa *aux=pessoa+*n;

    for (*j=1; *j<*n; *j=*j+1)
    {
        *i=*j-1;
        strcpy(aux->nome,(pessoa+*j)->nome);
        *tmp=(pessoa+*j)->identidade;
        while ((*i>=0) && (*tmp < (pessoa+*i)->identidade))
        {
            strcpy((pessoa+*i+1)->nome,(pessoa+*i)->nome);
            (pessoa+*i+1)->identidade = (pessoa+*i)->identidade;
            *i=*i-1;
        }
        strcpy((pessoa+*i+1)->nome,aux->nome);
    	(pessoa+*i+1)->identidade = *tmp;
    }
}

void SelectSort ()
{
   	int *min=pBuffer+sizeof(int), *tmp=pBuffer+0, *i=pBuffer+4*sizeof(int), *j=pBuffer+5*sizeof(int), *min_id=pBuffer+6*sizeof(int), *n=pBuffer+3*sizeof(int);
   	Pessoa *pessoa=pBuffer+7*sizeof(int);
	Pessoa *aux=pessoa+*n;
	
	for (*i=0; *i<*n-1; *i=*i+1)
	{
		*min_id = *i;
    	*min = (pessoa+*i)->identidade;
    	for (*j=*i+1; *j<*n; *j=*j+1) 
			if ((pessoa+*j)->identidade < *min)
			{
				*min = (pessoa+*j)->identidade; 
				*min_id = *j; 
			}
		strcpy(aux->nome,(pessoa+*i)->nome);
    	*tmp = (pessoa+*i)->identidade;
		strcpy((pessoa+*i)->nome,(pessoa+*min_id)->nome);
    	(pessoa+*i)->identidade = (pessoa+*min_id)->identidade; 
		strcpy((pessoa+*min_id)->nome,aux->nome);
    	(pessoa+*min_id)->identidade = *tmp; 
	}
}

void BubbleSort ()
{
	int *tmp=pBuffer+0, *i=pBuffer+4*sizeof(int), *j=pBuffer+5*sizeof(int), *n=pBuffer+3*sizeof(int);
	Pessoa *pessoa=pBuffer+7*sizeof(int);
	Pessoa *aux=pessoa+*n;
	for (*i=0; *i<*n-1; *i=*i+1)
	{
		for (*j=0; *j<*n-*i-1; *j=*j+1)
		{
			if ((pessoa+*j)->identidade > (pessoa+*j+1)->identidade)
			{
				strcpy(aux->nome,(pessoa+*j)->nome);
				*tmp = (pessoa+*j)->identidade;
				strcpy((pessoa+*j)->nome,(pessoa+*j+1)->nome);
				(pessoa+*j)->identidade = (pessoa+*j+1)->identidade;
				strcpy((pessoa+*j+1)->nome,aux->nome);
				(pessoa+*j+1)->identidade = *tmp; 
			}
		}
	}
}

void QuickSort (int *left,int *right)
{	//Passar como parâmetro (&pessoa->identidade,&(pessoa+*r-1)->identidade)
	int *mid=pBuffer+0,*tmp=pBuffer+sizeof(int),*i=pBuffer+4*sizeof(int),*j=pBuffer+5*sizeof(int);
	Pessoa *pessoa=pBuffer+7*sizeof(int);
	Pessoa *aux=pessoa+*right;
	*i = *left;
	*j = *right;
	*mid = (pessoa+((*left + *right)/2))->identidade;
	do
	{
		while((pessoa+*i)->identidade < *mid)
			*i=*i+1;
       	while(*mid < (pessoa+*j)->identidade)
           	*j=*j-1;
       	if (i <= j)
		{
			strcpy(aux->nome,(pessoa+*i)->nome);
           	*tmp = (pessoa+*i)->identidade;
			strcpy((pessoa+*i)->nome, (pessoa+*j)->nome);
           	(pessoa+*i)->identidade = (pessoa+*j)->identidade;
			strcpy((pessoa+*i)->nome,aux->nome);
           	(pessoa+*j)->identidade = *tmp;
           	*i=*i+1;
           	*j=*j-1;
       	}
	}while (*i <= *j);
	if (*left < *j)
		Quicksort(left,j);
	if (*i < *right)
		Quicksort(i,right);
}
/*
void Merge(int vetor[], int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim)
	{
        if(vetor[com1] < vetor[com2])
		{
            vetAux[comAux] = vetor[com1];
            com1++;
        }
		else
		{
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio)  //Caso ainda haja elementos na primeira metade
	{
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim)   //Caso ainda haja elementos na segunda metade
	{
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++)    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    
    free(vetAux);
}

void MergeSort(int vetor[], int comeco, int fim)
{
    if (comeco < fim)
	{
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
*/
//------------------------------Métodos
void incluirPessoa()
{
    int *q=pBuffer+2*sizeof(int), *r=pBuffer+3*sizeof(int);
    Pessoa *pessoa=pBuffer+7*sizeof(int);
    pessoa=pessoa+*r;

	printf("Digite o nome: ");
	getchar();
    fgets(pessoa->nome, 30, stdin);
	pessoa->identidade=(int)*pessoa->nome;

    *r=*r+1;
    *q=(*r+1)*sizeof(Pessoa)+7*sizeof(int);
    pBuffer=realloc(pBuffer,*q);
}

void apagarPessoa()
{
	int *i=pBuffer+4*sizeof(int), *r=pBuffer+3*sizeof(int);
	Pessoa *pessoa=pBuffer+7;
	Pessoa *alguem=pessoa+*r;
	printf("Digite o nome: ");
	getchar();
	fgets(alguem->nome, 30, stdin);
	for (*i=0; *i<=*r; (*i)++)
	{
		pessoa=pBuffer+7*sizeof(int);
		if (*i == *r)
			printf("Não há ninguém com este nome.\n");
		else
        {
			pessoa=pessoa+*i;
			if (strcmp(alguem->nome,pessoa->nome) == 0)
			{
				pessoa->identidade=999;
				BubbleSort();
				printf("Excluído com sucesso!\n");
				*r=*r-1;
				return;
			}
        }
	}
}

void buscarPessoa()
{
	int *i=pBuffer+4*sizeof(int), *r=pBuffer+3*sizeof(int);
	Pessoa *pessoa=pBuffer+7*sizeof(int);
	Pessoa *alguem=pessoa+*r;
	printf("Digite o nome: ");
	getchar();
	fgets(alguem->nome, 30, stdin);
	for (*i=0; *i<=*r; (*i)++)
	{
		pessoa=pBuffer+7*sizeof(int);
		if (*i == *r)
			printf("Não há ninguém com este nome.\n");
		else
        {
            pessoa=pessoa+*i;
			if (strcmp(alguem->nome,pessoa->nome) == 0)
			{
                printf("%s", pessoa->nome);
                printf("Código de identificação: %d\n", pessoa->identidade);
				return;
			}
        }
	}
}

void listarPessoa()
{
	int *i=pBuffer+4*sizeof(int), *r=pBuffer+3*sizeof(int);
	Pessoa *pessoa;
	for (*i=0; *i<=*r; (*i)++)
	{
		pessoa=pBuffer+7*sizeof(int);
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
	printf("\nObrigado! Um dia esta agenda irá salvar todos os nomes em um arquivo, portanto fique atento. Volte sempre!");
}

//------------------------------Main
void main()
{
	printf("Bem-vindo a Agenda de KDOXG. \nCarregando...");
	int *p, *q, *r, *s, *t, *u, *v;
    pBuffer=malloc(sizeof(int)*7+sizeof(Pessoa));
	Pessoa *pessoa = pBuffer+7*sizeof(int);
	Organizar(&p,&u,&q,&r,&s,&t,&v);
	*p=0;
	*q=0;
	*r=0;
	*s=0;

	printf("\n------------------------------");
	printf("\n\nDigite sua escolha...\n1 para incluir...\n2 para excluir...\n3 para buscar...\n4 para listar...\n5 para sair...\nCaso escolha outro valor, nada acontecerá");
	Inicio: Organizar(&p,&u,&q,&r,&s,&t,&v);
	printf("\n\nDigite: ");
	scanf("%d", s);

	switch (*s)
	{
		case 1:
			incluirPessoa();
			Organizar(&p,&u,&q,&r,&s,&t,&v);
			if (*r > 1)
			{
				pessoa=pBuffer+7*sizeof(int);
				QuickSort(&pessoa->identidade,&(pessoa+*r-1)->identidade);
			}
			printf("Pessoa incluída!\n");
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 2:
			apagarPessoa();
    		*q=(*r+1)*sizeof(Pessoa)+7*sizeof(int);
    		pBuffer=realloc(pBuffer,*q);
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 3:
			buscarPessoa();
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 4:
			listarPessoa();
			printf("Total de pessoas: %d", *r);
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 5:
			Sair();
		break;
		default:
			goto Inicio;
			pBuffer=pBuffer;
        break;
	}
}
