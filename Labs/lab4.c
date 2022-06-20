# include <stdio.h>
# include <conio.h> // getch ()
# include <math.h>

double f (double x)
{

    if (
            0 <= x
            &&
            x <= 1
            )
        return sqrt(x+1)-sqrt(x)-0.5;

    if (
            1 < x
            &&
            x <= 2
            )
        return exp(-x-1/x);
}


double I (long n)
{
    double
            S, // значение интеграла
    x, // переменная функции
    h; // шаг изменения аргумента

    long i; // номер текущего шага

    // OOФ f(x) [0..2]
    // 0 + 2 = 2
    // шаг изменения аргумента
    h = 2.0 / n;

    //printf ("h = %lf\n", h);

    // левая граница ООФ
    x = 0.0;
    i = 0L;
    S = 0.0;
    do
    {
        //printf ("%7.5lf    %7.5lf\n", x, f (x));
        S += h * f (x);
        x += h;
        i ++;
    }
    while (i <= n);

    return S;
}


int main ()
{
    long
    n; // столько шагов

    double
            delta2n, // величина
            e,
            I2n,
            In; // значение интеграла


    printf("Enter e: ");
    scanf("%lf", &e);


    // задайте шаг: 0.000001 и получите контрольное значение
    n=1;

    In = I (n);

    while (1)
    {
        n = 2 * n;
        I2n = I (n);
        delta2n = fabs (I2n - In) / 3.0;

        if (delta2n < e)
            break;

        In = I2n;
    }

    printf ("I = %7.5lf\n", I2n);


    getch ();
    return 0;
}
