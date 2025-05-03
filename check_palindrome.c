/* Assignment2 – Serial vs Parallel Implementation using OpenMp
Problem Statement: To check Palindrome
Implementing both:
a. A serial version (without OpenMP)
b. A parallel version (using OpenMP directives)

by Team:Deeksha K(4MW23CS033)
        Gagana Nayak(4MW23CS039)
        Kashish S Salian(4MW23CS056)
        Khushi(4MW23CS058)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>

// Function to generate a palindrome
void generatePalindrome(char *str, int length)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length / 2; i++)
    {
        char ch = charset[rand() % 26];
        str[i] = ch;
        str[length - i - 1] = ch; // Mirror the character to maintain palindrome
    }
    if (length % 2 != 0)
    {
        str[length / 2] = charset[rand() % 26]; // Add a middle character for odd-length strings
    }
    str[length] = '\0'; // Null-terminate the string
}

// Serial palindrome checker
int isPalindromeSerial(const char *str, int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
            return 0; // Not a palindrom
    }
    return 1;
}

// Parallel palindrome checker
int isPalindromeParallel(const char *str, int length)
{
    int isPalindrome = 1;
#pragma omp parallel for
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
// Synchronize threads before updating shared variable
#pragma omp critical
            isPalindrome = 0;
        }
    }
    return isPalindrome;
}

int main()
{
    int length;
    printf("Enter string length (greater than 10): ");
    scanf("%d", &length);

    if (length <= 10)
    {
        printf("Length must be greater than 10.\n");
        return 1;
    }

    char *str = (char *)malloc((length + 1) * sizeof(char));
    srand(time(NULL)); // Seed random number generator

    generatePalindrome(str, length); // Generate a valid palindrome
    printf("Generated palindrome string: ");
    for (int i = 0; i < (length > 50 ? 50 : length); i++)
    {
        printf("%c", str[i]);
    }
    if (length > 50)
        printf("...");
    printf("\nString length: %d\n", length);

    // Serial check
    clock_t start_serial = clock();
    int serial_result = isPalindromeSerial(str, length);
    clock_t end_serial = clock();
    double time_serial = ((double)(end_serial - start_serial)) / CLOCKS_PER_SEC;

    // Parallel check
    clock_t start_parallel = clock();
    int parallel_result = isPalindromeParallel(str, length);
    clock_t end_parallel = clock();
    double time_parallel = ((double)(end_parallel - start_parallel)) / CLOCKS_PER_SEC;

    // Print results
    printf("\n--- Serial Check ---\n");
    printf("Is palindrome? %s\n", serial_result ? "Yes" : "No");
    printf("Time taken: %f seconds\n", time_serial);

    printf("\n--- Parallel Check ---\n");
    printf("Is palindrome? %s\n", parallel_result ? "Yes" : "No");
    printf("Time taken: %f seconds\n", time_parallel);

    // Free allocated memory
    free(str);
    return 0;
}

/*To compile the code {gcc check_palindrome.c -o check_palindrome} and to run code {.\check_palindrome } */
//onlineGDB https://onlinegdb.com/BO4OkMdmh//