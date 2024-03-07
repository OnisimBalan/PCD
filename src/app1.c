#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt;
    int option_index = 0;
    char *file_name = NULL;
    int verbose = 0;
    int number = 0;
    int sum_start = 0; // Pentru inceputul intervalului de suma
    int sum_end = 0;   // Pentru sfsrsitul intervalului de suma
    int sum = 0;       // Pentru stocarea sumei

    static struct option long_options[] = {
        {"file",    required_argument, 0, 'f'},
        {"verbose", no_argument,       0, 'v'},
        {"number",  required_argument, 0, 'n'},
        {"sum",     required_argument, 0, 's'},  // Noua optiune pentru suma
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "vf:n:s:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'f':
                file_name = optarg;
                break;
            case 'v':
                verbose = 1;
                break;
            case 'n':
                number = atoi(optarg);
                break;
            case 's':
                // Parsam intervalul de suma, de exemplu: --sum 1-10
                sscanf(optarg, "%d-%d", &sum_start, &sum_end);
                break;
            case '?':
                // Putetm trata aici optiunile necunoscute sau eronate
                break;
            default:
                abort();
        }
    }

    // Afiaarea informatiilor extrase din argumentele de linie de comanda
    if (file_name != NULL) {
        printf("File name: %s\n", file_name);
    }

    if (verbose) {
        printf("Verbose mode is enabled.\n");
    }

    if (number != 0) {
        printf("Number is: %d\n", number);
    }

    // Se calculeaza suma pentru intervalul specificat
    for (int i = sum_start; i <= sum_end; ++i) {
        sum += i;
    }

    printf("Sum from %d to %d is: %d\n", sum_start, sum_end, sum);

    return 0;
}

//Modul de rulare
// gcc -o app1 app1.c -std=c99
// ./app1 -f file.txt -v -n 10 -s 1-5

