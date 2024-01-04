#include <stdio.h>
#include <math.h>

#define A 0 // 積分区間の先頭
#define B 1 // 積分区間の最後
#define N_LIMIT 100000 // 分割数の上限

double func1(double x) {
    // 積分区間は[0,1]
    return 4.0 * sqrt(1 - x * x);
}

double func2 (double x) {
    // 積分区間は[0,1]
    return 4.0 / (1.0 + x * x);
}

double gauss (double x) {
    // 積分区間は実数全体、最後に積分値を2乗して円周率を得る
    return exp(-x * x);
}

void simpson ( double (*f)(double), const double a, const double b, const int n, double *pre_err ) {
    double h = (b - a) / n;
    double r = (*f)(a) + (*f)(b);
    for (int i = 1; i < n; i++) {
        r += ((i % 2 == 0) ? 2.0 : 4.0) * (*f)(a + i * h);
    }
    // この時点で、r = f(a) + 4f(a+h) + 2f(a+2h) + 4f(a+3h) + ... + 2f(a+(n-1)h) + f(b)
    r *= h / 3.0;

    if (f == gauss) r *= r;

    printf("n = %lld, r = %1.10f, err = %1.10f, rate = %1.04f\n", n, r, fabs(r - M_PI),
           ((*pre_err == 1.0) ? 1.0 : (fabs(r - M_PI) / *pre_err)));
    *pre_err = fabs(r - M_PI);
}

int main(void) {
    double pre_err = 1.0;
    for (int N = 2; N <= N_LIMIT; N *= 2) {
        double a = A, b = B;
        int n = N;

        simpson(func2, a, b, n, &pre_err);
    }
}
