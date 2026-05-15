#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b);
void heapify(int vetor[], int tamanho, int raiz);
void heapSort(int vetor[], int tamanho);
void imprimir_array(int vetor[], int tamanho);
int *lerVetor(int *tamanho);


int main()
{
    int tamanho;
    int *vetor = lerVetor(&tamanho);

    heapSort(vetor, tamanho);

    imprimir_array(vetor, tamanho);

    free(vetor);

    return 0;
}


void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int vetor[], int tamanho, int raiz)
{
    int maior = raiz;

    int esquerda = 2 * raiz + 1;
    int direita = 2 * raiz + 2;

    if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
    {
        maior = esquerda;
    }

    if (direita < tamanho && vetor[direita] > vetor[maior])
    {
        maior = direita;
    }

    if (maior != raiz)
    {
        trocar(&vetor[raiz], &vetor[maior]);

        heapify(vetor, tamanho, maior);
    }
}

void heapSort(int vetor[], int tamanho)
{
    for (int i = tamanho / 2 - 1; i >= 0; i--)
    {
        heapify(vetor, tamanho, i);
    }

    for (int i = tamanho - 1; i > 0; i--)
    {
        trocar(&vetor[0], &vetor[i]);

        heapify(vetor, i, 0);
    }
}

void imprimir_array(int vetor[], int tamanho)
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