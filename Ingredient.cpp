#include "Ingredient.h"

int Ingredient::totalIngredients = 0;

// Конструктор з параметрами
Ingredient::Ingredient(std::string n, int q) : name(n), quantity(q) {
    totalIngredients++;
}

// Перевантажений конструктор
Ingredient::Ingredient() : name(""), quantity(0) {
    totalIngredients++;
}

// Деструктор
Ingredient::~Ingredient() {}

// Методи доступу до полів
std::string Ingredient::getName() const {
    return name;
}

int Ingredient::getQuantity() const {
    return quantity;
}

// Конструктор копіювання
Ingredient::Ingredient(const Ingredient& other) : name(other.name), quantity(other.quantity) {
    totalIngredients++;
}

// Конструктор переміщення
Ingredient::Ingredient(Ingredient&& other) noexcept : name(std::move(other.name)), quantity(other.quantity) {
    other.quantity = 0;
    totalIngredients++;
}

// Метод для збільшення кількості інгредієнта
void Ingredient::increaseQuantity(int amount) {
    this->quantity += amount;
}

// Метод для отримання загальної кількості інгредієнтів
int Ingredient::getTotalIngredients() {
    return totalIngredients;
}

// Перевантаження унарного оператору ++ (префіксний)
Ingredient& Ingredient::operator++() {
    this->quantity++;
    return *this;
}

// Перевантаження бінарного оператору + для об'єкта та цілого числа
Ingredient Ingredient::operator+(int value) const {
    Ingredient result = *this;
    result.quantity += value;
    return result;
}

// Перевантаження дружнього оператору >>
std::istream& operator>>(std::istream& is, Ingredient& ingredient) {
    is >> ingredient.name >> ingredient.quantity;
    return is;
}

// Перевантаження дружнього оператору <<
std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient) {
    os << "Name: " << ingredient.name << ", Quantity: " << ingredient.quantity;
    return os;
}
