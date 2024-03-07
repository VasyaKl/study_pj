#include <iostream>
#include "Ingredient.h"
#include "Recipe.h"
#include "Cookbook.h"

int main() {
    Ingredient sugar("Цукор", 200);
    Ingredient flour("Мука", 300);

    Recipe pancakeRecipe("Млинеці", {sugar, flour});

    Cookbook myCookbook;

    myCookbook.addRecipe(pancakeRecipe);

    std::vector<Recipe> recipes = myCookbook.getRecipes();
    for (const auto& recipe : recipes) {
        std::cout << recipe << std::endl;
    }

    std::cout << "Total ingredients: " << Ingredient::getTotalIngredients() << std::endl;
    std::cout << "Total recipes: " << Recipe::getRecipeCount() << std::endl;

    return 0;
}

