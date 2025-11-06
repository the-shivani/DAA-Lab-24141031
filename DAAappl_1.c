#include <stdio.h>
#include <string.h>
int binarySearch(char words[][20], int n, char target[]) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(words[mid], target);
        if (cmp == 0)
            return mid;  // Word found
        else if (cmp > 0)
            high = mid - 1;  // Search left half
        else
            low = mid + 1;   // Search right half
    }
    return -1;  // Word not found
}
int main() {
    // Sorted dictionary (alphabetical order)
    char words[][20] = {
        "apple", "ball", "binary", "book", "cat",
        "code", "data", "hello", "world"
    };
    int n = sizeof(words) / sizeof(words[0]);
    char target[20];
    printf("Enter a word to search: ");
    scanf("%s", target);
    int result = binarySearch(words, n, target);
    if (result != -1)
        printf("✅ Word '%s' found at position %d in the dictionary.\n", target, result);
    else
        printf("❌ Word '%s' not found! (Maybe check spelling?)\n", target);

    return 0;
}
