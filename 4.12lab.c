//本次题目难度较低，固不添加注释
//7.1
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    double sum = 0, sum2 = 0;
    scanf("%d", &n);
    int arr[10000] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    double avg = sum / n;
    for (int i = 0; i < n; i++)
    {
        sum2 += pow(arr[i] - avg, 2);
    }
    double result = sqrt(sum2 / n);
    printf("%.5lf", result);
    return 0;
}

//7.2
#include <stdio.h>
int main()
{
    int arr[50] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i], arr[n-1]);
        n--;
    }
    return 0;
}

//7.3
#include <stdio.h>
int main()
{
    int n, count = 0;
    scanf("%d", &n);
    int arr[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int height;
    scanf("%d", &height);
    height += 30;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= height)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

//7.4
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[10] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] != arr[j])
            {
                sum += arr[i] * 10 + arr[j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}
