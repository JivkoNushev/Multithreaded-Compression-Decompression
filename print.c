#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "print.h"

void print_converted(void* num, unsigned int base, print_t ty)
{
    char representation[] = "0123456789ABCDEF";
    char buffer[22];
    char *ptr, *start = buffer;

    switch (ty)
    {
    case T_DOUBLE:
    {
        ptr = buffer;

        double number = *(double*)num;
        unsigned int l_count = 0;
        for(double temp_num = number ; 1 < temp_num ; temp_num /= 10, l_count++);

        double temp_num = number;
        for (char *start = ptr + l_count; start > ptr;)
        {
            *--start = representation[(int)temp_num % base];
            temp_num /= base;
        }
        ptr+=l_count;

        *ptr++ = '.';
        temp_num = number*base + 0.0000001;
        for (int i = 0; i < 6; i++)
        {
            *ptr++ = representation[(int)temp_num % base];
            temp_num *= base;
        }
        
        *ptr++ = '\0';
        ptr = start;
    }
        break;
    case T_INT:
    {
        int number = *(int*)num;
        ptr = &buffer[21];
        *ptr = '\0';

        do
        {
            *--ptr = representation[number % base];
            number /= base;
        } while (0 != number);
    }
        break;
    default:
        puts("Error: Wrong input type");
        exit(-1);
    }
    
    int print_status = 0;
    if(EOF == (print_status = puts(ptr)))
    {
        puts("EOF Error at conversion\n");
        exit(-1);
    }
    if(0 > print_status)
    {
        puts("Couldn't write to stdout\n");
        exit(-1);
    }
}

int println(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    if (NULL == format)
    {
        printf("Data is NULL\n");
        return -1;
    }

    int print_status = 0;
    int input_ui = 0;
    double input_d = 0.;
    char *input_s = 0;
    for (char *str = (char *)format; *str != '\0'; str++)
    {
        if (*str != '%')
        {
            if (EOF == (print_status = putchar(*str)))
            {
                puts("EOF Error");
                exit(-1);
            }
            continue;
        }
        str++;

        switch (*str)
        {
        case 'd':
            input_ui = va_arg(args, int);
            if (0 > input_ui)
            {
                input_ui = -input_ui;
                putchar('-');
            }
            print_converted((void*)&input_ui, 10, T_INT);
            break;
        case 'f':
            input_d = va_arg(args, double);
            if (0 > input_d)
            {
                input_d = -input_d;
                putchar('-');
            }
            print_converted((void*)&input_d, 10, T_DOUBLE);
            break;
        case 's':
            input_s = va_arg(args, char *);
            puts(input_s);
            break;
        case 'c':
            input_ui = va_arg(args, int);
            if (0 > input_ui)
                input_ui = -input_ui;
            putchar(input_ui);
            break;
        default:
            putchar('%');
            putchar(*str);
        }
    }

    va_end(args);
    return 0;
}
