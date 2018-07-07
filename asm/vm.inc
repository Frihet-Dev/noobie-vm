%define vr0 0
%define vr1 1
%define vr2 2
%define vr3 3
%define vr4 4
%define vr5 5
%define vr6 6
%define vr7 7

%macro vnop 0
    db 0x00
%endmacro

%macro vxor 2
    db 0x01, %1, %2
%endmacro

%macro vand 2
    db 0x02, %1, %2
%endmacro

%macro vor 2
    db 0x03, %1, %2
%endmacro

%macro vxori 2
    db 0x04, %1
    dd 0, %2
%endmacro

%macro vandi 2
    db 0x05, %1
    dd 0, %2
%endmacro

%macro vori 2
    db 0x06, %1
    dd 0, %2
%endmacro

%macro vadd 2
    db 0x07, %1, %2
%endmacro

%macro vsub 2
    db 0x08, %1, %2
%endmacro

%macro vaddi 2
    db 0x09, %1
    dd %2
%endmacro

%macro vsubi 2
    db 0x0a, %1
    dd %2
%endmacro

%macro vmov 2
    db 0x10, %1, %2
%endmacro

%macro vmovi 2
    db 0x11, %1
    dd %2
%endmacro

%macro vhalt 0
    db 0xff
%endmacro