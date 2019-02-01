#include <stdio.h>

int main(int argc, char * argv[]) {
    int test_case;
    int dice;
    int i, j;
    double expected;
    scanf("%d", &test_case);
    while (test_case--) {
        scanf("%d", &dice);
        expected = 1.0;
        for (i = 1; i < dice; ++i) {
            expected += (double) dice / (double) i;
        }
        printf("%.2f\n", expected);
    }
    return 0;
}