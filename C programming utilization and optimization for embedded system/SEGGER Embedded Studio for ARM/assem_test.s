





//        .code 32
//        .global AssemTestFunc
//AssemTestFunc:
//        nop
//        mov pc, lr

/*** Data Processing (3) *******************************/
//        .code 32
//        .global AssemTestFunc
//AssemTestFunc:
//        mov r0, #0
//        mov r3, #0x12
//        AND R0, R0, #0xF
//        ADD R0, R0, #1
//        ADD R0, R0, R1
//        MOV R2, R0, LSL #2
//        SUB R3, R2, R1, LSR R2
//        BIC R9, R8, #0xFF00
//        RSB R0, R1, #0

//        mov pc, lr


///*** Load/Store Instructions(3) *******************************/
//        .code 32
//        .global AssemTestFunc
//AssemTestFunc:
//        mov r0, #0x20000000
//        //ldr r0, [0x20000000] -> syntax error
//        ldr r1, [r0]
//        ldr r1, [r0,#4]
//        str r0, [r1, #-4]
//        strb r0, [r1, #10]
//        strb r3, [r1,r2]
//        ldr r1, [r2, r3, lsr #2]
//        str r2, [r3, #4]!
//        ldr r1, [r2], r3

//        mov r0, #0x104
//        nop
//        //mov r0, #102 -> illegal
//        //mov r0, #0x12345678



/*** Load/Store Instructions(3) *******************************/
//        .code 32
//        .global AssemTestFunc
//AssemTestFunc:
//        mov r0, pc
//        ldr r0, =0x102


///*** Branch Instructions(2) *******************************/
//        .code 32
//        .global AssemTestFunc

//subfunc:
//        nop
//        mov pc, lr    //return
//AssemTestFunc:
//        push  {lr}
//        nop
//        bl subfunc
//        nop
//        pop   {lr}
//Loop:
//        add r0, r0, #1
//        nop
//        //b Loop

//        //mov pc, lr
//        mov r15, r14    //return


///*** Stack *******************************/
//        .code 32
//        .global AssemTestFunc

//subfunc:
//        push {r4-r7}    //backup stack
//        mov r4, #0
//        mov r5, #0
//        mov r6, #0
//        mov r7, #0

//        pop {r4-r7}
//        mov pc, lr    //return

//AssemTestFunc:
        
//        push {r4-r7, r12,r14}
        
//        mov r4, #4
//        mov r5, #5
//        mov r6, #6
//        mov r7, #7

//        bl     subfunc

//        nop

//        pop {r4-r7, r12, r14}        

//        //mov pc, lr
//        mov r15, r14    //return

//        //pop {r4-r7, r12, pc}    //pop plus return


///*** CPSR test *******************************/
//        .code 32
//        .global AssemTestFunc
//AssemTestFunc:
//        mov r0, #1
//        //sub r0, r0, #1
//        subs r0, r0, #1   //NZCV update
//        addeq r1, r0, #1    //condition check (Z=1)
//        movne r1, #0x100    //condition check (Z=0)

//        mov r15, r14    //return


///*** Assembly Code Test QUIZ 1 *******************************/
//        .code 32
//        .global AssemTestFunc
//AssemTestFunc:

//        // *(int *)0x20000000 = -1;
//        ldr r0, =-1
//        mov r1, #0x20000000
//        str r0, [r1]

//        // *(int *)0x20000000 = *(int *)0x20000000 + 1;
//        mov r1, #0x20000000
//        ldr r0, [r1]    //read from r1 to r0
//        add r0, r0, #1
//        str r0, [r1]

//        mov r15, r14    //return


///*** Assembly Code Test QUIZ 1 *******************************/
//        .code 32
//        .global AssemTestFunc
//AssemTestFunc:
//        // gVar = gVar +1
//        ldr r0, =gVar   //
//        ldr r1, [r0]
//        add r1, r1, #1
//        str r1, [r0]

//        mov pc, lr  //return


///*** Assembly Code Test QUIZ 2 DoSum test *******************************/
//        .code 32
//        .global AssemTestFunc
//        .global DoSum

//        //int DoSum(int n)
//        //{
//        //  int sum = 0;
//        //  for (int k=0; k<=n; k++)
//        //  {
//        //    sum = sum + k;
//        //  }
//        //  return sum;
//        //}

//DoSum:
//        mov r1, #0    //sum
//        mov r2, #0    //k
//Loop:
//        add r1, r1, r2    //sum = sum + k
//        add r2, r2, #1
        
//        cmp r0, r2
//        bge Loop

//        mov r0, r1    //return is r0
//        mov pc, lr


//AssemTestFunc:
//        mov pc, lr    //return


///*** Assembly Code Test QUIZ 3 test *******************************/
//        .code 32
//        .global AssemTestFunc
//        .global DoDist


////int GetDist(int a, int b)
////{
////  int d;
////  d = a-b;
////  if (d<0)
////  {
////    d = -d;
////  }
////  return d;
////}


//DoDist:

//        //mov r2, #0    //d
//        //sub r2, r0, r1
//        //cmp r2, #0
//        //mov r0, r2
//        sub r0, r0, r1
//        com r0, #0

//        rsblt r0, r0, #0

//        mov pc, lr


//AssemTestFunc:
//        mov pc, lr    //return


/*** Assembly Code Test QUIZ 3 test *******************************/
        .code 32
        .global AssemTestFunc
        .global memory_copy


    //void memory_copy(int*pdst, int * psrc, int len)
    //{
    //  for (int k=0; k<len; k++)
    //  {
    //    pdst[k] = psrc[k];
    //  }
    //}

    //memory_copy(buf1, buf0, 8); //r0, r1, r3

memory_copy:    //ldr, str, b

        mov r4, #0

Loop:
        //ldr r3, [r1]    //r3 = pdst
        //str r3, [r0]

        //add r1, r1, #4
        //add r0, r0, #4

        ldr r3, [r1], #4    //r3 = pdst
        str r3, [r0], #4
        subs r2, r2, #1
        bne Loop2

        mov pc, lr


AssemTestFunc:
        mov pc, lr    //return
