#include <stdio.h>
#include <math.h>

int main()
{
    int h = 100,
        n = 10;

    int i, j = 0;
    float s = 0;//1.0/h;

    for(i = n+1; i >= 1; i--) {
        s += i*pow((h-1.0)/h, i-1)*pow((1.0/h), i<=n);
        //printf("%f %d %f %f %d\n ", s, i, pow((h-1.0)/h, i-1), pow((1.0/h), j), j);
    }

    printf("%.2f\n", s);

    return 0;
}
