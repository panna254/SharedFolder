
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2;
    char ch;

    // Open file1 for reading
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        perror("Error opening file1.txt");
        return 1;
    }

    // Open the socond file for copying
    file2 = fopen("file2.txt", "a");
    if (file2 == NULL) {
        perror("Error opening file2.txt");
        fclose(file1);  // Close file1 before exiting
        return 1;
    }

    // copy  file1 contents to file2
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file2);
    }

    // Close files
    fclose(file1);
    fclose(file2);

    printf("Contents of file1 appended to file2 successfully.\n");
    return 0;
}

