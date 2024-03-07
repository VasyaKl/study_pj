#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <iostream>

class Ingredient {
private:
    std::string name;
    int quantity; // кількість в грамах
    static int totalIngredients;

public:
    // Конструктор з параметрами
    Ingredient(std::string n, int q);

    // Перевантажений конструктор
    Ingredient();

    // Деструктор
    ~Ingredient();

    // Методи доступу до полів
    std::string getName() const;
    int getQuantity() const;

    // Конструктор копіювання
    Ingredient(const Ingredient& other);

    // Конструктор переміщення
    Ingredient(Ingredient&& other) noexcept;

    // Метод для збільшення кількості інгредієнта
    void increaseQuantity(int amount);

    // Метод для отримання загальної кількості інгредієнтів
    static int getTotalIngredients();

    // Перевантаження унарного оператору ++ (префіксний)
    Ingredient& operator++();

    // Перевантаження бінарного оператору + для об'єкта та цілого числа
    Ingredient operator+(int value) const;

    // Перевантаження дружнього оператору >>
    friend std::istream& operator>>(std::istream& is, Ingredient& ingredient);

    // Перевантаження дружнього оператору <<
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
};

#endif // INGREDIENT_H
