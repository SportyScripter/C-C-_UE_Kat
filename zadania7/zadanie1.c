#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int extract_energy_value(const char *line) {
    int first_digit = -1;
    int last_digit = -1;
    int i = 0;

    // Find the first digit
    while (line[i] != '\0') {
        if (isdigit(line[i])) {
            first_digit = line[i] - '0';
            break;
        }
        i++;
    }

    // Find the last digit
    while (line[i] != '\0') {
        if (isdigit(line[i])) {
            last_digit = line[i] - '0';
        }
        i++;
    }

    if (first_digit == -1 || last_digit == -1) {
        return 0; // No valid digits found
    }

    return first_digit * 10 + last_digit;
}

int main() {
    FILE *file = fopen("energia.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char line[256];
    int total_sum = 0;

    while (fgets(line, sizeof(line), file)) {
        total_sum += extract_energy_value(line);
    }

    fclose(file);
    printf("Total energy sum: %d\n", total_sum);

    return 0;
}
