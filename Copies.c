#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int fd1, fd2, fd3;
    ssize_t nbyte;
    char buffer[BUF_SIZE];

    if (argc != 4) {
        fprintf(stderr, "Usage: %s file1 file2 file3\n", argv[0]);
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        perror("Error opening file1");
        exit(1);
    }

    fd2 = open(argv[2], O_RDONLY);
    if (fd2 < 0) {
        perror("Error opening file2");
        close(fd1);
        exit(1);
    }
    fd3 = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd3 < 0) {
        perror("Error creating file3");
        close(fd1);
        close(fd2);
        exit(1);
    }
    while ((nbyte = read(fd1, buffer, BUF_SIZE)) > 0) {
        if (write(fd3, buffer, nbyte) != nbyte) {
            perror("Error writing from file1 to file3");
            close(fd1);
            close(fd2);
            close(fd3);
            exit(1);
        }
    }
    while ((nbyte = read(fd2, buffer, BUF_SIZE)) > 0) {
        if (write(fd3, buffer, nbyte) != nbyte) {
            perror("Error writing from file2 to file3");
            close(fd1);
            close(fd2);
            close(fd3);
            exit(1);
        }
    }
    close(fd1);
    close(fd2);
    close(fd3);

    printf("Contents of %s and %s copied into %s successfully.\n", argv[1], argv[2], argv[3]);
    return 0;
}
