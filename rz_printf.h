/***************************************************************************//**
 * @file    rz_printf.h
 * @author 	Youmin
 * @data    20190814
 * @version 0.0.3
 *
 ******************************************************************************/
#ifndef RZ_PRINTF_H
#define RZ_PRINTF_H

// ==================================================
//                  configuration
// ==================================================
#define RZ_PRINTF_BUFFER_SIZE   512



 // ==================================================
 //                  type define
 // ==================================================
#if 1
#define FIRMWARE_VERSION_MAJOR       ('0')
#define FIRMWARE_VERSION_MINOR       ('0')
#define FIRMWARE_VERSION_PATCH       ('3')

#define U8      unsigned char
#define U16     unsigned short
#define U32     unsigned int
#define U64     unsigned long long
#define S8      char
#define S16     short
#define S32     int
#define S64     long long

#endif

#define _FLAG_LEFT          0x1
#define _FLAG_SIGN          0x2
#define _FLAG_SPACE         0x4
#define _FLAG_0X            0x8
#define _FLAG_ZERO_PAD      0x10
#define _FLAG_LONG          0x20
#define _FLAG_LONG_LONG     0x40
#define _FLAG_SHORT         0x80
#define _FLAG_CHAR          0x100
#define _FLAG_DOUBLE        0x200
#define _FLAG_LONG_DOUBLE   0x400
#define _FLAG_PRECISION     0x800
#define _FLAG_UPPERCASE     0x1000
#define _ARG_TYPE_S         0x10000         //signed
#define _ARG_TYPE_F         0x20000         //float
#define _ARG_TYPE_U         0x40000         //unsigned
#define _ARG_TYPE_N         0X80000         //one string -> direct over
#define _ARG_TYPE_D         0X100000        //one arg -> direct over

// ==================================================
//                  prototypes
// ==================================================
void rz_printf_init(void (*put)(S8));
U32 rz_printf(const S8 * myStr, ...);
U32 rz_sprintf(char *des, const char * myFormat, ...);
U32 rz_vsprintf(S8* des, S8* begin, S8* argAddr);

void rz_memset(S8* str, S32 value, U32 size);
void rz_memCpy(S8* des, S8* src, U32 size);

U32 rz_atoi(S8* a);

U32 rz_itoa(U32 val, S8* buf, U8 base);
U32 rz_itoa64(U64 val, S8* buf, U8 base);
U32 rz_ftoa(double f, S8* buf, U8 prec);

U32 rz_isDigit(S8 c);
U32 rz_strlen(const S8* str);
U32 rz_strRev(S8* str, U32 size);
U32 rz_getFormatArg(S8 **src, S8** argP);

#endif
//
//



