#include <Windows.h>
#include <stdio.h>

int main() {
    // Set the input code page to 437 (OEM United States)
    if (!SetConsoleCP(437)) {
        printf("Error setting console input code page\n");
        return 1;
    }

    // Set the output code page to 437 as well
    if (!SetConsoleOutputCP(437)) {
        printf("Error setting console output code page\n");
        return 1;
    }

    printf("Console code page set to 437\n");
    return 0;
}
