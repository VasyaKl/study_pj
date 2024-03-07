#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <vector>
#include "Ingredient.h"

class Recipe {
private:
    std::string name;
    std::vector<Ingredient> ingredients;
    static int recipeCount;

public:
    // Конструктори
    Recipe(std::string n, std::vector<Ingredient> ingr);
    Recipe(std::vector<Ingredient> ingr);
    Recipe();

    // Деструктор
    ~Recipe();

    // Методи
    void addIngredient(const Ingredient& ingredient);
    std::vector<Ingredient> getIngredients() const;
    std::string getName() const;

    // Конструктор копіювання
    Recipe(const Recipe& other);

    // Конструктор переміщення
    Recipe(Recipe&& other) noexcept;

    // Приклад використання 'this'
    void addIngredient(int ingredient);

    // Статичні члени
    static int getRecipeCount();

    // Перевантаження операторів
    Recipe& operator++(); // Унарний оператор
    Recipe operator+(const Recipe& other) const; // Бінарний оператор

    // Дружні оператори для введення та виведення в потік
    friend std::istream& operator>>(std::istream& is, Recipe& recipe);
    friend std::ostream& operator<<(std::ostream& os, const Recipe& recipe);
};

#endif // RECIPE_H
