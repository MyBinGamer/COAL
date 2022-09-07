#include <cstdio>
#include <cassert>

// For each grade level variant implement separate function, e.g.:
// arr – the parameter that points to the pointer of the beginning of the two-dimension array
// arr_rows – assumes the count of rows in the array
// arr_cols – assumes the count of columns in the array
// result – assumes the pointer to the beginnin of the one-dimension array, where the result
// values are to be placed. It’s size is assumed to be either equal to arr_rows or arr_cols,
// depending on an algorithm
void solution_for_grade_7(const int* arr, size_t arr_rows, size_t arr_cols, int* result)
{
    const char* error = "Error: Invalid Input\n";
    //Calculate the sum of positive elements for each row
    __asm {
        cmp [arr], 0
        je fail
        cmp [arr_rows], 0
        jle fail
        cmp [arr_cols], 0
        jle fail
        cmp [result], 0
        je fail
        mov eax, [arr]
        mov ecx, [arr_rows]
        xor edi, edi
        row_loop:
            push ecx
            xor esi, esi
            xor ebx, ebx // Sum
            mov ecx, [arr_cols]
        col_loop:
            cmp dword ptr [eax+esi], 0
            jle negative
            add ebx, [eax+esi]
        negative:
            add esi, 4
            loop col_loop
            add eax, esi
            mov edx, result
            mov [edx+edi*4], ebx
            inc edi
            pop ecx
            loop row_loop
            jmp done
        fail:
            push [error]
            call printf
            pop edi
        done:
    }
}
void solution_for_grade_9(const int* arr, size_t arr_rows, size_t arr_cols, int* result)
{
    const char* error = "Error: Invalid Input\n";
    //Count the number of even elements for each column
    __asm {
        cmp[arr], 0
        je fail
        cmp[arr_rows], 0
        jle fail
        cmp[arr_cols], 0
        jle fail
        cmp[result], 0
        je fail
        xor esi, esi
        mov ecx, [arr_cols]
        xor edi, edi
        col_loop :
            push ecx
            mov eax, [arr]
            push esi
            xor ebx, ebx //count for col
            mov ecx, [arr_rows]
        row_loop :
            test dword ptr[eax+esi*4], 1
            jnz odd
            inc ebx
        odd :
            add esi, [arr_cols]
            loop row_loop
            mov eax, result
            mov[eax + edi * 4], ebx
            pop esi
            inc esi
            inc edi
            pop ecx
            loop col_loop
            jmp done
        fail :
            push[error]
            call printf
            pop edi
        done :
    }
}
// write solution for grade 10 here
void solution_for_grade_10(const int* arr, size_t arr_rows, size_t arr_cols, int* result)
{
    const char* error = "Error: Invalid Input\n";
    //Find the minimum positive element for each column
    __asm {
        cmp[arr], 0
        je fail
        cmp[arr_rows], 0
        jle fail
        cmp[arr_cols], 0
        jle fail
        cmp[result], 0
        je fail
        xor esi, esi
        mov ecx, [arr_cols]
        xor edi, edi
        col_loop :
        push ecx
            mov eax, [arr]
            xor ebx, ebx // min = 0
            push esi
            mov ecx, [arr_rows]
        row_loop :
            cmp dword ptr [eax+esi*4], 0
            jle skip
            cmp ebx, 0
            je min_found
            cmp dword ptr[eax + esi * 4], ebx
            jge skip
        min_found :
            mov ebx, dword ptr[eax + esi * 4]
        skip :
            add esi, [arr_cols]
            loop row_loop
            mov eax, result
            mov[eax + edi * 4], ebx
            pop esi
            inc esi
            inc edi
            pop ecx
            loop col_loop
            jmp done
        fail :
            push[error]
            call printf
            pop edi
        done :
    }
}
const size_t ROWS = 2;
const size_t COLS = 3;

int main()
{
    // Change the array definitions and/or values to demonstrate your variant:
    int data1[ROWS][COLS] = { { 0, -101, -200 }, { 300, 403, -501 } };
    int result1[ROWS]; // Note: for some variants the result array size depends on the COLS!
    // Change the parameters according to your assignment function, e.g.:
    int result2[COLS];
    int result3[COLS];
    solution_for_grade_7((const int*)data1, ROWS, COLS, result1);
    solution_for_grade_9((const int*)data1, ROWS, COLS, result2);
    solution_for_grade_10((const int*)data1, ROWS, COLS, result3);

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
    int data2[ROWS][COLS] = { { 1, -2, 3 }, { 4, -5, 6 } };
    int result4[ROWS];
    int result5[COLS];
    int result6[COLS];
    solution_for_grade_7((const int*)data2, ROWS, COLS, result4);
    solution_for_grade_9((const int*)data2, ROWS, COLS, result5);
    solution_for_grade_10((const int*)data2, ROWS, COLS, result6);
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
    solution_for_grade_7(nullptr, ROWS, 0, 0);
    solution_for_grade_10(0, 0, COLS, result2);
    // :::

    return 0;
}