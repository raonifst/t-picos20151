/*
Questões:
1) Entenda e comente o código abaixo.
2) Teste o programa para diferentes valores de N (linha 8).
*/
#include <stdio.h>

#define N 6

int eh_valido(int x, int y, int n, int tabuleiro[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && tabuleiro[x][y] == 0);
}

int passeio(int tabuleiro[N][N], int n, int x, int y, int v)
{
    int i, xn, yn;
    int xDes[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yDes[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    if(!ha_espaco(tabuleiro, n))
        return 1;

    for (i = 0; i < 8; i++)
    {
        xn = x + xDes[i];
        yn = y + yDes[i];

        if (eh_valido(xn, yn, n, tabuleiro))
        {
            tabuleiro[xn][yn] = v;

            if (passeio(tabuleiro, n, xn, yn, v+1) == 1)
                return 1;
            else
                tabuleiro[xn][yn] = 0;// backtracking
        }
    }

    return 0;

}


int ha_espaco(int tabuleiro[N][N], int n)
{
    int i, j, s = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n ; j++)
             if(tabuleiro[i][j] > 0) s += 1;
    return (s < (n*n));
}

void iniciar(int tabuleiro[N][N], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            tabuleiro[i][j] = 0;
}

void mostrar(int tabuleiro[N][N], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%2d ", tabuleiro[i][j]);
        printf("\n");
    }
}

int main()
{
    int tabuleiro[N][N], x, y, v = 1;

    iniciar(tabuleiro, N);

    x = 0;
    y = 0;
    tabuleiro[x][y] = v;

    if(passeio(tabuleiro, N, x, y, v+1) == 1)
        mostrar(tabuleiro, N);
    else
        printf("Nao\n");

    return 0;
}
