#include <cstdio>
#include <cassert>

// :::

// For each grade level variant implement own function, e.g.:
// arr – the parameter that points to the pointer of the beginning of the one-dimension array
// arr_size – assumes the count of 32-bit integer values in the array
int solution_for_grade_6(const int arr[], unsigned arr_size)
{
    int result{ 0 };
    __asm
    {
        // Your Inline Assembler instructions for grade 6 level go here, e.g.
        mov	ESI, [arr] //; an example of how to obtain the addres of and array parameter
        mov	ECX, [arr_size]
        mov EAX, 0 //number of elements
        // :::		; additional before the loop validations and initializations
        Cycle:
        cmp dword ptr[ESI], 0 //; an example of addressing individual dword element ; of an array
        jle Next
        inc EAX
        // :::		; some conditional jump to Next and intermediate calculations
        Next:
        add	ESI, 4 //; an example of adjusting the array offset(4 bytes)
        loop Cycle
        Exit:
        mov[result], EAX //; save the result assuming it is in the register EAX
    }
    return result;
}

int solution_for_grade_7(const int arr[], unsigned arr_size)
{
    int result{ 0 };
    __asm
    {
        // Your Inline Assembler instructions for grade 6 level go here, e.g.
        mov	ESI, [arr] //; an example of how to obtain the addres of and array parameter
        mov	ECX, [arr_size]
        mov EAX, 0 // total
        mov EDX, 0 //index
        // :::		; additional before the loop validations and initializations
        Cycle:
        test dl, 1 // checks lowest bit of edx. If it is 1, number is odd, 0-> even 
        jz Next
        mov EBX, dword ptr[ESI]
        add EAX, EBX
            // :::		; some conditional jump to Next and intermediate calculations
        Next :
        add	ESI, 4 //; an example of adjusting the array offset(4 bytes)
        inc EDX
        loop Cycle
        Exit :
        mov[result], EAX //; save the result assuming it is in the register EAX
    }
    return result;
}

int solution_for_grade_9(const int arr[], unsigned arr_size)
{

    int result{ 0 };

    __asm
    {
        // Your Inline Assembler instructions for grade 9 level go here, e.g.
        mov	ESI, [arr] //; an example of how to obtain the addres of and array parameter
        mov	ECX, [arr_size]
        mov EAX, -2147483648 //the lowest possible value
        mov EDX, 0 //index
        mov EBX, -1
        // :::		; additional before the loop validations and initializations

        Cycle:
        test dword ptr[ESI], 1
        jz Next
        cmp EAX, dword ptr[ESI]
        jge Next
        mov EAX, dword ptr[ESI]
        mov EBX, EDX
        // :::		; some conditional jump to Next and intermediate calculations
        Next :
        add	ESI, 4 //; an example of adjusting the array offset(4 bytes)
        inc EDX
        loop Cycle
        Exit :
        mov[result], EBX //; save the result assuming it is in the register EBX
    }
    return result;
}

int main()
{
    int test_result;
    int test_result1;
    int test_result2;

    // Change the count of elements and their values according to your task specifics:
    int test_arr1[] = { 0, 1000, 2250, -3000, 4444, 5678, 66543, 70, -80000, 900000 };

    test_result = solution_for_grade_6(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
    test_result1 = solution_for_grade_7(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
    test_result2 = solution_for_grade_9(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0]));
    // You can use assert() function to test for correctness:
    //assert(test_result == 0);
    // Or print the results to console:
    printf("Grade 6 result1 = %d\n", test_result);
    printf("Grade 7 result1 = %d\n", test_result1);
    printf("Grade 9 result1 = %d\n", test_result2);

    // To test for side cases, for the same grade level function you might need different input arrays, e.g.:
    int test_arr2[] = { 0, -1, 2, -3, 4, -5, 6, -7, 8, -9 };

    test_result = solution_for_grade_6(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    test_result1 = solution_for_grade_7(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    test_result2 = solution_for_grade_9(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0]));
    //assert(test_result == 0);
    // Or print the results to console:
    printf("Grade 6 result2 = %d\n", test_result);
    printf("Grade 7 result2 = %d\n", test_result1);
    printf("Grade 9 result2 = %d\n", test_result2);
    // ...
    getchar(); // Wait for the Enter key
    return 0;
}
