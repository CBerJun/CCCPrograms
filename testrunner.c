/*
 * Run test files of CCC.
 * Usage:
 *   testrunner <program file> <sample dir>
 * Program file can be a C or C++ source file (with .cpp or .c).
 * Example:
 *   testrunner ./2023/j1.c path/to/2023_Junior_data/j1
 * This does not work well on PowerShell.
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define DEBUG 0
#define OUTFILE "_runnerout"
#define STDOUTFILE "_runnerstdout.txt"
#define MAX_TESTCASES 100
#define FILE_BUF 512
#define INPUT_SHOW_MAX 4  // 4 * FILE_BUF

// Command line reference: https://cccgrader.com/sample_soln.pdf
const char CC_CMD_CPP[] = "g++ -o " OUTFILE " -O2 -std=c++17 -static %s";
const char CC_CMD_C[] = "gcc -o " OUTFILE " -O2 -lm -static %s";
const size_t CMD_BUF_SIZE = 512 * sizeof(char);

int endswith(char str[], char suffix[]) {
    /* Return 0 if `str` ends with `suffix`. */
    size_t len = strlen(str);
    size_t suffix_len = strlen(suffix);
    if (len < suffix_len) {
        return -1;
    }
    for (size_t i = 0; i < suffix_len; i++) {
        if (str[len - suffix_len + i] != suffix[i]) {
            return -1;
        }
    }
    return 0;
}

int compile(char infile[]) {
    // Compile
    char *compile_cmd = malloc(CMD_BUF_SIZE);
    snprintf(
        compile_cmd, CMD_BUF_SIZE,
        endswith(infile, ".cpp") == 0 ? CC_CMD_CPP : CC_CMD_C,
        infile  /* In file */
    );
#if DEBUG
    printf("Compiling: %s\n", compile_cmd);
#endif
    int result = system(compile_cmd);
    free(compile_cmd);
    return result;
}

typedef struct samples_t {
    char *dirname;
    char *filenames[MAX_TESTCASES];
    int case_no;
} samples_t;

int find_samples(char dirname[], samples_t *samples) {
    int result = 1;
    samples->dirname = malloc(strlen(dirname) + 1);
    strcpy(samples->dirname, dirname);
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory %s\n", dirname);
        goto dir_error;
    }
    struct stat st;
    struct dirent *file = NULL;
    samples->case_no = 0;
    while ((file = readdir(dir)) != NULL) {
        if (endswith(file->d_name, ".in") != 0) {
            // Not a test input file
            continue;
        }
        stat(file->d_name, &st);
        if (S_ISREG(st.st_mode) != 0) {
            // Not a regular file
            continue;
        }
        if (samples->case_no >= MAX_TESTCASES) {
            fprintf(stderr, "Too many testcases. Alter MAX_TESTCASES\n");
            goto too_many_cases;
        }
        int len = strlen(file->d_name) - 3;  // strlen(".in") == 3
        len++;  // Space for '\0'
        samples->filenames[samples->case_no] = malloc(sizeof(char[len]));
        strncpy(samples->filenames[samples->case_no], file->d_name, len);
        samples->filenames[samples->case_no][len-1] = '\0';
        samples->case_no++;
    }
    result = 0;
too_many_cases:
    closedir(dir);
dir_error:
    return result;
}

void run_samples(samples_t *samples) {
    char *run_cmd = malloc(CMD_BUF_SIZE);
    char *filename = malloc(FILENAME_MAX);  // without extension
    char *out_filename = malloc(FILENAME_MAX);
    char *in_filename = malloc(FILENAME_MAX);
    int passed = 0;
    int this_passed;
    // Make sure the output file exists
    fclose(fopen(STDOUTFILE, "w"));
    for (int i = 0; i < samples->case_no; i++) {
        filename[0] = '\0';
        strcat(filename, samples->dirname);
        strcat(filename, "/");
        strcat(filename, samples->filenames[i]);
        strcpy(in_filename, filename);
        strcat(in_filename, ".in");
        strcpy(out_filename, filename);
        strcat(out_filename, ".out");
        run_cmd[0] = '\0';
        strcat(run_cmd, OUTFILE " < ");
        strcat(run_cmd, in_filename);
        strcat(run_cmd, " > ");
        strcat(run_cmd, STDOUTFILE);
#if DEBUG
        printf("Running %s\n", run_cmd);
#endif
        system(run_cmd);
        FILE *fp_expect = fopen(out_filename, "r");
        FILE *fp_actual = fopen(STDOUTFILE, "r");
        if (fp_expect == NULL) {
            fprintf(stderr, "Failed to open %s, skipping\n", out_filename);
            continue;
        }
        char buf1[FILE_BUF], buf2[FILE_BUF];
        this_passed = 1;
        while (fgets(buf1, FILE_BUF, fp_expect) != NULL) {
            fgets(buf2, FILE_BUF, fp_actual);
            if (strcmp(buf1, buf2) != 0) {
                printf("Test case %s failed! T_T\n", samples->filenames[i]);
                // Print input, actual and expected output
                rewind(fp_expect);
                rewind(fp_actual);
                printf("Input:\n");
                FILE *fp_input = fopen(in_filename, "r");
                int input_len = 0;
                while (fgets(buf1, FILE_BUF, fp_input) != NULL) {
                    if (input_len >= INPUT_SHOW_MAX) {
                        printf("(Too long for showing...)\n");
                        break;
                    }
                    printf(buf1);
                    input_len++;
                }
                fclose(fp_input);
                printf("\nExpected:\n");
                while (fgets(buf1, FILE_BUF, fp_expect) != NULL) {
                    printf(buf1);
                }
                printf("\nActual:\n");
                while (fgets(buf2, FILE_BUF, fp_actual) != NULL) {
                    printf(buf2);
                }
                printf("\n");
                this_passed = 0;
                break;
            }
        }
        fclose(fp_expect);
        fclose(fp_actual);
        if (this_passed) {
            passed++;
        }
    }
    printf("%d/%d tests passed.\n", passed, samples->case_no);
    free(run_cmd);
    free(filename);
    free(out_filename);
    free(in_filename);
}

void close_samples(samples_t *samples) {
    for (int i = 0; i < samples->case_no; i++) {
        free(samples->filenames[i]);
    }
    free(samples->dirname);
}

int main(int argc, char *argv[]) {
    int result = 1;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <program file> <sample dir>\n", argv[0]);
        goto cli_error;
    }
    if (compile(argv[1]) != 0) {
        fprintf(stderr, "Failed to compile %s\n", argv[1]);
        goto compile_error;
    }
    // Find samples
    samples_t samples;
    if (find_samples(argv[2], &samples) != 0) {
        goto samples_error;
    }
#if DEBUG
    printf("Test cases found:\n");
    for (int i = 0; i < samples.case_no; i++) {
        printf("  %s\n", samples.filenames[i]);
    }
#endif  /* DEBUG */
    run_samples(&samples);
    result = 0;
samples_error:
    close_samples(&samples);
compile_error:
cli_error:
    return result;
}
