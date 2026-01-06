#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

/**
 * Usage:
 *   ./writer <writefile> <writestr>
 */
int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *writefile = argv[1];
    const char *writestr  = argv[2];

    // Open syslog with LOG_USER facility
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Log debug message
    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", writestr, writefile);

    // Open file for writing (overwrite if exists)
    FILE *fp = fopen(writefile, "w");
    if (!fp) {
        syslog(LOG_ERR, "Error opening file \"%s\": %s", writefile, strerror(errno));
        fprintf(stderr, "Error opening file \"%s\": %s\n", writefile, strerror(errno));
        closelog();
        exit(EXIT_FAILURE);
    }

    // Write the string
    if (fprintf(fp, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error writing to file \"%s\": %s", writefile, strerror(errno));
        fprintf(stderr, "Error writing to file \"%s\": %s\n", writefile, strerror(errno));
        fclose(fp);
        closelog();
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    closelog();

    return EXIT_SUCCESS;
}
