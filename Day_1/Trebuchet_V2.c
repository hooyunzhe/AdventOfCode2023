#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void    transform_line(char *line)
{
    int     i = 0;
    char    *num_words[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char    *found = NULL;

    while (i < 9)
    {
        while ((found = strstr(line, num_words[i])))
            found[1] = '1' + i;
        i++;
    }
}

int get_calibration_value(char *line)
{
    int i = 0;
    int len = strlen(line);
    int first_digit = 0;
    int last_digit = 0;

    while (line[i] && (!first_digit || !last_digit))
    {
        if (!first_digit && isdigit(line[i]))
            first_digit = line[i] - '0';
        if (!last_digit && isdigit(line[len - i - 1]))
            last_digit = line[len - i - 1] - '0';
        i++;
    }
    return (first_digit * 10) + last_digit;
}

int main(void)
{
    FILE    *ptr = fopen("input.txt", "r");
    char    *line = NULL;
    size_t  len = 0;
    ssize_t read = 0;
    int total_calibration_value = 0;

    while ((read = getline(&line, &len, ptr)) != -1)
    {
        transform_line(line);
        total_calibration_value += get_calibration_value(line);
    }

    printf("Total Calibration Value: %d\n", total_calibration_value);
    fclose(ptr);
}
