#include "Cookbook.h"

// Конструктор за замовчуванням
Cookbook::Cookbook() : recipes() {}

// Деструктор
Cookbook::~Cookbook() {}

// Метод для додавання рецепту до книги
void Cookbook::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

// Метод для отримання списку рецептів
std::vector<Recipe> Cookbook::getRecipes() const {
    return recipes;
}
