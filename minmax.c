/* Display min/max limits using limits.h header file */ 

#include <stdio.h>    /* printf */
#include <limits.h>   /* limits */
#include <assert.h>   /* assert */

#define COMPUTE 1
/* used values:
 *
 * 0 - do not calculate min/max values
 * 1 - calculate min/max values with exceptions for "long" types
 * 2 - calculate min/max values without any exceptions */

/* calculate max value */
#define max(var, temp) \
  var=0; temp=0;       \
  while((++var)>0)     \
    temp++;

/* calculate min value */
#define min(var, temp) \
  var=0; temp=0;       \
  while((--var)<0)     \
    temp--;

/* print description and min/max limits using limits.h */
#define describe(description, type,  min, max) \
  printf("%s\n\tlimits.h:   <%" type ", %" type ">\n", \
         description, min, max);

/* calculate and print min/max values */
#define calculate(var, type, vmin, vmax) \
  min(var, vmin); \
  max(var, vmax); \
  printf("\tcalculated: <%" type ", %" type ">\n", \
         vmin, vmax);


int main()
{

  /* signed char */
  describe("signed char", "hhd", SCHAR_MIN, SCHAR_MAX);
# if COMPUTE 
    signed char schar, schar_max, schar_min;
    calculate(schar, "hhd", schar_min, schar_max);
    assert(schar_min == SCHAR_MIN && schar_max == SCHAR_MAX);
# endif

  /* unsigned char */
  describe("unsigned char", "hhu", 0, UCHAR_MAX);
# if COMPUTE
    unsigned char uchar, uchar_min, uchar_max;
    calculate(uchar, "hhu", uchar_min, uchar_max);
    assert(uchar_min == 0 && uchar_max == UCHAR_MAX);
# endif

  /* char */
  describe("char", "hhd", CHAR_MIN, CHAR_MAX);
# if COMPUTE
    char character, char_min, char_max;
    calculate(character, "hhd", char_min, char_max);
    assert(char_min == CHAR_MIN && char_max == CHAR_MAX);
# endif
 
  /* signed short int */
  describe("signed short int", "hd", SHRT_MIN, SHRT_MAX);
# if COMPUTE
    signed short int ssint, ssint_min, ssint_max;
    calculate(ssint, "hd", ssint_min, ssint_max);
    assert(ssint_min == SHRT_MIN && ssint_max == SHRT_MAX);
# endif

  /* unsigned short int */
  describe("unsigned short int", "hu", 0, USHRT_MAX);
# if COMPUTE
    unsigned short int usint, usint_min, usint_max;
    calculate(usint, "hu", usint_min, usint_max);
    assert(usint_min == 0 && usint_max == USHRT_MAX);
# endif

  /* signed long int */
  describe("signed long int", "ld", LONG_MIN, LONG_MAX);
# if COMPUTE == 2
    signed long int slint, slint_min, slint_max;
    calculate(slint, "ld", slint_min, slint_max);
    assert(slint_min == LONG_MIN && slint_max == LONG_MAX);
# endif

  /* unsigned long int */
  describe("unsigned long int", "lu", (unsigned long int) 0, ULONG_MAX);
# if COMPUTE == 2
    unsigned long int ulint, ulint_min, ulint_max;
    calculate(ulint, "lu", ulint_min, ulint_max);
    assert(ulint_min == 0 && ulint_max == ULONG_MAX);
# endif

#if defined __USE_ISOC99  && defined __GNUC__
    /* signed long long int */
    describe("signed long long int", "lld", LLONG_MIN, LLONG_MAX);
#   if COMPUTE == 2
      signed long long int sllint, sllint_min, sllint_max;
      calculate(sllint, "lld", sllint_min, sllint_max);
      assert(sllint_min == LLONG_MIN && sllint_max == LLONG_MAX);
#   endif

    /* unsigned long long int */
    describe("unsigned long long int", "llu", \
             (unsigned long long int) 0, ULLONG_MAX);
#   if COMPUTE == 2
      unsigned long long int ullint, ullint_min, ullint_max;
      calculate(ullint, "llu", ullint_min, ullint_max);
      assert(ullint_min == 0 && ullint_max == ULLONG_MAX);
#   endif
#endif

  /* signed int */
  describe("signed int", "d", INT_MIN, INT_MAX);
# if COMPUTE 
    signed int sint, sint_min, sint_max;
    calculate(sint, "d", sint_min, sint_max);
    assert(sint_min == INT_MIN && sint_max == INT_MAX);
# endif

  /* unsigned int */
  describe("unsigned int", "u", 0, UINT_MAX);
# if COMPUTE 
    unsigned int uint, uint_min, uint_max;
    calculate(uint, "u", uint_min, uint_max);
    assert(uint_min == 0 && uint_max == UINT_MAX);
# endif

  return 0;
}
