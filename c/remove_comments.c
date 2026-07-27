#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void removeComments(FILE *fin, FILE *fout) {
    char line[1024];
    bool in_multi_comment = false;

    while (fgets(line, sizeof(line), fin) != NULL) {
        int i = 0;
        int len = strlen(line);
        char cleaned_line[1024];
        int j = 0;
        
        bool in_string = false;
        bool in_char = false;

        while (i < len) {
            if (in_multi_comment) {
                if (line[i] == '*' && i + 1 < len && line[i + 1] == '/') {
                    in_multi_comment = false;
                    i += 2;
                    cleaned_line[j++] = ' '; 
                } else {
                    i++; 
                }
            } else {
                if (!in_char && line[i] == '"') {
                    in_string = !in_string;
                    cleaned_line[j++] = line[i++];
                }
                else if (!in_string && line[i] == '\'') {
                    in_char = !in_char;
                    cleaned_line[j++] = line[i++];
                }
                else if ((in_string || in_char) && line[i] == '\\' && i + 1 < len) {
                    cleaned_line[j++] = line[i++];
                    cleaned_line[j++] = line[i++];
                }
                else if (!in_string && !in_char && line[i] == '/' && i + 1 < len && line[i + 1] == '/') {
                    break; 
                }
                else if (!in_string && !in_char && line[i] == '/' && i + 1 < len && line[i + 1] == '*') {
                    in_multi_comment = true;
                    i += 2; 
                } 
                else {
                    cleaned_line[j++] = line[i++];
                }
            }
        }
        cleaned_line[j] = '\0';
        fputs(cleaned_line, fout);
    }
}

int main(int argc, char *argv[]) {
    FILE *fin = stdin;
    FILE *fout = stdout;

    if (argc > 1) {
        fin = fopen(argv[1], "r");
        if (!fin) {
            perror("Error opening input file");
            return 1;
        }
    }

    if (argc > 2) {
        fout = fopen(argv[2], "w");
        if (!fout) {
            perror("Error opening output file");
            fclose(fin);
            return 1;
        }
    }

    removeComments(fin, fout);

    if (fin != stdin) fclose(fin);
    if (fout != stdout) fclose(fout);

    return 0;
}