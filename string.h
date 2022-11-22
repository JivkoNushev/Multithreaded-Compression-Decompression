#ifndef STRING
#define STRING

// GET the lenght of a string
size_t strlen_(char *string);

// CONCATENATE two strings
// FIXME: doesn't write to the dest, so the data in the dest is freed
char* strcat_(char *dest, char *src); 

// COPY the string in src to the string in dest
char *strcpy_(char *dest, char *src);

#endif