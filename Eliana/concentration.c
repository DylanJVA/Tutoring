#include <stdio.h>
#include <string.h>
int score = 0;

void initialize() {
    printf("Setting up the game...\n");
}

void teardown() {
    printf("Destroying the game...\n");
}

int * input() {
    static int guesses[2] = {0,0}; 
    do {
        printf("Enter num 1 (1-40, 0 to exit)\n");
        scanf("%d",&guesses[0]);
    } while (guesses[0] > 40 || guesses[0] < 0);

    if (guesses[0] == 0) return guesses;

    do {
        printf("Enter num 2 (1-40, 0 to exit, NOT %d)\n", guesses[0]);
        scanf("%d",&guesses[1]);
    } while (guesses[1] > 40 || guesses[1] < 0 || guesses[1] == guesses[0]);
    
    return guesses;
}

int update(int * nums) { 
    if (nums[1] == 2*nums[0])
    {
        score = score + 1;
        return 1;
    }
    else return 0;
}

void display(int isMatch) {
    if (isMatch == 1) printf("This was a match\n");
    else printf("This wasn't a match\n");
    
    printf("Score: %d\n", score);
}

int main() {
    initialize();
    int flag = 0;
    do {
        int * nums = input();
        if (nums[0] == 0 || nums[1] == 0)
            flag = 1;
        else display(update(nums));
    } while(flag == 0);

    teardown();
}