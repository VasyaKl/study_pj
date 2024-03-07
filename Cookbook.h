#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <vector>
#include "Recipe.h"

class Cookbook {
private:
    std::vector<Recipe> recipes;

public:
    // Конструктор за замовчуванням
    Cookbook();

    // Деструктор
    ~Cookbook();

    // Метод для додавання рецепту до книги
    void addRecipe(const Recipe& recipe);

    // Метод для отримання списку рецептів
    std::vector<Recipe> getRecipes() const;
};

#endif // COOKBOOK_H
