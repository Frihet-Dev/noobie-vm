; Noobie assembler code
%include "vm.inc"

program:
    vmovi   vr0, 0x17
    vmovi   vr1, 0x29
    vsub    vr0, vr1
    vmov    vr7, vr0
    vaddi   vr7, 0xf0af
    vsub    vr7, vr1
    vhalt