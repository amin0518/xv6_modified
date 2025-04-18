// we added
#include "user.h"
#include "kernel/types.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("usage: trigger <level> <message>\n");
        exit(1);
    }

    int level = atoi(argv[1]);

    // Build the message from argv[2..argc-1]
    char msg[256] = {0};
    int offset = 0;

    for (int i = 2; i < argc; i++)
    {
        int len = strlen(argv[i]);
        if (offset + len + 1 >= sizeof(msg)) // +1 for space or null terminator
            break;

        memmove(msg + offset, argv[i], len);
        offset += len;

        if (i != argc - 1) // add space between words
            msg[offset++] = ' ';
    }

    msg[offset] = '\0'; // null-terminate

    trigger(level, msg); // syscall
    exit(0);
}
