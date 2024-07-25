#include<stdio.h>
#include<stdlib.h>    // to use system() function

int main()
{
    printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");
    char validation,systemType;
    do
    {
        printf("Choose Windows or UNIX(Linux/MacOS) system: ");
        scanf(" %c", &systemType);
    } while (!(systemType=='W'||systemType=='w'||systemType=='U'||systemType=='u'));
    
    if(systemType=='W'||systemType=='w'){

        printf("Do you want to shutdown your pc now(y/n)? ");
        scanf(" %c", &validation);

         if(validation == 'y' || validation == 'Y')
            printf("Shutting down now in\n");
            for (int i =5;i>=1;i--){
                printf("%d....\n",i);
            }
            system("C:\\WINDOWS\\System32\\shutdown -s");

    }else if (systemType=='U'||systemType=='u'){

        printf("Do you want to shutdown your pc now(y/n)?");
        scanf(" %c", &validation);
        if(validation == 'y' || validation == 'Y')
            printf("Shutting down now in\n");
            for (int i =5;i>=1;i--){
                printf("%d....\n",i);
            }
            system("shutdown -h now");
    }
    return 0;
}

    // if(validation == 'y' || validation == 'Y')
    //     system("shutdown -h now");

    //     int num1, num2, sum;
    // printf("Enter first number: ");
    // scanf("%d", &num1);
    // printf("Enter second number: ");
    // scanf("%d", &num2);

    // system("C:\\WINDOWS\\System32\\shutdown -s");

    // sum = num1 + num2;
    // printf("%d", sum);
