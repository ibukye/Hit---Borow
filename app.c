#include <stdio.h>

#define MAX_DIGIT 4

int digit;
int numbers[2][MAX_DIGIT];
int player = 0;     // Indicator of Player1, Player2
int guess[MAX_DIGIT];

// Prototype
void menu();
void get_number();
void get_guess();
int check_hit();
int check_borrow();


int main() {
    int guess_num;

    menu();
    get_number();


    int hit = 0, borrow = 0;
    while (hit != digit) {
        get_guess();
        hit = check_hit();
        borrow = check_borrow();
        
        printf("HIT | BORROW\n %d  |   %d   \n", hit, borrow);

        if (hit == digit) {
            printf("Player %d WIN!!!\n", player+1);
            break;
        }
        player = !player;   // Change the player
    }
    return 0;
}

void menu() {
    printf("Menu\n");
    while (1) {
        printf("Enter digit(3-4): ");
        if (scanf("%d", &digit) == 1 && digit >= 3 && digit <= 4) break;
        
        puts("Invalid input. Enter again.\n");
        while(getchar() != '\n');
    }
    puts("");
}


void get_number() {
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < digit; i++) {
            printf("Player %d, Enter %d-th digit: ", j+1, i+1);
            while (scanf("%d", &numbers[j][i]) != 1) {
                printf("Invalid input. Enter again.\n");
                while (getchar() != '\n');
            } 
        }
        puts("");
    }
}


int check_hit() {
    int hit = 0;
    for (int i = 0; i < digit; i++) {
        if (numbers[!player][i] == guess[i]) hit++;
    }
    return hit;
}

int check_borrow() {
    int borrow = 0;
    int checked[MAX_DIGIT] = {0};   // Store the numbers that already checked

    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < digit; j++) {
            if (i != j && numbers[!player][j] == guess[i] && !checked[j]) {
                borrow++; 
                checked[j] = 1; 
                break;   // i != j の処理 & dont count the same number
            }
        }
    }
    return borrow;
}

void get_guess() {
    printf("Player %d, enter guess number: ", player+1);
    for (int i = 0; i < digit; i++) {
        scanf("%d", &guess[i]);
    }
}