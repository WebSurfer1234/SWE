#include <stdio.h>
/**
 * file: swe2.c
 * Aufgabe: Beispiele
 * date: 2016-10-24
 * progtimeest.: 20 min
 * progtimereal: 26 min
 * author: David Seidl
 * email: dseidl.its-b2016@fh-salzburg.ac.at
 *
 * Salzburg University of Applied Sciences
 * Information Technology & Systems Management
 * SWE1-ILV/B, exercise 2
 *
 */
 //gehaltserhoehung
double gehaltsErhoehung(double gehalt) {
    if(gehalt > 1000) {
        return gehalt * 1.0085;
    } else {
        return gehalt * 1.0209;
    }
}

//BMICalc
int bmiCalc() {
    float groesse, gewicht;
    int geschlecht;
    printf("Bitte geben Sie Ihr Gewicht in kg ein: ");
    scanf("%f", &gewicht);
    printf("Bitte geben Sie Ihre Körpergrösse in m ein: ");
    scanf("%f", &groesse);
    printf("Bitte geben Sie Ihr Geschlecht ein 0 = Mann, 1 = Frau:");
    scanf("%d", &geschlecht);
    float bmi = gewicht / (groesse * groesse);
    printf("Der BMI beträgt %.2f --> ", bmi);
    if(bmi < 20 && geschlecht == 0 || bmi < 19 && geschlecht == 1) {
       printf("sind Sie untergewichtig");
    } else if(bmi >= 21 && bmi <= 25 && geschlecht == 0 || bmi >= 20 && bmi <= 24 && geschlecht == 1) {
       printf("sind Sie normalgewichtig");
    } else if(bmi >= 26 && bmi <= 30 && geschlecht == 0 || bmi >= 25 && bmi <= 30 && geschlecht == 1) {
        printf("sind Sie übergewichtig");
    } else if(bmi >= 31 && bmi <= 40) {
        printf("sind Sie fettleibig");
    } else if(bmi > 41) {
        printf("sind Sie krankhaft fettleibig");
    } else {
        printf("sind Sie zwischen zwei Klassen");
    }
    return 0;
}

//GQuadrant
void gQuadrant() {
    int x, y;
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);
    if(x == 0 && y == 0) {
        printf("Der Punkt ist der Ursprung.");
    } else if(x == 0) {
        if(y < 0) {
            printf("Der Punkt liegt auf der y-Achse zwischen 3. und 4. Quadranten.");
        } else {
            printf("Der Punkt liegt auf der y-Achse zwischen 1. und 2. Quadranten.");
        }
    } else if(y == 0) {
        if(x < 0) {
            printf("Der Punkt liegt auf der x-Achse zwischen 2. und 3. Quadranten.");
        } else {
            printf("Der Punkt liegt auf der x-Achse zwischen 1. und 4. Quadranten.");
        }
    } else {
        if(x < 0) {
            if(y < 0) {
                printf("Der Punkt liegt im 3. Quadranten.");
            } else {
                printf("Der Punkt liegt im 2. Quadranten.");
            }
        } else {
            if(y < 0) {
                printf("Der Punkt liegt im 4. Quadranten.");
            } else {
                printf("Der Punkt liegt im 1. Quadranten.");
            }
        }
    }
}

/**
 * file: swe2.c
 * Aufgabe: Arbeitsblatt
 * date: 2016-10-24
 * progtimeest.: 23 min
 * progtimereal: 46 min
 * author: David Seidl
 * email: dseidl.its-b2016@fh-salzburg.ac.at
 *
 * Salzburg University of Applied Sciences
 * Information Technology & Systems Management
 * SWE1-ILV/B, exercise 2
 *
 */

 int counter() {
    int i;
    /*While Schleife*/
    i = 1;
    while(i <= 5) {
        printf("%d\n", i);
        i++;
    }

    printf("\n");

    for(i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    printf("\n");
    i = 0;

    do {
        i++;
        printf("%d\n", i);
    } while(i < 5);
 }

int square() {
    int x, y, size;
    printf("size = ");
    scanf("%d", &size);
    for(x = 0; x < size; x++) {
        for(y = 0; y < size; y++) {
            printf("*");
        }
        printf("\n");
    }
 }

void mycat() {
    int ch;
    int lineNo = 1;
    printf("%06d: ", lineNo);
    while( (ch = fgetc(stdin))!= EOF) {
        fputc(ch, stdout);
        if(ch == '\n') {
            lineNo++;
            printf("%06d: ", lineNo);
        }
    }
 }

int gPow() {
    int x, n;
    double multi;
    double wert;
    printf("Basis = ");
    scanf("%d", &x);
    printf("Exponent = ");
    scanf("%d", &n);

    if(n != 0 && x != 0) {
        wert = 1;
        if(n < 0) {
            multi = 1.0 / x;
            n = -n;
        } else {
            multi = x;
        }
        for(n; n > 0; n--) {
            wert = wert*multi;
        }
    } else if(x == 0) {
        wert = 0;
    } else {
        wert = 1;
    }
    printf("Ergebnis = %lf", wert);
 }

 int querSumme() {
    int x;
    printf("Zahl = ");
    scanf("%d", &x);
    int summe = 0;
    while(x > 0) {
        summe += x % 10;
        x = x / 10;
    }
    printf("Zwischensumme = %d", summe);
 }
