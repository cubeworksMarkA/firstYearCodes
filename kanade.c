#include<stdio.h>
#include<math.h>

int main()
{
    int opp;

    double hypo;
   
    int adj;

    printf("Enter opposite: ");
    scanf("%d",&opp);

    printf("Enter adjacent: ");
    scanf("%d",&adj);


    hypo = sqrt(opp * opp + adj * adj);
    

    printf("Your hypotenuse is %.2f",hypo);

    return 0;

}
