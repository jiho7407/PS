#include <iostream>
#include <vector>

int countEvenIntervalsContainingX(const std::vector<int>& indices, int x) {
    int n = indices.size();
    int leftOdd = 0, leftEven = 0;
    int rightOdd = 0, rightEven = 0;
    int result = 0;

    // Count indices to the right of x that are odd and even
    for (int i = 0; i < n; ++i) {
        if (indices[i] > x) {
            rightEven++; // Before any intervals have been formed
        }
    }

    // Iterate through the indices to compute intervals
    for (int i = 0; i < n; ++i) {
        if (indices[i] > x) {
            if ((rightEven - rightOdd) % 2 == 0) {
                result += leftEven;
            } else {
                result += leftOdd;
            }
            // Update the counts as we pass an index
            rightEven--;
            rightOdd++;
        } else if (indices[i] < x) {
            if ((leftEven - leftOdd) % 2 == 0) {
                result += rightEven;
            } else {
                result += rightOdd;
            }
            // Update the counts as we pass an index
            leftOdd++;
            leftEven--;
        }

        // Update counts after processing each index
        std::swap(leftEven, leftOdd);
        std::swap(rightEven, rightOdd);
    }

    return result;
}

int main() {
    std::vector<int> indices = {0, 4, 7, 11, 13};
    int x = 7; // The index to find intervals for
    int result = countEvenIntervalsContainingX(indices, x);
    std::cout << "Number of even-numbered intervals containing " << x << ": " << result << std::endl;
    return 0;
}
