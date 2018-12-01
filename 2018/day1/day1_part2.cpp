/* Day 1: Chronal Calibration */
/*           Part Two         */
#include <stdio.h>
#include <set>

#define BUFFER_LEN 1000
#define INPUT_FILE "input.txt"

int charArrayToInt(char input[]);

int main() {
    FILE *fp;                       // Input file
    char str[BUFFER_LEN];           // Input buffer
    int frequency = 0;              // Result
    std::set<int> history;          // Frequency history

    history.insert(frequency);
    while(true) {
        fp = fopen(INPUT_FILE, "r");
        if (fp == NULL){
            printf("Could not open file %s\n",INPUT_FILE);
            return 1;
        }
        while (fgets(str, BUFFER_LEN, fp) != NULL) {
            frequency += charArrayToInt(str);
            if(history.count(frequency) != 0) {
                printf("%d", frequency);
                return 0;
            }
            history.insert(frequency);
        }
        fclose(fp);
    }
}

int charArrayToInt(char input[]) {
    int result;
    sscanf(input, "%d", &result);
    return result;
}