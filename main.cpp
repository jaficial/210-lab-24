// COMSC-210 | Lab 24 | Jed Aficial 
// github link: https://github.com/jaficial/210-lab-24

#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

/* NOTE: Syntax for using sets are very similar to using lists. Only had
         to change the data type from list to set throughout the code. */ 
int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();

int main_menu(){
    int choice;

    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl; 
    cout << "Choice --> ";
    cin >> choice;

    if ((choice < 1) || (choice > 4)){
        cout << "Invalid Choice" << endl;
    }
    return choice;
}

/*NOTE: parameters for goat: (name, age, color)
        add_goat selects a random age, name, and color for the goat, creates a temporary
        Goat object with the random parameters, and pushes the object into the trip set */
void add_goat(set <Goat> &trip, string name[], string color[]){
    int temp_age = rand() % MAX_AGE;
    int temp_name = rand() % SZ_NAMES;
    int temp_color = rand() % SZ_COLORS;
    
    Goat temp(name[temp_name], temp_age, color[temp_color]);
    trip.insert(temp); // had to replace "push_back" method with ".insert" method
}

// display_trip takes in the trip list as a parameter, iterates thorugh the list, and outputs the name, color, and age of each Goat object in the list
void display_trip(set <Goat> trip){
    int iter = 1;
    for (auto val : trip){
        cout << "\t" << "[" << iter << "] " << val.get_name() << " (" << val.get_age() << ", " << val.get_color() << ")" << endl;
        iter++;    
    }
}

// selecte_goat takes in the trip list as a parameter, displays the list, then asks for which goat the user would like to delete
// the user is to select the index of the goat that they would like to delete from the list
int select_goat(set <Goat> trip){
    int selection;
    display_trip(trip);
    cout << "Index Selection: ";
    cin >> selection;
    if ((selection > trip.size()) || selection < 1){ // if the user selects an index that does not exist, function provides an error message and returns back to main
        cout << "Invalid Selection" << endl;
        selection = -1;
        return selection;
    }
    return selection; // else returns the index selection
}

// delete_goat takes in the trip list as a parameter, utilizes the select_goat function to allow the user to select the index of a goat, and deletes the goat at the selected index
void delete_goat(set <Goat> &trip){
    cout << "Please input the index of the goat from the trip below, that you would like to delete." << endl;
    int temp_selection = select_goat(trip); 
    if (temp_selection == -1){ // if there was an invalid selection, function returns to main
        return;
    }

    auto iter = trip.begin(); // NOTE: .begin() returns an iterator to first element of list
    for (int i = 0; i < temp_selection - 1; i++){ // temp_selection - 1 because displaying the trip begins with 1 representing index 0 of the list
        iter++;
    }
    trip.erase(iter);
}

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];

    int i = 0;
    while (fin >> names[i++]); // while loop inserts all the names from the names.txt file into an array "names"
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]); // while loop inserts all possible colors from the colors.txt file into an array "colors"
    fin1.close();

    set<Goat> trip; // list of Goat objects is created

   // GM3K1 ENGINE THAT WILL LOOP THE main_menu function
    bool menu = true;
    while (menu){
        int temp_menu_choice;
        cout << endl;
        temp_menu_choice = main_menu();
        
        // if user chooses to quit the main menu
        if (temp_menu_choice == 4){
            menu = false;
        }
        
        // if user chooses to add a goat
        if (temp_menu_choice == 1){
            add_goat(trip, names, colors);
        }

        // if user chooses to delete a goat
        else if (temp_menu_choice == 2){
            cout << endl;
            delete_goat(trip);
        }

        // if user chooses to display the trip
        else if (temp_menu_choice == 3){
            cout << endl << "This is the current trip as of right now:" << endl;
            display_trip(trip);
        }
    }
    
    return 0;
}

