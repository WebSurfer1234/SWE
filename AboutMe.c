/**
 * file: AboutMe.c
 *
 * date: 2016-10-24
 * progtimeest.: 1 min
 * progtimereal: 1 min
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
    char name[] = "David";
    char lastName[] = "Seidl";
    char matrikelNo[] = "1610555034";
    char email[] = "dseidl.its-b2016@fh-salzburg.ac.at";
    printf("%s, %s\n%s\n%s", lastName, name, matrikelNo, email);
    return 0;
}
