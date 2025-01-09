#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char inputFile[100], outputFile[100];
    int *numbers = NULL;
    int count = 0, capacity = 10;

    // Allocate initial memory for numbers
    numbers = (int *)malloc(capacity * sizeof(int));
    if (numbers == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Get file names from user
    printf("Enter the input file name: ");
    scanf("%s", inputFile);
    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    // Open the input file
    FILE *inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        perror("Failed to open input file");
        free(numbers);
        return 1;
    }

    // Read integers from the file
    while (fscanf(inFile, "%d", &numbers[count]) == 1) {
        count++;
        if (count >= capacity) {
            capacity *= 2;
            int *temp = realloc(numbers, capacity * sizeof(int));
            if (temp == NULL) {
                perror("Failed to reallocate memory");
                free(numbers);
                fclose(inFile);
                return 1;
            }
            numbers = temp;
        }
    }
    fclose(inFile);

    // Sort the numbers using qsort
    qsort(numbers, count, sizeof(int), compare);

    // Write sorted numbers to the output file
    FILE *outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        perror("Failed to open output file");
        free(numbers);
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(outFile, "%d\n", numbers[i]);
    }
    fclose(outFile);

    // Free allocated memory
    free(numbers);

    printf("Numbers sorted and written to %s\n", outputFile);
    return 0;
}
