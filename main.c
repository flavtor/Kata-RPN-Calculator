#include "rpn_calculator.h"

int main() {
    const char* expression = "3 4 + 2 * 7 -";
    evaluate_rpn(expression);
    return 0;
}
