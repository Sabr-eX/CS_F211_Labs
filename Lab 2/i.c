#include <stdio.h>

struct Student
{
    char email[38];
    char branch[4];
    char id[14];
};
typedef struct Student Student;

int main()
{
    Student s;
    scanf("%s", &s.email);
    scanf("%s", &s.branch);
    printf("%s ||| %s\n", s.email, s.branch);
    s.email[37] = 0;
    s.branch[3] = 0;
    s.id[13] = 0;

    for (int i = 1; i < 5; i++)
    {
        s.id[i - 1] = s.email[i];
    }

    if (s.branch[1] == 'S')
    {
        s.id[4] = 'A';
        s.id[5] = '7';
    }
    else if (s.branch[1] == 'C')
    {
        s.id[4] = 'A';
        s.id[5] = 'A';
    }
    else if (s.branch[1] == 'E')
    {
        s.id[4] = 'A';
        s.id[5] = '3';
    }

    s.id[6] = 'P';
    s.id[7] = 'S';

    for (int i = 8; i < 12; i++)
    {
        s.id[i] = s.email[i - 3];
    }
    s.id[12] = 'H';
    for (int i = 0; i < 13; i++)
    {
        printf("%c", s.id[i]);
    }
    return 0;
}