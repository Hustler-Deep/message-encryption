#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(int l, int col, char* msg, char* enmsg);
int findRow(int col, int l);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage:./(program_name) K \"message\" \n");
        return 1;
    }
    char *c = argv[1];
    char *msg = argv[2];
    int l = strlen(msg);
    int col = *c - '0';
    int row = findRow(col, l);
    char enmsg[(row*col) + 1];
    encrypt(l, col, msg, enmsg);
    printf("Encrypted Message : ");
    printf("%s\n", enmsg);
    return 0;
}

int findRow(int col, int l)
{
    int row;
    if(l%(col) == 0)
    {
        row = l/(col);
    }
    else
    {
        row = (l/(col)) + 1;
    }
    return row;
}

void encrypt(int l, int col, char* msg, char* enmsg)
{
    int row = findRow(col, l);
    int fl = row * col;
    char en[fl + 1];
    for(int i = 0; i < l; i++)
    {
        if(isspace(msg[i]))
        {
            en[i] = '*';
        }
        else
        {
            en[i] = msg[i];
        }
    }
    for(int i = l ; i < fl; i++)
    {
        en[i] = '$';
    }
    int k = 0;
    for(int i = 0; i < col; i++)
    {
        for(int j = row-1; j >= 0; j--)
        {
            enmsg[k]  = en[i + (j*col)];
            k++;
        }
    }
    enmsg[fl] = '\0';
}
