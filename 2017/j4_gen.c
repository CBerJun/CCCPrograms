/* This is not a solution. It's a program that generates the answer. */

#include <stdio.h>
#include <stdlib.h>

const int HOURS[12] = {12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int main(void) {
    FILE *fp = fopen("j4.c", "w");
    fprintf(
        fp,
        "/* Generated by j4_gen.c */\n"
        "#include <stdio.h>\n\n"
        "const int VALS[] = {"
    );
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 60; j++) {
            int digits[4];
            int idx = 0;
            int hour = HOURS[i];
            if (hour < 10) {
                digits[idx++] = hour;
            }
            else {
                digits[idx++] = 1;
                digits[idx++] = hour - 10;
            }
            digits[idx++] = j / 10;
            digits[idx++] = j % 10;
            int delta = digits[1] - digits[0];
            if (digits[2] - digits[1] == delta
                && (
                    (idx == 3)
                    || (idx == 4 && digits[3] - digits[2] == delta)
                )
            ) {
                fprintf(fp, "%d,", i * 60 + j);
            }
        }
    }
    fprintf(fp, "};\n");
    fprintf(
        fp,
        "const int VALS_LEN = sizeof(VALS) / sizeof(VALS[0]);\n\n"
        "int main(void) {\n"
        "    int d;\n"
        "    scanf(\"%%d\", &d);\n"
        "    int days = d / (60 * 12), mins = d %% (60 * 12);\n"
        "    int res = VALS_LEN * days;\n"
        "    for (int i = 0; i < VALS_LEN; i++) {\n"
        "        if (VALS[i] > mins) {\n"
        "            break;\n"
        "        }\n"
        "        res++;\n"
        "    }\n"
        "    printf(\"%%d\\n\", res);\n"
        "}\n"
    );
    fclose(fp);
    return 0;
}
