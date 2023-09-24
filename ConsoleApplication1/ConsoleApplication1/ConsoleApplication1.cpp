#include <iostream>
#include <set>

class DigitSet {
private:
    std::set<int> digits;

public:
    void addDigit(int digit) {
        digits.insert(digit);
    }

    void displayDigits() {
        std::cout << "Цифри у множині: ";
        for (int digit : digits) {
            std::cout << digit << " ";
        }
        std::cout << std::endl;
    }

    int findMaxDigit() {
        if (digits.empty()) {
            std::cerr << "Множина цифр порожня." << std::endl;
            return -1;
        }

        int maxDigit = *digits.rbegin();
        return maxDigit;
    }

    int findSumOfDigits() {
        int sum = 0;
        for (int digit : digits) {
            sum += digit;
        }
        return sum;
    }
};

int main() {
    DigitSet digitSet;

    int digit;
    char addAnother;

    do {
        std::cout << "Введіть цифру: ";
        std::cin >> digit;
        digitSet.addDigit(digit);

        std::cout << "Додати ще цифру? (y/n): ";
        std::cin >> addAnother;
    } while (addAnother == 'y' || addAnother == 'Y');

    digitSet.displayDigits();
    int maxDigit = digitSet.findMaxDigit();
    if (maxDigit != -1) {
        std::cout << "Найбільша цифра: " << maxDigit << std::endl;
    }

    int sumOfDigits = digitSet.findSumOfDigits();
    std::cout << "Сума цифр: " << sumOfDigits << std::endl;

    return 0;
}
