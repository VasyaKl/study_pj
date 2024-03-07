#include "Recipe.h"

// Конструктори
Recipe::Recipe(std::string n, std::vector<Ingredient> ingr) : name{n}, ingredients{ingr} {
    recipeCount++;
}

Recipe::Recipe() : name(""), ingredients() {
    recipeCount++;
}

// Деструктор
Recipe::~Recipe() {}

// Методи
void Recipe::addIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

std::vector<Ingredient> Recipe::getIngredients() const {
    return ingredients;
}

std::string Recipe::getName() const {
    return name;
}

void Recipe::addIngredient(int ingredient) {
    // Приклад використання 'this'
    std::cout << "Додавання інгредієнта зі значенням: " << ingredient << " до рецепту." << std::endl;
}

// Конструктор копіювання
Recipe::Recipe(const Recipe& other) : name(other.name), ingredients(other.ingredients) {
    recipeCount++;
}

// Конструктор переміщення
Recipe::Recipe(Recipe&& other) noexcept : name(std::move(other.name)), ingredients(std::move(other.ingredients)) {
    // Додаткова логіка, якщо потрібно
    recipeCount++;
}

// Статичні члени
int Recipe::recipeCount = 0;

int Recipe::getRecipeCount() {
    return recipeCount;
}

// Перевантаження операторів
Recipe& Recipe::operator++() {
    return *this;
}

Recipe Recipe::operator+(const Recipe& other) const {
    Recipe result = *this;  // Створення копії поточного рецепту
    return result;
}

// Дружні оператори для введення та виведення в потік
std::istream& operator>>(std::istream& is, Recipe& recipe) {
    is >> recipe.name;
    int numIngredients;
    is >> numIngredients;

    recipe.ingredients.clear();

    for (int i = 0; i < numIngredients; ++i) {
        Ingredient ingredient;
        is >> ingredient;
        recipe.ingredients.push_back(ingredient);
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Recipe& recipe) {
    os << "Recipe: " << recipe.name << std::endl;
    os << "Ingredients:" << std::endl;

    for (const auto& ingredient : recipe.ingredients) {
        os << "- " << ingredient << std::endl;
    }

    return os;
}

