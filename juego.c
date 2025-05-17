// JUEGO DEL AHORCADO CON LECTURA DE PALABRAS DESDE FICHERO
// MAS DETALLES EN MI PAGINA WEB PROGRAMADOREC.COM

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

// PROTOTIPOS DE LAS FUNCIONES
long obtenerPalabraAleatoria(char fichero[], char palabra[]);
void empezarJuego(char palabra[]);
void dibujo(int intentos);

// FUNCION PRINCIPAL MAIN
int main() {
    system("mode con cols=80 lines=25");
    char nombreFichero[255];
    char palabraSeleccionada[30];
    long numeroPalabras;

    printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
    printf("Introduce el nombre del fichero de palabras: ");
    scanf("%s", nombreFichero);

    numeroPalabras = obtenerPalabraAleatoria(nombreFichero, palabraSeleccionada);

    if (numeroPalabras == 0) {
        printf("\nError al procesar el fichero %s\n", nombreFichero);
    } else {
        printf("\nSe encontraron %ld palabras en el fichero.\n", numeroPalabras);
        for (int i = 0; palabraSeleccionada[i] != '\0'; i++) {
            palabraSeleccionada[i] = toupper(palabraSeleccionada[i]);
        }
        empezarJuego(palabraSeleccionada);
    }

    system("pause");
    return 0;
}

// FUNCION QUE OBTIENE UNA PALABRA ALEATORIA DESDE UN FICHERO
long obtenerPalabraAleatoria(char fichero[], char palabra[]) {
    FILE *ptr;
    long num_pal = 0;
    long indiceAleatorio;

    srand(time(NULL));

    ptr = fopen(fichero, "r");

    if (ptr == NULL) {
        return 0;
    } else {
        // Contar el número de palabras en el fichero
        while (fscanf(ptr, "%s", palabra) == 1) {
            num_pal++;
        }

        if (num_pal > 0) {
            // Generar un índice aleatorio
            srand(time(NULL)); // Reinicializar la semilla para una nueva secuencia
            indiceAleatorio = rand() % num_pal;

            // Volver al inicio del fichero
            rewind(ptr);

            // Leer la palabra en el índice aleatorio
            for (long i = 0; i <= indiceAleatorio; i++) {
                fscanf(ptr, "%s", palabra);
            }
        }

        fclose(ptr);
        return num_pal;
    }
}

// FUNCION QUE CONTIENE EL ALGORITMO DEL JUEGO
void empezarJuego(char palabra[]) {
    int i, j, longitud, espacios, puntos = 1500;
    char letra;
    int aciertos = 0;
    int intentos = 0;
    longitud = strlen(palabra);
    char frase[longitud];

    // SE COLOCAN GUIONES BAJOS EN EL ARRAY DE CARACTERES FRASE
    for (i = 0; i < longitud; i++) {
        frase[i] = '_';
    }

    do {
        aciertos = 0;
        system("cls");
        printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
        printf("Intentos Disponibles: %i\t\t\t\tPuntuacion: %i\n\n", 10 - intentos, puntos);
        dibujo(intentos);

        // IMPRIME EL ARRAY DE CARACTERES FRASE
        printf("\n\n\n");
        for (i = 0; i < longitud; i++) {
            printf(" %c ", frase[i]);
        }

        if (intentos == 10) {
            printf("\n\n PERDISTE!!\n");
            printf(" LA SOLUCION ERA: %s\n\n", palabra);
            printf(" Presiona una tecla para volver a jugar..");
            getch();
            main(); // Volver al inicio para elegir otro fichero
            return;
        }

        // PROCESO QUE COMPRUEBA SI SE HA ADIVINADO LA PALABRA
        espacios = 0;
        for (i = 0; i < longitud; i++) {
            if (frase[i] == '_')
                espacios++;
        }

        if (espacios == 0) {
            printf("\n\n FELICIDADES.. GANASTE!!\n\n");
            printf(" Presiona una tecla para volver a jugar..");
            getch();
            main(); // Volver al inicio para elegir otro fichero
            return;
        }

        printf("\n\n Digite una letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra); // Convertir la letra a mayúscula
        // PROCESO QUE VERIFICA SI LA LETRA YA HA SIDO INGRESADA

        // PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA,
        // SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA
        for (j = 0; j < longitud; j++) {
            if (letra == palabra[j]) {
                frase[j] = letra;
                aciertos++;
            }
        }

        if (aciertos == 0) {
            intentos++;
            puntos -= 100; // Restar puntos por cada intento fallido
            printf("\n\n Letra incorrecta, intenta de nuevo.\n");
        }

    } while (intentos != 11);

    printf("\n\n");
}

// FUNCION QUE REALIZA EL DIBUJO DE EL AHORCADO, RECIBE EL NUMERO DE INTENTOS
// Y CON ESE DATO REALIZA EL DIBUJO
void dibujo(int intentos) {
    switch (intentos) {
    case 0:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 1:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 2:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |       |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 3:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |      /|");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 4:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |      /|\\");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 5:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |      /|\\");
        printf("\n    |       |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 6:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |      /|\\");
        printf("\n    |       |");
        printf("\n    |      /");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 7:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |      /|\\");
        printf("\n    |       |");
        printf("\n    |      / \\");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 8:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |     _/|\\");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 9:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |     _/|\\_");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    case 10:
        printf("\n     _______");
        printf("\n    |       |");
        printf("\n    |       O");
        printf("\n    |     _/|\\_");
        printf("\n    |       |");
        printf("\n    |      / \\");
        printf("\n    |");
        printf("\n    |");
        printf("\n    |");
        printf("\n----------");
        break;
    }
}