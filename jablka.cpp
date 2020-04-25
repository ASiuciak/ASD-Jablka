#include <iostream>

#define BILLION 1000000000

int main() {
    int n, d;
    scanf("%d", &n);
    scanf("%d", &d);
    int zasieg_x[n + 1];
    int lsyn[n + 1];
    int psyn[n + 1];
    int wszystkie[n + 1];
    int zasieg_xplus1[n + 1];
    zasieg_x[0] = 1;
    lsyn[0] = -1;
    psyn[0] = -1;
    wszystkie[0] = 1;
    zasieg_xplus1[0] = 1;

    for (int i = 1; i <= n; i ++) {
        int s1, s2;
        scanf("%d", &s1);
        scanf("%d", &s2);
        wszystkie[i] = (wszystkie[s1] + wszystkie[s2] + 1) % BILLION;
        zasieg_x[i] = 1;
        lsyn[i] = s1;
        psyn[i] = s2;
    }
    for (int x = 1; x < d; x ++) {
        for (int i = 1; i <= n; i ++){
            zasieg_xplus1[i] = (zasieg_x[lsyn[i]] + zasieg_x[psyn[i]] + 1) % BILLION;
        }
        for (int i = 1; i <= n; i ++){
            zasieg_x[i] = zasieg_xplus1[i];
        }
    }
    int wynik = (wszystkie[n] - zasieg_x[n]) % BILLION;
    if (wynik < 0) wynik += BILLION;
    printf("%d\n", wynik);
    return 0;
}
