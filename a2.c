#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define ITERATIONS 10000000

int main() {
    struct timespec start, end;
    long min_time = 1e9;
    long total_time = 0;

    for (int i = 0; i < ITERATIONS; i++) {

        clock_gettime(CLOCK_MONOTONIC, &start);

        // Syscall
        getpid();

        clock_gettime(CLOCK_MONOTONIC, &end);

        long diff = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
        if (diff < min_time) {
            min_time = diff;
        }
        total_time += diff;
    }

    printf("Minimale Latenz: %ld ns\n", min_time);
    printf("Durchschnittliche Latenz: %ld ns\n", total_time / ITERATIONS);
    return 0;
}