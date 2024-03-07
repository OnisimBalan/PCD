#include <stdio.h>
#include <argparse.h>

int main(int argc, char *argv[]) {
    int verbose = 0; // Variabila pentru modul verbose
    char *file_name = NULL; // Variabila pentru numele fisierului
    int number = 0; // Variabilă pentru număr

    // Definirea optiunilor cu ajutorul bibliotecii argparse
    struct argparse_option options[] = {
        OPT_HELP(), // Optiunea de ajutor (--help)
        OPT_BOOLEAN('v', "verbose", &verbose, "Activeaza modul verbose"),
        OPT_STRING('f', "file", &file_name, "Specifica numele fisierului"),
        OPT_INTEGER('n', "number", &number, "Specifica un numar"),
        OPT_END(), // Optiunea finala pentru argparse
    };

    struct argparse argparse;
    argparse_init(&argparse, options, NULL, 0); // Initializarea argparse cu optiunile

    // Parsarea optiunilor din linia de comanda
    argparse_describe(&argparse, "app3", "O aplicatie exemplu folosind argparse.");
    argparse_parse(&argparse, argc, argv);

    // Verificarea optiunilor extrase si afisarea lor
    if (file_name != NULL) {
        printf("Nume fisier: %s\n", file_name);
    }

    if (verbose) {
        printf("Mod verbose activat.\n");
    }

    if (number != 0) {
        printf("Numarul este: %d\n", number);
    }

    return 0;
}


//Modul de rulare
// gcc -o app3 app3.c -largparse
// ./app3 -f file.txt -v -n 10

//eroare: Cred ca pe linux exista probleme cu #include <argparse.h>, am incercat manual sa-l adaug si a mers.
// Dar am incercat la fel intr-o masina virtuala si nu merge