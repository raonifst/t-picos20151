#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define NR 10000
#define H 10
#define L 0

//range [M, N[
double randMToN(double M, double N)
{
    return M + (rand() / ( RAND_MAX / (N-M) ) ) ;
}

/*
 * Descricao: utiliza o gerador de números pseudo-aleatórios disponivível na 'stdlib'
 *            e preenche o vetor de entrada com 'n' números gerados, assumindo uma
 *            distribuicao uniforme.
 * Entrada: um vetor de números inteiros 'v' com memória previamente reservada
 *          um número inteiro 'n' indicando o tamanho de v
 * Saida: o vetor 'v' com os números pseudo-aleatórios
 * */
void vetorAleatorio(int v[], int n)
{
    int i, j;
    /*inicializacao do gerador com o 	*/

    for (i=0; i<n; i++)
    {
        /* faz com que os números gerados fiquem no intervalo [0, 5*n[
         *  explique para você mesmo o porquê*/
        //v[i] = rand() % (1*n);
        v[i] = randMToN(L, H);
        //printf("%d ", v[i]);
    }
    //printf("\n");
}

int busca(int v[], int inicio, int n, int chave)
{
    int i;
    for(i = inicio; i < n && v[i] != chave; i++) ;

    return i - inicio;
}

int rep(int v[], int n)
{
    int i, r = 0;
    for(i = 0; i < n-1; i++)
        r = r + busca(v, i + 1, n, v[i]) + 1;
    return r;
}

int main()
{
    int v[MAX], n = MAX, i;
    float m = 0, b;
    int chave;

    for(i = 0; i < NR; i++) {
        vetorAleatorio(v, n);
        m = m + rep(v, n);
    }
    printf("%f", m/(NR));

    return 0;
}



