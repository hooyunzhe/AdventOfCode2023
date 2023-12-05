#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_calibration_value(char *line)
{
    int i;
    int len;
    int first_digit;
    int last_digit;

    i = 0;
    len = strlen(line);
    first_digit = 0;
    last_digit = 0;
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
    FILE    *ptr;
    char    *line;
    size_t  len;
    ssize_t read;
    int total_calibration_value;

    ptr = fopen("input.txt", "r");
    line = NULL;
    len = 0;
    total_calibration_value = 0;

    while ((read = getline(&line, &len, ptr)) != -1)
        total_calibration_value += get_calibration_value(line);

    printf("Total Calibration Value: %d\n", total_calibration_value);
    fclose(ptr);
}
