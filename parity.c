#include <stdio.h>
#include <stdlib.h> /* Atoi */

int lookup[65536];

int precalculated_parity_init() {
    int i, temp, output;
    for(i = 0;i < 65536; i++) {
        temp = i;
        output = 0;
        while(temp) {
            output += temp & 1;
            temp = temp >> 1;
        }
        lookup[i] = output;
    }
    return 0;
}

int main() {
    unsigned long int input;
    int parity;
    precalculated_parity_init();

#if 0
    for(i = 0; i < 16; i++) {
        printf("%d %d \n",i, lookup[i]);
    }
#endif

    scanf("%ld",&input);

    parity = lookup[((input >> 48) & 0xFFFF) ^ ((input >> 32) & 0xFFFF) ^
                    ((input >> 16) & 0xFFFF) ^ (input & 0xFFFF)];

    printf("Parity of input value is %d \n",parity);
    return 0;

}
