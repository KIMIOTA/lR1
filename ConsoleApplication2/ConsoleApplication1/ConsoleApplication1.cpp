#include <iostream>
#include <cmath>

class LineEquation {
private:
    double A, B, C;

public:
    // Конструктор класу для ініціалізації коефіцієнтів рівняння
    LineEquation(double a, double b, double c) : A(a), B(b), C(c) {}

    // Індексатор для доступу до коефіцієнтів
    double& operator[](int index) {
        switch (index) {
        case 0: return A;
        case 1: return B;
        case 2: return C;
        default:
            throw std::out_of_range("Індекс виходить за межі діапазону.");
        }
    }

    // Метод для виведення рівняння прямої
    void display() {
        std::cout << A << "x + " << B << "y + " << C << " = 0" << std::endl;
    }

    // Метод для знаходження точки перетину з іншою прямою
    // Параметри m і n - коефіцієнти іншої прямої (m*x + n*y + k = 0)
    // Результат - координати точки перетину (x, y)
    std::pair<double, double> findIntersection(double m, double n, double k) {
        double determinant = A * n - B * m;
        if (std::abs(determinant) < 1e-6) {
            throw std::runtime_error("Прямі паралельні, немає точки перетину.");
        }
        double x = (C * n - B * k) / determinant;
        double y = (A * k - C * m) / determinant;
        return std::make_pair(x, y);
    }

    // Метод для перевірки належності точки прямій
    bool isPointOnLine(double x, double y) {
        return std::abs(A * x + B * y + C) < 1e-6;
    }
};

int main() {
    double a, b, c;
    std::cout << "Введіть коефіцієнти A, B і C для рівняння прямої (Ax + By + C = 0): ";
    std::cin >> a >> b >> c;

    LineEquation line(a, b, c);
    line.display();

    int choice;
    do {
        std::cout << "Оберіть операцію:" << std::endl;
        std::cout << "1. Знайти точку перетину з іншою прямою." << std::endl;
        std::cout << "2. Перевірити належність точки прямій." << std::endl;
        std::cout << "3. Вийти." << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double m, n, k;
            std::cout << "Введіть коефіцієнти для іншої прямої (mx + ny + k = 0): ";
            std::cin >> m >> n >> k;

            try {
                std::pair<double, double> intersection = line.findIntersection(m, n, k);
                std::cout << "Точка перетину: (" << intersection.first << ", " << intersection.second << ")" << std::endl;
            }
            catch (std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 2: {
            double x, y;
            std::cout << "Введіть координати точки (x, y) для перевірки: ";
            std::cin >> x >> y;

            if (line.isPointOnLine(x, y)) {
                std::cout << "Точка належить прямій." << std::endl;
            }
            else {
                std::cout << "Точка не належить прямій." << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Програма завершена." << std::endl;
            break;
        default:
            std::cout << "Некоректний вибір. Спробуйте ще раз." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
