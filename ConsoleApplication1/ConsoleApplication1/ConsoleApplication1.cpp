#include <iostream>
#include <cmath>

class TQuadrangle {
private:
    double side1, side2, side3, side4;
    double angle1, angle2, angle3, angle4;

public:
    TQuadrangle(double s1, double s2, double s3, double s4, double a1, double a2, double a3, double a4)
        : side1(s1), side2(s2), side3(s3), side4(s4), angle1(a1), angle2(a2), angle3(a3), angle4(a4) {}

    // Метод для визначення типу чотирикутника
    std::string determineType() {
        if (side1 == side2 && side2 == side3 && side3 == side4) {
            if (angle1 == 90 && angle2 == 90 && angle3 == 90 && angle4 == 90)
                return "Квадрат";
            else
                return "Ромб";
        }
        else {
            if (angle1 == 90 && angle2 == 90 && angle3 == 90 && angle4 == 90)
                return "Прямокутник";
            else
                return "Загальний чотирикутник";
        }
    }

    // Метод для знаходження периметру чотирикутника
    double findPerimeter() {
        return side1 + side2 + side3 + side4;
    }

    // Метод для знаходження площі чотирикутника
    double findArea() {
        // Використовуємо формулу Герона для обчислення площі загального чотирикутника
        double s = (side1 + side2 + side3 + side4) / 2;
        double area = sqrt((s - side1) * (s - side2) * (s - side3) * (s - side4));
        return area;
    }
};

int main() {
    double s1, s2, s3, s4, a1, a2, a3, a4;

    std::cout << "Введіть довжини сторін та кути чотирикутника:" << std::endl;
    std::cin >> s1 >> s2 >> s3 >> s4 >> a1 >> a2 >> a3 >> a4;

    TQuadrangle quadrangle(s1, s2, s3, s4, a1, a2, a3, a4);

    std::string type = quadrangle.determineType();
    std::cout << "Тип чотирикутника: " << type << std::endl;

    double perimeter = quadrangle.findPerimeter();
    std::cout << "Периметр чотирикутника: " << perimeter << std::endl;

    double area = quadrangle.findArea();
    std::cout << "Площа чотирикутника: " << area << std::endl;

    return 0;
}
