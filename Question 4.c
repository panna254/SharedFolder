#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2, *file3;
    char ch;

    // Open file1 for reading
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        perror("Error opening file1.txt");
        return 1;
    }

    // Open file2 for reading
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        perror("Error opening file2.txt");
        fclose(file1);  // Close file1 before exiting
        return 1;
    }

    // Create file3 for writing
    file3 = fopen("file3.txt", "w");
    if (file3 == NULL) {
        perror("Error creating file3.txt");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file3);
    }

    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, file3);
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);

    printf("Contents of file1 and file2 copied to file3 successfully.\n");
    return 0;
}
