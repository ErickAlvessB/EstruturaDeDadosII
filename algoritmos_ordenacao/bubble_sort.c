#include <stdio.h>
#include <stdlib.h>

void imprimir_array(int arr[], int tamanho);
void bubble_sort(int vetor[], int tamanho);
int *lerVetor(int *tamanho);

int main()
{
    int tamanho;

    int *vetor = lerVetor(&tamanho);

    bubble_sort(vetor, tamanho);

    imprimir_array(vetor, tamanho);

    return 0;
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

void bubble_sort(int vetor[], int tamanho)
{
    int i, j;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - 1 - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}