#include <iostream>

class PlaneEquation {
private:
    double A, B, C, D;

public:
    PlaneEquation(double a, double b, double c, double d) : A(a), B(b), C(c), D(d) {}

    // Індексатор для доступу до коефіцієнтів
    double& operator[](int index) {
        switch (index) {
        case 0: return A;
        case 1: return B;
        case 2: return C;
        case 3: return D;
        default:
            throw std::out_of_range("Індекс виходить за межі діапазону.");
        }
    }

    // Метод для виведення рівняння площини
    void display() {
        std::cout << A << "x + " << B << "y + " << C << "z + " << D << " = 0" << std::endl;
    }

    // Метод для знаходження точки перетину площини з осями координат
    // Результат - координати точки перетину (x, y, z)
    void findIntersectionWithAxes() {
        double x, y, z;

        // Площина з осью X: x = -D / A
        x = -D / A;

        // Площина з осью Y: y = -D / B
        y = -D / B;

        // Площина з осью Z: z = -D / C
        z = -D / C;

        std::cout << "Точка перетину з осью X: (" << x << ", 0, 0)" << std::endl;
        std::cout << "Точка перетину з осью Y: (0, " << y << ", 0)" << std::endl;
        std::cout << "Точка перетину з осью Z: (0, 0, " << z << ")" << std::endl;
    }

    // Метод для перевірки належності точки площині
    bool isPointOnPlane(double x, double y, double z) {
        return (A * x + B * y + C * z + D) == 0;
    }
};

int main() {
    double a, b, c, d;

    std::cout << "Введіть коефіцієнти A, B, C, D для рівняння площини (Ax + By + Cz + D = 0): ";
    std::cin >> a >> b >> c >> d;

    PlaneEquation plane(a, b, c, d);
    plane.display();

    plane.findIntersectionWithAxes();

    double x, y, z;
    std::cout << "Введіть координати точки (x, y, z) для перевірки: ";
    std::cin >> x >> y >> z;

    if (plane.isPointOnPlane(x, y, z)) {
        std::cout << "Точка належить площині." << std::endl;
    }
    else {
        std::cout << "Точка не належить площині." << std::endl;
    }

    return 0;
}
