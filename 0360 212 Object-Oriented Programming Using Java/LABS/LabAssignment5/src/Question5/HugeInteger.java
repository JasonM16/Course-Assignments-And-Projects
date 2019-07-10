/**
 * PROJECT          : Lab 5 - Question 5
 * FILE             : HugeInteger.java
 * AUTHOR           : Jason Choquette - 104337378
 * LAST MODIFIED    : March 12, 2017
 * REQUIREMENTS     : Create a class HugeInteger which uses a 40-element array of digits to store integers as large
 *                    as 40 digits each.
 *
 *                    Provide methods parse, toString, add and subtract.
 *                    Method parse should receive a String, extract each digit using method charAt and place the integer
 *                    equivalent of each digit into the integer array.
 *
 *                    For comparing HugeInteger objects, provide the following methods: isEqualTo, isNotEqualTo,
 *                    isGreaterThan, isLessThan, isGreaterThanOrEqualTo and isLessThanOrEqualTo.
 *
 *                    Each of these is a predicate method that returns true if the relationship holds between the
 *                    two HugeInteger objects and returns false if the relationship does not hold. Provide a predicate
 *                    method isZero.
 */

package Question5;


public class HugeInteger implements Comparable<HugeInteger>
{
    // This mask is used to obtain the value of an int as if it were unsigned.
    private final static long LONG_MASK = 0xffffffffL;

    //The index of the lowest-order int in the hugeInteger of this HugeInteger that contains a nonzero int, or -2
    // (either value is acceptable). The least significant int has int-number 0, the next int in order of increasing
    // significance has int-number 1, and so forth.
    private int firstNonzeroIntNum = -2;

    // The sign of this HugeInteger: -1 for negative, 0 for zero, or 1 for positive.
    // Note that the HugeInteger zero must have a sign of 0. This is necessary to ensures that there is exactly one
    // representation for each BigInteger value.
    private int sign;

    // The hugeInteger of this HugeInteger, in big-endian order: the zeroth element of this array is the most-significant
    // int of the hugeInteger.
    // The hugeInteger must be "minimal" in that the most-significant int (mag[0]) must be non-zero. This is necessary
    // to ensure that there is exactly one representation for each HugeInteger value.
    // Note that this implies that the HugeInteger zero has a zero-length mag array.
    private int[] hugeInteger = new int[40];

    private static String zeros[] = {"0000000000000000000000000000000000000000"};

    // The HugeInteger constant zero.
    private static final HugeInteger ZERO = new HugeInteger(new int[0], 0);




    //************************************* CONSTRUCTORS ************************************//
    /******************************************************************************
     CONSTRUCTOR    : HugeInteger

     DESCRIPTION	: This private constructor differs from its public cousin
                      with the arguments reversed in two ways: it assumes that its
                      arguments are correct, and it doesn't copy the hugeInteger
                      array.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    private HugeInteger(int[] hugeInteger, int signum)
    {
        this.sign = (hugeInteger.length == 0 ? 0 : signum);
        this.hugeInteger = hugeInteger;
    }





    /******************************************************************************
     CONSTRUCTOR    : HugeInteger

     DESCRIPTION	: Translates the decimal String representation of a HugeInteger
                      into a HugeInteger. The String representation consists of
                      an optional minus sign followed by a sequence of one or more
                      decimal digits.
                      The character-to-digit mapping is provided by Character.digit.
                      The String may not contain any extraneous characters
                      (whitespace, for example).

     INPUT			: Type			: String
                    : Description	: The String value of HugeInteger.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    HugeInteger(String val)
    {
        parse(val);
    }





    /******************************************************************************
     CONSTRUCTOR    : HugeInteger

     DESCRIPTION	: Constructs a HugeInteger with the specified value, which may
                      not be zero.

     INPUT			: Type			: long
                    : Description	: value of HugeInteger.

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    private HugeInteger(long val)
    {
        if (val < 0)
        {
            sign = -1;
            val = -val;
        }
        else
            sign = 1;

        int highWord = (int)(val >>> 32);
        if (highWord == 0)
        {
            hugeInteger = new int[1];
            hugeInteger[0] = (int)val;
        }
        else
        {
            hugeInteger = new int[2];
            hugeInteger[0] = highWord;
            hugeInteger[1] = (int)val;
        }
    }





    /******************************************************************************
     CONSTRUCTOR    : HugeInteger

     DESCRIPTION	: This private constructor is for internal use in converting
                      from a MutableHugeInteger object into a BigInteger.

     INPUT			: Type			: MutableHugeInteger
                    : Description	: value of HugeInteger.

                    : Type			: int
                    : Description	: sign of the new HugeInteger instance..

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    HugeInteger(MutableHugeInteger val, int sign)
    {
        if (val.offset > 0 || val.value.length != val.intLen)
        {
            hugeInteger = new int[val.intLen];

            for(int i = 0; i < val.intLen; i++)
                hugeInteger[i] = val.value[val.offset+i];
        }
        else
            hugeInteger = val.value;

        this.sign = (val.intLen == 0) ? 0 : sign;
    }
    //********************************** END CONSTRUCTORS **********************************//





    /******************************************************************************
     METHOD		    : abs

     DESCRIPTION	: This method returns a positive-valued HugeInteger instance.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: HugeInteger
                    : Description	: HugeInteger whose value is the absolute value
                                      of this.
     ******************************************************************************/
    private HugeInteger abs()
    {
        return (sign >= 0 ? this : this.negate());
    }




    /******************************************************************************
     METHOD		    : add

     DESCRIPTION	: This method adds the contents of the int arrays x and y.
                      This method allocates a new int array to hold the answer and
                      returns a reference to that array.

     INPUT			: Type			: void
                    : Description	: N/A

                    : Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: HugeInteger
                    : Description	: The resulting sum of the two HugeIntegers.
     ******************************************************************************/
    private static int[] add(int[] x, int[] y)
    {
        // If x is shorter, swap the two arrays
        if (x.length < y.length)
        {
            int[] tmp = x;
            x = y;
            y = tmp;
        }

        int xIndex = x.length;
        int yIndex = y.length;
        int result[] = new int[xIndex];
        long sum = 0;

        // Add common parts of both numbers
        while(yIndex > 0)
        {
            sum = (x[--xIndex] & LONG_MASK) + (y[--yIndex] & LONG_MASK) + (sum >>> 32);
            result[xIndex] = (int)sum;
        }

        // Copy remainder of longer number while carry propagation is required
        boolean carry = (sum >>> 32 != 0);
        while (xIndex > 0 && carry)
            carry = ((result[--xIndex] = x[xIndex] + 1) == 0);

        // Copy remainder of longer number
        while (xIndex > 0)
            result[--xIndex] = x[xIndex];

        // Grow result if necessary
        if (carry)
        {
            int newLen = result.length + 1;
            int temp[] = new int[newLen];
            for (int i = 1; i<newLen; i++)
                temp[i] = result[i-1];

            temp[0] = 0x01;
            result = temp;
        }

        return result;
    }





    /******************************************************************************
     METHOD		    : add

     DESCRIPTION	: This method adds two HugeInteger instances.

     INPUT			: Type			: HugeInteger
                    : Description	:

     OUTPUT			: Type 			: HugeInteger
                    : Description	: The resulting sum of the two HugeIntegers.
     ******************************************************************************/
    HugeInteger add(HugeInteger val)
    {
        int[] resultMag;
        if (val.sign == 0)
            return this;

        if (sign == 0)
            return val;

        if (val.sign == sign)
            return new HugeInteger(add(hugeInteger, val.hugeInteger), sign);

        int comparison = intArrayCmp(hugeInteger, val.hugeInteger);

        if (comparison == 0)
            return ZERO;

        resultMag = (comparison > 0 ? subtract(hugeInteger, val.hugeInteger) : subtract(val.hugeInteger, hugeInteger));

        resultMag = trustedStripLeadingZeroInts(resultMag);

        return new HugeInteger(resultMag, comparison * sign);
    }





    /******************************************************************************
     METHOD		    : compareTo

     DESCRIPTION	: Compares this BigInteger with the specified BigInteger.
                      This method is provided in preference to individual methods
                      for each of the six boolean comparison operators
                      (<, ==, >, >=, !=, <=). The suggested idiom for performing these
                      comparisons is:
                      (x.compareTo(y) <op> 0), where <op> is one of the six
                      comparison operators.

     INPUT			: Type			: HugeInteger
                    : Description	: BigInteger to which this BigInteger is to
                                      be compared.

     OUTPUT			: Type 			: int
                    : Description	: -1, 0 or 1 as this BigInteger is numerically
                                      less than, equal to, or greater than val.
     ******************************************************************************/
    public int compareTo(HugeInteger val)
    {
        return (sign == val.sign ? sign * intArrayCmp(hugeInteger, val.hugeInteger) : (sign > val.sign ? 1 : -1));
    }





    /******************************************************************************
     METHOD		    : destructiveMulAdd

     DESCRIPTION	: This method compares two HugeInteger instances.

     INPUT			: Type			: int[]
                    : Description	:

                    : Type			: int
                    : Description	:

                    : Type			: int
                    : Description	:

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private static void destructiveMulAdd(int[] x, int y, int z)
    {
        // Perform the multiplication word by word
        long ylong = y & LONG_MASK;
        long zlong = z & LONG_MASK;
        int len = x.length;
        long product = 0;
        long carry = 0;

        for (int i = len-1; i >= 0; i--)
        {
            product = ylong * (x[i] & LONG_MASK) + carry;
            x[i] = (int)product;
            carry = product >>> 32;
        }

        // Perform the addition
        long sum = (x[len-1] & LONG_MASK) + zlong;
        x[len-1] = (int)sum;
        carry = sum >>> 32;

        for (int i = len-2; i >= 0; i--)
        {
            sum = (x[i] & LONG_MASK) + carry;
            x[i] = (int)sum;
            carry = sum >>> 32;
        }
    }





    /******************************************************************************
     METHOD		    : firstNonzeroIntNum

     DESCRIPTION	: This method returns the index of the int that contains the
                      first nonzero int in the little-endian binary representation
                      of the magnitude (int 0 is the least significant).
                      If the magnitude is zero, return value is undefined.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: returns the index of the int that contains the
                                      first nonzero int.
     ******************************************************************************/
    private int firstNonzeroIntNum()
    {
    /*
     * Initialize firstNonzeroIntNum field the first time this method is
     * executed. This method depends on the atomicity of int modifies;
     * without this guarantee, it would have to be synchronized.
     */

        if (firstNonzeroIntNum == -2)
        {
            // Search for the first nonzero int
            int i;

            for (i = hugeInteger.length-1; i >= 0 && hugeInteger[i] == 0; i--);

            firstNonzeroIntNum = hugeInteger.length-i-1;
        }

        return firstNonzeroIntNum;
    }





    /******************************************************************************
     METHOD		    : getInt

     DESCRIPTION	: This method returns the specified int of the little-endian
                      two's complement representation (int 0 is the least significant).
                      The int number can be arbitrarily high (values are logically
                      preceded by infinitely many sign ints).

     INPUT			: Type			: int
                    : Description	:

     OUTPUT			: Type 			: int
                    : Description	: Returns int value of HugeInteger.
     ******************************************************************************/
    private int getInt(int n)
    {
        if (n < 0)
            return 0;

        if (n >= hugeInteger.length)
            return signInt();

        int magInt = hugeInteger[hugeInteger.length-n-1];

        return (sign >= 0 ? magInt : (n <= firstNonzeroIntNum() ? -magInt : ~magInt));
    }





    /******************************************************************************
     METHOD		    : intArrayCmp

     DESCRIPTION	: Returns -1, 0 or +1 as big-endian unsigned int array arg1 is
                      less than, equal to, or greater than arg2.

     INPUT			: Type			: int
                    : Description	: First HugeInteger array

     OUTPUT			: Type 			: int
                    : Description	: Second HugeInteger array
     ******************************************************************************/
    private static int intArrayCmp(int[] arg1, int[] arg2)
    {
        if (arg1.length < arg2.length)
            return -1;

        if (arg1.length > arg2.length)
            return 1;

        // Argument lengths are equal; compare the values
        for (int i = 0; i < arg1.length; i++)
        {
            long b1 = arg1[i] & LONG_MASK; // treat as an unsigned int
            long b2 = arg2[i] & LONG_MASK; // treat as an unsigned int
            if (b1 < b2)
                return -1;
            if (b1 > b2)
                return 1;
        }

        return 0;
    }





    /******************************************************************************
     METHOD		    : isGreaterThan

     DESCRIPTION	: This method tests whether 'this' HugeInteger instance is
                      greater than the argument instance.

     INPUT			: Type			: HugeInteger
                    : Description	: instance to compare 'this' to.

     OUTPUT			: Type 			: boolean
                    : Description	: True if 'this' instance is greater.
                                      False, otherwise.
     ******************************************************************************/
    boolean isGreaterThan(HugeInteger that)
    {
        return this.compareTo(that) > 0;
    }





    /******************************************************************************
     METHOD		    : isLessThan

     DESCRIPTION	: This method tests whether 'this' HugeInteger instance is less
                      than the argument instance.

     INPUT			: Type			: HugeInteger
                    : Description	: instance to compare 'this' to.

     OUTPUT			: Type 			: boolean
                    : Description	: True if 'this' instance is less.
                                      False, otherwise.
     ******************************************************************************/
    boolean isLessThan(HugeInteger that)
    {
        return this.compareTo(that) < 0;
    }





    /******************************************************************************
     METHOD		    : isGreaterThanOrEqualTo

     DESCRIPTION	: This method tests whether 'this' HugeInteger instance is
                      greater than or equal to the argument instance.

     INPUT			: Type			: HugeInteger
                    : Description	: instance to compare 'this' to.

     OUTPUT			: Type 			: boolean
                    : Description	: True if 'this' instance is greater or equal.
                                      False, otherwise.
    ******************************************************************************/
    boolean isGreaterThanOrEqualTo(HugeInteger that)
    {
        return isEqualTo(that) | isGreaterThan(that);
    }





    /******************************************************************************
     METHOD		    : isLessThanOrEqualTo

     DESCRIPTION	: This method tests whether 'this' HugeInteger instance is less
                      than or equal to the argument instance.

     INPUT			: Type			: HugeInteger
                    : Description	: instance to compare 'this' to.

     OUTPUT			: Type 			: boolean
                    : Description	: True if 'this' instance is less or equal.
                                      False, otherwise.
    ******************************************************************************/
    boolean isLessThanOrEqualTo(HugeInteger that)
    {
        return isEqualTo(that) | isLessThan(that);
    }





    /******************************************************************************
     METHOD		    : isZero

     DESCRIPTION	: This method tests whether a number is zero.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: boolean
                    : Description	: True if the number is zero. False, otherwise.
    ******************************************************************************/
    public boolean isZero()
    {
        return this.sign == 0;
    }





    /******************************************************************************
     METHOD		    : isEqualTo

     DESCRIPTION	: This method tests whether two HugeInteger instances are equal.

     INPUT			: Type			: HugeInteger
                    : Description	: instance to compare 'this' to

     OUTPUT			: Type 			: boolean
                    : Description	: True if instances are equal. False, otherwise.
     ******************************************************************************/
    public boolean isEqualTo(HugeInteger that)
    {
        return this.compareTo(that) == 0;
    }





    /******************************************************************************
     METHOD		    : isNotEqualTo

     DESCRIPTION	: This method tests whether two HugeInteger instances are not
                      equal.

     INPUT			: Type			: HugeInteger
                    : Description	: instance to compare 'this' to

     OUTPUT			: Type 			: boolean
                    : Description	: True if instances are not equal.
                                      False, otherwise.
     ******************************************************************************/
    public boolean isNotEqualTo(HugeInteger that)
    {
        return !isEqualTo(that);
    }





    /******************************************************************************
     METHOD		    : longValue

     DESCRIPTION	: This method Converts this BigInteger to a long.
                      This conversion is analogous to a narrowing primitive
                      conversion from long to int as defined in the Java Language
                      Specification: if this BigInteger is too big to fit in a long,
                      only the low-order 64 bits are returned.

                      Note that this conversion can lose information about the
                      overall magnitude of the BigInteger value as well as return a
                      result with the opposite sign.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: long
                    : Description	: this BigInteger converted to a long
     ******************************************************************************/
    long longValue()
    {
        long result = 0;
        for (int i = 1; i >= 0; i--)
            result = (result << 32) + (getInt(i) & LONG_MASK);

        return result;
    }





    /******************************************************************************
     METHOD		    : negate

     DESCRIPTION	: Returns a BigInteger whose value is (-this).

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: HugeInteger
                    : Description	: -this
     ******************************************************************************/
    HugeInteger negate()
    {
        return new HugeInteger(this.hugeInteger, -this.sign);
    }





    /******************************************************************************
     METHOD		    : parse

     DESCRIPTION	: This method translates the String representation of a
                      HugeInteger in the specified radix into a BigInteger.
                      The String representation consists of an optional minus
                      followed by a sequence of one or more digits in the
                      specified radix.
                      The character-to-digit mapping is provided by Character.digit.
                      The String may not contain any extraneous characters
                      (whitespace, for example).

     INPUT			: Type			: String
                    : Description	: String representation of a HugeInteger.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    void parse(String val)
    {
        int cursor = 0, numDigits;
        int len = val.length();

        if (val.length() == 0)
            throw new NumberFormatException("Zero length HugeInteger");

        // Check for at most one leading sign
        sign = 1;
        int index = val.lastIndexOf('-');

        if (index != -1)
        {
            if (index == 0 )
            {
                if (val.length() == 1)
                    throw new NumberFormatException("Zero length HugeInteger");

                sign = -1;
                cursor = 1;
            }
            else
                throw new NumberFormatException("Illegal embedded sign character");
        }

        // Skip leading zeros and compute number of digits in hugeInteger
        while (cursor < len && Character.digit(val.charAt(cursor), 10) == 0)
            cursor++;

        if (cursor == len)
        {
            sign = 0;
            hugeInteger = ZERO.hugeInteger;
            return;
        }
        else
            numDigits = len - cursor;

        // Pre-allocate array of expected size. May be too large but can
        // never be too small. Typically exact.
        int numBits = (int)(((numDigits * 3402) >>> 10) + 1); // 3402  bitsPerDigit[radix]
        int numWords = (numBits + 31) /32;
        hugeInteger = new int[numWords];

        // Process first (potentially short) digit group
        int firstGroupLen = numDigits % 9;  // digitsPerInt[radix]

        if (firstGroupLen == 0)
            firstGroupLen = 9;  // digitsPerInt[radix]

        String group = val.substring(cursor, cursor += firstGroupLen);
        hugeInteger[hugeInteger.length - 1] = Integer.parseInt(group);

        if (hugeInteger[hugeInteger.length - 1] < 0)
            throw new NumberFormatException("Illegal digit");

        // Process remaining digit groups
        int superRadix = 0x3b9aca00; //1_000_000_000
        int groupVal;

        while (cursor < val.length())
        {
            group = val.substring(cursor, cursor += 9);   // digitsPerInt[radix]
            groupVal = Integer.parseInt(group);

            if (groupVal < 0)
                throw new NumberFormatException("Illegal digit");

            destructiveMulAdd(hugeInteger, superRadix, groupVal);
        }

        // Required for cases where the array was over-allocated.
        hugeInteger = trustedStripLeadingZeroInts(hugeInteger);
    }





    /******************************************************************************
     METHOD		    : primitiveLeftShift

     DESCRIPTION	: This method

     INPUT			: Type			: int[]
                    : Description	: HugeInteger value

                    : Type			: int
                    : Description	: Length of the HugeInteger value

                    : Type			: int
                    : Description	: Number of bits to shift.

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    static void primitiveLeftShift(int[] a, int len, int n)
    {
        if (len == 0 || n == 0)
            return;

        int n2 = 32 - n;

        for (int i = 0, c = a[i], m = i + len-1; i < m; i++)
        {
            int b = c;
            c = a[i+1];
            a[i] = (b << n) | (c >>> n2); //
        }

        a[len-1] <<= n;
    }





    /******************************************************************************
     METHOD		    : signInt

     DESCRIPTION	: This method returns -1 or 0 if this is negative or positive,
                      respectfully.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: The sign of this HugeInteger.
     ******************************************************************************/
    private int signInt()
    {
        return sign < 0 ? -1 : 0;
    }





    /******************************************************************************
     METHOD		    : subtract

     DESCRIPTION	: This method returns a HugeInteger whose value is (this - val)

     INPUT			: Type			: HugeInteger
                    : Description	: value to be subtracted from this.

     OUTPUT			: Type 			: HugeInteger
                    : Description	: this - val
     ******************************************************************************/
    public HugeInteger subtract(HugeInteger val)
    {
        int[] resultMag;
        if (val.sign == 0)
            return this;

        if (sign == 0)
            return val.negate();

        if (val.sign != sign)
            return new HugeInteger(add(hugeInteger, val.hugeInteger), sign);

        int cmp = intArrayCmp(hugeInteger, val.hugeInteger);

        if (cmp == 0)
            return ZERO;

        resultMag = (cmp > 0 ? subtract(hugeInteger, val.hugeInteger) : subtract(val.hugeInteger, hugeInteger));

        resultMag = trustedStripLeadingZeroInts(resultMag);

        return new HugeInteger(resultMag, cmp * sign);
    }





    /******************************************************************************
     METHOD		    : subtract

     DESCRIPTION	: This method Subtracts the contents of the second int arrays
                      (little) from the first (big).
                      The first int array (big) must represent a larger number than the second.
                      This method allocates the space necessary to hold the answer.

     INPUT			: Type			: int[]
                    : Description	: The larger HugeInteger value

                    : Type			: int[]
                    : Description	: The smaller HugeInteger value

     OUTPUT			: Type 			: int[]
                    : Description	: The resulting difference of the two
                                      arrays.
     ******************************************************************************/
    private static int[] subtract(int[] big, int[] little)
    {
        int bigIndex = big.length;
        int result[] = new int[bigIndex];
        int littleIndex = little.length;
        long difference = 0;

        // Subtract common parts of both numbers
        while(littleIndex > 0)
        {
            difference = (big[--bigIndex] & LONG_MASK) - (little[--littleIndex] & LONG_MASK) + (difference >> 32);
            result[bigIndex] = (int)difference;
        }
        // Subtract remainder of longer number while borrow propagates

        boolean borrow = (difference >> 32 != 0);
        while (bigIndex > 0 && borrow)
            borrow = ((result[--bigIndex] = big[bigIndex] - 1) == -1);

        // Copy remainder of longer number
        while (bigIndex > 0)
            result[--bigIndex] = big[bigIndex];

        return result;
    }




    /******************************************************************************
     METHOD		    : toString

     DESCRIPTION	: This method prints the numeric value of the HugeInteger.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: HugeInteger as a string.
     ******************************************************************************/
    public String toString()
    {
        if (sign == 0)
            return "0";

        // Compute upper bound on number of digit groups and allocate space
        int maxNumDigitGroups = (4* hugeInteger.length + 6)/7;
        String digitGroup[] = new String[maxNumDigitGroups];

        // Translate number to string, a digit group at a time
        HugeInteger tmp = this.abs();
        int numGroups = 0;

        while (tmp.sign != 0)
        {
            HugeInteger d =  new HugeInteger(0xde0b6b3a7640000L); // longRadix[radix]; // 1,000,000,000,000,000,000
            MutableHugeInteger q = new MutableHugeInteger(),
                    r = new MutableHugeInteger(),
                    a = new MutableHugeInteger(tmp.hugeInteger),
                    b = new MutableHugeInteger(d.hugeInteger);
            a.divide(b, q, r);
            HugeInteger q2 = new HugeInteger(q, tmp.sign * d.sign);
            HugeInteger r2 = new HugeInteger(r, tmp.sign * d.sign);
            digitGroup[numGroups++] = Long.toString(r2.longValue(), 10);
            tmp = q2;
        }

        // Put sign (if any) and first digit group into result buffer
        StringBuilder buf = new StringBuilder(numGroups*18+1); // 18 digitsPerLong[radix]

        if (sign < 0)
            buf.append('-');

        buf.append(digitGroup[numGroups-1]);

        // Append remaining digit groups padded with leading zeros
        for (int i = numGroups-2; i >= 0; i--)
        {
            // Prepend (any) leading zeros for this digit group
            int numLeadingZeros = 18-digitGroup[i].length(); // 18 digitsPerLong[radix]

            if (numLeadingZeros != 0)
                buf.append(zeros[numLeadingZeros]);

            buf.append(digitGroup[i]);
        }

        return buf.toString();
    }







    /******************************************************************************
     METHOD		    : trustedStripLeadingZeroInts

     DESCRIPTION	: Returns the input array stripped of any leading zero bytes.
                      Since the source is trusted the copying may be skipped.

     INPUT			: Type			: int[]
                    : Description	: HugeInteger value

     OUTPUT			: Type 			: int[]
                    : Description	: The original HugeInteger value with leading
                                      leading zeros removed.
     ******************************************************************************/
    private static int[] trustedStripLeadingZeroInts(int val[])
    {
        int keep;

        // Find first nonzero byte
        for (keep = 0; keep < val.length && val[keep] == 0; keep++);

        // Only perform copy if necessary
        if (keep > 0)
        {
            int result[] = new int[val.length - keep];
            for(int i = 0; i < val.length - keep; i++)
                result[i] = val[keep+i];

            return result;
        }

        return val;
    }
}


 // region
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/math/BigInteger.java

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