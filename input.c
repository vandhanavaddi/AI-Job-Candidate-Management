#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

static void discardLine(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
}

int readInt(const char *prompt)
{
    char line[128], *end;
    long value;

    for (;;) {
        printf("%s", prompt);
        if (!fgets(line, sizeof line, stdin)) return 0;
        value = strtol(line, &end, 10);
        if (end != line) {
            while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n')
                ++end;
            if (*end == '\0' && value >= -2147483647L && value <= 2147483647L)
                return (int)value;
        }
        puts("Please enter a valid whole number.");
        if (!strchr(line, '\n')) discardLine();
    }
}

float readFloat(const char *prompt)
{
    char line[128], *end;
    float value;

    for (;;) {
        printf("%s", prompt);
        if (!fgets(line, sizeof line, stdin)) return 0.0f;
        value = strtof(line, &end);
        if (end != line) {
            while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n')
                ++end;
            if (*end == '\0' && value >= 0.0f)
                return value;
        }
        puts("Enter a valid non-negative number.");
        if (!strchr(line, '\n')) discardLine();
    }
}

void readLine(const char *prompt, char *buffer, int capacity)
{
    size_t length;
    int ch;

    printf("%s", prompt);
    if (!fgets(buffer, capacity, stdin)) {
        buffer[0] = '\0';
        return;
    }
    length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    } else {
        while ((ch = getchar()) != '\n' && ch != EOF) { }
    }
}
