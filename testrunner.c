/*
 * Run test files of CCC.
 *
 * Copyright 2023 CBerJun
 * Licensed under the Apache License, Version 2.0
 *
 * Usage:
 *   testrunner <program file> <sample dir>
 * Program file can be a C, C++, Python or Java source file
 * (with .c, .cpp/.cc, .py or .java extensions, respectively).
 * Example:
 *   testrunner ./2023/j1.c path/to/2023_Junior_data/j1
 * This does not work well on PowerShell.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define DEBUG 0
#define OUT_PROGRAM "_runnerout"
#define OUT_JAVADIR "_runnerjavadir"
#define STDOUTFILE "_runnerstdout.txt"
#define MAX_TESTCASES 100
#define FILE_BUF 512
#define INPUT_SHOW_MAX 4  // 4 * FILE_BUF

// Command line reference: https://cccgrader.com/sample_soln.pdf
const char CC_CMD_CPP[] = "g++ -o " OUT_PROGRAM " -O2 -std=c++17 -static %s";
const char CC_CMD_C[] = "gcc -o " OUT_PROGRAM " -O2 -lm -static %s";
const char CC_CMD_JAVA[] = "javac -d " OUT_JAVADIR " %s";
const char PYTHON[] = "python";
const char JAVA[] = "java";
const size_t CMD_BUF_SIZE = 512 * sizeof(char);

char* view_extension(const char str[]) {
    /*
     * Return the extension of `str`.
     * Example: view_extension("abc.txt") -> ".txt"
     * Note that the returned pointer points to the part of the given
     * `str` so it should not be freed and should not be used when
     * `str` changes.
     */
    return strrchr(str, '.');
}

int compile(const char infile[], const char cmd[]) {
    char *compile_cmd = malloc(CMD_BUF_SIZE);
    snprintf(
        compile_cmd, CMD_BUF_SIZE,
        cmd,
        infile
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

int find_samples(const char dirname[], samples_t *samples) {
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
        char *extension = view_extension(file->d_name);
        if (extension == NULL || strcmp(extension, ".in") != 0) {
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

void run_samples(const samples_t *samples, const char program[]) {
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
        strcat(run_cmd, program);
        strcat(run_cmd, " < ");
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
        samples->filenames[i] = NULL;
    }
    free(samples->dirname);
    samples->dirname = NULL;
}

int main(int argc, char *argv[]) {
    int result = 1;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <program file> <sample dir>\n", argv[0]);
        goto before_samples;
    }
    char *extension = view_extension(argv[1]);
    if (extension == NULL) {
        fprintf(stderr, "Failed to get extension of %s\n", argv[1]);
        goto before_samples;
    }
    const int is_python = (strcmp(extension, ".py") == 0);
    const int is_java = (strcmp(extension, ".java") == 0);
    if (!is_python) {
        const char *cmd = NULL;
        if (strcmp(extension, ".c") == 0) {
            cmd = CC_CMD_C;
        }
        else if (strcmp(extension, ".cpp") == 0
                 || strcmp(extension, ".cc") == 0) {
            cmd = CC_CMD_CPP;
        }
        else if (is_java) {
            cmd = CC_CMD_JAVA;
        }
        else {
            fprintf(stderr, "Failed to recognize extension of %s\n", argv[1]);
            goto before_samples;
        }
        if (compile(argv[1], cmd) != 0) {
            fprintf(stderr, "Failed to compile %s\n", argv[1]);
            goto before_samples;
        }
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
    // Run samples
    char *program = malloc(CMD_BUF_SIZE);
    if (is_python) {
        strcpy(program, PYTHON);
        strcat(program, " ");
        strcat(program, argv[1]);
    }
    else if (is_java) {
        strcpy(program, JAVA);
        strcat(program, " -cp ");
        strcat(program, OUT_JAVADIR " ");
        char *filename = strrchr(argv[1], '/');
        if (filename == NULL) {
            filename = strrchr(argv[1], '\\');
        }
        if (filename == NULL) {
            filename = argv[1];
        }
        else {
            filename++;  // Skip the '/'
        }
        strncat(
            program, filename,
            // Remove .java extension
            strlen(filename) - strlen(extension)
        );
    }
    else {
        // C or C++
        strcpy(program, OUT_PROGRAM);
    }
    run_samples(&samples, program);
    free(program);
    result = 0;
samples_error:
    close_samples(&samples);
before_samples:
    return result;
}
