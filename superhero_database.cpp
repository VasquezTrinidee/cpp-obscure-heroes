#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> heroNames = {
    "Doorman", "Bouncing Boy", "Flatman", "Jubilee", "Ambush Bug",
    "Maggott", "Ferro Lad", "Ragman", "El Guapo", "Zeitgeist"
};

vector<string> superpowers = {
    "Phase through walls", "Inflates into a human ball", "Paper-thin stretching",
    "Fireworks from hands", "Breaks the 4th wall", "Digestive slugs",
    "Turns into living iron", "Soul-absorbing rags", "Sentient skateboard control",
    "Acid vomit"
};

vector<string> weaknesses = {
    "Requires external energy", "Can be punctured", "Easily crumpled",
    "Relatively low power", "Mental instability", "Slugs can be harmed",
    "Self-sacrifice tendency", "Weakened without souls", "Co-dependency with board",
    "Self-injury"
};

vector<vector<int>> details = {
    {1989, 0}, {1961, 1}, {1989, 0}, {1989, 0}, {1982, 1},
    {1997, 0}, {1966, 1}, {1976, 1}, {2001, 0}, {2001, 0}
};

vector<int> powerLevels = {60, 55, 50, 65, 70, 68, 72, 74, 58, 65};

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void displayAll(bool upperCase = false) {
    cout << "\n--- All Superheroes ---\n";
    for (size_t i = 0; i < heroNames.size(); ++i) {
        string name = upperCase ? toUpperCase(heroNames[i]) : toLowerCase(heroNames[i]);
        string power = upperCase ? toUpperCase(superpowers[i]) : toLowerCase(superpowers[i]);
        string weak = upperCase ? toUpperCase(weaknesses[i]) : toLowerCase(weaknesses[i]);
        string universe = (details[i][1] == 0) ? "Marvel" : (details[i][1] == 1) ? "DC" : "Other";

        cout << "Name: " << name << ", Power: " << power
             << ", Weakness: " << weak << ", Year: " << details[i][0]
             << ", Universe: " << universe
             << ", Power Level: " << powerLevels[i] << "\n";
    }
}

void searchByName(string name) {
    string lowerName = toLowerCase(name);
    for (size_t i = 0; i < heroNames.size(); ++i) {
        if (toLowerCase(heroNames[i]).find(lowerName) != string::npos) {
            cout << "Found: " << heroNames[i] << " - " << superpowers[i] << " - " << weaknesses[i] << "\n";
            return;
        }
    }
    cout << "No superhero found with that name.\n";
}

void searchByPower(string power) {
    string lowerPower = toLowerCase(power);
    bool found = false;
    for (size_t i = 0; i < superpowers.size(); ++i) {
        if (toLowerCase(superpowers[i]).find(lowerPower) != string::npos) {
            cout << heroNames[i] << " has power: " << superpowers[i] << "\n";
            found = true;
        }
    }
    if (!found) cout << "No superheroes found with that power.\n";
}

void sortHeroes() {
    for (size_t i = 0; i < heroNames.size(); ++i) {
        for (size_t j = i + 1; j < heroNames.size(); ++j) {
            if (heroNames[j] < heroNames[i]) {
                swap(heroNames[i], heroNames[j]);
                swap(superpowers[i], superpowers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(details[i], details[j]);
                swap(powerLevels[i], powerLevels[j]);
            }
        }
    }
    cout << "Superheroes sorted alphabetically.\n";
}

void addSuperhero() {
    string name, power, weak;
    int year, universe, level;
    cout << "Enter name: ";
    getline(cin >> ws, name);
    cout << "Enter power: ";
    getline(cin >> ws, power);
    cout << "Enter weakness: ";
    getline(cin >> ws, weak);
    cout << "Enter year introduced: ";
    cin >> year;
    cout << "Enter universe (0: Marvel, 1: DC, 2: Other): ";
    cin >> universe;
    cout << "Enter power level (1-100): ";
    cin >> level;

    heroNames.push_back(name);
    superpowers.push_back(power);
    weaknesses.push_back(weak);
    details.push_back({year, universe});
    powerLevels.push_back(level);

    cout << "Superhero added successfully!\n";
}

void generateRandomHero() {
    srand(time(0));
    int index = rand() % heroNames.size();
    cout << "\n--- Random Superhero ---\n";
    cout << "Name: " << heroNames[index] << "\nPower: " << superpowers[index]
         << "\nWeakness: " << weaknesses[index]
         << "\nYear: " << details[index][0]
         << "\nUniverse: " << (details[index][1] == 0 ? "Marvel" : (details[index][1] == 1 ? "DC" : "Other"))
         << "\nPower Level: " << powerLevels[index] << "\n";
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n--- Obscure Superhero Database ---\n";
        cout << "1. Display All Superheroes (lowercase)\n";
        cout << "2. Display All Superheroes (UPPERCASE)\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by Power\n";
        cout << "5. Sort Superheroes Alphabetically\n";
        cout << "6. Add New Superhero\n";
        cout << "7. Generate Random Superhero\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAll(false);
                break;
            case 2:
                displayAll(true);
                break;
            case 3:
                cout << "Enter name to search: ";
                getline(cin >> ws, input);
                searchByName(input);
                break;
            case 4:
                cout << "Enter power to search: ";
                getline(cin >> ws, input);
                searchByPower(input);
                break;
            case 5:
                sortHeroes();
                break;
            case 6:
                addSuperhero();
                break;
            case 7:
                generateRandomHero();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
