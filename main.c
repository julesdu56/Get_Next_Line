
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
        char *line;
        int fd;

        (void)argc;
        fd = open(argv[1], O_RDONLY);
        while (get_next_line(fd, &line) > 0)
        {
                printf("%s\n", line);
                free(line);
        }
        return (0);
}