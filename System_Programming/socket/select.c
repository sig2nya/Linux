#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main()
{
    int fd;
    fd_set readfds;
    struct timeval tv;
    int retval;
    char buf[BUF_LEN];

    fd = STDIN_FILENO;

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        retval = select(fd + 1, &readfds, NULL, NULL, &tv);

        if (retval == -1) {
            perror("select()");
            exit(EXIT_FAILURE);
        } else if (retval) {
            printf("Data is available now.\n");

            if (FD_ISSET(fd, &readfds)) {
                int len = read(fd, buf, BUF_LEN);

                if (len == -1) {
                    perror("read()");
                    exit(EXIT_FAILURE);
                }

                buf[len] = '\0';
                printf("Read %d bytes : %s\n", len, buf);
            }
        } else {
            printf("No Data within %d seconds.\n", TIMEOUT);
        }
    }

    exit(EXIT_SUCCESS);
}
