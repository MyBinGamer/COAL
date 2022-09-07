.586
.model flat, stdcall
option casemap:none
include \masm32\include\kernel32.inc
includelib \masm32\lib\kernel32.lib
include \masm32\include\masm32.inc
includelib \masm32\lib\masm32.lib

.data
Alpha     dd          16

Vect       dd          1, -2, 3
.code
start 	proc
		 mov       eax, Alpha

              mov       Vect, -1

              mov       Vect+4, eax
		push	0
		call	ExitProcess
start endp
	end	start        