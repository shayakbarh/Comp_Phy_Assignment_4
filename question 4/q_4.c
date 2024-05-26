#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 10000

double generate_exponential(double lambda) {
    double u = (double)rand() / RAND_MAX;
    return -log(1 - u) / lambda;
}

int main() {
    double lambda = 2.0;
    double samples[NUM_SAMPLES];
    FILE *f = fopen("exponential_samples.txt", "w");
    
    if (f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    for (int i = 0; i < NUM_SAMPLES; i++) {
        samples[i] = generate_exponential(lambda);
        fprintf(f, "%f\n", samples[i]);
    }
    
    fclose(f);
    return 0;
}
