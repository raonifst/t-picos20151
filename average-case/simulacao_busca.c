/*
* Simulação - Algoritimo de Busca
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define NR 1000000
#define H 100
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
int busca(int v[], int n, int chave)
{
    int i;
    for(i = 0; i < n && v[i] != chave; i++) ;

    return i;
}

int init(int n)
{
    int i;
    int *p = malloc(sizeof(int)*n);
    for(i = 0; i < n; i++) p[i] = 0;

    return p;

}

int main()
{
    int v[MAX], n = MAX, i, *h;
    float m = 0;
    int b, chave;

    h = init(n+1);
    srand(time(NULL));
    for(i =0; i < NR; i++) {
        vetorAleatorio(v, n);
        chave = randMToN(L, H);
        b = busca(v, n, chave);
        h[b]++;

    }

    for(i = 0; i <= MAX; i++) {
        printf("%d: %d %.4f\n ", i, h[i], (h[i]+0.0)/NR);
        m = m + (h[i]+0.0)/NR * (i+1);
    }

    printf("%.2f\n", m);
    return 0;
}



