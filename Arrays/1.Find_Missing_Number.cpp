
// Approach 1: Prepare a Hash Array for it.



// Approach 2: Sum of N Natural Numbers

/*
    Time Complexity: O( N )
    Space Complexity: O( N )

    Where 'N' is the given input.
*/

int missingNumber(vector<int>&a, int N) {

    int n = N - 1;

    // Initialize an array 'hash' of length
    // 'N'+1 (1- based indexing) with zero.
    int hash[N + 1] = {};

    // Mark element in the hash array.
    for (int i = 0; i < n; i++) {
        hash[ a[i] ] = 1;
    }

    int answer = 1;
    for (int i = 1; i <= N; i++) {

        // If number is not present then
        // update the 'answer' and break.
        if (hash[i] == 0) {
            answer = i;
            break;
        }
    }

    // Return the 'answer' here.
    return answer;
}

// Find the total sum of first 'N' natural number.
    long long total = ((long long)N * (long long) (N + 1)) / 2LL;

    // Find the sum of the array.
    long long arraySum = 0;
    for (int i = 0; i < N - 1; i++) {
        arraySum += a[i];
    }

    // Return the difference of 'total' and 'arraySum'.
    return total - arraySum;


// Approach 3: XOR

/*
    Time Complexity: O( N )
    Space Complexity: O(1)

    Where 'N' is the given input.
*/

int missingNumber(vector<int>&a, int N) {

    // Find the total XOR of first 'N' natural number.
    int XOR1 = 0;

    for (int i = 1; i <= N; i++) {
        XOR1 ^= i;
    }

    // Find the XOR of the array.
    int arrayXor = 0;
    for (int i = 0; i < N - 1; i++) {
        arrayXor ^= a[i];
    }

    // Return the XOR of 'XOR1' and 'arrayXor'.
    return XOR1 ^ arrayXor;
}