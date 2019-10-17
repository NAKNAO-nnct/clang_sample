#include <stdio.h>
#include <stdlib.h>

typedef struct
{              /* 分数の構造体 */
    int numer; /* 分子 */
    int denom; /* 分母 */
} FRACTION;

typedef struct
{                  /* 複素数の構造体 */
    FRACTION real; /* 実部 */
    FRACTION imag; /* 虚部 */
} FCOMP;

/* 関数を追加する場合はここに */
// sub-1
FCOMP sub(FCOMP a)
{
    FCOMP result;
    result.real.numer = a.real.numer - a.real.denom;
    result.real.denom = a.real.denom;
    result.imag.numer = a.imag.numer;
    result.imag.denom = a.imag.denom;
    return result;
}

// multiplication
FCOMP mult(FCOMP a, FCOMP b)
{
    FCOMP result;
    int X = a.real.denom * a.imag.denom * b.real.denom * b.imag.denom;
    int bc = a.real.numer * a.imag.denom;
    int eh = b.real.denom * b.imag.numer;
    int fg = b.real.numer * b.imag.denom;
    int ad = a.real.denom * a.imag.numer;
    result.real.numer = bc * fg + ad * eh;
    result.real.denom = X;
    result.imag.numer = bc * eh + ad * fg;
    result.imag.denom = X;
    return result;
}

// division
FCOMP divi(FCOMP a, FCOMP b)
{
    FCOMP result;
    int BD = a.real.denom * a.imag.denom;
    result.real.numer = b.real.numer * BD;
    int X = a.real.numer * a.imag.denom - a.real.denom * a.imag.numer;
    result.real.denom = X * b.real.denom;
    result.imag.numer = b.imag.numer * BD;
    result.imag.denom = X * b.real.denom;
    printf("%d\n", b.imag.numer);
    return result;
}

FCOMP fcomp_comp(FCOMP x)
{
    /* ここを作る  */
    FCOMP temp_A1, temp_A2, temp_A3, temp_A4;
    temp_A1 = mult(x, x);
    temp_A2 = sub(temp_A1);
    temp_A3 = sub(temp_A1);
    temp_A3.imag.numer = -temp_A3.imag.numer;
    temp_A4 = divi(temp_A1, temp_A3);
    return temp_A4;
}

int main(int argc, char **argv)
{
    FCOMP a, b;

    a.real.numer = atoi(argv[1]);
    a.real.denom = atoi(argv[2]);
    a.imag.numer = atoi(argv[3]);
    a.imag.denom = atoi(argv[4]);

    b = fcomp_comp(a);
    printf("(%d/%d)+j(%d/%d)\n", b.real.numer, b.real.denom, b.imag.numer, b.imag.denom);
}
