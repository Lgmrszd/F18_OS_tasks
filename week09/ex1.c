#include <stdio.h>
#include <stdlib.h>
#define N 50
#define FILENAME "input.txt"

struct lru_page {
    unsigned char counter;
    unsigned char r;
};


int read_r_bit(int page_num, unsigned char *r_bits) {
    int offset = page_num/8;
    int bit_num = page_num - offset*8;
    unsigned char bit_mask = 1<<bit_num;
    return (bit_mask == ( bit_mask & *(r_bits+offset))); 
}

void set_r_bit(int page_num, unsigned char *r_bits) {
    int offset = page_num/8;
    int bit_num = page_num - offset*8;
    unsigned char bit_mask = 1<<bit_num;
    *(r_bits+offset) = *(r_bits+offset) | bit_mask;
}

void reset_r_bit(int page_num, unsigned char *r_bits) {
    int offset = page_num/8;
    int bit_num = page_num - offset*8;
    unsigned char bit_mask = 1<<bit_num;
    *(r_bits+offset) = *(r_bits+offset) & ~bit_mask;
}

void reset_r_bits(unsigned char *r_bits) {
    for (int i=0; i < N; i++) reset_r_bit(i, r_bits);
}


int main() {
    unsigned char *page_counters = malloc(sizeof(unsigned char)*N);
    int *pages = malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) pages[i] = -1;
    int hit = 0;
    int miss = 0;
    int *r_bytes = malloc(sizeof(int));
    *r_bytes = N/8;
    if (*r_bytes * 8 != N) {
        (*r_bytes)++;
    }
    unsigned char *r_bits = calloc(*r_bytes, sizeof(unsigned char));
    free(r_bytes);

    FILE *file = fopen(FILENAME, "r");
    int page_num;
    int found;
    int i;
    while(EOF != fscanf(file, "%d", &page_num)) {
        found = 0;
        i = 0;
        while (i<N & !found) {
            //printf("%d, %d\n", i, pages[i]);
            found = (pages[i] == page_num);
            i++;
        }
        i--; 
        reset_r_bits(r_bits);
        for (int j=0; j<N; j++) {
            page_counters[j] >> 1u;
        }
        if (found) {
            set_r_bit(i, r_bits);
            hit++;
            printf("_hit vnum: %d, pnum: %d\n", page_num, i);
            page_counters[i] = page_counters[i] | 1<<7;
        } else {
            miss++;
            printf("miss vnum: %d, debug: %d", page_num, pages[7]);
            int lowest = 0;
            for (int j=0; j<N; j++) {
                //printf("j: %d, lowest: %d, pc[j]: %d, pc[l]: %d\n", j, lowest, page_counters[j], page_counters[lowest]);
                if(page_counters[j] < page_counters[lowest]) {
                    lowest = j;
                }
            }
            printf(" putted in %d\n", lowest);
            pages[lowest] = page_num;
            page_counters[lowest] = 1<<7;
        }
    }
    printf("%d %d\n", hit, miss);
    printf("Hit/Miss ratio is: %.5f\n", (double)hit/miss);
    return 0;
}
