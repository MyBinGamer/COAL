.model flat, C 

includelib msvcrtd
.data
error db "Error: Invalid Input. ", 0
.code
extrn printf:near

solution_for_7 PROC PUBLIC USES EBX ECX EDX ESI source: PTR BYTE
        cmp [source], 0
        je fail
        mov ebx, source
        xor ecx, ecx
        src_loop:
            cmp byte ptr[ebx], 0
            je done
            cmp byte ptr[ebx], 40
            je opening_bracket
            cmp byte ptr[ebx], 41
            je closing_bracket
            jmp back
        opening_bracket:
            inc ecx
            jmp back
        closing_bracket:
            dec ecx
        back:
            inc ebx
            jmp src_loop
        done:
            cmp ecx, 0
            je good
            mov eax, 0
            jmp post_done
        good:
            mov eax, 1
            jmp post_done
        fail:
            push offset error
            call printf
        post_done:
    ret

solution_for_7 ENDP

solution_for_9 PROC PUBLIC USES EAX EBX ECX EDX ESI EDI src: PTR BYTE, dst: PTR BYTE
        cmp [src], 0
        je fail
        cmp [dst], 0
        je fail
        mov eax, [src]
        mov ebx, [dst]
        mov esi, -1
        xor edi, edi
        mov ecx, -1
        get_length:
            inc ecx
            cmp byte ptr[eax+ecx], 0
            jne get_length
        start:
            inc esi
            cmp byte ptr[eax+esi], 20h
            je start
        other:
            dec ecx
            cmp byte ptr[eax+ecx], 20h
            je other
        transform:
            cmp esi, ecx
            jg done
            mov dl, [eax + esi]
            mov [ebx + edi], dl
            inc esi
            inc edi
            jmp transform
        fail:
            push offset error
            call printf
        done:
    ret

solution_for_9 ENDP

END