// cflags: -fno-schedule-insns -fno-schedule-insns2

// MATCH func_0018A298
long file_0018a298(char **cursor)
{
    unsigned long result = 0;
    int shift;
    char *p;

    for (shift = 56; shift >= 0; shift -= 8) {
        char c;

        p = *cursor;
        {
            unsigned long digit = (unsigned long)(long)*p << shift;
            char *next = p + 1;

            result |= digit;
            *cursor = next;
        }
        c = p[1];
        if (c == 0x2f) {
            *cursor = p + 2;
            break;
        }
        if (c == 0x2e || c == 0) {
            *cursor = 0;
            break;
        }
    }
    return (long)result;
}
