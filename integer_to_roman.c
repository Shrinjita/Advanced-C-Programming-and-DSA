#include <stdio.h>
#include <string.h>
// Define a structure to map Roman numeral symbols to their values
typedef struct {
    int value;
    const char *symbol;
} RomanMapping;
int main() {
    int num;
    scanf("%d", &num);
    // Define the Roman numeral mappings
    RomanMapping romanMap[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    int n = sizeof(romanMap) / sizeof(RomanMapping);
    char romanNumeral[50] = ""; // Resulting Roman numeral string
    int i = 0;
    // Convert the integer to a Roman numeral
    while (num > 0) {
        while (num >= romanMap[i].value) {
            strcat(romanNumeral, romanMap[i].symbol);
            num -= romanMap[i].value;
        }
        i++;
    }
    printf("Roman: %s\n", romanNumeral);
    return 0;
}
