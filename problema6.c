#include <stdio.h>
#include <stdlib.h>

int buscar(const int *v, int n, int objetivo, int *posicion) {
    if (v == NULL || n <= 0 || posicion == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == objetivo) {
            *posicion = i;
            return 1;
        }
    }

    return 0;
}

void reemplazar(int *v, int n, int antiguo, int nuevo) {
    if (v == NULL || n <= 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == antiguo) {
            v[i] = nuevo;
        }
    }
}

int main(void) {
    int n;

    printf("Ingrese n (1 a 500): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 500) {
        printf("n debe estar entre 1 y 500.\n");
        return 1;
    }

    int *v = malloc((size_t)n * sizeof(*v));
    if (v == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    printf("Ingrese %d enteros:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &v[i]) != 1) {
            printf("Entrada invalida.\n");
            free(v);
            return 1;
        }
    }

    int objetivo;
    printf("Ingrese el objetivo a buscar: ");
    if (scanf("%d", &objetivo) != 1) {
        printf("Entrada invalida.\n");
        free(v);
        return 1;
    }

    int posicion = -1;
    if (buscar(v, n, objetivo, &posicion)) {
        printf("Encontrado en la posicion %d.\n", posicion);
    } else {
        printf("no encontrado\n");
    }

    int antiguo, nuevo;
    printf("Ingrese el valor a reemplazar y el nuevo valor: ");
    if (scanf("%d %d", &antiguo, &nuevo) != 2) {
        printf("Entrada invalida.\n");
        free(v);
        return 1;
    }

    reemplazar(v, n, antiguo, nuevo);
    printf("Arreglo despues de reemplazar:\n");
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], i == n - 1 ? "\n" : " ");
    }

    free(v);
    return 0;
}