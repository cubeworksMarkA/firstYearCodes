#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
    int choice = 0;
    int a, b, c, d;
    int sum, difference, product;
    float quotient;

    printf("*********************\n");
    printf("*   MAIN MENU       *\n");
    printf("* 1. ADDITION       *\n");
    printf("* 2. SUBTRACTION    *\n");
    printf("* 3. MULTIPLICATION *\n");
    printf("* 4. DIVISION       *\n");
    printf("* 5. EXIT           *\n");
    printf("*********************\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 5)
    {
        switch (choice)
        {
            case 1:
                system("cls");
                printf("Welcome to Addition\n\n");
                
                printf("Enter value for a: ");
                scanf("%d", &a);

                printf("Enter value for b: ");
                scanf("%d", &b);

                sum = a + b;

                printf("The sum of %d and %d is %d\n", a, b, sum);
                printf("Would you like to try again Y/N:");
                getch();
                break;

            case 2:
                system("cls");
                printf("Welcome to Subtraction\n\n");

                printf("Enter value for a: ");
                scanf("%d", &a);

                printf("Enter value for b: ");
                scanf("%d", &b);

                difference= a - b;

                printf("The difference between  %d and %d is %d", a, b, difference);
                getch();
                break;
                
            case 3:
                system("cls");
                printf("Welcome to Multiplication\n\n");

                printf("Enter value for a: ");
                scanf("%d", &a);

                printf("Enter value for b: ");
                scanf("%d", &b);

                product = a * b;

                printf("The product of %d and %d is %d", a, b, product);
                getch();
                break;

            case 4:
                system("cls");
                printf("Welcome to Quotient\n\n");

                printf("Enter value for a: ");
                scanf("%d", &a);

                printf("Enter value for b: ");
                scanf("%d", &b);

                while (b==0)
                {
                    printf("Error!\n");
                    printf("Enter value for b:");
                    scanf("%d", &b);
                }
                    
                
                quotient = (float)a / b;
                printf("The quotient of %d and %d is %.2f", a, b, quotient);
                getch();
                
                
                
        
    
        }

        system("cls");
        printf("*********************\n");
        printf("*   MAIN MENU       *\n");
        printf("* 1. ADDITION       *\n");
        printf("* 2. SUBTRACTION    *\n");
        printf("* 3. MULTIPLICATION *\n");
        printf("* 4. DIVISION       *\n");
        printf("* 5. EXIT           *\n");
        printf("*********************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        
    }

    

    if (choice != 5) {
            printf("Would you like to try another operation? (1 for YES, 2 for NO): ");
            scanf("%d", &choice);

    while (choice == 1); 

    getch();
    }

}