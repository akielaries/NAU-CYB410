.text:0040487C loc_40487C: ; CODE
XREF: sub_4047FE+B8j
.text:0040487C mov bh, [esi] ; retrieve encrypted byte
.text:0040487E add esi, 1
.text:00404881 add bh, bl
.text:00404883 add bh, dl
.text:00404885 mov [edi], bh ; store decrypted byte
.text:00404887 inc edi
.text:00404888 push edx
.text:00404889 push ecx
.text:0040488A push 0 ;lpModuleName
.text:0040488C call ds:GetModuleHandleA ; get base address of system proc
.text:00404892 pop ecx
.text:00404893 pop edx
.text:00404894 and eax, 0FFh
.text:00404899 add eax, 4
.text:0040489C shr edx, 8
.text:0040489F inc ebp
.text:004048A0 cmp ebp, eax
.text:004048A2 jnz short loc_4048B0
.text:004048A4 mov ebp, 0F5DC7E46h
.text:004048A9 mov edx, ebp
.text:004048AB mov ebp, 0
.text:004048B0
.text:004048B0 loc_4048B0: ; CODE
XREF: sub_4047FE+A4j
.text:004048B0 sub ecx, 1 ; ecx = counter
.text:004048B3 cmp ecx, 0 ; any bytes left to decrypt?
.text:004048B6 jnz short loc_40487C ; loop if so
.text:004048B8 pop eax 

.text:004048B9 mov edx, eax ; edx stores decrypted layer
.text:004048BB jmp edx ; jump to decrypted code
