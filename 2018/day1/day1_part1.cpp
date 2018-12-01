/* Day 1: Chronal Calibration */
/*           Part One         */
#include <stdio.h>

#define BUFFER_LEN 1000
#define INPUT_FILE "input.txt"

int charArrayToInt(char input[]);

main() {
    FILE *fp;                       // Input file
    char str[BUFFER_LEN];           // Input buffer
    int frequency = 0;              // Result

    fp = fopen(INPUT_FILE, "r");
    if (fp == NULL){
        printf("Could not open file %s\n",INPUT_FILE);
        return 1;
    }
    while (fgets(str, BUFFER_LEN, fp) != NULL) {
        frequency += charArrayToInt(str);
    }
    fclose(fp);
    printf("%d", frequency);
}

int charArrayToInt(char input[]) {
    int result;
    sscanf(input, "%d", &result);
    return result;
}