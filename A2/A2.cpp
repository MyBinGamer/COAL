#include <cstdio>
#include <cassert>
// :::

// NOTE:
//   char  data type is signed  8-bit integer (DB in assembler)
//   short data type is signed 16-bit integer (DW in assembler)
//   int   data type is signed 32-bit integer (DD in assembler)

// You must use at least integer data type for input values.
// Update the given template code appropriately.

int solution_for_grade_4(int x, int y, int z)
{
    int result;
    // Visual C++ inline assembler syntax:
    __asm
    {
        // Your Inline Assembler instructions for grade 4 go here
        // :::
        mov EAX, [x]
        sub EAX, [y]
        mov ECX, [z]
        add EAX, ECX
        mov[result], EAX //save the result assuming it is in the register AX
    }
    return result;
}


int solution_for_grade_5(int x, int y, int z)
{
    int result;
    __asm
    {
        // Your Inline Assembler instructions for grade 4 go here
        // :::
        mov EAX, [x]
        imul EAX, -5
        push EAX
        mov EAX, [y]
        imul EAX, 6
        imul EAX, [z]
        pop EDX
        add EAX, EDX
        mov[result], EAX //save the result
    }
    return result;
}


int solution_for_grade_7(int x, int y, int z)
{
    int result;
    __asm
    {
        mov EAX, x
        sub EAX, y
        add EAX, z
        push EAX
        cmp EAX, 0
        jg b // A>0
        jle c //else (that includes A==0 and A<0)
        b:  mov EAX, x
            imul EAX, -5
            push EAX
            mov EAX, y
            imul EAX, 6
            imul EAX, z
            pop EDX
            add EAX, EDX
            pop EBX
            imul EBX
            jmp done
            c: cmp z, 0
            jne g
            mov EAX, -1
            pop EBX
            jmp done
            g:
            mov EAX, x
            add EAX, 1
            mov EBX, EAX
            cdq
            imul EAX
            imul EBX
            push EAX
            mov EAX, y
            cdq
            idiv z
            pop EBX
            sub EBX, EAX
            pop EAX
            imul EBX
            jmp done
        done:
            mov [result], EAX
    }
    return result;
}
int solution_for_grade_8(int x, int y, int z)
{
    int result;
    __asm
    {
        mov EAX, x
        sub EAX, y
        add EAX, z
        push EAX
        cmp EAX, 0
        jle b //A<=0
        jg c //else (just A>0 without A==0)
        b : mov EAX, -1 //saving -1 beforehand, it will be replaced later if A isn't 0
        pop EBX
        cmp EBX, 0
        je done //in case if A=0, jump to done
        mov EAX, x //-1 is overwritten
        imul EAX, -5
        push EAX
        mov EAX, y
        imul EAX, 6
        imul EAX, z
        pop EDX
        add EAX, EDX
        cdq
        idiv EBX
        jmp done
        c : cmp z, 0
        jne g
        mov EAX, -1
        pop EBX
        jmp done
        g : mov EAX, y
        cdq 
        idiv z //Y/Z
        push EAX
        mov EAX, x
        add EAX, 1 // X+1
        mov EBX, EAX
        imul EAX // (X+1)^2
        imul EBX // (X+1)^3
        pop EBX
        sub EAX, EBX // (X+1)^3-Y/Z
        pop ECX
        idiv ECX // C / A
        jmp done
        done :
        mov[result], EAX
    }
    return result;
}

int solution_for_grade_9(int x, int y, int z)
{
    int result;
    __asm
    {
        mov EAX, x
        sub EAX, y
        add EAX, z
        push EAX
        cmp EAX, 0
        jl b //A<0
        jg c //else if A>0
        je d //A==0
        b:
        mov EAX, x
        imul EAX, -5
        push EAX
        mov EAX, y
        imul EAX, 6
        imul EAX, z
        pop EDX
        add EAX, EDX
        pop EBX
        cdq
        idiv EBX
        jmp done
        c: 
        cmp z, 0
        jne g
        mov EAX, -1
        pop EBX
        jmp done
        g :
        mov EAX, y
        cdq
        idiv z //Y/Z
        push EAX
        mov EAX, x
        add EAX, 1 // X+1
        mov EBX, EAX
        imul EAX // (X+1)^2
        imul EBX // (X+1)^3
        pop EBX
        sub EAX, EBX // (X+1)^3-Y/Z
        pop ECX
        idiv ECX // C / A
        jmp done
        d: 
        mov EAX, -1
        pop EBX
        jmp done
        done :
        mov[result], EAX
    }
    return result;
}

int solution_for_grade_6(int x, int y, int z)
{
    int result;
    __asm
    {
        cmp z, 0
        jne g //g for good to go
        mov EBX, -1
        jmp done
        g:
        mov EAX, x
        add EAX, 1
        mov EBX, EAX
        cdq
        imul EAX
        imul EBX
        push EAX
        mov EAX, y
        cdq
        idiv z
        pop EBX
        sub EBX, EAX
        jmp done
        done:
        mov[result], EBX
    }
    return result;
}

int main()
{
    // Note the 32-bit signed int value range is –2’147’483’648.. 2’147’483’647
    int X = -420;
    int Y = 3526;
    int Z = 3921;
    //int result_true = (1+X)*(1+X)*(1+X) - Y / Z;
    //int result233 = solution_for_grade_6_try(X, Y, Z);
    int result = solution_for_grade_4(X, Y, Z);
    int result1 = solution_for_grade_5(X, Y, Z);
    int result2 = solution_for_grade_6(X, Y, Z);
    int result3 = solution_for_grade_7(X, Y, Z);
    int result4 = solution_for_grade_8(X, Y, Z);
    int result5 = solution_for_grade_9(X, Y, Z);
    printf("solution_for_grade_4(%d, %d, %d) = %d\n", X, Y, Z, result);
    printf("solution_for_grade_5(%d, %d, %d) = %d\n", X, Y, Z, result1);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", X, Y, Z, result2);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", X, Y, Z, result3);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", X, Y, Z, result4);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", X, Y, Z, result5);

    //results where devision by zero occurs
    X = 420;
    Y = 425;
    Z = 5;
    //int result_true = (1+X)*(1+X)*(1+X) - Y / Z;
    //int result233 = solution_for_grade_6_try(X, Y, Z);
    result = solution_for_grade_4(X, Y, Z);
    result1 = solution_for_grade_5(X, Y, Z);
    result2 = solution_for_grade_6(X, Y, Z);
    result3 = solution_for_grade_7(X, Y, Z);
    result4 = solution_for_grade_8(X, Y, Z);
    result5 = solution_for_grade_9(X, Y, Z);
    printf("solution_for_grade_4(%d, %d, %d) = %d\n", X, Y, Z, result);
    printf("solution_for_grade_5(%d, %d, %d) = %d\n", X, Y, Z, result1);
    printf("solution_for_grade_6(%d, %d, %d) = %d\n", X, Y, Z, result2);
    printf("solution_for_grade_7(%d, %d, %d) = %d\n", X, Y, Z, result3);
    printf("solution_for_grade_8(%d, %d, %d) = %d\n", X, Y, Z, result4);
    printf("solution_for_grade_9(%d, %d, %d) = %d\n", X, Y, Z, result5);

    getchar(); // Wait for the Enter key
    return 0;
}
