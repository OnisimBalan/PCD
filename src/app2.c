#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt;
    char *file_name = NULL;
    int verbose = 0;
    int number = 0;

    // Iteram prin optiunile de linie de comanda
    while ((opt = getopt_long_only(argc, argv, "vf:n", NULL, NULL)) != -1) {
        switch (opt) {
            case 'v': // Optiunea verbose
                verbose = 1;
                break;
            case 'f': // Opsiunea pentru fisier
                file_name = optarg;
                break;
            case 'n': // optiunea pentru numar
                number = atoi(optarg);
                break;
            case '?': // optiune necunoscuta sau eroare
                break;
            default:
                abort(); // Iesire în caz de optiune necunoscuta
        }
    }

    // Afisam informatiile extrase
    if (file_name != NULL) {
        printf("File: %s\n", file_name);
    }

    if (verbose) {
        printf("Verbose mode enabled.\n");
    }

    if (number != 0) {
        printf("Number: %d\n", number);
    }

    return 0;
}

//Modul de rulare
// gcc -o app2 app2.c -std=c99
// ./app2 -f file.txt -v -n 10

