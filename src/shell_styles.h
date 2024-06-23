#ifndef SHELL_STYLES_H
#define SHELL_STYLES_H

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define KBOLD "\x1B[1m"
#define KRESET "\x1B[0m"

#define kprintf(color, format, ...) \
  do {                              \
    printf("%s", color);            \
    printf(format, ##__VA_ARGS__);  \
    printf("%s", KRESET);           \
  } while (0)

#define kfprintf(file, color, format, ...) \
  do {                                     \
    fprintf(file, "%s", color);            \
    fprintf(file, format, ##__VA_ARGS__);  \
    fprintf(file, "%s", KRESET);           \
  } while (0)

#endif