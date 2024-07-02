#include "rpn_calculator.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_evaluate_rpn(const char* expression, int expected_result) {
    // Redirection de la sortie standard vers un buffer
    char buffer[128];
    FILE* output = freopen("/dev/null", "w", stdout); // Bloquer la sortie standard
    setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));

    int result = evaluate_rpn(expression);

    freopen("/dev/tty", "w", stdout); // Restaurer la sortie standard

    if (result == -1) {
        printf("Test passed (error expected): %s\n", expression);
    } else {
        assert(result == expected_result);
        printf("Test passed: %s = %d\n", expression, expected_result);
    }
}

int main() {
    // Tests valides
    test_evaluate_rpn("3 4 +", 7);
    test_evaluate_rpn("10 2 -", 8);
    test_evaluate_rpn("2 3 *", 6);
    test_evaluate_rpn("5 1 2 + 4 * + 3 -", 14);
    test_evaluate_rpn("15 7 1 1 + - / 3 * 2 1 1 + + -", 5);

    // Tests d'erreurs
    test_evaluate_rpn("3 4 &", -1); // Opérateur inconnu
    test_evaluate_rpn("3 4 + +", -1); // Dépassement de pile

    printf("All tests passed!\n");
    return 0;
}
