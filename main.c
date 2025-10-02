#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    FILE *file = fopen("a2_test.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[256];
    int total_tests = 0;
    int tests_passed = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r') {continue;}

        line[strcspn(line, "\n")] = '\0';

        char function_name[20];
        char input1[100];
        char expected_output[100];

        //checking for each function
        if (sscanf(line, "%s %s %s", function_name, input1, expected_output) == 3) {
            total_tests++;

            if (strcmp(function_name, "oct_to_bin") == 0) {

                char out[100];
                oct_to_bin(input1, out);

                if (strcmp(expected_output, out) == 0) {
                    tests_passed++;
                    printf("Test %d: oct_to_bin(%s) -> Expected: '%s', Got: '%s' [PASS]\n", total_tests, input1, expected_output, out);
                }
                else {
                    printf("Test %d: oct_to_bin(%u) -> Expected: '%s', Got: '%s' [FAIL]\n", total_tests, input1, expected_output, out);
                }
            }

            else if (strcmp(function_name, "oct_to_hex") == 0) {


                char out[100];
                oct_to_hex(input1, out);

                if (strcmp(expected_output, out) == 0) {
                    tests_passed++;
                    printf("Test %d: oct_to_hex(%s) -> Expected: '%s', Got: '%s' [PASS]\n", total_tests, input1, expected_output, out);
                }
                else
                    printf("Test %d: oct_to_hex(%s) -> Expected: '%s', Got: '%s' [FAIL]\n", total_tests, input1, expected_output, out);

            }

            else if (strcmp(function_name, "hex_to_bin") == 0) {

                char out[100];
                hex_to_bin(input1, out);

                if (strcmp(expected_output, out) == 0) {
                    tests_passed++;
                    printf("Test %d: hex_to_bin(%s) -> Expected: '%s', Got: '%s' [PASS]\n", total_tests, input1, expected_output, out);
                }
                else {
                    printf("Test %d: hex_to_bin(%s) -> Expected: '%s', Got: '%s' [FAIL]\n", total_tests, input1, expected_output, out);
                }
            }

            else if (strcmp(function_name, "to_sign_magnitude") == 0) {
                int32_t input = atoi(input1);

                char out[100];
                to_sign_magnitude(input, out);

                if (strcmp(expected_output, out) == 0) {
                    tests_passed++;
                    printf("Test %d: to_sign_magnitude(%s) -> Expected: '%s', Got: '%s' [PASS]\n", total_tests, input1, expected_output, out);
                }
                else {
                    printf("Test %d: to_sign_magnitude(%s) -> Expected: '%s', Got: '%s' [FAIL]\n", total_tests, input1, expected_output, out);
                }
            }

            else if (strcmp(function_name, "to_ones_complement") == 0) {
                int32_t input = atoi(input1);


                char out[100];
                to_ones_complement(input, out);

                if (strcmp(expected_output, out) == 0) {
                    tests_passed++;
                    printf("Test %d: to_ones_complement(%s) -> Expected: '%s', Got: '%s' [PASS]\n", total_tests, input1, expected_output, out);
                }
                else {
                    printf("Test %d: to_ones_complement(%s) -> Expected: '%s', Got: '%s' [FAIL]\n", total_tests, input1, expected_output, out);
                }
            }

            else if (strcmp(function_name, "to_twos_complement") == 0) {
                int32_t input = atoi(input1);


                char out[100];
                to_twos_complement(input, out);

                if (strcmp(expected_output, out) == 0) {
                    tests_passed++;
                    printf("Test %d: to_twos_complement(%s) -> Expected: '%s', Got: '%s' [PASS]\n", total_tests, input1, expected_output, out);
                }
                else {
                    printf("Test %d: to_twos_complement(%s) -> Expected: '%s', Got: '%s' [FAIL]\n", total_tests, input1, expected_output, out);
                }
            }
        }
    }
    printf("Summary: %d/%d tests passed", tests_passed, total_tests);
    return 0;
}