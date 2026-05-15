#include <stdio.h>
#include <stdlib.h>

void imprimir_array(int arr[], int tamanho);
void insertion_sort(int arr[], int tamanho);
int *lerVetor(int *tamanho);

int main()
{
    int tamanho;

    int *vetor = lerVetor(&tamanho);

    insertion_sort(vetor, tamanho);

    imprimir_array(vetor, tamanho);

    return 0;
}

void imprimir_array(int arr[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void insertion_sort(int arr[], int tamanho)
{
    int i, j, temp;

    for (i = 1; i < tamanho; i++)
    {
        j = i;

        while (j > 0 && arr[j] < arr[j - 1])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            j--;
        }
    }
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