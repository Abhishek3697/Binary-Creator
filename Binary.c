#include<stdio.h>
#include<stdlib.h>
#include<io.h>

void bina(int num, char c);
void main()
{
    int bin[8];
    int num,test;
    char choice;
    FILE *f;

    system("del Binary.txt");
    system("cls");

    printf("E : Even Parity\nO : Odd Parity\nEnter Your Choice : ");
    scanf("%c",&choice);
    f = fopen("input.dat","r");

    fscanf(f,"%d\n",&test);
    while(test > 0)
    {
        fscanf(f,"%d\n",&num);
        printf("%d",num);
        bina(num,choice);
        test--;
    }
    fclose(f);
}

void bina(int num,char c)
{
    FILE *f;
    int bin[8];
    int  i = 0;

    f = fopen("Binary.txt","a");
    for(i =0 ; i < 7; num = num/2,i++)
    {
        printf("%d",num);
        if(num > 0)
            bin[7-i] = num % 2;
        else
            bin[7-i] = 0;
    }

    if(paritycheck(bin) == 1)
        bin[0] = 1;
    else
        bin[0] = 0;

    for(i = 0; i < 8; i++)
    {
        fprintf(f,"%d",bin[i]);
    }
    fprintf(f,"\n");
    fclose(f);
}

int paritycheck(int bin[])
{
    int ret = 0, i;
    for(i = 1; i < 8; i++)
    {
        if(bin[i] == 1)
            ret++;
    }
    ret = ret % 2;
    return ret;
}
