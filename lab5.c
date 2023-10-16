#include <stdio.h>

void calculateCombinations(int score)
{
    for (int td6 = 0; td6 * 6 <= score; td6++) // td no field goal
    {
        for (int td7 = 0; td7 * 7 <= score; td7++) // td with field goal
        {
            for (int td8 = 0; td8 * 8 <= score; td8++) // td with 2pt conversion
            {
                for (int fg = 0; fg * 3 <= score; fg++)
                {
                    for (int safety = 0; safety * 2 <= score; safety++)
                    {
                        int total = td6 * 6 + td7 * 7 + td8 * 8 + fg * 3 + safety * 2;
                        if (total == score)
                        {
                            printf("%d TD, %d TD + FG, %d TD + 2pt, %d FG, %d Safety\n", td6, td7, td8, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int score;
    printf("Enter 0 or 1 to stop\n"); // these scores are invalid
    while (1)
    {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1)
        {
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        calculateCombinations(score);
    }
    return 0;
}
