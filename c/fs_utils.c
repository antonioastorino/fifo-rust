#include <sys/stat.h>  /* for stat() and mkfifo() */
#include <sys/types.h> /* for mkfifo() */
#include <stdio.h>     /* for perror() */
#include <unistd.h>    /* for chmod() */
#include <stdlib.h>    /* for exit() */

int make_fifo(char* fifo_path_char_p)
{
    struct stat st;
    // If the file is not present, create it
    if (stat(fifo_path_char_p, &st) < 0)
    {
        if (mkfifo(fifo_path_char_p, 0777) < 0)
        {
            perror("Failed to create FIFO");
            return -1;
        }
    }
    // If it is present, check that it's a fifo
    else if ((st.st_mode & S_IFMT) != S_IFIFO)
    {
        fprintf(stderr, "File present but not a FIFO");
        return -2;
    }
    // TODO(antonio): change permissions may not be required but I don't know why it's there
    //    if (chown(fifo_path_char_p, 1000, 1000) < 0)
    //    {
    //        perror("Failed to set FIFO ownership.");
    //        return -3;
    //    }
    return 0;
}
