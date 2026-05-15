#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b);
int particao(int vetor[], int inicio, int fim);
void quick_sort(int vetor[], int inicio, int fim);
void imprimir(int vetor[], int tamanho);
int *lerVetor(int *tamanho);

int main()
{
    int tamanho;
    int *vetor = lerVetor(&tamanho);

    quick_sort(vetor, 0, tamanho - 1);

    imprimir(vetor, tamanho);

    return 0;
}

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int vetor[], int inicio, int fim)
{
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (vetor[j] <= pivo)
        {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }

    trocar(&vetor[i + 1], &vetor[fim]);

    return i + 1;
}

void quick_sort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int posicaoPivo = particao(vetor, inicio, fim);

        quick_sort(vetor, inicio, posicaoPivo - 1);
        quick_sort(vetor, posicaoPivo + 1, fim);
    }
}

void imprimir(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
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