#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int score;
int flag;
int * nums;
struct cardStruct {
        char planet[10];
        int flipped;
    };
typedef struct cardStruct card;

card *cards;
void initialize() {
    printf("Setting up the game...\n");
    srand(time(0));
    score=0;
    flag=0;
    
    cards=(card*)malloc(16*sizeof(card));

    char planets[8][10] = {
        "mercery",
        "venus",
        "earth",
        "mars",
        "jupiter",
        "saturn",
        "uranus",
        "neptune"
                    };


    for (int i=0;i<8;i++)
    {
        int rng = rand()%16;
        while (cards[rng].planet[0]!=0)
        {
            rng=rand()%16;
        }
        strcpy(cards[rng].planet,planets[i]);
        cards[rng].flipped=0;

        rng = rand()%16;
        while (cards[rng].planet[0]!=0)
        {
            rng=rand()%16;
        }
        strcpy(cards[rng].planet,planets[i]);
        cards[rng].flipped=0;
    }
}

void teardown() {
    printf("\nDestroying the game...\n");
    free(cards);
}

int * input() {
    static int guesses[2] = {0,0}; 
    do {
        printf("Enter num 1 (1-16, 0 to exit)\n");
        scanf("%d",&guesses[0]);
    } while (guesses[0] > 16 || guesses[0] < 0 || cards[guesses[0]-1].flipped == 1);

    if (guesses[0] == 0) return guesses;
    printf("Card 1: %s\n",cards[guesses[0]-1].planet);

    do {
        printf("Enter num 2 (1-16, 0 to exit, NOT %d)\n", guesses[0]);
        scanf("%d",&guesses[1]);
    } while (guesses[1] > 16 || guesses[1] < 0 || guesses[1] == guesses[0] || cards[guesses[1]-1].flipped == 1);
    
    return guesses;
}

int update() { 
    if (strcmp(cards[nums[0]-1].planet,cards[nums[1]-1].planet)==0)
    {
        score = score + 1;
        if (score == 8)
        {
            flag=1;
            return 2;
        }
        cards[nums[0]-1].flipped = 1;
        cards[nums[1]-1].flipped = 1;
        return 1;
    }
    else return 0;
}

void printRemaining() {
    printf("Remaining card numbers: ");
    for (int i = 0; i <16; i++)
    {
        if (cards[i].flipped!=1) printf("%d, ",i+1);
    }
}

int display(int isMatch) { 
    if (isMatch==0) 
    {
        printf("Card 2: %s\n",cards[nums[1]-1].planet);
        printf("This wasn't a match\n");
        printf("Score: %d\n", score);
        printRemaining();
        return 0;
    }
    else if (isMatch == 1)
    {
        printf("Card 2: %s\n",cards[nums[1]-1].planet);
        printf("This was a match\n");
        printf("Score: %d\n", score);
        printRemaining();
        return 0;
    }
    else if (isMatch==2)
    {
        char another[3];
        printf("\nCongrats! You won!\n");
        printf("Would you like to play again? yes or no\n");
        scanf("%s", another);
        if (strcmp(another,"yes")==0)
        {
            initialize();
            return 0;
        }
        else return 1;
    }
}

int main() {
    initialize();
    int flag = 0;
    while (flag != 1)
    {
        nums = input();
        if (nums[0] == 0 || nums[1] == 0)
            flag = 1;
        else flag = display(update());
        printf("\n------------------\n");
    } 
    teardown();
}