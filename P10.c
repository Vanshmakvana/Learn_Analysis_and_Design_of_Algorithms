#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, amount;
    int coin[20], dp[100];

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    printf("Enter coin values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <= amount; j++)
        {
            if (dp[j - coin[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[amount] == INT_MAX)
        printf("Change not possible\n");
    else
        printf("Minimum coins required = %d\n", dp[amount]);

    return 0;
}
