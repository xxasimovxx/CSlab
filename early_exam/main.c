#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int f(const char *input, const char *output);

int main(){

  f("number.txt", "output.txt");

  return 0;
}
// Function to evaluate operations from input file and write results to output file
int f(const char *input, const char *output) {
    // Open input and output files
    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    if (fin == NULL || fout == NULL) {
        if (fin != NULL) fclose(fin);
        if (fout != NULL) fclose(fout);
        return -1;  // Error opening files
    }

    char line[256];  // Buffer to hold each line
    int num1, num2, result;
    char op;
    int operations_count = 0;

    // Read each line from the input file
    while (fgets(line, sizeof(line), fin) != NULL) {
        // Use sscanf to parse the line with whitespace handling
        if (sscanf(line, "%d %c %d", &num1, &op, &num2) != 3) {
            fclose(fin);
            fclose(fout);
            return -1;  // Error: line doesn't match the format
        }

        // Perform the operation based on the operator
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    fclose(fin);
                    fclose(fout);
                    return -1;  // Error: division by zero
                }
                result = num1 / num2;
                break;
            default:
                fclose(fin);
                fclose(fout);
                return -1;  // Error: invalid operator
        }

        // Write the result to the output file
        fprintf(fout, "%d\n", result);
        operations_count++;
    }

    // Close files
    fclose(fin);
    fclose(fout);

    // Return the number of operations successfully evaluated
    return operations_count;
}

