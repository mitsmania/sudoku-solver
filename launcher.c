#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    printf("Choose Mode:\n");
    printf("1. Terminal Mode\n");
    printf("2. GUI Mode\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        system("terminal_app");   // your terminal executable
    }
    else if (choice == 2) {
        system("gui_app");        // your GUI executable
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}