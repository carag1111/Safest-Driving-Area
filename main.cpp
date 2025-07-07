
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function prototypes
void getRegInfo(string& regionName, int& accidents);
bool isLower(int value1, int value2);
void showLowest(const string& regionName, int accidents);

/*
 * This program determines the safest driving region in the city based on the number of
 * accidents reported for each region during the past year.
 * Input: Region names and accident counts for 5 regions (north, south, east, west, central)
 * Output: The region with the lowest number of accidents
 */
int main() {
    string currentRegion, safestRegion;
    int currentAccidents, lowestAccidents;
    
    cout << "Safest Driving Area Analysis" << endl;
    cout << "=============================" << endl;
    cout << "Enter accident data for 5 regions (north, south, east, west, central)" << endl << endl;
    
    // Get data for the first region to initialize our "lowest" values
    cout << "Region 1:" << endl;
    getRegInfo(currentRegion, currentAccidents);
    safestRegion = currentRegion;
    lowestAccidents = currentAccidents;
    
    // Get data for the remaining 4 regions and compare
    for (int i = 2; i <= 5; i++) {
        cout << "\nRegion " << i << ":" << endl;
        getRegInfo(currentRegion, currentAccidents);
        
        if (isLower(currentAccidents, lowestAccidents)) {
            safestRegion = currentRegion;
            lowestAccidents = currentAccidents;
        }
    }
    
    // Display the results
    cout << "\n=============================" << endl;
    cout << "ANALYSIS RESULTS:" << endl;
    showLowest(safestRegion, lowestAccidents);
    
    return 0;
}

/*
 * This function gets the name of a region and the number of accidents that occurred in
 * that region during the past year.
 * Preconditions: Parameters must be passed by reference to return multiple values
 * Postconditions: regionName contains the name of the region, accidents contains the
 *                number of accidents (guaranteed to be >= 0)
 * Input validation: The number of accidents must be >= 0
 */
void getRegInfo(string& regionName, int& accidents) {
    cout << "Enter region name: ";
    getline(cin, regionName);
    
    do {
        cout << "Enter number of accidents (must be >= 0): ";
        cin >> accidents;
        
        if (accidents < 0) {
            cout << "Error: Number of accidents cannot be negative. Please try again." << endl;
        }
        
        // Clear input buffer for any invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            accidents = -1; // Force loop to continue
        }
    } while (accidents < 0);
    
    // Clear the input buffer for the next getline call
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
 * This function takes two integer values as input, it returns true if the first value 
 * is <= the second value, otherwise it returns false.
 * Preconditions: value1 and value2 are valid integer values
 * Postconditions: Returns true if value1 <= value2, false otherwise
 */
bool isLower(int value1, int value2) {
    return value1 <= value2;
}

/*
 * This function gets the name of the region with the lowest reported accidents for the year
 * and the number of accidents for that region. It displays these values on the screen.
 * Preconditions: regionName is a valid string, accidents is a valid non-negative integer
 * Postconditions: The region name and accident count are displayed to the user
 */
void showLowest(const string& regionName, int accidents) {
    cout << "The safest driving region is: " << regionName << endl;
    cout << "Number of accidents reported: " << accidents << endl;
    cout << "\nThis region had the fewest automobile accidents last year." << endl;
}
