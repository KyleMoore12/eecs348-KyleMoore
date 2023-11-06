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

void printSalesReport(double sales[], char *months[])
{
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%s\t%.2f\n", months[i], sales[i]);
    }
}

void printSalesSummary(double sales[])
{
    double min = sales[0];
    double max = sales[0];
    double total = 0;

    for (int i = 1; i < 12; i++)
    {
        if (sales[i] < min)
        {
            min = sales[i];
        }
        if (sales[i] > max)
        {
            max = sales[i];
        }
        total += sales[i];
    }

    double avg = total / 12;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f\n", min);
    printf("Maximum sales: $%.2f\n", max);
    printf("Average sales: $%.2f\n", avg);
}

void printMovingAverages(double sales[])
{
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++)
    {
        double average = (sales[i] + sales[i + 1] + sales[i + 2] + sales[i + 3] + sales[i + 4] + sales[i + 5]) / 6;
        printf("Month %d - %d: $%.2f\n", i + 1, i + 6, average);
    }
}

void sortSales(double sales[], char *months[])
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = i + 1; j < 12; j++)
        {
            if (sales[i] < sales[j])
            {
                double temp_sales = sales[i];
                sales[i] = sales[j];
                sales[j] = temp_sales;
                char *temp_month = months[i];
                months[i] = months[j];
                months[j] = temp_month;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%s\t%.2f\n", months[i], sales[i]);
    }
}

int main()
{
    double sales[] = {
        23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
        72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    printf("Problem 1:\n");
    printSalesReport(sales, months);
    printSalesSummary(sales);
    printMovingAverages(sales);
    sortSales(sales, months);
    printf("\nProblem 2:\n"); // sales report first then football scores
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
