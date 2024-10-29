#include<stdio.h>
#include<stdlib.h>

void FindLength(char *str)
{
    int i;
    int count = 0;
    for(i=0;str[i]!='\0';i++)
        count++;
    printf("\nThe length of the strength is %d\n", count);
};

void LowerCase(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
        str[i]=str[i]+=32;
    printf("\n%s\n", str);
};

void ReverseString(char *str)
{
    char t;
    int i, j;
    for (j = 0; str[j] != '\0'; j++)
        ;
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    printf("\n%s\n", str);
}

void FindDuplicates(char *str)
{
    int count[256] = {0}; // Assuming ASCII characters
    for (int i = 0; str[i] != '\0'; i++)
    {
        count[(int)str[i]]++;
    }
    printf("\nDuplicates characters in the string are: \n");
    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 1)
        {
            printf("%c ", i);
        }
    }
}

void Permutation(char s[], int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i;
    
    if (s[k] == '\0')
    {
        Res[k] = '\0';
        printf("%s\n", Res);
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                Permutation(s, k + 1);
                A[i] = 0;
            }
        }
    }
} 

int main()
{
    char wel[] = "WELCOME";
    FindLength(wel);
    LowerCase(wel);
    ReverseString(wel);
    FindDuplicates(wel);
    char s[] = "ABC";
    Permutation(s, 0);
    return 0;
}