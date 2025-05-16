Description:

This project demonstrates the comparison between a serial and parallel implementation of a palindrome checker using OpenMP in C. 
The program generates a random palindrome string of user-defined length (greater than 10) and checks whether it is a palindrome using both approaches, measuring execution time for each.

👨‍💻 Authors

Deeksha K (4MW23CS033)

Gagana Nayak (4MW23CS039)

Kashish S Salian (4MW23CS056)

Khushi (4MW23CS058)

🛠️ Features

Generates a random palindrome string.
Serial implementation of palindrome check.  
Parallel implementation using OpenMP.
Execution time comparison for both methods.

⚙️ Requirements:

GCC Compiler
OpenMP support (gcc with -fopenmp flag)
C Standard Library

🚀 Compilation & Execution:

Compile:

bash:gcc check_palindrome.c -o check_palindrome -fopenmp

Run:

bash:./check_palindrome

🔸 You will be prompted to enter the length of the string (must be greater than 10).

🧪 Example Output

Enter string length (greater than 10): 100

Generated palindrome string: abccba...

String length: 100

--- Serial Check ---

Is palindrome? Yes

Time taken: 0.000001 seconds

--- Parallel Check ---

Is palindrome? Yes

Time taken: 0.000025 seconds

🔍 Notes

For strings shorter than or equal to 10 characters, the program will exit with a message.
Only the first 50 characters of the generated string are printed for readability.
This implementation is for educational/demonstration purposes.

🌐 Online Compiler

You can also test the code on OnlineGDB.
