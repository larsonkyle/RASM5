  .global InsertionSortA

  .data

  .text

/*
 params: X0 - array address
	 X1 - array size
*/
main:
InsertionSortA:
  str LR,[SP, #-16]!		// store LR

  mov X2,#1			// Initialize index and outer lcvi
  mov x7,#4			// hard code 4 for mul instruction
/*
 X0 - array address
 X1 - array size

 X2 - outer loop control AND index	(i)
 X3 - inner loop control AND prev index	(j)

 w4 - current index to sort		(key)
 w5 - prev array contents		(arr[j])

 x6 - variable used to store current calculate offsets
 x7 - HARD CODED 4 CAUSE AARCH64 MUL INSTRUCTION SUCKS
*/
forLoop:
  // i < n
  cmp x1,x2			// check if index is larger than size
  ble InsertionSortReturn	// if larger, finish

  //int key = arr[i];
  mul x6,x2,x7			// calc offset
  ldr w4,[x0,x6]		// load index and set as key

  //int j = i - 1
  sub x3,x2,#1			// calculate one before index

  while:
    //j >= 0
    cmp x3,#0			// check if j is in bounds
    blt loopend			// end if not in bounds

    //arr[j] > key
    mul x6,x3,x7		// calcualte offset
    ldr w5,[x0,x6]		// load arr[j]
    cmp w5,w4			// compare the two
    ble loopend			// if less than or equal, loop end

    //arr[j + 1] = arr[j]
    add x3,x3,#1		// add one to j for offset
    mul x6,x3,x7		// calculate offset
    str w5,[x0,x6]		// store at location with offset

    sub x3,x3,#2		// minus 2 to remove the previous add one and to minus one for the algorithm

    b   while			// repeat algo
  loopend:

  add x3,x3,#1			// add one for offset calculation
  mul x6,x3,x7			// calc offset
  str w4,[x0,x6]		// store key at location + offset
  sub x3,x3,#1			// undo add one

  add x2,x2,#1			// i++
  b   forLoop			// repeat algo

InsertionSortReturn:
  ldr     LR,[SP],#16		// pop LR off the stack
  ret     LR			// ret KR
