#include <stdio.h>

int is_space(char ch)
{
    if (ch == ' ' || ch == '\t')
        return 1;
    else
        return 0;
}

int my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    /* Skip leading spaces and tabs */
    while (is_space(str[i]))
    {
        i++;
    }

    /* Check sign */
    if (str[i] == '+')
    {
        i++;
    }
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    /* Convert digits */
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

double my_atof(const char *str)
{
    int i = 0;
    int sign = 1;
    double result = 0.0;
    double decimal_value = 0.1;

    /* Skip leading spaces and tabs */
    while (is_space(str[i]))
    {
        i++;
    }

    /* Check sign */
    if (str[i] == '+')
    {
        i++;
    }
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    /* Convert integer part */
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    /* Convert decimal part */
    if (str[i] == '.')
    {
        i++;

        while (str[i] >= '0' && str[i] <= '9')
        {
            result = result + (str[i] - '0') * decimal_value;
            decimal_value = decimal_value * 0.1;
            i++;
        }
    }

    return result * sign;
}

int main()
{
    char str1[] = "   12345";
    char str2[] = "   -9876abc";
    char str3[] = " +456xyz";
    char str4[] = "   123.45";
    char str5[] = " -45.67abc";
    char str6[] = " +0.25xyz";
    char str7[] = "   abc123";

    printf("----- MY OWN ATOI() -----\n");

    printf("Input  : \"%s\"\n", str1);
    printf("Output : %d\n\n", my_atoi(str1));

    printf("Input  : \"%s\"\n", str2);
    printf("Output : %d\n\n", my_atoi(str2));

    printf("Input  : \"%s\"\n", str3);
    printf("Output : %d\n\n", my_atoi(str3));

    printf("Input  : \"%s\"\n", str7);
    printf("Output : %d\n\n", my_atoi(str7));

    printf("----- MY OWN ATOF() -----\n");

    printf("Input  : \"%s\"\n", str4);
    printf("Output : %.2lf\n\n", my_atof(str4));

    printf("Input  : \"%s\"\n", str5);
    printf("Output : %.2lf\n\n", my_atof(str5));

    printf("Input  : \"%s\"\n", str6);
    printf("Output : %.2lf\n\n", my_atof(str6));

    printf("Input  : \"abc123\"\n");
    printf("Output : %.2lf\n", my_atof("abc123"));

    return 0;
}
