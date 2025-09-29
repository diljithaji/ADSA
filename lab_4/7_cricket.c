#include <stdio.h>

struct Player {
    char name[50];
    int runs;
    int wickets;
};

int main() {
    int n, i;

    printf("Enter the number of players in the team: ");
    scanf("%d", &n);

    struct Player team[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Entering details for Player %d ---\n", i + 1);
        printf("Name: ");
        scanf(" %s", team[i].name); 
        printf("Runs Scored: ");
        scanf("%d", &team[i].runs);
        printf("Wickets Taken: ");
        scanf("%d", &team[i].wickets);
    }

    int highestRunsIndex = 0;
    
    for (i = 1; i < n; i++) {
        if (team[i].runs > team[highestRunsIndex].runs) {
            highestRunsIndex = i;
        }
    }

    printf("\n\n--- Player with the Highest Runs ---\n");
    printf("Name: %s\n", team[highestRunsIndex].name);
    printf("Runs Scored: %d\n", team[highestRunsIndex].runs);
    printf("Wickets Taken: %d\n", team[highestRunsIndex].wickets);

    return 0;
}