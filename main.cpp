#include <iostream>

using namespace std;

class CalorieCalculator {
private:
    double weight;
    double height;
    int age;
    char gender;
    double activityLevel;

public:
    void inputUserData() {
        cout << "Enter your weight (in kilograms): ";
        cin >> weight;

        cout << "Enter your height (in centimeters): ";
        cin >> height;

        cout << "Enter your age: ";
        cin >> age;

        cout << "Enter your gender (m - male, f - female): ";
        cin >> gender;

        cout << "Enter your activity level (from 1 to 5):\n";
        cout << "1 - Sedentary (little to no exercise)\n";
        cout << "2 - Lightly active (light exercise/sports 1-3 days/week)\n";
        cout << "3 - Moderately active (moderate exercise/sports 3-5 days/week)\n";
        cout << "4 - Very active (hard exercise/sports 6-7 days a week)\n";
        cout << "5 - Super active (very hard exercise/sports, physical job, or training twice a day)\n";

        cin >> activityLevel;
    }

    double calculateCaloricNeeds() {
        double bmr;

        if (gender == 'm') {
            bmr = 66 + (13.75 * weight) + (5 * height) - (6.75 * age);
        } else if (gender == 'f') {
            bmr = 655 + (9.56 * weight) + (1.85 * height) - (4.67 * age);
        } else {
            cout << "Invalid gender!\n";
            return 0.0;
        }

        double multiplier;

        switch (static_cast<int>(activityLevel)) {
            case 1:
                multiplier = 1.0;
                break;
            case 2:
                multiplier = 1.1;
                break;
            case 3:
                multiplier = 1.25;
                break;
            case 4:
                multiplier = 1.35;
                break;
            case 5:
                multiplier = 2.0;
                break;
            default:
                cout << "Invalid activity level!\n";
                return 0.0;
        }

        double caloricNeeds = bmr * multiplier;

        return caloricNeeds;
    }

    double calculateBMI() {
        double heightMeters = height / 100.0;
        double bmi = weight / (heightMeters * heightMeters);
        return bmi;
    }

    void displayBMIcategory() {
        double bmi = calculateBMI();

        cout << "Your BMI is: " << bmi << endl;

        if (bmi < 16.0) {
            cout << "Category: Severe Thinness\n";
        } else if (bmi >= 16.0 && bmi < 17.0) {
            cout << "Category: Moderate Thinness\n";
        } else if (bmi >= 17.0 && bmi < 18.5) {
            cout << "Category: Mild Thinness\n";
        } else if (bmi >= 18.5 && bmi < 25.0) {
            cout << "Category: Normal\n";
        } else if (bmi >= 25.0 && bmi < 30.0) {
            cout << "Category: Overweight\n";
        } else if (bmi >= 30.0 && bmi < 35.0) {
            cout << "Category: Obesity Class I\n";
        } else if (bmi >= 35.0 && bmi < 40.0) {
            cout << "Category: Obesity Class II\n";
        } else {
            cout << "Category: Obesity Class III\n";
        }
    }
};

int main() {
    char choice;

    do {
        CalorieCalculator calculator;
        calculator.inputUserData();

        double caloricNeeds = calculator.calculateCaloricNeeds();
        cout << "Your daily caloric needs are: " << caloricNeeds << " kcal\n";

        calculator.displayBMIcategory();

        cout << "Do you want to perform the calculations again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
