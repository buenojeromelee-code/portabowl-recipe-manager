#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Max number ng recipe
const int MAX_RECIPES = 50;

// Arrays
string recipeNames[MAX_RECIPES];
string recipeCategories[MAX_RECIPES];
string recipeIngredients[MAX_RECIPES];
string recipeInstructions[MAX_RECIPES];

int totalRecipes = 0;  // kung ilang recipe na ang meron

// menu function
void showMenu() {
    cout << "\n==============================\n";
    cout << "PORTABOWL: RECIPE MANAGEMENT SYSTEM\n";
    cout << "==============================\n";
    cout << "1. Add New Recipe\n";
    cout << "2. View All Recipes\n";
    cout << "3. Search Recipe by Name\n";
    cout << "4. Edit Recipe\n";
    cout << "5. Delete Recipe\n";
    cout << "6. Save Recipes\n";
    cout << "7. Exit\n";
    cout << "==============================\n";
}

// add recipe function
void addRecipe() {
    if (totalRecipes >= MAX_RECIPES) {
        cout << "\nSorry! Recipe book is full.\n";
        return;
    }

    cout << "\n--- ADD NEW RECIPE ---\n";

    cout << "Enter recipe name: ";
    getline(cin, recipeNames[totalRecipes]);

    cout << "Enter category (Dessert/Main Course/Appetizer): ";
    getline(cin, recipeCategories[totalRecipes]);

    cout << "Enter ingredients: ";
    getline(cin, recipeIngredients[totalRecipes]);

    cout << "Enter cooking instructions: ";
    getline(cin, recipeInstructions[totalRecipes]);

    totalRecipes++;  // Increase the count

    cout << "\nRecipe added successfully!\n";
}

// view all function
void viewAllRecipes() {
    cout << "\n--- ALL RECIPES ---\n";

    if (totalRecipes == 0) {
        cout << "No recipes found. Add some recipes first!\n";
        return;
    }

    for (int i = 0; i < totalRecipes; i++) {
        cout << "\nRecipe #" << (i + 1) << "\n";
        cout << "Name: " << recipeNames[i] << "\n";
        cout << "Category: " << recipeCategories[i] << "\n";
        cout << "Ingredients: " << recipeIngredients[i] << "\n";
        cout << "Instructions: " << recipeInstructions[i] << "\n";
        cout << "----------------------------\n";
    }
}

// search function
void searchRecipe() {
    cout << "\n--- SEARCH RECIPE ---\n";
    cout << "Enter recipe name to search: ";
    string searchName;
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < totalRecipes; i++) {
        if (recipeNames[i] == searchName) {
            cout << "\nRecipe Found!\n";
            cout << "Name: " << recipeNames[i] << "\n";
            cout << "Category: " << recipeCategories[i] << "\n";
            cout << "Ingredients: " << recipeIngredients[i] << "\n";
            cout << "Instructions: " << recipeInstructions[i] << "\n";
            found = true;
            break;  // Stop searching once found
        }
    }

    if (!found) {
        cout << "Recipe not found.\n";
    }
}

// edit recipe function
void editRecipe() {
    cout << "\n--- EDIT RECIPE ---\n";

    if (totalRecipes == 0) {
        cout << "No recipes to edit.\n";
        return;
    }

    viewAllRecipes();

    cout << "\nEnter recipe number to edit: ";
    int recipeNumber;
    cin >> recipeNumber;
    cin.ignore();

    if (recipeNumber < 1 || recipeNumber > totalRecipes) {
        cout << "Invalid recipe number!\n";
        return;
    }

    int index = recipeNumber - 1;

    cout << "\n--- EDITING: " << recipeNames[index] << " ---\n";
    cout << "What would you like to edit?\n";
    cout << "1. Name\n";
    cout << "2. Category\n";
    cout << "3. Ingredients\n";
    cout << "4. Instructions\n";
    cout << "5. Edit All\n";
    cout << "Enter choice: ";

    int editChoice;
    cin >> editChoice;
    cin.ignore();

    if (editChoice == 1) {
        cout << "Current name: " << recipeNames[index] << "\n";
        cout << "Enter new name: ";
        getline(cin, recipeNames[index]);
        cout << "Name updated successfully!\n";
    } 
    else if (editChoice == 2) {
        cout << "Current category: " << recipeCategories[index] << "\n";
        cout << "Enter new category: ";
        getline(cin, recipeCategories[index]);
        cout << "Category updated successfully!\n";
    } 
    else if (editChoice == 3) {
        cout << "Current ingredients: " << recipeIngredients[index] << "\n";
        cout << "Enter new ingredients: ";
        getline(cin, recipeIngredients[index]);
        cout << "Ingredients updated successfully!\n";
    } 
    else if (editChoice == 4) {
        cout << "Current instructions: " << recipeInstructions[index] << "\n";
        cout << "Enter new instructions: ";
        getline(cin, recipeInstructions[index]);
        cout << "Instructions updated successfully!\n";
    } 
    else if (editChoice == 5) {
        cout << "Enter new name: ";
        getline(cin, recipeNames[index]);

        cout << "Enter new category: ";
        getline(cin, recipeCategories[index]);

        cout << "Enter new ingredients: ";
        getline(cin, recipeIngredients[index]);

        cout << "Enter new instructions: ";
        getline(cin, recipeInstructions[index]);

        cout << "All fields updated successfully!\n";
    } 
    else {
        cout << "Invalid choice!\n";
    }
}

// delete function
void deleteRecipe() {
    cout << "\n--- DELETE RECIPE ---\n";

    if (totalRecipes == 0) {
        cout << "No recipes to delete.\n";
        return;
    }

    viewAllRecipes();

    cout << "\nEnter recipe number to delete: ";
    int recipeNumber;
    cin >> recipeNumber;
    cin.ignore();

    if (recipeNumber < 1 || recipeNumber > totalRecipes) {
        cout << "Invalid recipe number!\n";
        return;
    }

    int index = recipeNumber - 1;
    
    // Shift all recipes after the deleted one left by one position
    for (int i = index; i < totalRecipes - 1; i++) {
        recipeNames[i] = recipeNames[i + 1];
        recipeCategories[i] = recipeCategories[i + 1];
        recipeIngredients[i] = recipeIngredients[i + 1];
        recipeInstructions[i] = recipeInstructions[i + 1];
    }
    
    totalRecipes--;  // Decrease the count
    
    cout << "Recipe deleted successfully!\n";
}

// save recipes to file
void saveRecipes() {
    ofstream outFile("recipes.txt");
    
    if (!outFile) {
        cout << "\nError: Unable to create file!\n";
        return;
    }
    
    outFile << totalRecipes << endl;
    
    for (int i = 0; i < totalRecipes; i++) {
        outFile << recipeNames[i] << endl;
        outFile << recipeCategories[i] << endl;
        outFile << recipeIngredients[i] << endl;
        outFile << recipeInstructions[i] << endl;
    }
    
    outFile.close();
    cout << "\nRecipes saved successfully to recipes.txt!\n";
}

// load recipes from file (optional - can be called at program start)
void loadRecipes() {
    ifstream inFile("recipes.txt");
    
    if (!inFile) {
        return; // File doesn't exist yet
    }
    
    inFile >> totalRecipes;
    inFile.ignore(); // Clear the newline
    
    for (int i = 0; i < totalRecipes && i < MAX_RECIPES; i++) {
        getline(inFile, recipeNames[i]);
        getline(inFile, recipeCategories[i]);
        getline(inFile, recipeIngredients[i]);
        getline(inFile, recipeInstructions[i]);
    }
    
    inFile.close();
}

int main() {
    int choice;
    
    loadRecipes(); // Load existing recipes from file
    
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline character
        
        switch(choice) {
            case 1:
                addRecipe();
                break;
            case 2:
                viewAllRecipes();
                break;
            case 3:
                searchRecipe();
                break;
            case 4:
                editRecipe();
                break;
            case 5:
                deleteRecipe();
                break;
            case 6:
                saveRecipes();
                break;
            case 7:
                cout << "\nThank you for using PORTABOWL! Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter 1-7.\n";
        }
    } while(choice != 7);
    
    return 0;
}
