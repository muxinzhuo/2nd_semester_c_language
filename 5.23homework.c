// BBDDB BBDCA
// 6.1
void fun(char *s, char *t)
{
    int i = 0, j = 0;
    while (s[i] != '\0')
    {
        t[j++] = s[i++];
    }
    i--;
    while (i >= 0)
    {
        t[j++] = s[i--];
    }
    t[j] = '\0';
}

// 6.2
void reOut(int (*p)[3])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%3d", p[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 2; i++)
        {
            printf("%3d", p[i][j]);
        }
        printf("\n");
    }
}

// 6.4
void strmcpy(char *t, int m, char *s)
{
    int i = 0;
    if (m <= 0)
    {
        s[0] = '\0';
        return;
    }
    while (t[m - 1] != '\0')
    {
        s[i++] = t[m - 1];
        m++;
    }
    s[i] = '\0';
}

// 6.5
void Shift(char s[])
{
    char temp[4];
    int len = strlen(s);
    temp[0] = s[0];
    temp[1] = s[1];
    temp[2] = s[2];
    temp[3] = '\0';
    for (int i = 3; i <= len; i++)
    {
        s[i - 3] = s[i];
    }
    strcat(s, temp);
}

// 6.6
int search(int list[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i] == x)
            return i;
    }
    return -1;
}
