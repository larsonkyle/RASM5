  .global BubbleSortA

  .data

  .text

/*
Params: X0 Array address
	X1 Array Length
*/
main:
BubbleSortA:
  str 	  X30,[SP, #-16]! // store LR
  /*
	create outer for loop that just sets the starting position to start bubbling
        create inner loop that iterates from outer loop start to the end, comparing the current index to current index + 1 and swapping if currend index + 1 is greater
  */ 

  mov x2,#0		// Initialize Outer Loop Control variable
  mov x7,x0		// Store copy of array start address
/*
  X0: Array Address
  X1: Array Length

  X2: Inner Loop Control (i)
  X3: Outer Loop Control (j)
    - X4: contents of the array, being the Current location of inner loop comparisons
    - X5: contents of the array, being the Current location of inner loop comparisons PLUS ONE
    - X6: temp var
  X7: Copy of starting array address
  
*/
BubbleSortOuter:
  // Check if at end of array
  cmp x2,X1		// Compare x2 and x3
  bge BubbleSortReturn	// if X2 >= X1, end

  mov x3,#0		// initialize Inner Loop Control variable
  mov x0,x7		// reset array starting address
  //length - i - 1
  sub x6,x1,x2		// length - i
  sub x6,x6,#1		// (length - i) - 1
  BubbleSortInner:
    ldr w4,[x0]
    ldr w5,[x0,#4]
    
    cmp w4,w5
    blt dontSwap

    str w5,[x0]
    str w4,[x0,#4]
    dontSwap:
    
    add x0,x0,#4
    add x3,x3,#1
    
    cmp x3,x6		// j < length - i - 1
    blt BubbleSortInner	// if true, then repeat algorithm

  add x2,x2,#1
  b   BubbleSortOuter


BubbleSortReturn:
  ldr LR,[SP],#16
  ret LR
