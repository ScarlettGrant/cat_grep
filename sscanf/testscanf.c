#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *str = "0X7C4";
    
    
    unsigned int i_1;
    int res = sscanf(str, "%x", &i_1);
    printf("res = %d, i1 = %u\n", res, i_1);

    // char *buf = "0x3db";
    // long int i = strtol(buf, NULL, 0);
    // printf("%ld", i);

    return 0;
}