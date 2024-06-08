#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_GAMES 100

typedef struct {
    int id;
    int max_red;
    int max_green;
    int max_blue;
} Game;

void parse_game_line(const char* line, int* red, int* green, int* blue) {
    *red = 0;
    *green = 0;
    *blue = 0;

    const char* ptr = line;
    while (*ptr) {
        if (isdigit(*ptr)) {
            int num = atoi(ptr);
            while (isdigit(*ptr)) ptr++;
            if (strncmp(ptr, " red", 4) == 0) {
                if (num > *red) *red = num;
            } else if (strncmp(ptr, " green", 6) == 0) {
                if (num > *green) *green = num;
            } else if (strncmp(ptr, " blue", 5) == 0) {
                if (num > *blue) *blue = num;
            }
        }
        ptr++;
    }
}

int main() {
    FILE *file = fopen("kostka.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    Game games[MAX_GAMES];
    int game_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int id = 0;
        if (sscanf(line, "Game %d:", &id) != 1) {
            continue; // Ignore lines that do not start with "Game %d:"
        }

        games[game_count].id = id;
        games[game_count].max_red = 0;
        games[game_count].max_green = 0;
        games[game_count].max_blue = 0;

        char* token = strtok(line, ";");
        while (token) {
            int red, green, blue;
            parse_game_line(token, &red, &green, &blue);

            if (red > games[game_count].max_red) games[game_count].max_red = red;
            if (green > games[game_count].max_green) games[game_count].max_green = green;
            if (blue > games[game_count].max_blue) games[game_count].max_blue = blue;

            token = strtok(NULL, ";");
        }

        game_count++;
    }
    fclose(file);

    int sum_id = 0;
    int min_cubes_sum = 0;

    for (int i = 0; i < game_count; i++) {
        if (games[i].max_red <= 12 && games[i].max_green <= 13 && games[i].max_blue <= 14) {
            printf("Game %d is possible\n", games[i].id);
            sum_id += games[i].id;
        }
        min_cubes_sum += games[i].max_red * games[i].max_green * games[i].max_blue;
    }

    printf("Sum of possible game IDs: %d\n", sum_id);
    printf("Sum of minimal cube sets power: %d\n", min_cubes_sum);

    return 0;
}
