/**
 * PROJECT          : Lab 5 - Question 5
 * FILE             : MutableHugeInteger.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 12, 2017
 * REQUIREMENTS     :
 */


package Question5;


public class MutableHugeInteger
{
    /* Holds the magnitude of this MutableHugeInteger in big endian order.
     The magnitude may start at an offset into the value array, and it may end before the length of the value array. */
    int[] value;

    /* The number of ints of the value array that are currently used to hold the magnitude of this MutableHugeInteger.
     The magnitude starts at an offset and offset + intLen may be less than value.length. */
    int intLen;

    /* The offset into the value array where the magnitude of this MutableHugeInteger begins.*/
    int offset = 0;

    /* This mask is used to obtain the value of an int as if it were unsigned.*/
    private final static long LONG_MASK = 0xffffffffL;

    /* bitLen(val) is the number of bits in val.*/
    static int bitLen(int w)
    {
        // Binary search - decision tree (5 tests, rarely 6)
        return
                (w < 1<<15 ?
                        (w < 1<<7 ?
                                (w < 1<<3 ?
                                        (w < 1<<1 ? (w < 1 ? (w<0 ? 32 : 0) : 1) : (w < 1<<2 ? 2 : 3)) :
                                        (w < 1<<5 ? (w < 1<<4 ? 4 : 5) : (w < 1<<6 ? 6 : 7))) :
                                (w < 1<<11 ?
                                        (w < 1<<9 ? (w < 1<<8 ? 8 : 9) : (w < 1<<10 ? 10 : 11)) :
                                        (w < 1<<13 ? (w < 1<<12 ? 12 : 13) : (w < 1<<14 ? 14 : 15)))) :
                        (w < 1<<23 ?
                                (w < 1<<19 ?
                                        (w < 1<<17 ? (w < 1<<16 ? 16 : 17) : (w < 1<<18 ? 18 : 19)) :
                                        (w < 1<<21 ? (w < 1<<20 ? 20 : 21) : (w < 1<<22 ? 22 : 23))) :
                                (w < 1<<27 ?
                                        (w < 1<<25 ? (w < 1<<24 ? 24 : 25) : (w < 1<<26 ? 26 : 27)) :
                                        (w < 1<<29 ? (w < 1<<28 ? 28 : 29) : (w < 1<<30 ? 30 : 31)))));
    }



    /******************************************************************************
     CONSTRUCTOR    : MutableHugeInteger

     DESCRIPTION	: The default constructor. An empty MutableHugeInteger is
                      created with a size of one.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    MutableHugeInteger()
    {
        value = new int[1];
        intLen = 0;
    }



    /******************************************************************************
     CONSTRUCTOR    : MutableHugeInteger

     DESCRIPTION	: Construct a new MutableHugeInteger with the specified value
                      array up to the length of the array supplied.

     INPUT			: Type			: int[]
                    : Description	: The value array.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    MutableHugeInteger(int[] val)
    {
        value = val;
        intLen = val.length;
    }






    /******************************************************************************
     METHOD		    : clear

     DESCRIPTION	: This method clears out a MutableHugeInteger for reuse.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void clear()
    {
        offset = intLen = 0;
        for (int index = 0, n = value.length; index < n; index++)
            value[index] = 0;
    }






    /******************************************************************************
     METHOD		    : getInt

     DESCRIPTION	: This method compares the magnitude of two MutableHugeInteger.
                      Returns -1, 0 or 1 as this MutableHugeInteger is
                      numerically less than, equal to, or greater than b.

     INPUT			: Type			: MutableHugeInteger
                    : Description	: Comparator against this.

     OUTPUT			: Type 			: int
                    : Description	: Result of comparison.
     ******************************************************************************/
    private int compare(MutableHugeInteger b)
    {
        if (intLen < b.intLen)
            return -1;

        if (intLen > b.intLen)
            return 1;

        for (int i = 0; i < intLen; i++)
        {
            int b1 = value[offset+i]     + 0x80000000;
            int b2 = b.value[b.offset+i] + 0x80000000;

            if (b1 < b2)
                return -1;

            if (b1 > b2)
                return 1;
        }

        return 0;
    }





    /******************************************************************************
     METHOD		    : copyValue

     DESCRIPTION	: This method sets this MutableHugeInteger's value array to a
                      copy of the specified array. The intLen is set to the length
                      of the new array.

     INPUT			: Type			: MutableHugeInteger
                    : Description	: Since HugeInteger is immutable data type,
                                      this reference is used as temp reference for
                                      copying.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void copyValue(MutableHugeInteger val)
    {
        int len = val.intLen;

        if (value.length < len)
            value = new int[len];

        for(int i = 0; i < len; i++)
            value[i] = val.value[val.offset+i];

        intLen = len;
        offset = 0;
    }







    /******************************************************************************
     METHOD		    : divWord

     DESCRIPTION	: This method divides a long quantity by an int to estimate
                      qhat for two multi precision numbers.
                      It is used when the signed value of n is less than zero.

     INPUT			: Type			: int[]
                    : Description	: HugeInteger value (length > MAX_INT)

                    : Type			: long
                    : Description	: long value

                    : Type			: int
                    : Description	: The divisor

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void divWord(int[] result, long n, int d)
    {
        long dLong = d & LONG_MASK;

        if (dLong == 1)
        {
            result[0] = (int)n;
            result[1] = 0;
            return;
        }

        // Approximate the quotient and remainder
        long q = (n >>> 1) / (dLong >>> 1);
        long r = n - q * dLong;

        // Correct the approximation
        while (r < 0)
        {
            r += dLong;
            q--;
        }
        while (r >= dLong)
        {
            r -= dLong;
            q++;
        }

        // n - q * dlong == r && 0 <= r < dLong, hence we're done.
        result[0] = (int)q;
        result[1] = (int)r;
    }





    /******************************************************************************
     METHOD		    : divideOneWord

     DESCRIPTION	: This method is used for division of an n word dividend by a
                      one word divisor.
                      The quotient is placed into quotient. The one word divisor is
                      specified by divisor.
                      The value of this MutableBigInteger is the dividend at
                      invocation but is replaced by the remainder.

                      NOTE: The value of this MutableHugeInteger is modified by this method.

     INPUT			: Type			: int
                    : Description	: The one word divisor.

                    : Type			: MutableHugeInteger
                    : Description	: The quotient object reference.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void divideOneWord(int divisor, MutableHugeInteger quotient)
    {
        long divLong = divisor & LONG_MASK;

        // Special case of one word dividend
        if (intLen == 1)
        {
            long remValue = value[offset] & LONG_MASK;
            quotient.value[0] = (int) (remValue / divLong);
            quotient.intLen = (quotient.value[0] == 0) ? 0 : 1;
            quotient.offset = 0;
            value[0] = (int) (remValue - (quotient.value[0] * divLong));
            offset = 0;
            intLen = (value[0] == 0) ? 0 : 1;
            return;
        }

        if (quotient.value.length < intLen)
            quotient.value = new int[intLen];

        quotient.offset = 0;
        quotient.intLen = intLen;

        // Normalize the divisor
        int shift = 32 - bitLen(divisor);
        int rem = value[offset];
        long remLong = rem & LONG_MASK;
        if (remLong < divLong)
            quotient.value[0] = 0;

        else
        {
            quotient.value[0] = (int)(remLong/divLong);
            rem = (int) (remLong - (quotient.value[0] * divLong));
            remLong = rem & LONG_MASK;
        }

        int xlen = intLen;
        int[] qWord = new int[2];

        while (--xlen > 0)
        {
            long dividendEstimate = (remLong<<32) | (value[offset + intLen - xlen] & LONG_MASK);

            if (dividendEstimate >= 0)
            {
                qWord[0] = (int) (dividendEstimate/divLong);
                qWord[1] = (int) (dividendEstimate - (qWord[0] * divLong));
            }
            else
                divWord(qWord, dividendEstimate, divisor);

            quotient.value[intLen - xlen] = qWord[0];
            rem = qWord[1];
            remLong = rem & LONG_MASK;
        }

        // Unnormalize
        if (shift > 0)
            value[0] = rem %= divisor;

        else
            value[0] = rem;

        intLen = (value[0] == 0) ? 0 : 1;
        quotient.normalize();
    }




    /******************************************************************************
     METHOD		    : divide

     DESCRIPTION	: This method Calculates the quotient and remainder of this
                      div b and places them in the MutableBigInteger objects provided.
                      Uses Algorithm D in Knuth section 4.3.1. Many optimizations
                      to that algorithm have been adapted from the Colin Plumb C
                      library. It special cases one word divisors for speed.
                      The contents of a and b are not changed.

     INPUT			: Type			: MutableHugeInteger
                    : Description	: HugeInteger Divisor

                    : Type			: MutableHugeInteger
                    : Description	: HugeInteger Quotient

                    : Type			: MutableHugeInteger
                    : Description	: Used as copy array to avoid mutating references

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    void divide(MutableHugeInteger b, MutableHugeInteger quotient, MutableHugeInteger rem)
    {
        if (b.intLen == 0)
            throw new ArithmeticException("BigInteger divide by zero");

        // Dividend is zero
        if (intLen == 0)
        {
            quotient.intLen = quotient.offset = rem.intLen = rem.offset = 0;
            return;
        }

        int cmp = compare(b);

        // Dividend less than divisor
        if (cmp < 0)
        {
            quotient.intLen = quotient.offset = 0;
            rem.copyValue(this);
            return;
        }

        // Dividend equal to divisor
        if (cmp == 0)
        {
            quotient.value[0] = quotient.intLen = 1;
            quotient.offset = rem.intLen = rem.offset = 0;
            return;
        }

        quotient.clear();

        // Special case one word divisor
        if (b.intLen == 1)
        {
            rem.copyValue(this);
            rem.divideOneWord(b.value[b.offset], quotient);
            return;
        }

        // Copy divisor value to protect divisor
        int[] d = new int[b.intLen];

        for(int i = 0; i < b.intLen; i++)
            d[i] = b.value[b.offset+i];

        int dlen = b.intLen;

        // Remainder starts as dividend with space for a leading zero
        if (rem.value.length < intLen +1)
            rem.value = new int[intLen+1];

        for (int i = 0; i < intLen; i++)
            rem.value[i+1] = value[i+offset];

        rem.intLen = intLen;
        rem.offset = 1;

        int nlen = rem.intLen;

        // Set the quotient size
        int limit = nlen - dlen + 1;

        if (quotient.value.length < limit)
        {
            quotient.value = new int[limit];
            quotient.offset = 0;
        }

        quotient.intLen = limit;
        int[] q = quotient.value;

        // D1 normalize the divisor
        int shift = 32 - bitLen(d[0]);

        if (shift > 0)
        {
            // First shift will not grow array
            HugeInteger.primitiveLeftShift(d, dlen, shift);

            // But this one might
            rem.leftShift(shift);
        }

        // Must insert leading 0 in rem if its length did not change
        if (rem.intLen == nlen)
        {
            rem.offset = 0;
            rem.value[0] = 0;
            rem.intLen++;
        }

        int dh = d[0];
        long dhLong = dh & LONG_MASK;
        int dl = d[1];
        int[] qWord = new int[2];

        // D2 Initialize j


        for(int j = 0; j < limit; j++)
        {
            // D3 Calculate qhat
            // estimate qhat
            int qhat = 0;
            int qrem = 0;
            boolean skipCorrection = false;
            int nh = rem.value[j+rem.offset];
            int nh2 = nh + 0x80000000;              // 2,147,483 -- allowable positive unsigned int range
            int nm = rem.value[j + 1 + rem.offset];

            if (nh == dh)
            {
                qhat = ~0;
                qrem = nh + nm;
                skipCorrection = qrem + 0x80000000 < nh2;
            }
            else
            {
                long nChunk = (((long)nh) << 32) | (nm & LONG_MASK);

                if (nChunk >= 0)
                {
                    qhat = (int) (nChunk / dhLong);
                    qrem = (int) (nChunk - (qhat * dhLong));
                }
                else
                {
                    divWord(qWord, nChunk, dh);
                    qhat = qWord[0];
                    qrem = qWord[1];
                }
            }

            if (qhat == 0)
                continue;

            // Correct qhat
            if (!skipCorrection)
            {
                long nl = rem.value[j + 2 + rem.offset] & LONG_MASK;
                long rs = ((qrem & LONG_MASK) << 32) | nl;
                long estProduct = (dl & LONG_MASK) * (qhat & LONG_MASK);

                if (unsignedLongCompare(estProduct, rs))
                {
                    qhat--;
                    qrem = (int)((qrem & LONG_MASK) + dhLong);

                    if ((qrem & LONG_MASK) >=  dhLong)
                    {
                        estProduct = (dl & LONG_MASK) * (qhat & LONG_MASK);
                        rs = ((qrem & LONG_MASK) << 32) | nl;

                        if (unsignedLongCompare(estProduct, rs))
                            qhat--;
                    }
                }
            }

            // D4 Multiply and subtract
            rem.value[j+rem.offset] = 0;
            int borrow = mulsub(rem.value, d, qhat, dlen, j+rem.offset);

            // D5 Test remainder
            if (borrow + 0x80000000 > nh2)
            {
                // D6 Add back
                divadd(d, rem.value, j+1+rem.offset);
                qhat--;
            }

            // Store the quotient digit
            q[j] = qhat;
        }

        // D7 loop on j

        // D8 Unnormalize
        if (shift > 0)
            rem.rightShift(shift);

        rem.normalize();
        quotient.normalize();
    }





    /******************************************************************************
     METHOD		    : divadd

     DESCRIPTION	: This method is a primitive used for division. This method
                      adds in one multiple of the divisor a back to the dividend
                      result at a specified offset.
                      It is used when qhat was estimated too large, and must be
                      adjusted.

     INPUT			: Type			: int[]
                    : Description	: Divisor

                    : Type			: int[]
                    : Description	: Remainder from division

                    : Type			: int
                    : Description	: Carried offset from division calculation

     OUTPUT			: Type 			: int
                    : Description	: The carry bit (as int)
     ******************************************************************************/
    private int divadd(int[] a, int[] result, int offset)
    {
        long carry = 0;

        for (int j = a.length-1; j >= 0; j--)
        {
            long sum = (a[j] & LONG_MASK) + (result[j+offset] & LONG_MASK) + carry;
            result[j+offset] = (int)sum;
            carry = sum >>> 32;
        }

        return (int)carry;
    }





    /******************************************************************************
     METHOD		    : mulsub

     DESCRIPTION	: This method is used for division. It multiplies an n word
                      input a by one word input x, and subtracts the n word
                      product from q. This is needed when subtracting
                      qhat * divisor from dividend.

     INPUT			: Type			: int[]
                    : Description	: XOR'd quotient as reference from division method

                    : Type			: int[]
                    : Description	:

                    : Type			: int
                    : Description	: Used as a long value in method

                    : Type			: int
                    : Description	: Length (bits) of HugeInteger.

                    : Type			: int
                    : Description	: Carried offset from division calculation

     OUTPUT			: Type 			: int
                    : Description	: The carry bit (as int)
     ******************************************************************************/
    private int mulsub(int[] q, int[] a, int x, int len, int offset)
    {
        long xLong = x & LONG_MASK; // treat as unsigned int i.e. positive or 2 * |n|
        long carry = 0;

        offset += len;

        for (int j = len-1; j >= 0; j--)
        {
            long product = (a[j] & LONG_MASK) * xLong + carry;
            long difference = q[offset] - product;
            q[offset--] = (int)difference;
            carry = (product >>> 32) + (((difference & LONG_MASK) > (((~(int)product) & LONG_MASK))) ? 1 : 0);
        }

        return (int)carry;
    }





    /******************************************************************************
     METHOD		    : normalize

     DESCRIPTION	: This method ensures that the MutableHugeInteger is in normal
                      form, specifically making sure that there are no leading zeros,
                      and that if the magnitude is zero, then intLen is zero.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void normalize()
    {
        if (intLen == 0)
        {
            offset = 0;
            return;
        }

        int index = offset;

        if (value[index] != 0)
            return;

        int indexBound = index + intLen;

        do
        {
            index++;
        } while(index < indexBound && value[index] == 0);

        int numZeros = index - offset;
        intLen -= numZeros;
        offset = (intLen == 0 ?  0 : offset + numZeros);
    }





    /******************************************************************************
     METHOD		    : leftShift

     DESCRIPTION	: This method left shifts this MutableHugeInteger n bits.

     INPUT			: Type			: int
                    : Description	: Number of bits to be shifted.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void leftShift(int n)
    {
     /*
      * If there is enough storage space in this MutableHugeInteger already,
      * the available space will be used. Space to the right of the used
      * ints in the value array is faster to utilize, so the extra space
      * will be taken from the right if possible.
      */
        if (intLen == 0)
            return;

        int nInts = n >>> 5;
        int nBits = n & 0x1F;               // 31
        int bitsInHighWord = bitLen(value[offset]);

        // If shift can be done without moving words, do so
        if (n <= (32-bitsInHighWord))
        {
            primitiveLeftShift(nBits);
            return;
        }

        int newLen = intLen + nInts +1;

        if (nBits <= (32-bitsInHighWord))
            newLen--;

        if (value.length < newLen)
        {
            // The array must grow
            int[] result = new int[newLen];

            for (int i = 0; i < intLen; i++)
                result[i] = value[offset+i];

            setValue(result, newLen);
        }

        else if (value.length - offset >= newLen)
        {
            // Use space on right
            for(int i = 0; i < newLen - intLen; i++)
                value[offset+intLen+i] = 0;
        }
        else
        {
            // Must use space on left
            for (int i = 0; i < intLen; i++)
                value[i] = value[offset+i];

            for (int i = intLen; i < newLen; i++)
                value[i] = 0;

            offset = 0;
        }

        intLen = newLen;

        if (nBits == 0)
            return;

        if (nBits <= (32-bitsInHighWord))
            primitiveLeftShift(nBits);

        else
            primitiveRightShift(32 -nBits);
    }




    /******************************************************************************
     METHOD		    : rightShift

     DESCRIPTION	: This method right shifts this MutableHugeInteger n bits.
                      The MutableHugeInteger is left in normal form.

     INPUT			: Type			: int
                    : Description	: Number of bits to be shifted.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void rightShift(int n)
    {
        if (intLen == 0)
            return;

        int nInts = n >>> 5;
        int nBits = n & 0x1F; // get top word (high word of int)
        this.intLen -= nInts;

        if (nBits == 0)
            return;

        int bitsInHighWord = bitLen(value[offset]);

        if (nBits >= bitsInHighWord)
        {
            this.primitiveLeftShift(32 - nBits);
            this.intLen--;
        }
        else
            primitiveRightShift(nBits);
    }




    /******************************************************************************
     METHOD		    : primitiveLeftShift

     DESCRIPTION	: This method left shifts this MutableHugeInteger n bits, where n is less than 32.
                      Assumes that intLen > 0, n > 0 for speed.

     INPUT			: Type			: int
                    : Description	: Number of bits to be shifted.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void primitiveLeftShift(int n)
    {
        int[] val = value;
        int n2 = 32 - n;

        for (int i = offset, c = val[i], m = i + intLen-1; i < m; i++)
        {
            int b = c;
            c = val[i+1];
            val[i] = (b << n) | (c >>> n2); // note: << is logical shift left (move highest bit to carry flag)
                                            // note: >>> is arithmetic shift right (keep msb, i.e. sign)
        }

        val[offset + intLen-1] <<= n;
    }





    /******************************************************************************
     METHOD		    : primitiveRightShift

     DESCRIPTION	: This method right shifts this MutableHugeInteger n bits,
                      where n is less than 32. Assumes that intLen > 0, n > 0 for
                      speed

     INPUT			: Type			: int
                    : Description	: Number of bits to be shifted.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void primitiveRightShift(int n)
    {
        int[] val = value;
        int n2 = 32 - n;

        for (int i = offset + intLen-1, c = val[i]; i > offset; i--)
        {
            int b = c;
            c = val[i-1];
            val[i] = (c << n2) | (b >>> n); // note: << is logical shift left (move highest bit to carry flag)
                                            // note: >>> is arithmetic shift right (keep msb, i.e. sign)
        }

        val[offset] >>>= n;
    }





    /******************************************************************************
     METHOD		    : setValue

     DESCRIPTION	: This method sets this MutableHugeInteger's value array to
                      the specified array. The intLen is set to the specified length.

     INPUT			: Type			: int[]
                    : Description	: The value to be set.

                    : Type			: int
                    : Description	: The length of the HugeInteger.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void setValue(int[] val, int length)
    {
        value = val;
        intLen = length;
        offset = 0;
    }


    /******************************************************************************
     METHOD		    : unsignedLongCompare

     DESCRIPTION	: This method compares two longs as if they were unsigned.

     INPUT			: Type			: long
                    : Description	: First long to compare.

                    : Type			: long
                    : Description	: Second long to compare.

     OUTPUT			: Type 			: boolean
                    : Description	: Returns true iff one is bigger than two.
     ******************************************************************************/
    private boolean unsignedLongCompare(long one, long two)
    {
        return (one + Long.MIN_VALUE) > (two + Long.MIN_VALUE);
    }
}


 //region
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/math/MutableBigInteger.java

 /*

    * Copyright 1999-2007 Sun Microsystems, Inc.  All Rights Reserved.

    * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.

    *

    * This code is free software; you can redistribute it and/or modify it

    * under the terms of the GNU General Public License version 2 only, as

    * published by the Free Software Foundation.  Sun designates this

    * particular file as subject to the "Classpath" exception as provided

    * by Sun in the LICENSE file that accompanied this code.

   *

   * This code is distributed in the hope that it will be useful, but WITHOUT

   * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or

   * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License

   * version 2 for more details (a copy is included in the LICENSE file that

   * accompanied this code).

   *

   * You should have received a copy of the GNU General Public License version

   * 2 along with this work; if not, write to the Free Software Foundation,

   * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.

   *

   * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa Clara,

   * CA 95054 USA or visit www.sun.com if you need additional information or

   * have any questions.

   */
//endregion