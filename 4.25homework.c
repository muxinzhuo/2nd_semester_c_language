//TTTFF
//BABBC
//6.1
void sum_diff(float op1, float op2, float *psum, float *pdiff) {
    *psum = op1 + op2;
    *pdiff = op1 - op2;
}

//6.2
void splitfloat( float x, int *intpart, float *fracpart )
{
    *intpart = (int)x;
    *fracpart = x - *intpart;
}

//6.3
void fun(long s, long *t) {
    long temp = 0, base = 1;
    long digits[20];
    int count = 0;

    while (s > 0) {
        int digit = s % 10;
        if (digit % 2 == 0) {
            digits[count++] = digit;
        }
        s /= 10;
    }

    for (int i = count - 1; i >= 0; i--) {
        temp = temp * 10 + digits[i];
    }

    *t = temp;
}

//6.5
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int monthInYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapyear = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        monthInYear[1] = 29;
    }
    int month = 0;
    while (yearday > monthInYear[month])
    {
        yearday -= monthInYear[month];
        month++;
    }
    *pmonth = month + 1;
    *pday = yearday;
}

//6.6
void fun ( double a, double b, double *x, double *y )
{
    *x = a * b;
    *y = a / b;
}