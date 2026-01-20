/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int ns = n << 3;
    int ms = m << 3;

    int nb = (x >> ns) & 0xFF;
    int mb = (x >> ms) & 0xFF;

    int mask = ~((0xFF << ns) | (0xFF << ms));

    return (x & mask) | (nb << ms) | (mb << ns);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    int mask1, mask2, mask4, mask8, mask16;
    int m;

    mask1 = 0x55 | (0x55 << 8);
    mask1 = mask1 | (mask1 << 16);
    mask2 = 0x33 | (0x33 << 8);
    mask2 = mask2 | (mask2 << 16);
    mask4 = 0x0F | (0x0F << 8);
    mask4 = mask4 | (mask4 << 16);
    m = 0xFF;
    mask8 = m | (m << 16);
    mask16 = m | (m << 8); 

    x = (x & mask1) + ((x >> 1) & mask1);    
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
}
/*

 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7B3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x) {
    int mask1, mask2, mask4, mask8, mask16;
    int m;

    mask1 = 0x55 | (0x55 << 8);
    mask1 = mask1 | (mask1 << 16);
    mask2 = 0x33 | (0x33 << 8);
    mask2 = mask2 | (mask2 << 16);
    mask4 = 0x0F | (0x0F << 8);
    mask4 = mask4 | (mask4 << 16);
    m = 0xFF;
    mask8 = m | (m << 16);
    mask16 = m | (m << 8);

    x = ((x >> 1) & mask1) | ((x & mask1) << 1);
    x = ((x >> 2) & mask2) | ((x & mask2) << 2);
    x = ((x >> 4) & mask4) | ((x & mask4) << 4);
    x = ((x >> 8) & mask8) | ((x & mask8) << 8);
    x = ((x >> 16) & mask16) | ((x & mask16) << 16);
    
    return x;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  int y = x & 1;
  return (~y + !y) | y;
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  int mask;
  mask = 0x55 | (0x55 << 8);
  mask = mask | (mask << 16);
  return mask;
}
 //3
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  return ((x >> 31) & 1); // x < 0일 때  1				   
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int mask = x >> 31;
  return (x ^ mask) + (mask & 1);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    return (x >> 31) | !!x;
}
 //4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  return !(x & (x + ~0)) & !!x & !(x >> 31);
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  return !(x + x) & !!x;
}
 //5
/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567) = 0
 *            isPallindrome(0x0123C480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x) {
    int orig = x;
    int ma, mb, mc, md, me, y;

    ma = 0x55 | (0x55 << 8);
    ma = ma | (ma << 16);
    mb = 0x33 | (0x33 << 8);
    mb = mb | (mb << 16);;
    mc = 0x0F | (0x0F << 8);
    mc = mc | (mc << 16);
    md = 0xFF | (0xFF << 16);
    me = 0xFF | (0xFF << 8);

    y = (x >> 1) & ma;
    x = (x & ma) << 1 | y;
    y = (x >> 2) & mb;
    x = (x & mb) << 2 | y;
    y = (x >> 4) & mc;
    x = (x & mc) << 4 | y;
    y = (x >> 8) & md;
    x = (x & md) << 8 | y;
    y = (x >> 16) & me;
    x = (x << 16) | y;

    return !(orig ^ x);
}
/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
   int sign = x >> 31;
   int mag = x & ~(1 << 31);
   return (mag ^ sign) + (sign & 1);
}
 //float
/* 
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
  // 30~23 : exp, 22~0 : fraction
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & ((1 << 23) - 1);
  if (exp == 0xFF && frac)
      return uf;
  return uf ^ (1 << 31);
}
/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {
	unsigned s = 0;
	unsigned exp = 0;
	unsigned frac = 0;
	unsigned r = 0;
	unsigned tmp = 0;
	unsigned shift = 0;
	int expval = 0;

	if (x == 0) return 0;

	if (x & 0x80000000) {
	    s = 1 << 31;
	    x = (~x) + 1;
	}

	tmp = x;
	while (tmp = tmp >> 1)
	    expval= expval + 1;

	exp = expval + 127;
	shift = x << (31 + ((~expval)+1));
	frac = (shift >> 8) & 0x7FFFFF;

	r = shift & 0xFF;
	if ((r > 0x80) || ((r == 0x80) && (frac & 1))) {
   		frac = frac + 1;
   		if (frac & 0x800000) {
    		frac = 0;
    		exp = exp + 1;
    		}
	}	

	return s | (exp << 23) | frac;
}
/* 
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf) {
	unsigned exp = uf & (0xFF << 23);
	unsigned frac = uf & 0x7FFFFF;
	unsigned sign = uf & (1 << 31);
	unsigned dton = 0, dover = 0;

	if ((exp>>23) == 0xFF) {
		return uf;
	}
	if ((exp>>23) >= 249) {
		if (uf >> 31) return 0xff800000;
		return 0x7F800000;
	}
	if ((uf & 0x7FFFFFFF) == 0) {
		return uf;
	}
	if (!exp) {
		frac = frac << 6;

		while(frac >= (1<<23)) {
			frac = frac >> 1;
			dton = dton + 1;
			dover = 1;
		}
		if (dover) {
			frac = frac << 1;
			frac = frac & (~(1 << 23));
		}
		exp = dton;
		exp = exp << 23; 
		return sign | exp | frac;
	}
	exp = exp >> 23;
	exp = exp + 6;
	exp = exp << 23;
	uf = uf & (~(0xFF << 23));
	uf = uf | exp;
	return uf;	
}
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & ((1 << 23) - 1);
  if (exp == 0xFF && frac)
      return uf;
  return uf & ((1<<31)-1);
}
