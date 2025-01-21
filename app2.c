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
    while (hit != digit && borrow != digit) {
        get_guess();
        hit = check_hit();
        borrow = check_borrow();
        player = !(player);
        printf("HIT | BORROW\n %d  |   %d   \n", hit, borrow);
    }
    printf("Player %d WIN!!!\n", player);

    return 0;
}

void menu() {
    printf("Menu\n");
    printf("Enter digit(3-4): ");
    scanf("%d", &digit);
}


void get_number() {
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < digit; i++) {
            printf("Player %d, Enter %d-th digit: ", j+1, i);
            scanf("%d", &numbers[player][i]);
        }
        puts("");
    }
}


int check_hit() {
    int hit = 0;
    for (int i = 0; i < digit; i++) {
        if (numbers[player][i] == guess[i]) hit++;
    }
    return hit;
}

int check_borrow() {
    int borrow = 0;
    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < digit; j++) {
            if (i != j && numbers[player][j] == guess[i]) borrow++;    // i != j の処理
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