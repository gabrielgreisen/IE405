#include <iostream>
#include <limits>

int main() {
    std::cout << "Type in a simple expression: ";
    double v1, v2;
    char op;

    if (!(std::cin >> v1 >> op >> v2)) {
        std::cerr << "Error: failed to read expression.\n";
        return 1;
    }

    switch (op) {
        case '+':
            std::cout << (v1 + v2) << "\n";
            break;
        case '-':
            std::cout << (v1 - v2) << "\n";
            break;
        case '*':
            std::cout << (v1 * v2) << "\n";
            break;
        case '/':
            if (v2 == 0.0) {
                std::cerr << "Error: division by zero.\n";
                return 1;
            }
            std::cout << (v1 / v2) << "\n";
            break;
        case '%': {
            // Assume both inputs are integers for modulus, as stated.
            long long a = static_cast<long long>(v1);
            long long b = static_cast<long long>(v2);
            if (b == 0) {
                std::cerr << "Error: division by zero in modulus.\n";
                return 1;
            }
            std::cout << (a % b) << "\n";
            break;
        }
        default:
            std::cerr << "Error: unknown operator '" << op << "'. Use +, -, *, /, or %.\n";
            return 1;
    }

    return 0;
}
