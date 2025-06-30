#include<stdio.h>

int main() {
    int i, x;
    char str[100];

    // Get the input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Get the size of the encryption shift
    printf("Enter the encryption key (integer value): ");
    scanf("%d", &x);

    // Encrypt the string
    for(i = 0; (i < 100 && str[i] != '\0'); i++) {
        if(str[i] != '\n') // Avoid encrypting the newline character
            str[i] = str[i] + x;
    }

    printf("Encrypted string: %s\n", str);

    // Decrypt the string
    for(i = 0; (i < 100 && str[i] != '\0'); i++) {
        if(str[i] != '\n') // Avoid decrypting the newline character
            str[i] = str[i] - x;
    }

    printf("Decrypted string: %s\n", str);

    return 0;
}

