#include <stdio.h>

#define MAX_DIGITS 4

int player_number[2][MAX_DIGITS];   // 3, 4 digits

void get_valid_input(int, int [][MAX_DIGITS]);

int main () {
    int digits;
    printf("HIT & BORROW\n");
    printf("Enter digits (3-4): ");
    if (scanf("%d", &digits) != 1 || (digits != 3 && digits != 4)) {
        printf("Invalid input. Enter again.\n");
        return 1;
    }
    get_valid_input(digits, player_number);
    return 0;
}

void get_valid_input(int digits, int player_number[2][MAX_DIGITS]) {
    int max_number = (digits == 3) ? 999 : 9999;

    for (int i = 0; i < 2; i++) {
        printf("Enter a %d-digit number for player %d: ", digits, i + 1);
        if (scanf("%d", &player_number[i][0]) != 1 || player_number[i][0] < 0 || player_number[i][0] > max_number) {
            printf("Invalid input. Enter again.\n");
            i--; // Loop again for the same player
        }
    }
}

    








// H = number


// B = number & position is the same