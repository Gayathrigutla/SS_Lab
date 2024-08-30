#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>

#define TIMEOUT_SECONDS 10

int main() {
    fd_set read_fds;
    struct timeval timeout;
    int result;

    // Initialize the fd_set
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    // Set the timeout
    timeout.tv_sec = TIMEOUT_SECONDS;
    timeout.tv_usec = 0;

    // Wait for input on STDIN with a timeout
    result = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    // Check the result
    if (result == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (result == 0) {
        printf("No data available within %d seconds.\n", TIMEOUT_SECONDS);
    } else if (FD_ISSET(STDIN_FILENO, &read_fds)) {
        printf("Data is available on STDIN.\n");
    } else {
        printf("Unexpected outcome.\n");
    }

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/13$ ./a.out
No data available within 10 seconds.
gayathri@alahomora:~/Desktop/SS/13$ ./a.out
Hi
Data is available on STDIN.
*/

