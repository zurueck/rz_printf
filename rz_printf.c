/***************************************************************************//**
 * @author  youmin
 * @data    20190814
 * @version 0.0.3
 *
 ******************************************************************************/
#include "rz_printf.h"


void (*rz_putchar)(S8);         //function pointer to be initialized

void rz_printf_init(void (*put)(S8)) {

    rz_putchar = put;
}

U32 rz_sprintf(char *des, const char * myFormat, ...) {

    return rz_vsprintf((S8*)des, (S8*)myFormat, (S8*)(((S8*)&myFormat)+4));
}

/**
* output to the moniter
*
* 1. finish myprintf() (uart i2c...)
* 2. use rz_printf("anything here") while coding
* 3. string size is 25, can be changed
*
*/
//format %[flags] [width] [.precision] [length] [specifier]
U32 rz_printf(const char * myStr, ...) {
    S8            strBuff[RZ_PRINTF_BUFFER_SIZE] = {0};
    U32           strBuffSize;

    strBuffSize = rz_vsprintf((S8*)strBuff, (S8*)myStr, (S8*)(((S8*)&myStr)+4));

    for (int m = 0; m<strBuffSize; m++) {
        (*rz_putchar)(strBuff[m]);
    }

    return strBuffSize;
}

//format %[flags] [width] [.precision] [length] [specifier]
U32 rz_vsprintf(S8* des, S8* begin, S8* argAddr) {
    S8* srcP = begin;
    S8* desP = des;
    S8* argP = (S8*)argAddr;
    U32 flags = 0;      //printf format
    S32 width = 0;      //printf format
    S32 prec = 0;       //printf format
    S32 leng = 0;       //printf format
    U8 base = 0;        //printf format in specifier
    U8 sign = 0;        //positive/negative number

    U32 argType = 0;

    S8* fragSta = 0;    //specifier fragment start position in *des string
    S8  fragLeng = 0;    //fragment length 

    S8 xtoaFlag = 0;

    U64 tmpPos;         //buffer
    void* vpTmp = (void*)&tmpPos;
    S32 lengTmp = 0;

    while (*srcP != 0) {
        if (*srcP != '%') {
            *desP++ = *srcP++;
            continue;
        }
        srcP++;

        fragSta = desP = desP;
        xtoaFlag = fragLeng = 0;

        //flags
        while (1) {
            switch (*srcP) {    //'0', '-', '+', ' ', '#'
                case '0':
                    flags |= _FLAG_ZERO_PAD;
                    srcP++;
                    break;
                case '-':
                    flags |= _FLAG_LEFT;
                    srcP++;
                    break;
                case '+':
                    flags |= _FLAG_SIGN;
                    srcP++;
                    break;
                case ' ':
                    flags |= _FLAG_SPACE;
                    srcP++;
                    break;
                case '#':
                    flags |= _FLAG_0X;
                    srcP++;
                    break;
                default:
                    goto LEAVE_FLAG;
            }
        }
LEAVE_FLAG:
        
        //width
        width = rz_getFormatArg(&srcP, &argP);
        if (width < 0) {
            flags |= _FLAG_LEFT;
            width = -width;
        }

        //precision
        if (*srcP == '.') {
            flags |= _FLAG_PRECISION;
            srcP++;
            prec = rz_getFormatArg(&srcP, &argP);
            if (prec < 0) {
                prec = 0;
            }
        }

        //length
        switch (*srcP) {
            case 'l':                   //long int
                leng |= _FLAG_LONG;
                srcP++;
                if (*srcP == 'l') {      //C99
                    leng |= _FLAG_LONG_LONG;
                    srcP++;
                }
                break;
            case 'h':
                leng |= _FLAG_SHORT;
                srcP++;
                if (*srcP == 'h') {      //C99
                    leng |= _FLAG_CHAR;
                    srcP++;
                }
                break;
            case 'j':                   //C99
            case 'z':                   //C99
            case 't':                   //C99
                break;
            case 'L':
                leng |= _FLAG_LONG_DOUBLE;
                break;
            default:
                break;
        }

        //specifier
        switch (*srcP) {
            case 'i':
            case 'd':
                base = 10;
                argType |= _ARG_TYPE_S;
                break;
            case 'u':
                base = 10;
                argType |= _ARG_TYPE_U;
                break;
            case 'o':
                base = 8;
                flags &= ~(_FLAG_SIGN | _FLAG_SPACE);
                argType |= _ARG_TYPE_U;
                break;
            case 'x':
            case 'X':
                base = 16;
                flags &= ~(_FLAG_SIGN | _FLAG_SPACE);
                argType |= _ARG_TYPE_U;
                break;
            case 'f':
                argType |= _ARG_TYPE_F;
                if (!(flags & _FLAG_PRECISION)) {
                    prec = 6;
                }
                if ((flags & _FLAG_LEFT)) {
                    flags &= ~_FLAG_ZERO_PAD;
                }
                break;
            case 'F':   //c99
            case 'e':   //skip
            case 'E':   //skip
            case 'g':   //skip
            case 'G':   //skip
            case 'a':   //c99
            case 'A':   //c99
                break;
            case 'c':
                if (!(flags & _FLAG_LEFT)) {
                    char l = width - 1;
                    while (l) {
                        if (flags & _FLAG_ZERO_PAD) {
                            *desP = '0';
                        } else {
                            *desP = ' ';
                        }
                        desP++;
                        l--;
                    }
                }

                *desP = *argP;
                argP += 4;
                desP++;

                if (flags & _FLAG_LEFT) {
                    char l = width - 1;
                    while (l) {
                        *desP = ' ';
                        desP++;
                        l--;
                    }
                }
                argType |= _ARG_TYPE_D;     //done
                break;
            case 's':
                flags &= ~_FLAG_SPACE;
                flags &= ~_FLAG_SIGN;
                flags &= ~_FLAG_0X;
                vpTmp = (void*)*(unsigned int*)argP;
                argP += 4;
                lengTmp = rz_strlen((S8*)vpTmp);

                if (flags & _FLAG_PRECISION) {
                    if (lengTmp > prec) {
                        lengTmp = prec;
                    } else {
                        prec = lengTmp;
                    }
                }
                
                if (flags & _FLAG_LEFT) {
                    flags &= ~_FLAG_ZERO_PAD;
                }

                for (int m = 0; m<lengTmp; m++) {
                    *desP++ = *(S8*)vpTmp++;
                }

                argType |= _ARG_TYPE_N;     //done
                break;
            case 'p':   //not finish yet
            case 'n':   //lazy
                break;
            case '%':
                *desP = '%';
                desP++;
                srcP++;
                argType |= _ARG_TYPE_D;     //done
                break;
            default:
                break;
        }


        if (argType & _ARG_TYPE_S) {
            if (flags & _FLAG_LONG_LONG) {
                *(S64*)vpTmp = *(long long*)argP;
                argP += 8;
                if (*(S64*)vpTmp < 0) {
                    sign = 1;
                    *(U64*)vpTmp = -*(S64*)vpTmp;
                }
                lengTmp = rz_itoa64(*(U64*)vpTmp, desP, base);
                desP += lengTmp;
                xtoaFlag = 1;
            } else {
                *(S32*)vpTmp = *(S32*)argP;
                argP += 4;
                if (*(S32*)vpTmp < 0) {
                    sign = 1;
                    *(U32*)vpTmp = -*(S32*)vpTmp;
                } else {
                    *(U32*)vpTmp = *(S32*)vpTmp;
                }
                lengTmp = rz_itoa(*(U32*)vpTmp, desP, base);
                desP += lengTmp;
                xtoaFlag = 1;
            }
        } else if (argType & _ARG_TYPE_F) {
            *(double*)vpTmp = *(double*)argP;
            argP += 8;
            flags &= ~_FLAG_0X;
            if (!(flags & _FLAG_PRECISION)) {
                prec = 6;
            }

            if ((flags & _FLAG_LEFT)) {
                flags &= ~_FLAG_ZERO_PAD;
            }

            lengTmp = rz_ftoa(*(double*)vpTmp, desP, prec);
            desP += lengTmp;
            xtoaFlag = 1;

        } else if (argType & _ARG_TYPE_U) {
            if (flags & _FLAG_LONG_LONG) {
                *(U64*)vpTmp = *(unsigned long long*)argP;
                argP += 8;
                argP += 8;
                lengTmp = rz_itoa64(*(U64*)vpTmp, desP, base);
                desP += lengTmp;
                xtoaFlag = 1;
            } else {
                *(U32*)vpTmp = *(unsigned int*)argP;
                argP += 4;
                lengTmp = rz_itoa(*(U32*)vpTmp, desP, base);
                desP += lengTmp;
                xtoaFlag = 1;
            }
        } else if (argType & _ARG_TYPE_D) {
            continue;
        } else if (argType & _ARG_TYPE_N) {
            desP += lengTmp;
            srcP++;
            continue;       //try to remove later
        } else {            //ARG_TYPE_N
            //do nothing
        }

        if (flags & _FLAG_SIGN) {
            if (sign) {
                if (xtoaFlag) {
                    rz_strRev(fragSta, lengTmp);
                }
                *desP++ = '-';
                if (xtoaFlag) {
                    rz_strRev(fragSta, lengTmp + 1);
                }
            } else {
                if (xtoaFlag) {
                    rz_strRev(fragSta, lengTmp);
                }
                *desP++ = '+';
                if (xtoaFlag) {
                    rz_strRev(fragSta, lengTmp + 1);
                }
            }
            fragLeng++;
        } else if (flags & _FLAG_SPACE) {
            if (xtoaFlag) {
                rz_strRev(fragSta, lengTmp);
            }
            *desP++ = ' ';
            if (xtoaFlag) {
                rz_strRev(fragSta, lengTmp + 1);
            }
            fragLeng++;
        }

        //add 0
        if (flags & _FLAG_PRECISION) {
            flags &= ~_FLAG_ZERO_PAD;
            if (prec == 0) {
                prec = lengTmp;
            }
            if (prec-lengTmp > 0) {
                if (xtoaFlag) {
                    rz_strRev(fragSta, lengTmp);
                }
                for (int m = 0; m<prec-lengTmp; m++) {
                    *desP++ = '0';
                }
                if (xtoaFlag) {
                    rz_strRev(fragSta, lengTmp + prec-lengTmp);
                }
                fragLeng += prec - lengTmp;
            }
        }

        if (flags & _FLAG_0X) {
            if (xtoaFlag) {
                rz_strRev(fragSta, lengTmp);
            }
            *desP++ = 'x';
            fragLeng++;
            *desP++ = '0';
            fragLeng++;
            if (xtoaFlag) {
                rz_strRev(fragSta, lengTmp + 2);
            }
        }

        if (flags & _FLAG_ZERO_PAD) {
            for (int m = 0; m<width-lengTmp-fragLeng; m++) {
                *desP++ = '0';
            }
            fragLeng += prec-lengTmp-fragLeng;
        }

        // add string
        fragLeng += lengTmp;

        if (width > fragLeng) {
            if (flags & _FLAG_LEFT) {
                for (int m = 0; m<(width-fragLeng); m++) {
                    *desP++ = ' ';
                }
                fragLeng += width - fragLeng;
            } else {
                rz_strRev(fragSta, fragLeng);
                for (int m = 0; m<(width-fragLeng); m++) {
                    *desP++ = ' ';
                }
                fragLeng += width - fragLeng;
                rz_strRev(fragSta, fragLeng);
            }
        }

        srcP++;
    }

    return desP - des;
}


void rz_memset(S8* str, S32 value, U32 size) {
    for (int m = 0; m<size; m++) {
        *(str + m) = value;
    }
}
void rz_memCpy(S8* des, S8* src, U32 size) {
    for (int m = 0; m<size; m++) {
        *(des + m) = *(src + m);
    }
}

U32 rz_atoi(S8* a) {
    U32 value = 0;

    while (*a>='0' && *a<='9') {
        value *= 10;
        value += *a - '0';
        a++;
    }
    return value;
}
U32 rz_itoa(U32 val, S8* buf, U8 base) {
    U32 tmp = 0;
    U32 i = 0;

    while (val) {
        tmp = val % base;
        if (tmp < 10) {
            buf[i++] = tmp + '0';
        } else {
            buf[i++] = tmp - 10 + 'a';
            //*buf = tmp - 10 + 'A';
        }
        val /= base;
    }

    rz_strRev(buf, i);
    return i;
}
U32 rz_itoa64(U64 val, S8* buf, U8 base) {
    U64 tmp = 0;
    U32 i = 0;

    while (val) {
        tmp = val % base;
        if (tmp < 10) {
            buf[i++] = tmp + '0';
        } else {
            buf[i++] = tmp - 10 + 'a';
            //*buf = tmp - 10 + 'A';
        }
        val /= base;
    }

    rz_strRev(buf, i);
    return i;
}
U32 rz_ftoa(double f, S8* buf, U8 prec) {
    U32 precArr[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,};
    U32 integ = 0;
    U32 frac = 0;
    S8 integStr[11] = {0};
    S8 fracStr[11] = {0};
    U8 intLeng = 0;
    U8 fracLeng = 0;
    U8 negSign = 0;
    U8 dotLeng = 0;
    S8 *p = buf;

    integ = (U32)f;
    intLeng = rz_itoa(integ, integStr, 10);

    frac = (U32)((f-integ) * precArr[prec]);
    fracLeng = rz_itoa(frac, fracStr, 10);

    //calculate how many digit
    if (f<0) {
        negSign = 1;
        f = -f;
    }

    if (negSign) {
        *p++ = '-';
    }

    for (int m = 0; m<intLeng; m++) {
        *p++ = integStr[m];
    }

    if (prec) {
        *p++ = '.';
        dotLeng = 1;
    }

    for (int m = 0; m<fracLeng && m<prec; m++) {
        *p++ = fracStr[m];
    }

    return negSign + intLeng + dotLeng + prec;
}

inline U32 rz_isDigit(S8 c) {
    return (c>='0' && c<='9');
}
U32 rz_strlen(const S8* str) {
    U32 leng = 0;

    while (*str != 0) {
        leng++;
        str++;
    }
    return leng;
}
U32 rz_strRev(S8* str, U32 size) {

    if (size > 512) { return 1; }
    for (int m = 0; m<(size>>1); m++) {         //swap
        str[m] = str[m] ^ str[size-1 -m];
        str[size-1 -m] = str[m] ^ str[size-1 -m];
        str[m] = str[m] ^ str[size-1 -m];
    }
    return 0;
}
U32 rz_getFormatArg(S8 **src, S8** argP) {
    U32 tmp = 0;

    if (rz_isDigit(**src)) {
        tmp = rz_atoi(*src);
        while (rz_isDigit(**src)) {
            (*src)++;
        }
    } else if (**src == '*') {
        tmp = *(int*)(*argP);
        *argP += 4;
        (*src)++;
    }

    return tmp;
}



