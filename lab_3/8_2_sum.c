#include <stdio.h>

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                printf("Indices: %d and %d\n", i, j);
                return 0; // found solution, exit program
            }
        }
    }

    printf("No solution found\n");
    return 0;
}
