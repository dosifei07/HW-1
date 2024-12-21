#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// №1
void findMinMax(int a, int b, int c, int& min, int& max) {
    min = std::min({ a, b, c });
    max = std::max({ a, b, c });
}

// №2
void countElements(int arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = negativeCount = zeroCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) positiveCount++;
        else if (arr[i] < 0) negativeCount++;
        else zeroCount++;
    }
}

// №3
void sortArray(int arr[], int size, int order = 1) {
    if (order == 1) {
        std::sort(arr, arr + size, std::greater<int>());
    }
    else {
        std::sort(arr, arr + size);
    }
}

// №4
void rollDice(int& playerScore, int& computerScore, int rolls) {
    for (int i = 0; i < rolls; i++) {
        int playerRoll = rand() % 6 + 1;
        int computerRoll = rand() % 6 + 1;
        playerScore += playerRoll;
        computerScore += computerRoll;
        cout << "Кидок " << (i + 1) << ": Гравець: " << playerRoll << ", Комп'ютер: " << computerRoll << endl;
    }
}

void playGame() {
    srand(static_cast<unsigned int>(time(0)));
    int playerScore = 0, computerScore = 0;
    int rolls = 5;

    char firstTurn;
    cout << "Хто кидає першим? (g - гравець, c - комп'ютер): ";
    cin >> firstTurn;

    if (firstTurn == 'g') {
        rollDice(playerScore, computerScore, rolls);
        rollDice(computerScore, playerScore, rolls);
    }
    else {
        rollDice(computerScore, playerScore, rolls);
        rollDice(playerScore, computerScore, rolls);
    }

    cout << "Сумарний рахунок гравця: " << playerScore << endl;
    cout << "Сумарний рахунок комп'ютера: " << computerScore << endl;
    cout << "Середня сума гравця: " << static_cast<double>(playerScore) / rolls << endl;
    cout << "Середня сума комп'ютера: " << static_cast<double>(computerScore) / rolls << endl;
}

// №5
void findMinSumSequence(int arr[], int size) {
    int minSum = INT_MAX;
    int startIndex = 0;

    for (int i = 0; i <= size - 10; i++) {
        int currentSum = 0;
        for (int j = 0; j < 10; j++) {
            currentSum += arr[i + j];
        }
        if (currentSum < minSum) {
            minSum = currentSum;
            startIndex = i;
        }
    }

    cout << "Позиція з мінімальною сумою: " << startIndex << endl;
}

int main() {

    // №1

    int a = 5, b = 10, c = 3, min, max;
    findMinMax(a, b, c, min, max);
    cout << "Min: " << min << ", Max: " << max << endl;

    // №2
    const int size = 10;
    int arr[size] = { 1, -2, 0, 4, -5, 6, 0, -1, 3, 0 };
    int positiveCount, negativeCount, zeroCount;
    countElements(arr, size, positiveCount, negativeCount, zeroCount);
    cout << "Додатні: " << positiveCount << ", Від'ємні : " << negativeCount << ", Нулі: " << zeroCount << endl;

    // №3
    int arrToSort[] = { 5, 2, 9, 1, 5, 6, 3, 8, 7, 4 };
    int arrSize = sizeof(arrToSort) / sizeof(arrToSort[0]);
    sortArray(arrToSort, arrSize, 0);
    cout << "Відсортований масив (зростання): ";
    for (int i : arrToSort) cout << i << " ";
    cout << endl;

    sortArray(arrToSort, arrSize, 1);
    cout << "Відсортований масив (спадання): ";
    for (int i : arrToSort) cout << i << " ";
    cout << endl;

    // №4
    playGame();

    // №5
    const int arraySize = 100;
    int randomArray[arraySize];
    for (int i = 0; i < arraySize; i++) {
        randomArray[i] = rand() % 100 - 50;
    }
    findMinSumSequence(randomArray, arraySize);

    return 0;
}