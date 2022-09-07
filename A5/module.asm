.586
.model flat, C 

includelib msvcrtd
.data
error db "Error: Invalid Input. ", 0

.code
; Matches the following C/C++ declaration:
; extern "C" void solution_for_grade_X(const int * arr, size_t arr_rows, size_t arr_cols, int * result);
extrn printf:near
solution_for_grade_7 PROC EXPORT \ 
    USES EAX EBX ECX EDX ESI EDI \
    arr: PTR DWORD, arr_rows: DWORD, arr_cols: DWORD, result: PTR DWORD
    cmp[arr], 0
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
        xor ebx, ebx
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
        push offset error
        call printf
    done:
    ret

solution_for_grade_7 ENDP

solution_for_grade_8 PROC EXPORT \ 
    USES EAX EBX ECX EDX ESI EDI \
    arr: PTR DWORD, arr_rows: DWORD, arr_cols: DWORD, result: PTR DWORD
        cmp[arr], 0
        je fail
        cmp [arr_rows], 0
        jle fail
        cmp [arr_cols], 0
        jle fail
        cmp [result], 0
        je fail
        xor esi, esi
        mov ecx, [arr_cols]
        xor edi, edi
        col_loop :
            push ecx
            mov eax, [arr]
            push esi
            xor ebx, ebx
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
        fail:
            push offset error
            call printf
        done:
    ret

solution_for_grade_8 ENDP

solution_for_grade_9 PROC EXPORT \ 
    USES EAX EBX ECX EDX ESI EDI \
    arr: PTR DWORD, arr_rows: DWORD, arr_cols: DWORD, result: PTR DWORD
        cmp[arr], 0
        je fail
        cmp [arr_rows], 0
        jle fail
        cmp [arr_cols], 0
        jle fail
        cmp [result], 0
        je fail
        xor esi, esi
        mov ecx, [arr_cols]
        xor edi, edi
        col_loop :
        push ecx
            mov eax, [arr]
            xor ebx, ebx
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
        fail:
            push offset error
            call printf
        done:
    ret

solution_for_grade_9 ENDP

END