/*Dada el peso, la altura y el sexo, de unos estudiantes. Determinar la cantidad de vitaminas que
deben consumir estos estudiantes, en base al siguiente criterio: Si son varones, y su estatura es
mayor a 1.60, y su peso es mayor o igual a 150 lb, su dosis, serán: 20% de la estatura y 80% de
su peso. De lo contrario, la dosis será la siguiente: 30% de la estatura y 70% de su peso. Si son
mujeres, y su estatura es mayor de a 1.50 m y su peso es mayor o igual a 130 lb, su dosis será:
25% de la estatura y 75% de su peso. De lo contrario, la dosis será: 35% de la estatura y 65% de
su peso. La dosis debe ser expresada en gramos. La cantidad de vitaminas solo es aplicable a
personas mayores de 18 años.
Además, se solicita el proceso se repita tantas veces como el usuario desee. Es decir, debemos
hacer un proceso repetitivo.*/

#include <stdio.h>
#include <conio.h>

int main() {
    int sexo, edad;
    float estatura, peso, dosis;
    int otroEstudiante;

    int totalEstudiantes = 0;
    int totalHombres = 0;
    int totalMujeres = 0;
    int totalMenoresEdad = 0;  // Nueva variable para contar alumnos menores de edad
    float sumaEstaturaHombres = 0;
    float sumaEstaturaMujeres = 0;
    float sumaPesoHombres = 0;
    float sumaPesoMujeres = 0;
    float sumaDosisHombres = 0;
    float sumaDosisMujeres = 0;

    do {
        do {
            printf("Ingrese el sexo (1 para masculino, 2 para femenino): ");
            scanf("%d", &sexo);

            if (sexo != 1 && sexo != 2) {
                printf("Número de sexo ingresado no válido. Por favor, ingrese 1 o 2.\n");
            }
        } while (sexo != 1 && sexo != 2);

        printf("Ingrese la edad: ");
        scanf("%d", &edad);

        while (edad <= 0 || edad > 100) {
            printf("Edad no válida. Por favor, ingrese una edad válida: ");
            scanf("%d", &edad);
        }

        if (edad >= 18) {
            printf("Ingrese la estatura (metros): ");
            scanf("%f", &estatura);

            while (estatura <= 0.5 || estatura > 2.5) {
                printf("Altura no válida. Por favor, ingrese una altura válida: ");
                scanf("%f", &estatura);
            }

            printf("Ingrese el peso (lb): ");
            scanf("%f", &peso);

            while (peso <= 10 || peso > 1000) {
                printf("Peso no válido. Por favor, ingrese un peso válido: ");
                scanf("%f", &peso);
            }

            if ((sexo == 1 && estatura > 1.60 && peso >= 150) || (sexo == 2 && estatura > 1.50 && peso >= 130)) {
                if (sexo == 1) {
                    dosis = 0.2 * estatura + 0.8 * peso;
                    totalHombres++;
                    sumaEstaturaHombres += estatura;
                    sumaPesoHombres += peso;
                    sumaDosisHombres += dosis;
                } else {
                    dosis = 0.25 * estatura + 0.75 * peso;
                    totalMujeres++;
                    sumaEstaturaMujeres += estatura;
                    sumaPesoMujeres += peso;
                    sumaDosisMujeres += dosis;
                }
            } else {
                if (sexo == 1) {
                    dosis = 0.3 * estatura + 0.7 * peso;
                    totalHombres++;
                    sumaEstaturaHombres += estatura;
                    sumaPesoHombres += peso;
                    sumaDosisHombres += dosis;
                } else {
                    dosis = 0.35 * estatura + 0.65 * peso;
                    totalMujeres++;
                    sumaEstaturaMujeres += estatura;
                    sumaPesoMujeres += peso;
                    sumaDosisMujeres += dosis;
                }
            }

            printf("La cantidad de vitaminas a consumir es: %.2f gramos\n", dosis);
        } else {
            printf("Lo siento, solo se permiten datos de personas mayores de edad.\n");
            totalMenoresEdad++;  // Incrementa el contador de alumnos menores de edad
        }

        totalEstudiantes++;

        printf("¿Desea calcular la dosis para otro estudiante? (1 para sí, 0 para no): ");
        scanf("%d", &otroEstudiante);

    } while (otroEstudiante == 1);

    if (totalEstudiantes > 0) {
        printf("\nResumen:\n");
        printf(" - Total de estudiantes: %d\n", totalEstudiantes);
        printf(" - Total de hombres: %d\n", totalHombres);
        if (totalHombres > 0) {
            printf("   - Altura media: %.2f metros\n", sumaEstaturaHombres / totalHombres);
            printf("   - Peso medio: %.2f lb\n", sumaPesoHombres / totalHombres);
            printf("   - Dosis media: %.2f gramos\n", sumaDosisHombres / totalHombres);
        }
        printf(" - Total de mujeres: %d\n", totalMujeres);
        if (totalMujeres > 0) {
            printf("   - Altura media: %.2f metros\n", sumaEstaturaMujeres / totalMujeres);
            printf("   - Peso medio: %.2f lb\n", sumaPesoMujeres / totalMujeres);
            printf("   - Dosis media: %.2f gramos\n", sumaDosisMujeres / totalMujeres);
        }
        printf(" - Total de alumnos menores de edad: %d\n", totalMenoresEdad);
    }
    getch();
    return 0;
}
