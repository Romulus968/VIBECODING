"""Calculate UPM average for truck moves based on crew size."""


def get_positive_float(prompt: str) -> float:
    """Prompt for a positive numeric value."""
    while True:
        raw_value = input(prompt).strip()
        try:
            value = float(raw_value)
        except ValueError:
            print("Please enter a valid number.")
            continue

        if value <= 0:
            print("Please enter a value greater than 0.")
            continue

        return value


def calculate_upm_average(crew_size: float, moves_45: float, moves_40: float) -> float:
    """Compute the UPM average using 4.5 and 4.0 move factors."""
    upm_45 = (moves_45 / 4.5) / crew_size
    upm_40 = (moves_40 / 4.0) / crew_size
    return (upm_45 + upm_40) / 2


def main() -> None:
    print("UPM Average Calculator")
    crew_size = get_positive_float("Enter crew size: ")
    moves_45 = get_positive_float("Enter total number of 4.5 moves: ")
    moves_40 = get_positive_float("Enter total number of 4.0 moves: ")

    average = calculate_upm_average(crew_size, moves_45, moves_40)
    print(f"UPM average: {average:.2f}")


if __name__ == "__main__":
    main()
