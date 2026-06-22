#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

void show_intro(void);
int generate_number(void);
int get_guess(void);
int check_guess(int guess, int secret);

int main(void)
{
    int secret = generate_number();
    int guess ;
    int attempts = 0;

    show_intro();

    do {
        guess = get_guess();
        ++attempts;

    }while (!check_guess(guess, secret));

    printf("\nYou guessed it in %d attempts!\n", attempts);

    return 0;
}

void show_intro(void) {
    printf("====================================\n");
    printf("         TRY GUESS THE NUMBER       \n");
    printf("====================================\n");

   printf("Guess a number between %d and %d\n\n", MIN_NUMBER, MAX_NUMBER);
}

int generate_number(void) {
    srand(time(NULL));

    return rand() % MAX_NUMBER + MIN_NUMBER;
}

int get_guess(void) {
    int guess;

    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

int check_guess(int guess, int secret) {
    if (guess < secret) {
        printf("Too low!\n\n");
        return 0;
    }

    if (guess > secret) {
        printf("Too high!\n\n");
        return 0;
    }

    printf("\nCorrect! the number was %d.\n", secret);
    return 1;
}
