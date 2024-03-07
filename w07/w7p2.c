/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Chia-Yu Chien
Student ID#: 157049222
Email      : cchien8@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX_PATH_LENGTH 70

#include <stdio.h>

struct PlayerInfo
{
    int lives;
    char ch;
    int treasures;
    int pastPositions[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int remainingMove;
    int pathLength;
    int bombPlacements[MAX_PATH_LENGTH];
    int treasurePlacements[MAX_PATH_LENGTH];
};

int main(void)
{
    int i = 0, j = 0;
    // Game Name Display
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    // Initial Instances
    struct PlayerInfo player = {};
    struct GameInfo game = {};

    // Player Configuration
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    // (1) --- Setup character
    char tempChar;
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &tempChar);
    player.ch = tempChar;
    // (2) --- Setup the number of lives
    int flag = 1;
    do
    {
        int tempNumberLives = 0;
        printf("Set the number of lives: ");
        scanf("%d", &tempNumberLives);
        if (tempNumberLives < 1 || tempNumberLives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }
        else
        {
            player.lives = tempNumberLives;
            flag = 0;
        }
    } while (flag);
    // (3) --- Clean up previous game play
    for (i = 0; i < MAX_PATH_LENGTH; i++)
    {
        player.pastPositions[i] = 0;
    }
    printf("Player configuration set-up is complete\n");
    printf("\n");

    // Game Configuration
    printf("GAME Configuration\n");
    printf("------------------\n");
    // (1) --- Setup path length
    flag = 1;
    do
    {
        int tempPathLength = 0;
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &tempPathLength);
        if (tempPathLength > MAX_PATH_LENGTH || tempPathLength < 10 || tempPathLength % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        else
        {
            game.pathLength = tempPathLength;
            flag = 0;
        }
    } while (flag);
    // (2) --- Setup max move
    flag = 1;
    do
    {
        int tempMaxMove;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &tempMaxMove);
        if (tempMaxMove < 3 || tempMaxMove > game.pathLength * 0.75f)
        {
            printf("    Value must be between 3 and %.f\n", game.pathLength * 0.75f);
        }
        else
        {
            game.remainingMove = tempMaxMove;
            flag = 0;
        }
    } while (flag);
    printf("\n");

    // Bomb Placement
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength / 5; i++)
    {
        if (i == 0)
        {
            printf("   Positions [ %d- %d]: ", (i * 5) + 1, (i * 5) + 5);
        }
        else if (i == 1)
        {
            printf("   Positions [ %d-%d]: ", (i * 5) + 1, (i * 5) + 5);
        }
        else
        {
            printf("   Positions [%d-%d]: ", (i * 5) + 1, (i * 5) + 5);
        }

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.bombPlacements[i * 5 + j]);
        }
    }
    printf("BOMB placement set\n");
    printf("\n");

    // Treasure Placement
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength / 5; i++)
    {
        if (i == 0)
        {
            printf("   Positions [ %d- %d]: ", (i * 5) + 1, (i * 5) + 5);
        }
        else if (i == 1)
        {
            printf("   Positions [ %d-%d]: ", (i * 5) + 1, (i * 5) + 5);
        }
        else
        {
            printf("   Positions [%d-%d]: ", (i * 5) + 1, (i * 5) + 5);
        }

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.treasurePlacements[i * 5 + j]);
        }
    }
    printf("TREASURE placement set\n");
    printf("\n");

    // Configuration End Display
    printf("GAME configuration set-up is complete...\n");
    printf("\n");

    // Settings Display
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.ch);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombPlacements[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasurePlacements[i]);
    }
    printf("\n");
    printf("\n");

    // Game Start Display
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    // Display empty board
    {
        printf("\n");
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10)
            {
                printf("|");
            }
            else
            {
                printf("%d", (i + 1) / 10);
            }
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%d", (i + 1) % 10);
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
               player.lives, player.treasures, game.remainingMove);
        printf("+---------------------------------------------------+\n");
    }

    // Start game loop
    while (game.remainingMove > 0 && player.lives > 0)
    {
        // Let user choose move
        int choseMove = -1;
        int repeat = 0;
        flag = 1;
        do
        {
            printf("Next Move [1-20]: ");
            scanf("%d", &choseMove);
            // user choose move start from 1, should minus one for stardard
            choseMove--;
            if (choseMove < 0 || choseMove >= game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
            // If user choose move has been made before
            else if (player.pastPositions[choseMove])
            {
                flag = 0;
                repeat = 1;
            }
            else
            {
                flag = 0;
                player.pastPositions[choseMove] = 1;
            }
        } while (flag);
        printf("\n");

        if (repeat)
        {
            printf("===============> Dope! You've been here before!\n");
        }
        else if (game.bombPlacements[choseMove] && game.treasurePlacements[choseMove])
        {
            player.lives--;
            player.treasures++;
            game.remainingMove--;
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
        }
        else if (game.bombPlacements[choseMove])
        {
            player.lives--;
            game.remainingMove--;
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
        }
        else if (game.treasurePlacements[choseMove])
        {
            player.treasures++;
            game.remainingMove--;
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
        }
        else
        {
            game.remainingMove--;
            printf("===============> [.] ...Nothing found here... [.]\n");
        }
        printf("\n");

        // Display warning for one live remaing
        if (player.lives == 0)
        {
            printf("No more LIVES remaining!\n");
            printf("\n");
        }
        else if (game.remainingMove == 0)
        {
            printf("No more MOVES remaining!\n");
            printf("\n");
        }

        // Display player's last move
        printf("  ");
        for (i = 0; i <= choseMove; i++)
        {
            if (i == choseMove)
            {
                printf("%c", player.ch);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        // Display player's game path
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if (player.pastPositions[i] == 0)
            {
                printf("-");
            }
            else if (game.bombPlacements[i] && game.treasurePlacements[i])
            {
                printf("&");
            }
            else if (game.bombPlacements[i])
            {
                printf("!");
            }
            else if (game.treasurePlacements[i])
            {
                printf("$");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
        // Display major ruler (the 1st number in every 10 positions)
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10)
            {
                printf("|");
            }
            else
            {
                printf("%d", (i + 1) / 10);
            }
        }
        printf("\n");
        // Display minor ruler (each numeric position starting at 1)
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%d", (i + 1) % 10);
        }
        printf("\n");
        // Display player's statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
               player.lives, player.treasures, game.remainingMove);
        printf("+---------------------------------------------------+\n");
    }
    printf("\n");

    // Display game over
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    printf("\n");
    return 0;
}
