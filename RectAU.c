/**
 * file: RectAU.c
 *
 * date: 2016-10-24
 * progtimeest.: 1 min
 * progtimereal: 2 min
 * author: David Seidl
 * email: dseidl.its-b2016@fh-salzburg.ac.at
 *
 * Salzburg University of Applied Sciences
 * Information Technology & Systems Management
 * SWE1-ILV/B, exercise 1
 *
 */

 #include <stdio.h>

int main() {
    int laenge, breite = 0;                                                             //Zuerst werden die Variablen laenge und Breite deklariert
    printf("Bitte Breite eingeben: ");
    scanf("%d", &breite);                                                               //Breite wird eingelesen
    printf("Bitte Länge eingeben: ");
    scanf("%d", &laenge);                                                               //Laenge wird eingelesen
    printf("Fläche: %d, Umfang: %d", breite*laenge, breite * 2 + laenge * 2);           //Flaeche und Umfang werden berechnet und ausgegeben
    return 0;
}
