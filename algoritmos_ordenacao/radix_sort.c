#include <stdio.h>
#include <stdlib.h>

int *lerVetor(int *tamanho);
int maiorElemento(int vetor[], int tamanho);
void countingSort(int vetor[], int tamanho, int exp);
void radixSort(int vetor[], int tamanho);
void imprimir_array(int vetor[], int tamanho);
int *lerVetor(int *tamanho);

int main()
{
    int tamanho;
    int *vetor = lerVetor(&tamanho);

    radixSort(vetor, tamanho);

    imprimir_array(vetor, tamanho);

    return 0;
}


int maiorElemento(int vetor[], int tamanho)
{
    int maior = vetor[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }

    return maior;
}

void countingSort(int vetor[], int tamanho, int exp)
{
    int saida[tamanho];
    int contagem[10] = {0};

    for (int i = 0; i < tamanho; i++)
    {
        int indice = (vetor[i] / exp) % 10;
        contagem[indice]++;
    }

    for (int i = 1; i < 10; i++)
    {
        contagem[i] += contagem[i - 1];
    }

    for (int i = tamanho - 1; i >= 0; i--)
    {
        int indice = (vetor[i] / exp) % 10;

        saida[contagem[indice] - 1] = vetor[i];

        contagem[indice]--;
    }

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = saida[i];
    }
}

void radixSort(int vetor[], int tamanho)
{
    int maior = maiorElemento(vetor, tamanho);

    for (int exp = 1; maior / exp > 0; exp *= 10)
    {
        countingSort(vetor, tamanho, exp);
    }
}


void imprimir_array(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int *lerVetor(int *tamanho)
{
    printf("Quantos elementos deseja inserir? ");
    scanf("%d", tamanho);

    int *vetor = (int *)malloc((*tamanho) * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }

    for (int i = 0; i < *tamanho; i++)
    {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    return vetor;
}