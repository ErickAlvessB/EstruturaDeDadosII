#include <stdio.h>
#include <stdlib.h>

int *lerVetor(int *tamanho);
void imprimir(int vetor[], int tamanho);
void merge(int vetor[], int inicio, int meio, int fim);
void mergeSort(int vetor[], int inicio, int fim);

int main()
{
    int tamanho;
    int *vetor = lerVetor(&tamanho);

    mergeSort(vetor, 0, tamanho - 1);

    imprimir(vetor, tamanho);

    free(vetor);
    return 0;
}

void merge(int vetor[], int inicio, int meio, int fim)
{
    int i, j, k;

    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int esquerda[tamanhoEsquerda];
    int direita[tamanhoDireita];

    for (i = 0; i < tamanhoEsquerda; i++)
    {
        esquerda[i] = vetor[inicio + i];
    }

    for (j = 0; j < tamanhoDireita; j++)
    {
        direita[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (esquerda[i] <= direita[j])
        {
            vetor[k] = esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = direita[j];
            j++;
        }

        k++;
    }

    while (i < tamanhoEsquerda)
    {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita)
    {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
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
