#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int tamanho);
void imprimir_array(int arr[], int tamanho);
int *lerVetor(int *tamanho);

int main()
{
    int tamanho;
    int *vetor = lerVetor(&tamanho);

    selection_sort(vetor, tamanho);
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

void selection_sort(int arr[], int tamanho)
{
    int i, j;

    for (i = 0; i < tamanho - 1; i++)
    {
        int pos_menor_elemento = i;
        int menor_elemento_da_pos = arr[i];

        for (j = i + 1; j <= tamanho - 1; j++)
        {

            if (arr[j] < menor_elemento_da_pos)
            {
                pos_menor_elemento = j;
                menor_elemento_da_pos = arr[j];
            }
        }

        int temp = arr[i];
        arr[i] = menor_elemento_da_pos;
        arr[pos_menor_elemento] = temp;
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