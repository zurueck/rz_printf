/***************************************************************************//**
 * @author  youmin
 * @data    20190624
 * @version 0.0.1
 *
 ******************************************************************************/
#include "rz_printf.h"


void rz_putchar(S32 c) {

}

/**
* output to the moniter
*
* 1. finish myprintf() (uart i2c...)
* 2. use rz_printf("anything here") while coding
* 3. string size is 25, can be changed
*
*/
//%[flags] [width] [.precision] [length] specifier
U32 rz_printf(char * myStr, ...) {
    S8            strBuff[512] = {0};
    U32           strBuffSize;

    strBuffSize = rz_vsprintf((S8*)strBuff, (S8*)myStr, (S8*)(((S8*)&myStr)+4));

    for (int m = 0; m<strBuffSize; m++) {
        rz_putchar(strBuff[m]);
    }
}

U32 rz_vsprintf(S8* des, S8* begin, S8* argAddr) {
    S8* src = 0;
    S8* desP = 0;
    S8* argP = 0;
    U32 flags = 0;
    S32 width = 0;
    S32 prec = 0;
    S32 leng = 0;
    U8 base;
    S8 strTmp[512] = {0};
    S8 inStrTmp[512] = {0};
    S64 s64tmp = 0;
    U32 argType = 0;
    U64 u64tmp = 0;
    S32 s32tmp = 0;
    U32 u32tmp = 0;
    S32 lengTmp = 0;
    S32 strLeng = 0;
    S8  s8tmp = 0;
    S8* s8ptmp = 0;
    U8 sign = 0;
    double f64Tmp = 0.0;


    desP = des;
    src = begin;
    argP = (S8*)argAddr;

    while (*src != 0) {
        if (*src != '%') {
            *desP = *src;
            desP++;
            src++;
            continue;
        }

        src++;
        //flags
        while (1) {
            switch (*src) {    //'0', '-', '+', ' ', '#'
                case '0':
                    flags |= _FLAG_ZERO_PAD;
                    src++;
                    break;
                case '-':
                    flags |= _FLAG_LEFT;
                    src++;
                    break;
                case '+':
                    flags |= _FLAG_SIGN;
                    src++;
                    break;
                case ' ':
                    flags |= _FLAG_SPACE;
                    src++;
                    break;
                case '#':
                    flags |= _FLAG_0X;
                    src++;
                    break;
                default:
                    goto LEAVE_FLAG;
            }
        }
LEAVE_FLAG:
        
        //width
        width = rz_getFormatArg(&src, &argP);
        if (width < 0) {
            flags |= _FLAG_LEFT;
            width = -width;
        }

        //precision
        if (*src == '.') {
            flags |= _FLAG_PRECISION;
            src++;
            prec = rz_getFormatArg(&src, &argP);
            if (prec < 0) {
                prec = 0;
            }
        }

        //length
        switch (*src) {
            case 'l':                   //long int
                leng |= _FLAG_LONG;
                src++;
                if (*src == 'l') {      //C99
                    leng |= _FLAG_LONG_LONG;
                    src++;
                }
                break;
            case 'h':
                leng |= _FLAG_SHORT;
                src++;
                if (*src == 'h') {      //C99
                    leng |= _FLAG_CHAR;
                    src++;
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
        switch (*src) {
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
                s8ptmp = (S8*)*(unsigned int*)argP;
                argP += 4;
                lengTmp = rz_strlen(s8ptmp);

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
                    *(inStrTmp+m) = *s8ptmp++;
                }

                argType |= _ARG_TYPE_N;     //done
                break;
            case 'p':   //not finish yet
            case 'n':   //lazy
                break;
            case '%':
                *desP = '%';
                desP++;
                src++;
                argType |= _ARG_TYPE_D;     //done
                break;
            default:
                break;
        }


        if (argType & _ARG_TYPE_S) {
            if (flags & _FLAG_LONG_LONG) {
                s64tmp = *(long long*)argP;
                argP += 8;
                if (s64tmp < 0) {
                    sign = 1;
                    u64tmp = -s64tmp;
                }
                lengTmp = rz_itoa64(u64tmp, inStrTmp, base);
            } else {
                s32tmp = *(int*)argP;
                argP += 4;
                if (s32tmp < 0) {
                    sign = 1;
                    u32tmp = -s32tmp;
                } else {
                    u32tmp = s32tmp;
                }
                lengTmp = rz_itoa(u32tmp, inStrTmp, base);
            }
        } else if (argType & _ARG_TYPE_F) {
            f64Tmp = *(double*)argP;
            argP += 8;
            flags &= ~_FLAG_0X;
            if (!(flags & _FLAG_PRECISION)) {
                prec = 6;
            }

            if ((flags & _FLAG_LEFT)) {
                flags &= ~_FLAG_ZERO_PAD;
            }

            lengTmp = rz_ftoa(f64Tmp, inStrTmp, prec);

            //if ((width-lengTmp) > 0) {
            //    pad = 1;
            //}
        } else if (argType & _ARG_TYPE_U) {
            if (flags & _FLAG_LONG_LONG) {
                u64tmp = *(unsigned long long*)argP;
                argP += 8;
                lengTmp = rz_itoa64(u64tmp, inStrTmp, base);
            } else {
                u32tmp = *(unsigned long long*)argP;
                argP += 4;
                lengTmp = rz_itoa(u32tmp, inStrTmp, base);
            }
        } else if (argType & _ARG_TYPE_D) {
            continue;
        } else if (argType & _ARG_TYPE_N) {
            rz_memCpy(desP, strTmp, strLeng);
            desP += strLeng;
            src++;
            continue;       //try to remove later
        } else {            //ARG_TYPE_N
            //do nothing
        }

        if (flags & _FLAG_SIGN) {
            if (sign) {
                strTmp[strLeng] = '-';
            } else {
                strTmp[strLeng] = '+';
            }
            strLeng++;
        } else if (flags & _FLAG_SPACE) {
            strTmp[strLeng] = ' ';
            strLeng++;
        }

        //add 0
        if (flags & _FLAG_PRECISION) {
            flags &= ~_FLAG_ZERO_PAD;
            if (prec == 0) {
                prec = lengTmp;
            }
            if (prec-lengTmp > 0) {
                for (int m = 0; m<prec-lengTmp; m++) {
                    strTmp[strLeng + m] = '0';
                }
                strLeng += prec - lengTmp;
            }
        }

        if (flags & _FLAG_0X) {
            strTmp[strLeng] = 'x';
            strLeng++;
            strTmp[strLeng] = '0';
            strLeng++;
        }

        if (flags & _FLAG_ZERO_PAD) {
            for (int m = 0; m<width-lengTmp-strLeng; m++) {
                strTmp[strLeng+m] = '0';
            }
            strLeng += prec-lengTmp-strLeng;
        }

        // add string
        for (int m = 0; m<lengTmp; m++) {
            strTmp[strLeng+m] = inStrTmp[m];
        }
        strLeng += lengTmp;

        if (width > strLeng) {
            if (flags & _FLAG_LEFT) {
                for (int m = 0; m<(width-strLeng); m++) {
                    strTmp[strLeng+m] = ' ';
                }
                strLeng += width-strLeng;
            } else {
                rz_strRev(strTmp, strLeng);
                for (int m = 0; m<(width-strLeng); m++) {
                    strTmp[strLeng+m] = ' ';
                }
                strLeng += width-strLeng;
                rz_strRev(strTmp, strLeng);
            }
        }

        rz_memCpy(desP, strTmp, strLeng);
        desP += strLeng;
        src++;
    }
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





