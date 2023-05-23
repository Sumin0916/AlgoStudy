#include <stdio.h>

int main()
{
    int a, b, c;
    int e, f, g;

    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &e, &f, &g);
    printf("%d %d %d", e-c, f/b, g-a);

    return 0;
}