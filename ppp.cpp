#include <iostream>
#include <limits> // for numeric_limits
#include <string> // for string and getline
#include <sstream> // for stringstream
using namespace std;

// Function to get the cost multiplier based on material quality
double getQualityMultiplier(string quality) {
    if (quality == "low") {
        return 0.8; // 20% less cost for low quality
    } else if (quality == "medium") {
        return 1.0; // No change for medium quality
    } else if (quality == "high") {
        return 1.2; // 20% more cost for high quality
    } else {
        cout << "Invalid quality type. Defaulting to medium quality." << endl;
        return 1.0;
    }
}

// Function to check if a string is a valid double
bool isValidDouble(const string& str) {
    stringstream ss(str);
    double value;
    ss >> value;
    return ss.eof() && !ss.fail();
}

// Function to get a valid double input
double getValidDoubleInput() {
    string input;
    double value;
    while (true) {
        getline(cin, input);
        if (isValidDouble(input)) {
            stringstream(input) >> value;
            return value;
        } else {
            cout << "Invalid input. Please enter a valid number: ";
        }
    }
}

// Function to check if a string is a valid integer
bool isValidInt(const string& str) {
    stringstream ss(str);
    int value;
    ss >> value;
    return ss.eof() && !ss.fail();
}

// Function to get a valid integer input
int getValidIntInput() {
    string input;
    int value;
    while (true) {
        getline(cin, input);
        if (isValidInt(input)) {
            stringstream(input) >> value;
            return value;
        } else {
            cout << "Invalid input. Please enter a valid number: ";
        }
    }
}

int main() {
    double area, constableArea, roomCost = 0, kitchenCost = 0, bathroomCost = 0, garageCost = 0, doorCost = 0, windowCost = 0, tvLoungeCost = 0, totalCost;
    double totalRoomArea = 0, totalKitchenArea = 0, totalBathroomArea = 0, totalGarageArea = 0, totalWindowArea = 0, totalDoorArea = 0;
    int numFloors, numRooms, numKitchens, numBathrooms, numGarages, numWindows, numDoors, numTVLounges;
    string quality;

    // Get the area of the building from the user in square feet
    cout << "Enter the area of the building in square feet: ";
    area = getValidDoubleInput();

    // Get the number of floors from the user
    cout << "Enter the number of floors: ";
    numFloors = getValidIntInput();

    // Calculate the constable area
    constableArea = area * 0.8; // Assume 80% of the area is constable area

    // Get the number of rooms, kitchens, bathrooms, garages, and windows from the user for each floor
    for (int i = 1; i <= numFloors; i++) {
        cout << "Enter the number of rooms on the " << i << "th floor: ";
        numRooms = getValidIntInput();
        for (int j = 1; j <= numRooms; j++) {
            double length, width;
            cout << "Enter the dimensions (length and width) of room " << j << " on floor " << i << ": ";
            length = getValidDoubleInput();
            width = getValidDoubleInput();
            double roomArea = length * width;
            totalRoomArea += roomArea;
            roomCost += roomArea * 25000.0; // assume PKR 25000 per square meter
            cout << "Enter the number of windows in room " << j << " on floor " << i << ": ";
            numWindows = getValidIntInput();
            for (int k = 1; k <= numWindows; k++) {
                double winLength, winWidth;
                cout << "Enter the dimensions (length and width) of window " << k << " in room " << j << ": ";
                winLength = getValidDoubleInput();
                winWidth = getValidDoubleInput();
                double windowArea = winLength * winWidth;
                totalWindowArea += windowArea;
                windowCost += windowArea * 2000.0; // assume PKR 2000 per square meter
            }
            cout << "Enter the number of doors in room " << j << " on floor " << i << ": ";
            numDoors = getValidIntInput();
            for (int k = 1; k <= numDoors; k++) {
                double doorLength, doorWidth;
                cout << "Enter the dimensions (length and width) of door " << k << " in room " << j << ": ";
                doorLength = getValidDoubleInput();
                doorWidth = getValidDoubleInput();
                double doorArea = doorLength * doorWidth;
                totalDoorArea += doorArea;
                doorCost += doorArea * 5000.0; // assume PKR 5000 per square meter
            }
        }

        cout << "Enter the number of kitchens on the " << i << "th floor: ";
        numKitchens = getValidIntInput();
        for (int j = 1; j <= numKitchens; j++) {
            double length, width;
            cout << "Enter the dimensions (length and width) of kitchen " << j << " on floor " << i << ": ";
            length = getValidDoubleInput();
            width = getValidDoubleInput();
            double kitchenArea = length * width;
            totalKitchenArea += kitchenArea;
            kitchenCost += kitchenArea * 25000.0; // assume PKR 25000 per square meter for kitchen
            cout << "Enter the number of windows in kitchen " << j << " on floor " << i << ": ";
            numWindows = getValidIntInput();
            for (int k = 1; k <= numWindows; k++) {
                double winLength, winWidth;
                cout << "Enter the dimensions (length and width) of window " << k << " in kitchen " << j << ": ";
                winLength = getValidDoubleInput();
                winWidth = getValidDoubleInput();
                double windowArea = winLength * winWidth;
                totalWindowArea += windowArea;
                windowCost += windowArea * 2000.0; // assume PKR 2000 per square meter
            }
            cout << "Enter the number of doors in kitchen " << j << " on floor " << i << ": ";
            numDoors = getValidIntInput();
            for (int k = 1; k <= numDoors; k++) {
                double doorLength, doorWidth;
                cout << "Enter the dimensions (length and width) of door " << k << " in kitchen " << j << ": ";
                doorLength = getValidDoubleInput();
                doorWidth = getValidDoubleInput();
                double doorArea = doorLength * doorWidth;
                totalDoorArea += doorArea;
                doorCost += doorArea * 5000.0; // assume PKR 5000 per square meter
            }
        }

        cout << "Enter the number of bathrooms on the " << i << "th floor: ";
        numBathrooms = getValidIntInput();
        for (int j = 1; j <= numBathrooms; j++) {
            double length, width;
            cout << "Enter the dimensions (length and width) of bathroom " << j << " on floor " << i << ": ";
            length = getValidDoubleInput();
            width = getValidDoubleInput();
            double bathroomArea = length * width;
            totalBathroomArea += bathroomArea;
            bathroomCost += bathroomArea * 30000.0; // assume PKR 30000 per square meter for bathroom
            cout << "Enter the number of doors in bathroom " << j << " on floor " << i << ": ";
            numDoors = getValidIntInput();
            for (int k = 1; k <= numDoors; k++) {
                double doorLength, doorWidth;
                cout << "Enter the dimensions (length and width) of door " << k << " in bathroom " << j << ": ";
                doorLength = getValidDoubleInput();
                doorWidth = getValidDoubleInput();
                double doorArea = doorLength * doorWidth;
                totalDoorArea += doorArea;
                doorCost += doorArea * 5000.0; // assume PKR 5000 per square meter
            }
        }

        if (numFloors != 2) { // Assuming garages are not present on the 2nd floor
            cout << "Enter the number of garages on the " << i << "th floor: ";
            numGarages = getValidIntInput();
            for (int j = 1; j <= numGarages; j++) {
                double length, width;
                cout << "Enter the dimensions (length and width) of garage " << j << " on floor " << i << ": ";
                length = getValidDoubleInput();
                width = getValidDoubleInput();
                double garageArea = length * width;
                totalGarageArea += garageArea;
                garageCost += garageArea * 10000.0; // assume PKR 10000 per square meter for garage
                cout << "Enter the number of windows in garage " << j << " on floor " << i << ": ";
                numWindows = getValidIntInput();
                for (int k = 1; k <= numWindows; k++) {
                    double winLength, winWidth;
                    cout << "Enter the dimensions (length and width) of window " << k << " in garage " << j << ": ";
                    winLength = getValidDoubleInput();
                    winWidth = getValidDoubleInput();
                    double windowArea = winLength * winWidth;
                    totalWindowArea += windowArea;
                    windowCost += windowArea * 2000.0; // assume PKR 2000 per square meter
                }
                cout << "Enter the number of doors in garage " << j << " on floor " << i << ": ";
                numDoors = getValidIntInput();
                for (int k = 1; k <= numDoors; k++) {
                    double doorLength, doorWidth;
                    cout << "Enter the dimensions (length and width) of door " << k << " in garage " << j << ": ";
                    doorLength = getValidDoubleInput();
                    doorWidth = getValidDoubleInput();
                    double doorArea = doorLength * doorWidth;
                    totalDoorArea += doorArea;
                    doorCost += doorArea * 5000.0; // assume PKR 5000 per square meter
                }
            }
        }

        cout << "Enter the number of TV lounges on the " << i << "th floor: ";
        numTVLounges = getValidIntInput();
        for (int j = 1; j <= numTVLounges; j++) {
            double length, width;
            cout << "Enter the dimensions (length and width) of TV lounge " << j << " on floor " << i << ": ";
            length = getValidDoubleInput();
            width = getValidDoubleInput();
            double tvLoungeArea = length * width;
            tvLoungeCost += tvLoungeArea * 20000.0; // assume PKR 20000 per square meter for TV lounge
        }
    }

    // Get the quality of materials from the user
    cout << "Enter the quality of the materials (low, medium, high): ";
    cin >> quality;

    // Get the quality multiplier
    double qualityMultiplier = getQualityMultiplier(quality);

    // Adjust costs based on quality
    roomCost *= qualityMultiplier;
    kitchenCost *= qualityMultiplier;
    bathroomCost *= qualityMultiplier;
    garageCost *= qualityMultiplier;
    doorCost *= qualityMultiplier;
    windowCost *= qualityMultiplier;
    tvLoungeCost *= qualityMultiplier;

    // Calculate the total cost
    totalCost = roomCost + kitchenCost + bathroomCost + garageCost + doorCost + windowCost + tvLoungeCost;

    // Output the results
    cout << "Constable area: " << constableArea << " square meters" << endl;
    cout << "Total room area: " << totalRoomArea << " square meters" << endl;
    cout << "Total kitchen area: " << totalKitchenArea << " square meters" << endl;
    cout << "Total bathroom area: " << totalBathroomArea << " square meters" << endl;
    cout << "Total garage area: " << totalGarageArea << " square meters" << endl;
    cout << "Total window area: " << totalWindowArea << " square meters" << endl;
    cout << "Total door area: " << totalDoorArea << " square meters" << endl;
    cout << "Net area (constable area minus window and door area): " << constableArea - totalWindowArea - totalDoorArea << " square meters" << endl;
    cout << "Room cost: PKR " << roomCost << endl;
    cout << "Kitchen cost: PKR " << kitchenCost << endl;
    cout << "Bathroom cost: PKR " << bathroomCost << endl;
    cout << "Garage cost: PKR " << garageCost << endl;
    cout << "Door cost: PKR " << doorCost << endl;
    cout << "Window cost: PKR " << windowCost << endl;
    cout << "TV lounge cost: PKR " << tvLoungeCost << endl;
    cout << "Total cost: PKR " << totalCost << endl;

    return 0;
}
