/* 
 * CS:APP Data Lab
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will submit on ics.men.ci
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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
the coding rules are less strict. You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according to the coding rules.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
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
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
   int x1=x&y;
   int y1=~y&~x;
   
  return ~x1&~y1;
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) 
{
  int a1=73; // 100 1001
  int a2=a1<<9|a1; 
  int a3=a2<<15|a2; 
  return a3;
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) 
{
  int x1=x<<16;
  int x2=x1>>16;
  int ans=!(x2^x);
  
  return ans;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)  // 00001 01111 10000000 11111 00010 11101
{
  int m=x+1;
  int a= m+m;
  int b=!(a+!m);
  return b;

}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) 
{
  // int move=33+~n;
  // int x1=x<<move;
  // int x2=x1>>move;
  // int ans=!(x2^x);
  // return ans;
  int a=x>>31;
	int b=x>>(n+31);
	int c=!(a^b);
	return c;

}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) 
{ 
  // int a = 1 << 31;
  // int b = n + 31;
  // return (a >> b) + !n;
  int b = n + 31;
  int a = (b & 32) << 26;
   return a >> b;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) // 1010 1010 
{
    int a=0xaa<<8|0xaa;
    int a1=a<<16|a;
    int ans=x&a1;
    return !!ans;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) 
{
    int nn = n<<3;
	  int mm = m<<3;
	  int c = ((x>>nn)^(x>>mm))&0xFF;
	  int d = x^(c<<nn)^(c<<mm);
    return d;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) 
{
  // int a=x>>31; //
  // int ans=x^a;
  // ans+=a&1;
  // return ans;
  int mid = x >> 31;
  x = (x + mid) ^ mid;
  return x;

}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) 
{
    // int a=x>>31;
    // int mask=(1<<n)+(~0);
    // int ans=(x+(mask&a))>>n;
    // return ans;
    int a = x >> 31;
    int b = a<<n;
    return (x +(a^b))>>n;

}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) 
{
  // unsigned e = uf & 0x7f800000;  //获得 阶码
  // unsigned f = uf & 0x007fffff;  //获得尾数
  // if (e == 0x7f800000 && f)      
  //   return uf;//阶码全为1且尾数不全为0为NaN，返回参数
  // return uf ^ 0x80000000;  //符号位取反
  unsigned int temp = uf & 0x7FFFFFFF;
  unsigned int result = uf ^ 0x80000000;
  if(temp > 0x7F800000)
      result = uf;
  return result;

}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) 
{
  // x=x<<;
  int a=(x|(~x+1))>>31;
  return a+1;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) 
{
  int a = ~0;// 11111
    int c = 2<<highbit; // 100
    int x = ((a+c)>>lowbit)<<lowbit;
    return x;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y)
{
  // 0 0 1 0 0 , 0 0 1 0 0 
  return !((x + ~(((x^y)>>31)|y))>>31);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n)
{
  // int x1=x>>n;
  // int x2=~((~0)<<(32+(~n))<<1);
  // return x1&x2;
  int a = 1 << (31^n); // 0000011111 0000011101
  return ((x >> n) + a)^a;

}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x7FFFFFFF (saturate to TMax)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x)  
{
  // //  volatile
  //  int a = x << 1;
  //   int mid = (x ^ a)>>31;
  //   return (a >> (31 & mid) )+ (mid<<31);
  int mul2 = x << 1;
  int mul2div2 = mul2 >> 1;
  int overflow = mul2div2 ^ x;
  int isoverflow = overflow >> 31;
  return (mul2 >> isoverflow) ^ overflow;
  // int xx = x+x;
	// int xxx = xx+x;
	// int of = ((x^xx)|(x^xxx))>>31;
	// return (of | xxx) ^ (of & ((x>>31) ^ (1<<31)));
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) 
{
  int yx = y + (~x);
	return (((x ^ y) & (y ^ yx)) >> 31) + 1;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x) 
{
  int x1 = x>>2;
  int ans1 = (x1+x1+x1);

	int x2 = x&3;
	// x2 = x%4 = 0, 1, 2, 3
	// 向零取整，意味着>=0时向下取整，<0时向上取整，即在/4前+3
	int sgn = (x>>31)&3;
	int ans2 = (x2+x2+x2+sgn)>>2;

	return ans1+ans2;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) 
{
  int a=x+~0; // 1000 000 
  int sign=a>>30;
  int z=x&a;
  // return !(a | !(x<<1));
  return !(z | sign);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x)  // 1 8 23
{
  unsigned shiftLeft=159;  // 1001 1111
  unsigned afterShift, tmp, flag = 0;  
  unsigned absX=x;  
  unsigned sign=0;    
  if (x<0)  // 
  {  
      sign=0x80000000;  
      absX=-x;  
  }  
  if(x == 0)
  {
      return 0;
  }
  afterShift=absX;  
  while (1)  
  {  
    tmp=afterShift;  
    afterShift<<=1;  
    shiftLeft--;  // 0001110001110
    if (tmp & 0x80000000) break;  
  }  
  if (afterShift & 0x0100)  
  {    
    if ((afterShift & 0x02ff))  // 0010 1111 1111
      flag=1; 
  }    
  return sign + (afterShift>>9) + (shiftLeft<<23) + flag;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) // 1111 1110 ->0001 0001 0010 ->0011 eg. 1000 0000 0000 0000
{
  int temp = x ^ (x << 1);//将负数转为正数相同的判别，同时加一个符号位(只能用32位才能表示的数不用加)
  int bit_16,bit_8,bit_4,bit_2,bit_1;

  bit_16 = !!(temp >> 16) << 4;//判断长度是否大于16  =16
  temp = temp >> bit_16;//对折操作  =1000 0000

  bit_8 = !!(temp >> 8) << 3;//同上  
  temp = temp >> bit_8;

  bit_4 = !!(temp >> 4) << 2;  // 4
  temp = temp >> bit_4;  // 1000 

  bit_2 = (!!(temp >> 2) << 1)+1; // 2
  temp = temp >> bit_2;

  bit_1 =temp&1;
  return bit_1 + bit_2 + bit_4 + bit_8 + bit_16;

}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) 
{
  unsigned sign_bit = (uf & 0x80000000);
  unsigned abs_f = uf - sign_bit;
  if (abs_f >= 0x7F800000)
    return uf;
  if (abs_f >= 0x1000000)
  {
    return uf - 0x800000;
  }
  else
  {
    int carry = ((abs_f & 0x3) == 0x3);
    return sign_bit + (abs_f >> 1) + carry;
  }
}
