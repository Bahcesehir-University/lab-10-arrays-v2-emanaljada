// ============================================================
//  Lab Title  : Arrays in C++ — Declare, Fill, Process, Analyze
//  Course     : CMP1001 – Introduction to Programming (C++)
//  Duration   : 60 minutes
//  Topic      : Arrays (1-D): declaration, initialization, traversal,
//               searching, sorting, and basic statistics
// ------------------------------------------------------------
//  *** TEACHER VERSION — FULL SOLUTIONS ***
// ============================================================

#include <iostream>
using namespace std;

// ============================================================
//  SECTION 1 — Warm-up
// ============================================================

void warmup_printNumbers()
{
    cout << "\n--- Warm-up 1-A: Print 1 to 10 ---\n";

    // TODO: write a for-loop that prints 1 2 3 4 5 6 7 8 9 10
    for (int i = 1; i <= 10; i++)
    {
        cout << i;
        if (i < 10) cout << " ";
    }
    cout << "\n";
}

void warmup_sumFive()
{
    cout << "\n--- Warm-up 1-B: Sum of 5 numbers ---\n";

    int sum = 0;

    // TODO: declare an integer variable 'num'
    int num;

    cout << "Enter 5 integers:\n";

    // TODO: loop 5 times: read num, add to sum
    for (int i = 0; i < 5; i++)
    {
        cout << "  [" << (i + 1) << "] ";
        cin >> num;
        sum += num;
    }

    // TODO: print sum
    cout << "Sum = " << sum << "\n";
}

// ============================================================
//  SECTION 2 — Core Concepts Demo
// ============================================================

void concepts_demo()
{
    cout << "\n--- Section 2: Core Concepts Demo ---\n";

    // --- GIVEN EXAMPLE (unchanged) ---
    int scores[5] = {90, 75, 88, 62, 95};

    cout << "Scores: ";
    for (int i = 0; i < 5; i++)
    {
        cout << scores[i];
        if (i < 4) cout << ", ";
    }
    cout << "\n";
    cout << "First score : " << scores[0] << "\n";
    cout << "Last score  : " << scores[4] << "\n";

    // TODO 2-A: declare and initialize 'temps'
    int temps[7] = {22, 19, 25, 30, 28, 17, 21};

    // TODO 2-B: print all elements
    cout << "Temperatures: ";
    for (int i = 0; i < 7; i++)
    {
        cout << temps[i];
        if (i < 6) cout << " ";
    }
    cout << "\n";

    // TODO 2-C: change index 3 to 35, then print to verify
    temps[3] = 35;
    cout << "After update, temps[3] = " << temps[3] << "\n";
}

// ============================================================
//  SECTION 3 — Guided Exercises
// ============================================================

// Exercise 3-A
void exercise_fillArray()
{
    cout << "\n--- Exercise 3-A: Fill array from input ---\n";

    const int MAX = 20;
    int grades[MAX];
    int n = 0;

    // TODO: ask the user to enter n; validate range
    do {
        cout << "How many grades (1-20)? ";
        cin >> n;
        if (n < 1 || n > MAX)
            cout << "  Out of range, try again.\n";
    } while (n < 1 || n > MAX);

    // TODO: read n grades
    for (int i = 0; i < n; i++)
    {
        cout << "  Grade [" << (i + 1) << "]: ";
        cin >> grades[i];
    }

    // TODO: print the grades
    cout << "You entered: ";
    for (int i = 0; i < n; i++)
    {
        cout << grades[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}

// Exercise 3-B
void exercise_statistics()
{
    cout << "\n--- Exercise 3-B: Statistics ---\n";

    int data[8] = {34, 67, 23, 89, 12, 55, 78, 45};
    int size = 8;

    // TODO: sum
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += data[i];

    // TODO: average
    double avg = static_cast<double>(sum) / size;

    // TODO: minimum
    int minVal = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] < minVal)
            minVal = data[i];

    // TODO: maximum
    int maxVal = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] > maxVal)
            maxVal = data[i];

    cout << "Sum     : " << sum    << "\n";
    cout << "Average : " << avg    << "\n";
    cout << "Minimum : " << minVal << "\n";
    cout << "Maximum : " << maxVal << "\n";
}

// Exercise 3-C — helper function
// TODO: implement linearSearch
int linearSearch(int arr[], int size, int target)
{
    // TODO: loop; return index if found
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;

    // TODO: return -1 if not found
    return -1;
}

void exercise_search()
{
    cout << "\n--- Exercise 3-C: Linear Search ---\n";

    int values[10] = {5, 12, 8, 3, 27, 19, 6, 44, 31, 7};

    // TODO: search for 27
    int idx = linearSearch(values, 10, 27);
    if (idx != -1)
        cout << "27 found at index " << idx << "\n";
    else
        cout << "27 not found\n";

    // TODO: search for 99
    idx = linearSearch(values, 10, 99);
    if (idx != -1)
        cout << "99 found at index " << idx << "\n";
    else
        cout << "99 not found\n";
}

// Exercise 3-D
void exercise_countChar()
{
    cout << "\n--- Exercise 3-D: Count characters ---\n";

    char text[] = "Abracadabra is a famous magic phrase";
    int  len    = 36;

    // TODO: count 'a' or 'A'
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 'a' || text[i] == 'A')
            count++;
    }

    cout << "Letter 'a'/'A' appears " << count << " times.\n";
}

// Exercise 3-E
void exercise_bubbleSort()
{
    cout << "\n--- Exercise 3-E: Bubble Sort ---\n";

    int arr[9] = {64, 34, 25, 12, 22, 11, 90, 45, 7};
    int size   = 9;

    // TODO: bubble sort — two nested loops + swap
    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int i = 0; i < size - 1 - pass; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int tmp    = arr[i];
                arr[i]     = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }

    // TODO: print sorted array
    cout << "Sorted: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << "\n";
}

// ============================================================
//  SECTION 4 — Challenges
// ============================================================

// Challenge A
void challenge_reverse()
{
    cout << "\n--- Challenge A: Reverse In-Place ---\n";

    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int size   = 7;

    // TODO: swap arr[i] with arr[size-1-i], stop at midpoint
    for (int i = 0; i < size / 2; i++)
    {
        int tmp        = arr[i];
        arr[i]         = arr[size - 1 - i];
        arr[size-1-i]  = tmp;
    }

    cout << "Reversed: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Challenge B
void challenge_removeDuplicates()
{
    cout << "\n--- Challenge B: Remove Duplicates ---\n";

    int original[10] = {4, 7, 2, 4, 9, 7, 3, 2, 8, 4};
    int origSize     = 10;

    int unique[10];
    int uniqueCount  = 0;

    // TODO: for each element check if it's already in unique[]
    for (int i = 0; i < origSize; i++)
    {
        bool found = false;
        for (int j = 0; j < uniqueCount; j++)
        {
            if (unique[j] == original[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            unique[uniqueCount] = original[i];
            uniqueCount++;
        }
    }

    cout << "Unique values (" << uniqueCount << "): ";
    for (int i = 0; i < uniqueCount; i++)
        cout << unique[i] << " ";
    cout << "\n";
}

// ============================================================
//  main
// ============================================================
int main()
{
    cout << "========================================\n";
    cout << "  CMP1001 Lab — Arrays in C++\n";
    cout << "========================================\n";

    warmup_printNumbers();
    warmup_sumFive();

    concepts_demo();

    exercise_fillArray();
    exercise_statistics();
    exercise_search();
    exercise_countChar();
    exercise_bubbleSort();

    challenge_reverse();
    challenge_removeDuplicates();

    cout << "\n========================================\n";
    cout << "  Lab complete — good work!\n";
    cout << "========================================\n";

    return 0;
}
