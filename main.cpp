/*Вариант № 3
Создать базовый класс «квадрат». Элементы класса: поле, задающее длину стороны (статус доступа protected);
конструктор для инициализации поля; функция для вычисления площади квадрата; функция для печати поля и площади квадрата.
Создать производный класс «куб». Элементы класса: конструктор для инициализации поля;
переопределенная функция для вычисления объема куба (вместо площади) (внутри переопределенной функции должна вызываться функция из базового класса).
Создать по 1 объекту каждого из классов. Показать вызов созданных функций.
При переопределении функций обеспечить и продемонстрировать два варианта: статический полиморфизм и динамический полиморфизм.*/

#include <stdlib.h>
#include <iostream>
using namespace std;
class Square // Базовый класс - "Квадрат"
{
protected:
    double l; // Длина стороны
public:
    Square(double l): l(l) {}  // Конструктор для инициализации поля

    virtual double area() {
        return l*l;
    }
    void print() {
        cout << "\nSide = " << l << " Area = " << l*l << "\n";
    }
};
class Cube: public Square // Производный класс - "Куб"
{
public:
    Cube(double l): Square(l) {} // Конструктор

    double area() override // Переопределенный метод area
    {
        return Square::area()*l;
    }
};

int main(int argc, char* argv[])
{
    Square sq_static(12);
    cout << sq_static.area() << "\n";
    Cube c_static(4);
    cout << c_static.area() << "\n";

    Square* sq_dinamic = new Square(10);
    cout << sq_dinamic->area() << "\n";
    Cube* c_dinamic = new Cube(7);
    cout << c_dinamic->area() << "\n";
    system("pause"); // Останавливаем программу до нажатия любой клавиши
    return 0;
}
