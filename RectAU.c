#include <stdio.h>

int main() {
    int laenge, breite = 0;
    printf("Bitte Breite eingeben: ");
    scanf("%d", &breite);
    printf("Bitte L�nge eingeben: ");
    scanf("%d", &laenge);
    printf("Fl�che: %d, Umfang: %d", breite*laenge, breite * 2 + laenge * 2);
    return 0;
}
