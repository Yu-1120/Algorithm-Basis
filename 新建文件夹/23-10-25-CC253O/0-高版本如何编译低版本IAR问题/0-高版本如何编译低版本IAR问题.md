# 0-高版本如何编译低版本IAR问题

<https://blog.csdn.net/a791404623/article/details/75529288>

是需要找到某一文件后把后面END注释掉，然后换成新的提示文件上去的

```纯文本

;----------------------------------------------------------------;
; Virtual registers                                              ;
; =================                                              ;
; Below is some segment needed for the IAR ICC C/EC++ compiler   ;
;                                                                ;
; BREG  : A segment for 8 bit registers for use by the compiler. ;
;         ?B0 is the first register.                             ;
; VREG  : Segment that holds up to 32 virtual registers for      ;
;         use by the compiler. ?V0 is the first register.        ;
; PSP   : Segment containing the PDATA stack pointer (?PSP)      ;
; XSP   : Segment containing the XDATA stack pointer (?XSP)      ;
;                                                                ;
;----------------------------------------------------------------;
;----------------------------------------------------------------;

        PROGRAM VIRTUAL_REGISTERS
        PUBLIC  ?B0
        PUBLIC  ?V0
        PUBLIC  ?V1
        PUBLIC  ?V2
        PUBLIC  ?V3
        PUBLIC  ?V4
        PUBLIC  ?V5
        PUBLIC  ?V6
        PUBLIC  ?V7
        PUBLIC  ?V8
        PUBLIC  ?V9
        PUBLIC  ?V10
        PUBLIC  ?V11
        PUBLIC  ?V12
        PUBLIC  ?V13
        PUBLIC  ?V14
        PUBLIC  ?V15
        PUBLIC  ?V16
        PUBLIC  ?V17
        PUBLIC  ?V18
        PUBLIC  ?V19
        PUBLIC  ?V20
        PUBLIC  ?V21
        PUBLIC  ?V22
        PUBLIC  ?V23
        PUBLIC  ?V24
        PUBLIC  ?V25
        PUBLIC  ?V26
        PUBLIC  ?V27
        PUBLIC  ?V28
        PUBLIC  ?V29
        PUBLIC  ?V30
        PUBLIC  ?V31
        PUBLIC  ?PSP
        PUBLIC  ?XSP
        RSEG    BREG:BIT:NOROOT
?B0:
        DS      8

        RSEG    VREG:DATA:NOROOT
?V0:
        DS      1
?V1:
        DS      1
?V2:
        DS      1
?V3:
        DS      1
?V4:
        DS      1
?V5:
        DS      1
?V6:
        DS      1
?V7:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V7
?V8:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V8
?V9:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V9
?V10:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V10
?V11:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V11
?V12:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V12
?V13:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V13
?V14:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V14
?V15:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V15
?V16:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V16
?V17:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V17
?V18:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V18
?V19:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V19
?V20:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V20
?V21:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V21
?V22:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V22
?V23:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V23
?V24:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V24
?V25:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V25
?V26:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V26
?V27:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V27
?V28:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V28
?V29:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V29
?V30:
        DS      1

        RSEG    VREG:DATA:NOROOT
        REQUIRE ?V30
?V31:
        DS      1

        RSEG    PSP:DATA:NOROOT
        EXTERN  ?RESET_PSP
        REQUIRE ?RESET_PSP
?PSP:
        DS      1

        RSEG    XSP:DATA:NOROOT
        EXTERN  ?RESET_XSP
        REQUIRE ?RESET_XSP
?XSP:
        DS      2

        ENDMOD ; VIRTUAL_REGISTERS

        END



```
