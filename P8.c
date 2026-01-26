#include <stdio.h>
struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    int n;
    float capacity, totalProfit = 0.0;
    struct Item item[20], temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &item[i].weight, &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    // Sort items by profit/weight ratio (descending)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
