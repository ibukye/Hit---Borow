#include <stdio.h>

#define MAX_DIGIT 4

int digit;
int numbers[2][MAX_DIGIT];
int player = 0;     // Indicator of Player1, Player2
int guess;

// Prototype
void menu();
void get_number();
void get_guess();
int check_hit(int [MAX_DIGIT]);
int check_borrow(int [MAX_DIGIT]);


int main() {
    int guess_num;

    menu();
    get_number();


    int hit = 0, borrow = 0;
    while (hit != digit) {
        get_guess();
        int guessed_number[digit];
        for (int i = 0; i < digit; i++) guessed_number[digit-i-1] = guess % 10; guess /= 10;
        borrow = check_borrow(guessed_number);
        hit = check_hit(guessed_number);
        
        
        printf("HIT | BORROW\n %d  |   %d   \n", hit, borrow);

        if (hit == digit) {
            printf("Player %d WIN!!!\n", player+1);
            break;
        }
        player = !(player);
    }
    
    return 0;
}

void menu() {
    printf("Menu\n");
    printf("Enter digit(3-4): ");
    scanf("%d", &digit);
}


void get_number() {
    for (int i = 0; i < 2; i++) {
        int num;
        printf("Player %d: ", i+1);
        scanf("%d", &num);
        for (int j = 0; j < digit; j++) numbers[i][digit-j-1] = num % 10; num /= 10;

        puts("");
    }
}


int check_hit(int guess[MAX_DIGIT]) {
    int hit = 0;
    for (int i = 0; i < digit; i++) {
        if (numbers[!player][i] == guess[i]) hit++;
    }
    return hit;
}

int check_borrow(int guess[MAX_DIGIT]) {
    int borrow = 0;
    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < digit; j++) {
            if (i != j && numbers[!player][j] == guess[i]) borrow++;    // i != j の処理
        }
    }
    return borrow;
}

void get_guess() {
    printf("Player %d, enter guess number: ", player+1);
    scanf("%d", &guess);
}