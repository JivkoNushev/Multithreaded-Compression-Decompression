#ifndef PRINT
#define PRINT
    
typedef enum print_t{T_INT, T_CHAR, T_FLOAT, T_DOUBLE, T_STRING}print_t;

int println(const char *format, ...);
void print_converted(void* num, unsigned int base, print_t ty);

#endif
