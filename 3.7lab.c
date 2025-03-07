//分时计价
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int year, time;
    float reward;
    scanf("%d %d", &year, &time);
    if (year >= 5)//老员工,50r
    {
        if (time <= 40)
        {
            reward = time * 50;
        }
        else
        {
            reward = 2000 + (time - 40) * 1.5 * 50;
        }
    }
    else//新员工，30r
    {
        if (time <= 40)
        {
            reward = time * 30;
        }
        else
        {
            reward = 1200 + (time - 40) * 1.5 * 30;
        }
    }
    printf("%.2f", reward);
    system("pause");
    return 0;
}

//矩形面积计算
#include <stdio.h>
#include <math.h>
int main()
{
    float len, high, x, y, z;
    float ABEF, ECGH, DFHG, FDCE;//面积
    scanf("%f %f %f %f", &len, &high, &x, &y, &z);
    ABEF = (x + y) * high / 2.0;
    FDCE = (len - x + len - y) * high / 2.0;
    ECGH = (len - x) * high / 4.0 + z * 0.5 * ( (y - x) / 2.0 + len - y );//连接CH，分别计算两个三角形面积
    DFHG = FDCE - ECGH;
    printf("Area of ABEF is %.3f\nArea of ECGH is %.3f\nArea of DFHG is %.3f", ABEF, ECGH, DFHG);
    return 0;
}

//谁能进图书馆
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ban, allow, age1, age2;
    int child, adult;
    //获取输入
    scanf("%d %d %d %d", &ban, &allow, &age1, &age2);//小屁孩<禁入年龄线<小孩<陪同年龄线<大人
    if (age1 >= age2)//判断可以入馆的人的编号
    {
        adult = 1;
        child = 2;
    }
    else
    {
        adult = 2;
        child = 1;
    }
    if ((age1 >= ban) && (age2 >= ban))//两个人都不是小屁孩，都可以进
    {
        printf("%d-Y %d-Y\n", age1, age2);
        printf("huan ying ru guan");
    }
    else if ((age1 < ban) && (age2 < ban))//两个人都是小屁孩，不许进
    {
        printf("%d-N %d-N\n", age1, age2);
        printf("zhang da zai lai ba");
    }
    else if ((age1 >= allow && age2 < ban) || (age2 >= allow && age1 < ban))//一个大人带一个小屁孩，都可以进
    {
        printf("%d-Y %d-Y\n", age1, age2);
        printf("qing %d zhao gu hao %d", adult, child);
    }
    else if ((age1 < allow && age2 < ban) || (age2 < allow && age1 < ban))//一个小屁孩一个小孩，小孩进，小屁孩爬
    {
        if (age1 > ban)//判断哪个人是小孩
        {
            printf("%d-Y %d-N\n", age1, age2);
        }
        else
        {
            printf("%d-N %d-Y\n", age1, age2);
        }
        printf("%d: huan ying ru guan", adult);//取上文判断好的，年龄更大的人的编号
    }
    
    return 0;
}

//计算天数
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int year, month, day;
    int add = 0;//一定一定一定要初始化，忘了找半天bug
    scanf("%d/%d/%d", &year, &month, &day);
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 建立数组储存每个月有多少天
    if ((year%4==0 && year%100!=0) || (year%400==0))//判断闰年
    {
        days[2] = 29;//闰年二月变29天
    }
    for (int i = 1; i < month; i++)
    {
        add += days[i];
    }
    add += day;
    printf("%d", add);

    return 0;
}

//日k蜡烛图
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float open, high, low, close;
    scanf("%f %f %f %f", &open, &high, &low, &close);
    if (close < open)
    {
        printf("BW-Solid");
    }
    else if (close > open)
    {
        printf("R-Hollow");
    }
    else
    {
        printf("R-Cross");
    }
    if (low < open && low < close && high > open && high > close)
    {
        printf(" with Lower Shadow and Upper Shadow");
    }
    else if (low < open && low < close)
    {
        printf(" with Lower Shadow");
    }
    else if (high > open && high > close)
    {
        printf(" with Upper Shadow");
    }
    system("pause");
    return 0;
}