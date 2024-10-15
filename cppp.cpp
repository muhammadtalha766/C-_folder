#include <iostream>
using namespace std;

void convertCelsiusToFahrenheit() {
    float celsius, fahrenheit;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    
    // Conversion formula
    fahrenheit = (celsius * 9 / 5) + 32;
    
    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
}

void convertFahrenheitToCelsius() {
    float fahrenheit, celsius;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;
    
    // Conversion formula
    celsius = (fahrenheit - 32) * 5 / 9;
    
    cout << "Temperature in Celsius: " << celsius << endl;
}

int main() {
    int choice;
    
    cout << "Choose conversion method: " << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            convertCelsiusToFahrenheit();
            break;
        case 2:
            convertFahrenheitToCelsius();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Exiting program." << endl;
            break;
    }
    
    return 0;
}
