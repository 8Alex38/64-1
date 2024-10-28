#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double getMaxAbsoluteElement(const double* arr, int size) {
    double maxElement = fabs(arr[0]);
    for (int i = 1; i < size; ++i) {
        if (fabs(arr[i]) > maxElement) {
            maxElement = fabs(arr[i]);
        }
    }
    return maxElement;
}

int findFirstPositiveIndex(const double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) return i;
    }
    return -1;
}

int findSecondPositiveIndex(const double* arr, int size, int firstPos) {
    for (int i = firstPos + 1; i < size; ++i) {
        if (arr[i] > 0) return i;
    }
    return -1;
}

double calculateSumBetweenPositives(const double* arr, int firstPos, int secondPos) {
    if (firstPos == -1 || secondPos == -1 || secondPos == firstPos + 1) return 0;
    double sum = 0;
    for (int i = firstPos + 1; i < secondPos; ++i) {
        sum += arr[i];
    }
    return sum;
}

void moveNonZeroElements(double* arr, int size, int& nonZeroIndex) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] != 0) {
            arr[nonZeroIndex++] = arr[i];
        }
    }
}

void fillRemainingZeros(double* arr, int size, int nonZeroIndex) {
    while (nonZeroIndex < size) {
        arr[nonZeroIndex++] = 0;
    }
}

void printArray(const double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter array: ";
    cin >> n;

    double* arr = new double[n];
    for (int i = 0; i < n; ++i) {
        cout << "Number " << (i + 1) << ": "; // Prompt for each number
        cin >> arr[i];
    }

    cout << "Original: ";
    printArray(arr, n);

    double maxAbs = getMaxAbsoluteElement(arr, n);
    cout << "Max: " << fixed << setprecision(2) << maxAbs << endl;

    int firstPos = findFirstPositiveIndex(arr, n);
    int secondPos = findSecondPositiveIndex(arr, n, firstPos);
    double sum = calculateSumBetweenPositives(arr, firstPos, secondPos);
    cout << "Sum: " << fixed << setprecision(2) << sum << endl;

    int nonZeroIndex = 0;
    moveNonZeroElements(arr, n, nonZeroIndex);
    fillRemainingZeros(arr, n, nonZeroIndex);

    cout << "Modified array: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
