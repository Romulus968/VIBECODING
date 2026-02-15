#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace {

double get_positive_number(const std::string& prompt) {
    double value = 0.0;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value && value > 0.0) {
            return value;
        }

        std::cout << "Please enter a valid number greater than 0.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double calculate_upm_average(double crew_size, double moves_45, double moves_40) {
    const double upm_45 = (moves_45 / 4.5) / crew_size;
    const double upm_40 = (moves_40 / 4.0) / crew_size;

    return (upm_45 + upm_40) / 2.0;
}

}  // namespace

int main() {
    std::cout << "UPM Average Calculator\n";

    const double crew_size = get_positive_number("Enter crew size: ");
    const double moves_45 = get_positive_number("Enter total number of 4.5 moves per crew: ");
    const double moves_40 = get_positive_number("Enter total number of 4.0 moves per crew: ");

    const double upm_average = calculate_upm_average(crew_size, moves_45, moves_40);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "UPM average: " << upm_average << '\n';

    return 0;
}
