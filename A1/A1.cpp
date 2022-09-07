// A1.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cassert>

// :::

// NOTE:
//   char  data type is signed  8-bit integer (DB in assembler)
//   short data type is signed 16-bit integer (DW in assembler)
//   int   data type is signed 32-bit integer (DD in assembler)

// You can use any integer data type for input values.
// Update the template code appropriately.

short solution_for_grade_5(short x, short y, short z)
{
    short result;
    __asm
    {
        // Your Inline Assembler instructions for grade 5 go here
        // :::
        mov AX, [x]
        sub AX, [y]
        mov CX, [z]
        add AX, CX
        mov [result], AX //save the result assuming it is in the register AX
    }
    return result;
}


int solution_for_grade_6(short x, short y, short z)
{
    int result;
    __asm
    {
        // Your Inline Assembler instructions for grade 6 go here
        // :::
        mov AX, [x]
        cwde
        imul EAX, -5
        push EAX
        mov AX, [y]
        cwde
        imul EAX, 6
        imul EAX, [z]
        pop EDX
        add EAX, EDX
        mov[result], EAX //save the result
    }
    return result;
}


int solution_for_grade_7(short x, short y, short z)
{
    int result;
    __asm
    {
        // Your Inline Assembler instructions for grade 7 go here
        // :::
        mov AX, [x]
        sub AX, [y]
        add AX, [z]
        cwde
        mov EBX, EAX // A result in EBX
        mov AX, [x]
        cwde
        imul EAX, -5
        mov EDX, EAX
        mov AX, [y]
        cwde
        imul EAX, 6
        imul EAX, [z]
        add EAX, EDX // B result in EAX
        sub EAX, EBX //B-A
        mov[result], EAX //save the result
    }
    return result;
}


int solution_for_grade_8(short x, short y, short z)
{
    int result;
    __asm
    {
        // Your Inline Assembler instructions for grade 8 go here
        // :::
        mov AX, [x]
        cwde
        mov EBX, EAX
        imul EAX, -5
        mov EDX, EAX
        mov AX, [y]
        cwde
        mov ECX, EAX
        sub EBX, EAX
        mov AX, [z]
        add EBX, EAX // A result in EBX
        imul ECX, 6
        imul ECX, EAX
        add EDX, ECX // B result in EDX
        imul EDX, EBX
        mov[result], EDX //save the result
    }
    return result;
}


int solution_for_grade_9(short x, short y, short z)
{
    int result;
    __asm
    {
        // Your Inline Assembler instructions for grade 9 go here
        // :::
        mov AX, [x]
        cwde
        mov EBX, EAX
        imul EAX, -5
        mov EDX, EAX
        mov AX, [y]
        cwde
        mov ECX, EAX
        sub EBX, EAX
        mov AX, [z]
        add EBX, EAX // A result in EBX
        imul ECX, 6
        imul EAX, ECX
        add EAX, EDX // B result in EAX
        cdq
        idiv EBX
        mov[result], EAX //save the result
    }
    return result;
}

// :::

int main()
{
    short X = 420; 
    short Y = 696;
    short Z = 240;

    short result = solution_for_grade_5(X, Y, Z);
    assert(result == (X-Y+Z));
    int result1 = solution_for_grade_6(X, Y, Z);
    assert(result1 == -5*X+6*Y*Z);
    int result2 = solution_for_grade_7(X, Y, Z);
    assert(result2 == (-5 * X + 6 * Y * Z)-(X-Y+Z));
    int result3 = solution_for_grade_8(X, Y, Z);
    assert(result3 == (-5 * X + 6 * Y * Z) * (X - Y + Z));
    int result4  = solution_for_grade_9(X, Y, Z);
    assert(result4 == (-5 * X + 6 * Y * Z) / (X - Y + Z));

    printf("solution_for_grade_5(%d, %d, %d) = %d\n", X, Y, Z, result);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", X, Y, Z, result1);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", X, Y, Z, result2);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", X, Y, Z, result3);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", X, Y, Z, result4);
    // You might need to invoke solution functions several times
    // with different parameter values (e.g., to demonstrate branching).
    // :::
    X = -469;
    Y = 444;
    Z = 69;

    result = solution_for_grade_5(X, Y, Z);
    assert(result == (X - Y + Z));
    result1 = solution_for_grade_6(X, Y, Z);
    assert(result1 == -5 * X + 6 * Y * Z);
    result2 = solution_for_grade_7(X, Y, Z);
    assert(result2 == (-5 * X + 6 * Y * Z) - (X - Y + Z));
    result3 = solution_for_grade_8(X, Y, Z);
    assert(result3 == (-5 * X + 6 * Y * Z) * (X - Y + Z));
    result4 = solution_for_grade_9(X, Y, Z);
    assert(result4 == (-5 * X + 6 * Y * Z) / (X - Y + Z));

    printf("solution_for_grade_5(%d, %d, %d) = %d\n", X, Y, Z, result);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", X, Y, Z, result1);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", X, Y, Z, result2);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", X, Y, Z, result3);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", X, Y, Z, result4);

    getchar(); // Wait for the Enter key
    return 0;
}
