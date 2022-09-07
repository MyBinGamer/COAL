#include <stdio.h>
extern "C" void solution_for_grade_7(const int* arr, size_t arr_rows, size_t arr_cols, int* result);
extern "C" void solution_for_grade_8(const int* arr, size_t arr_rows, size_t arr_cols, int* result);
extern "C" void solution_for_grade_9(const int* arr, size_t arr_rows, size_t arr_cols, int* result);

const size_t ROWS = 2;
const size_t COLS = 3;

int main() {
	int data1[ROWS][COLS] = { { 0, -101, 200 }, { 300, 403, -501 } };
	int result1[ROWS]; // Note: for some variants the result array size depends on the COLS!
    int result2[COLS];
    int result3[COLS];
    solution_for_grade_7((const int*)data1, ROWS, COLS, result1);
    solution_for_grade_8((const int*)data1, ROWS, COLS, result2);
    solution_for_grade_9((const int*)data1, ROWS, COLS, result3);

    // Show the result values:
    for (auto i{ 0U }; i < ROWS; i++)
        printf("%d ", result1[i]);
    printf("\n");

    // Show the result values:
    for (auto i{ 0U }; i < COLS; i++)
        printf("%d ", result2[i]);
    printf("\n");

    // Show the result values:
    for (auto i{ 0U }; i < COLS; i++)
        printf("%d ", result3[i]);
    printf("\n");

    // Use another input array definitions and/or values to demonstrate your solution:
    int data2[ROWS][COLS] = { { 1, 2, -3 }, { 4, 5, -6 } };
    int result4[ROWS];
    int result5[COLS];
    int result6[COLS];
    solution_for_grade_7((const int*)data2, ROWS, COLS, result4);
    solution_for_grade_8((const int*)data2, ROWS, COLS, result5);
    solution_for_grade_9((const int*)data2, ROWS, COLS, result6);
    for (auto i{ 0U }; i < ROWS; i++)
        printf("%d ", result4[i]);
    printf("\n");
    for (auto i{ 0U }; i < COLS; i++)
        printf("%d ", result5[i]);
    printf("\n");
    for (auto i{ 0U }; i < COLS; i++)
        printf("%d ", result6[i]);
    printf("\n");

    // Examples of passing invalid arguments (must not fail for grade 10 solution):
    solution_for_grade_7((const int*)data1, ROWS, 0, 0);
    solution_for_grade_8(nullptr, ROWS, 0, nullptr);
    solution_for_grade_9(nullptr, 0, COLS, result2);
	return 0;
}