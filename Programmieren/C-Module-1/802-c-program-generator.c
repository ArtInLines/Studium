// C-Program-generator.c

//    This program uses the file-io and string functions to generate text files containing C-programs.
//    As it usually requires some human intelligence to write meaningful C-programs, it is sufficient
//    such that the c-program-generator.c generator 'good-looking nonsense' C-files,
//    i.e. which look like C, can be compiled (and then see what happens...)

//    Who of you generates the most realistically-looking C-programs?

//    Approach:
//    - The C-program-generator uses an input file containing a dictionary of words, which can be used
//    as variable and function names.
//    - It writes its out to the file "great-c-program.c"

//    Extend the program-generator such that it writes more interesting C-Programs.
//    TODO 1: Have a look at the program and understand how it works.
//    TODO 2: Extend the generator functions such that they generate random C-statements, function calls, control structures etc.
//    TODO 3: Think about how program complexity can affect the different generator functions
//    TODO 4: Maintain a list of the defined functions (their names) and use it to generate corresponding function calls
//             and avoid double function definitions.
//    TODO 5: Can you achieve nice formatting such that in generate_function etc. leading tabs/blanks are correctly inserted?
//             (Use a variable which keeps track of the indentation and pass it to the generator functions)

#include <stdio.h>
#include <stdlib.h>


// Data structure to store dictionary
char* dict_memory;
char* dictionary[1000];   // Maximum pointers to 1000 words
int dict_cnt;             // Number of words in dictionary


// Read dictionary from file into dictionary array
int read_dictionary(char* file_name) {
    int i, len;
    FILE* file;

    dict_cnt = 0;
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: can't open dictionary file.\n");
        return 0;
        }
    fseek(file, 0L, SEEK_END);  // Go to end of file
    len = ftell(file);

    dict_memory = malloc(len + 1); // one more byte for 0-Byte at end
    if (dict_memory == NULL) {
        printf("Error: Cannot allocate memory for dictionary\n");
        return 0;
        }
    fseek(file, 0L, SEEK_SET);       // Go to beginning of file
    fread(dict_memory, sizeof(unsigned char), len, file); // file

    i = 0;
    while (i < len) {
        dictionary[dict_cnt++] = dict_memory + i;   // pointer to next string
        // TO DO: also consider newline, tabs, comma etc.
        while (i < len && dict_memory[i] != ' ') i++;

        while (i < len && dict_memory[i] == ' ')
            dict_memory[i++] = 0;
        }
    dict_memory[i] = 0;

    fclose(file);
    return 1;
    }

// Returns a pointer to a random string in the dictionary
char* name_from_dictionary() {
    int i = rand() % dict_cnt;

    return dictionary[i];
    }


// Generates a statement or a block of statements
void generate_statement_or_block(FILE* file, int complexity) {
    int i;

    if (complexity == 0) {   // very simple statement TO DO: randomize
        fprintf(file, "   printf(\"Output is ok.\")");
        }
    else {
        fprintf(file, "\n { \n");
        for (i = 0; i < complexity; i++) {
            // TO DO ..


            }
        fprintf(file, "\n}\n");
        }
    }

void generate_function(FILE* file, int complexity) {
    // TO DO: Generate some comments 
    // Take function name from list of strings 
    fprintf(file, "void %s(int a)\n", name_from_dictionary());
    fprintf(file, "{\n");

    // TO DO: Generate some (random) variable declarations

    // TO DO: Generate some commands


    fprintf(file, "}\n\n");

    }

// Generates the main function
void generate_program_header(FILE* file) {
    fprintf(file, "/* great-c-program.c */\n\n");
    // TO DO: Make header more interesting with some comments, using words from the dictionary

    fprintf(file, "#include <stdio.h>\n\n");
    // TO DO: Maybe include some other header files?
    }


// Generates the main function
void generate_main_function(FILE* file, int complexity) {
    fprintf(file, "\n");
    fprintf(file, "int main()\n{\n");
    generate_statement_or_block(file, complexity);
    fprintf(file, "}\n");
    }


// main
int main() {
    int no_functions = 4, complexity = 3;   // Measures to determine the result's complexity
    int i;
    FILE* file;

    // TO_DO: input of no_functions, complexity

    if (!read_dictionary("802-dictionary.txt"))
        return -1;

    // open file
    file = fopen("great-c-program.c", "w");

    generate_program_header(file);
    for (i = 0; i < no_functions; i++)
        generate_function(file, complexity);

    generate_main_function(file, complexity);
    fclose(file);

    free(dict_memory);
    }
