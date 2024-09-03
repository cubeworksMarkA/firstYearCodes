#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

const char *tui = "*********************\n"
                  "*     MAIN MENU     *\n"
                  "*********************\n"
                  "* 1. Addition       *\n"
                  "* 2. Subtraction    *\n"
                  "* 3. Multiplication *\n"
                  "* 4. Division       *\n"
                  "* 5. Exit           *\n"
                  "*********************\n"
                  "choose number (1-5): ";

void continue_block(char *msg)
{
    printf("%s", msg);
    printf("try again? ");
    getch();
}

int *ask_input(int input_len)
{
    char letters[4] = {'a', 'b', 'c', 'd'};
    int *nums = (int *)malloc(input_len * sizeof(int));
    for (int i = 0; i < input_len; i++)
    {
        printf("%c: ", letters[i]);
        scanf("%d", &nums[i]);
    }
    return nums;
}

int main(int argc, char *argv[])
{
    int num_operation = 1;
    int *nums;
    while (num_operation <= 5)
    {
        int operation = 0, res = 0, num_input = 0;
        int *nums;
        num_operation++;
        system("clear");
        printf("%s", tui);
        scanf("%d", &operation);
        if (operation > 5 || operation < 1)
        {
            continue_block("Invalid Input!\n");
            continue;
        }
        switch (operation)
        {
        case 1:
            printf("Addition\n");
            num_input = 2;
            nums = ask_input(num_input);
            for (int i = 0; i < num_input; i++)
            {
                res += nums[i];
            }
            break;
        case 2:
            printf("Subtraction\n");
            num_input = 3;
            nums = ask_input(num_input);
            res = nums[0];
            for (int i = 1; i < num_input; i++)
            {
                res -= nums[i];
            }
            break;
        case 3:
            printf("Multiplication\n");
            num_input = 4;
            nums = ask_input(num_input);
            res = nums[0];
            for (int i = 1; i < num_input; i++)
            {
                res *= nums[i];
            }
            break;
        case 4:
            printf("Division\n");
            num_input = 2;
            nums = ask_input(num_input);
            if (nums[1] == 0)
            {
                continue_block("You can't divide by zero\n");
                free(nums);
                continue;
            }
            res = nums[0];
            for (int i = 1; i < num_input; i++)
            {
                res /= nums[i];
            }
            break;
        case 5:
            printf("Goodbye!\n");
            return 0;
            break;
        }
        printf("result: %d\n", res);
        // reset
        continue_block("");
        free(nums);
    }
    printf("\nGoodbye!");
    sleep(3);
    system("clear");
    return 0;
}