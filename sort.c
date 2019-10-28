#include <stdio.h>
#include <stdlib.h>

// #define LENGTH 10

int main(int argc, char **argv)
{
    int i;
    int len = argc - 1;
    // int x[LENGTH];
    int *x = (int *)malloc((argc) * sizeof(int));

    for (i = 0; i < len; i++)
    {
        x[i] = atoi(argv[i + 1]);
    }

    int j;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (x[j] * x[j] > x[i] * x[i])
            {
                int buf = x[j];
                x[j] = x[i];
                x[i] = buf;
            }
        }
    }

    // i=0が大きい順
    // i=lenが小さい順
    for (i = len; i > 0; i--)
    {
        printf("%d\n", x[i]);
    }
    return 0;
}
