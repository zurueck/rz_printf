#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rz_printf.h"

#define PR_STR(x, y) "\""  #x "\\r\\n, " #y  "\""
char g_strBuff[1024] = {0};
char g_strBuff2[1024] = {0};
void test_f(void);
void test_d(void);
void test_x(void);
void test_s(void);
void test_c(void);

void dbg_printf(char* str, ...) {
    rz_vsprintf(g_strBuff, str, ((char*)&str)+4);
}

int main(int argc, char *argv[]) {
    
    
    test_x();
    
    return 0;
}

void test_f(){
    int res = 0;
    int k = 0;
    float f1 = 1.23456;
    char* f_str[] = {
                    PR_STR(%f, f1), //0
                    PR_STR(%+f, f1),
                    PR_STR(%-f, f1),
                    PR_STR(% f, f1),
                    PR_STR(%0f, f1),
                    
                    PR_STR(%+ f, f1),   //5
                    PR_STR(%+-f, f1),
                    PR_STR(%+0f, f1),
                    PR_STR(%- f, f1),
                    PR_STR(%-0f, f1),
                    PR_STR(% 0f, f1),   //10
                    PR_STR(% +0f, f1),
                    PR_STR(% -0f, f1),
                    PR_STR(% +-0f, f1),
                    
                    PR_STR(%6f, f1),
                    PR_STR(%7f, f1),    //15
                    PR_STR(%8f, f1),
                    PR_STR(%9f, f1),
                    
                    PR_STR(%.4f, f1),
                    PR_STR(%.5f, f1),
                    PR_STR(%.6f, f1),   //20
                    
                    PR_STR(%8.6f, f1),
                    PR_STR(%9.6f, f1),
                    PR_STR(%10.6f, f1),
                    PR_STR(%20.6f, f1),
                    
                    PR_STR(%+.6f, f1),  //25
                    PR_STR(%-.6f, f1),
                    PR_STR(% .6f, f1),
                    PR_STR(%0.6f, f1),
                    
                    PR_STR(%+6f, f1),
                    PR_STR(%-6f, f1),   //30
                    PR_STR(% 6f, f1),
                    PR_STR(%06f, f1),
                    
                    PR_STR(%+7f, f1),
                    PR_STR(%-7f, f1),
                    PR_STR(% 7f, f1),   //35
                    PR_STR(%07f, f1),
                    
                    PR_STR(%+8f, f1),
                    PR_STR(%-8f, f1),
                    PR_STR(% 8f, f1),
                    PR_STR(%08f, f1),   //40
                    
                    PR_STR(%+10f, f1),
                    PR_STR(%-10f, f1),
                    PR_STR(% 10f, f1),
                    PR_STR(%010f, f1),
                    
                    PR_STR(%+6.6f, f1), //45
                    PR_STR(%-6.6f, f1),
                    PR_STR(% 6.6f, f1),
                    PR_STR(%06.6f, f1),
                    
                    PR_STR(%+7.6f, f1),
                    PR_STR(%-7.6f, f1), //50
                    PR_STR(% 7.6f, f1),
                    PR_STR(%07.6f, f1),
                    
                    PR_STR(%+8.6f, f1),
                    PR_STR(%-8.6f, f1),
                    PR_STR(% 8.6f, f1), //55
                    PR_STR(%08.6f, f1),
                    
                    PR_STR(%+10.6f, f1),
                    PR_STR(%-10.6f, f1),
                    PR_STR(% 10.6f, f1),
                    PR_STR(%010.6f, f1),    //60
                    
                    PR_STR(%+010.6f, f1),
                    PR_STR(%+ 10.6f, f1),
                    PR_STR(%+ 010.6f, f1),
                    PR_STR(%-010.6f, f1),
                    PR_STR(%- 10.6f, f1),   //65
                    PR_STR(%- 010.6f, f1),
                    PR_STR(%+-010.6f, f1),
                    PR_STR(%+- 10.6f, f1),
                    PR_STR(%+- 010.6f, f1),
                    
                    PR_STR(%+04.6f, f1),    //70
                    PR_STR(%+ 4.6f, f1),
                    PR_STR(%+ 04.6f, f1),
                    PR_STR(%-04.6f, f1),
                    PR_STR(%- 4.6f, f1),
                    PR_STR(%- 04.6f, f1),   //75
                    PR_STR(%+-04.6f, f1),
                    PR_STR(%+- 4.6f, f1),
                    PR_STR(%+- 04.6f, f1),  //78
                    
                
      };
 
    //0
    printf("[%d] = %s ......", k, f_str[k]);
    {
        memset((void*)g_strBuff, 0, 1024);
        memset((void*)(void*)g_strBuff2, 0, 1024);
        dbg_printf("%f", f1);
        sprintf (g_strBuff2, "%f", f1);
        res = strcmp(g_strBuff, g_strBuff2);
        if (res == 0) {
            printf("PASS\r\n");
        } else {
            printf("FAIL:\r\n");
              rz_printf("%f\r\n", f1);
            printf("%f\r\n", f1);
            printf("\r\n");
        }
        k++;
    }
    
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
        dbg_printf("%+f", f1);
        sprintf (g_strBuff2, "%+f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
        rz_printf("%+f\r\n", f1);
        printf("%+f\r\n", f1);printf("\r\n");}k++;}
        
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-f", f1);
    sprintf (g_strBuff2, "%-f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-f\r\n", f1);
    printf("%-f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% f", f1);
    sprintf (g_strBuff2, "% f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% f\r\n", f1);
    printf("% f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%0f", f1);
    sprintf (g_strBuff2, "%0f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%0f\r\n", f1);
    printf("%0f\r\n", f1);printf("\r\n");}k++;}
    
    //5
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+ f", f1);
    sprintf (g_strBuff2, "%+ f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+ f\r\n", f1);
    printf("%+ f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+-f", f1);
    sprintf (g_strBuff2, "%+-f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+-f\r\n", f1);
    printf("%+-f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+0f", f1);
    sprintf (g_strBuff2, "%+0f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+0f\r\n", f1);
    printf("%+0f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%- f", f1);
    sprintf (g_strBuff2, "%- f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%- f\r\n", f1);
    printf("%- f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-0f", f1);
    sprintf (g_strBuff2, "%-0f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-0f\r\n", f1);
    printf("%-0f\r\n", f1);printf("\r\n");}k++;}
    
    //10
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 0f", f1);
    sprintf (g_strBuff2, "% 0f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 0f\r\n", f1);
    printf("% 0\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% +f", f1);
    sprintf (g_strBuff2, "% +f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% +f\r\n", f1);
    printf("% +f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% -f", f1);
    sprintf (g_strBuff2, "% -f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% -f\r\n", f1);
    printf("% -f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% +-0f", f1);
    sprintf (g_strBuff2, "% +-0f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% +-0f\r\n", f1);
    printf("% +-0f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%6f", f1);
    sprintf (g_strBuff2, "%6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%6f\r\n", f1);
    printf("%6f\r\n", f1);printf("\r\n");}k++;}

    //15
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%7f", f1);
    sprintf (g_strBuff2, "%7f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%7f\r\n", f1);
    printf("%7\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%8f", f1);
    sprintf (g_strBuff2, "%8f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%8f\r\n", f1);
    printf("%8f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%9f", f1);
    sprintf (g_strBuff2, "%9f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%9f\r\n", f1);
    printf("%9f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.4f", f1);
    sprintf (g_strBuff2, "%.4f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%.4f\r\n", f1);
    printf("%.4f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.5f", f1);
    sprintf (g_strBuff2, "%.5f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%.5f\r\n", f1);
    printf("%.5f\r\n", f1);printf("\r\n");}k++;}

    //20
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.6f", f1);
    sprintf (g_strBuff2, "%.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%.6f\r\n", f1);
    printf("%.6\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%8.6f", f1);
    sprintf (g_strBuff2, "%8.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%8.6f\r\n", f1);
    printf("%8.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%9.6f", f1);
    sprintf (g_strBuff2, "%9.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%9.6f\r\n", f1);
    printf("%9.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%10.6f", f1);
    sprintf (g_strBuff2, "%10.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%10.6f\r\n", f1);
    printf("%10.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%20.6f", f1);
    sprintf (g_strBuff2, "%20.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%20.6f\r\n", f1);
    printf("%20.6f\r\n", f1);printf("\r\n");}k++;}

    //25
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+.6f", f1);
    sprintf (g_strBuff2, "%+.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+.6f\r\n", f1);
    printf("%+.6\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-.6f", f1);
    sprintf (g_strBuff2, "%-.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-.6f\r\n", f1);
    printf("%-.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% .6f", f1);
    sprintf (g_strBuff2, "% .6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% .6f\r\n", f1);
    printf("% .6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%0.6f", f1);
    sprintf (g_strBuff2, "%0.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%0.6f\r\n", f1);
    printf("%0.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+6f", f1);
    sprintf (g_strBuff2, "%+6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+6f\r\n", f1);
    printf("%+6f\r\n", f1);printf("\r\n");}k++;}

    //30
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-6f", f1);
    sprintf (g_strBuff2, "%-6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-6f\r\n", f1);
    printf("%-6\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 6f", f1);
    sprintf (g_strBuff2, "% 6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 6f\r\n", f1);
    printf("% 6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%06f", f1);
    sprintf (g_strBuff2, "%06f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%06f\r\n", f1);
    printf("%06f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+7f", f1);
    sprintf (g_strBuff2, "%+7f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+7f\r\n", f1);
    printf("%+7f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-7f", f1);
    sprintf (g_strBuff2, "%-7f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-7f\r\n", f1);
    printf("%-7f\r\n", f1);printf("\r\n");}k++;}   
    
    //35
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 7f", f1);
    sprintf (g_strBuff2, "% 7f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 7f\r\n", f1);
    printf("% 7f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%07f", f1);
    sprintf (g_strBuff2, "%07f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%07f\r\n", f1);
    printf("%07f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+8f", f1);
    sprintf (g_strBuff2, "%+8f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+8f\r\n", f1);
    printf("%+8f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-8f", f1);
    sprintf (g_strBuff2, "%-8f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-8f\r\n", f1);
    printf("%-8f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 8f", f1);
    sprintf (g_strBuff2, "% 8f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 8f\r\n", f1);
    printf("% 8f\r\n", f1);printf("\r\n");}k++;}   
        
    
    //40
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%08f", f1);
    sprintf (g_strBuff2, "%08f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%08f\r\n", f1);
    printf("%08f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+10f", f1);
    sprintf (g_strBuff2, "%+10f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+10f\r\n", f1);
    printf("%+10f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-10f", f1);
    sprintf (g_strBuff2, "%-10f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-10f\r\n", f1);
    printf("%-10f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 10f", f1);
    sprintf (g_strBuff2, "% 10f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 10f\r\n", f1);
    printf("% 10f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%010f", f1);
    sprintf (g_strBuff2, "%010f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%010f\r\n", f1);
    printf("%010f\r\n", f1);printf("\r\n");}k++;}   
        
    //45
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+6.6f", f1);
    sprintf (g_strBuff2, "%+6.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+6.6f\r\n", f1);
    printf("%+6.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-6.6f", f1);
    sprintf (g_strBuff2, "%-6.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-6.6f\r\n", f1);
    printf("%-6.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 6.6f", f1);
    sprintf (g_strBuff2, "% 6.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 6.6f\r\n", f1);
    printf("% 6.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%06.6f", f1);
    sprintf (g_strBuff2, "%06.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%06.6f\r\n", f1);
    printf("%06.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+7.6f", f1);
    sprintf (g_strBuff2, "%+7.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+7.6f\r\n", f1);
    printf("%+7.6f\r\n", f1);printf("\r\n");}k++;}
    
    //50
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-7.6f", f1);
    sprintf (g_strBuff2, "%-7.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-7.6f\r\n", f1);
    printf("%-7.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 7.6f", f1);
    sprintf (g_strBuff2, "% 7.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 7.6f\r\n", f1);
    printf("% 7.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%07.6f", f1);
    sprintf (g_strBuff2, "%07.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%07.6f\r\n", f1);
    printf("%07.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+8.6f", f1);
    sprintf (g_strBuff2, "%+8.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+8.6f\r\n", f1);
    printf("%+8.6f\r\n", f1);printf("\r\n");}k++;}

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-8.6f", f1);
    sprintf (g_strBuff2, "%-8.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-8.6f\r\n", f1);
    printf("%-8.6f\r\n", f1);printf("\r\n");}k++;}

    //55
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 8.6f", f1);
    sprintf (g_strBuff2, "% 8.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 8.6f\r\n", f1);
    printf("% 8.6f\r\n", f1);printf("\r\n");}k++;}

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%08.6f", f1);
    sprintf (g_strBuff2, "%08.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%08.6f\r\n", f1);
    printf("%08.6f\r\n", f1);printf("\r\n");}k++;}

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+10.6f", f1);
    sprintf (g_strBuff2, "%+10.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+10.6f\r\n", f1);
    printf("%+10.6f\r\n", f1);printf("\r\n");}k++;}

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-10.6f", f1);
    sprintf (g_strBuff2, "%-10.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-10.6f\r\n", f1);
    printf("%-10.6f\r\n", f1);printf("\r\n");}k++;}
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 10.6f", f1);
    sprintf (g_strBuff2, "% 10.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("% 10.6f\r\n", f1);
    printf("% 10.6f\r\n", f1);printf("\r\n");}k++;}
    
    //60
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%010.6f", f1);
    sprintf (g_strBuff2, "%010.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%010.6f\r\n", f1);
    printf("%010.6f\r\n", f1);printf("\r\n");}k++;}       
    
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+010.6f", f1);
    sprintf (g_strBuff2, "%+010.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+010.6f\r\n", f1);
    printf("%+010.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+ 10.6f", f1);
    sprintf (g_strBuff2, "%+ 10.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+ 10.6f\r\n", f1);
    printf("%+ 10.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+ 010.6f", f1);
    sprintf (g_strBuff2, "%+ 010.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+ 010.6f\r\n", f1);
    printf("%+ 010.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-010.6f", f1);
    sprintf (g_strBuff2, "%-010.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-010.6f\r\n", f1);
    printf("%-010.6f\r\n", f1);printf("\r\n");}k++;}       
    
    //65
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%- 10.6f", f1);
    sprintf (g_strBuff2, "%- 10.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%- 10.6f\r\n", f1);
    printf("%- 10.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%- 010.6f", f1);
    sprintf (g_strBuff2, "%- 010.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%- 010.6f\r\n", f1);
    printf("%- 010.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+-010.6f", f1);
    sprintf (g_strBuff2, "%+-010.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+-010.6f\r\n", f1);
    printf("%+-010.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+- 10.6f", f1);
    sprintf (g_strBuff2, "%+- 10.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+- 10.6f\r\n", f1);
    printf("%+- 10.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+- 010.6f", f1);
    sprintf (g_strBuff2, "%+- 010.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+- 010.6f\r\n", f1);
    printf("%+- 010.6f\r\n", f1);printf("\r\n");}k++;}       

    //70
    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+04.6f", f1);
    sprintf (g_strBuff2, "%+04.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+04.6f\r\n", f1);
    printf("%+04.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+ 4.6f", f1);
    sprintf (g_strBuff2, "%+ 4.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+ 4.6f\r\n", f1);
    printf("%+ 4.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+ 04.6f", f1);
    sprintf (g_strBuff2, "%+ 04.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+ 04.6f\r\n", f1);
    printf("%+ 04.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-04.6f", f1);
    sprintf (g_strBuff2, "%-04.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%-04.6f\r\n", f1);
    printf("%-04.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%- 4.6f", f1);
    sprintf (g_strBuff2, "%- 4.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%- 4.6f\r\n", f1);
    printf("%- 4.6f\r\n", f1);printf("\r\n");}k++;}       

    //75
     printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%- 04.6f", f1);
    sprintf (g_strBuff2, "%- 04.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%- 04.6f\r\n", f1);
    printf("%- 04.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+-04.6f", f1);
    sprintf (g_strBuff2, "%+-04.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+-04.6f\r\n", f1);
    printf("%+-04.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+- 4.6f", f1);
    sprintf (g_strBuff2, "%+- 4.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+- 4.6f\r\n", f1);
    printf("%+- 4.6f\r\n", f1);printf("\r\n");}k++;}       

    printf("[%d] = %s ......", k, f_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+- 04.6f", f1);
    sprintf (g_strBuff2, "%+- 04.6f", f1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, f_str[k]);
    rz_printf("%+- 04.6f\r\n", f1);
    printf("%+- 04.6f\r\n", f1);printf("\r\n");}k++;}       

   
    
    

}

void test_d(){
    int res = 0;
    int k = 0;
    int i1 = 1234;
    char* i_str[] = {
            PR_STR(%d, i1),  //0
            PR_STR(%+d, i1),
            PR_STR(%-d, i1),
            PR_STR(% d, i1),
            PR_STR(%0d, i1),

            PR_STR(%3d, i1),    //5
            PR_STR(%4d, i1),
            PR_STR(%5d, i1),
            PR_STR(%.3d, i1),
            PR_STR(%.4d, i1),

            PR_STR(%.5d, i1),   //10
            PR_STR(%2.3d, i1),
            PR_STR(%2.4d, i1),
            PR_STR(%2.5d, i1),
            PR_STR(%10.3d, i1),

            PR_STR(%10.4d, i1), //15
            PR_STR(%10.5d, i1),
            PR_STR(%+3d, i1),
            PR_STR(%-3d, i1),
            PR_STR(% 3d, i1),

            PR_STR(%03d, i1),   //20
            PR_STR(%+4d, i1),
            PR_STR(%-4d, i1),
            PR_STR(% 4d, i1),
            PR_STR(%04d, i1),

            PR_STR(%+6d, i1),   //25
            PR_STR(%-6d, i1),
            PR_STR(% 6d, i1),
            PR_STR(%06d, i1),
            PR_STR(% 08d, i1),

            PR_STR(%+08d, i1),  //30
            PR_STR(%+ 08d, i1),
        };

    //0
    printf("[%d] = %s ......", k, i_str[k]);
    {
        memset((void*)g_strBuff, 0, 1024);
        memset((void*)g_strBuff2, 0, 1024);
        dbg_printf("%d", i1);
        sprintf (g_strBuff2, "%d", i1);
        res = strcmp(g_strBuff, g_strBuff2);
        if (res == 0) {
            printf("PASS\r\n");
        } else {
            printf("FAIL:\r\n");
              rz_printf("%d\r\n", i1);
            printf("%d\r\n", i1);
            printf("\r\n");
        }
        k++;
    } 
          
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+d", i1);
    sprintf (g_strBuff2, "%+d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%+d\r\n", i1);
    printf("%+d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-d", i1);
    sprintf (g_strBuff2, "%-d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%-d\r\n", i1);
    printf("%-d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% d", i1);
    sprintf (g_strBuff2, "% d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("% d\r\n", i1);
    printf("% d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%0d", i1);
    sprintf (g_strBuff2, "%0d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%0d\r\n", i1);
    printf("%0d\r\n", i1);printf("\r\n");}k++;}          

    //5     
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%3d", i1);
    sprintf (g_strBuff2, "%3d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%3d\r\n", i1);
    printf("%3d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%4d", i1);
    sprintf (g_strBuff2, "%4d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%4d\r\n", i1);
    printf("%4d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%5d", i1);
    sprintf (g_strBuff2, "%5d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%5d\r\n", i1);
    printf("%5d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.3d", i1);
    sprintf (g_strBuff2, "%.3d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%.3d\r\n", i1);
    printf("%.3d\r\n", i1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.4d", i1);
    sprintf (g_strBuff2, "%.4d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%.4d\r\n", i1);
    printf("%.4d\r\n", i1);printf("\r\n");}k++;}                     

    //10
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.5d", i1);
    sprintf (g_strBuff2, "%.5d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%.5d\r\n", i1);
    printf("%.5d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%2.3d", i1);
    sprintf (g_strBuff2, "%2.3d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%2.3d\r\n", i1);
    printf("%2.3d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%2.4d", i1);
    sprintf (g_strBuff2, "%2.4d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%2.4d\r\n", i1);
    printf("%2.4d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%2.5d", i1);
    sprintf (g_strBuff2, "%2.5d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%2.5d\r\n", i1);
    printf("%2.5d\r\n", i1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%10.3d", i1);
    sprintf (g_strBuff2, "%10.3d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%10.3d\r\n", i1);
    printf("%10.3d\r\n", i1);printf("\r\n");}k++;}                     

    //15
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%10.4d", i1);
    sprintf (g_strBuff2, "%10.4d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%10.4d\r\n", i1);
    printf("%10.4d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%10.5d", i1);
    sprintf (g_strBuff2, "%10.5d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%10.5d\r\n", i1);
    printf("%10.5d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+3d", i1);
    sprintf (g_strBuff2, "%+3d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%+3d\r\n", i1);
    printf("%+3d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-3d", i1);
    sprintf (g_strBuff2, "%-3d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%-3d\r\n", i1);
    printf("%-3d\r\n", i1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 3d", i1);
    sprintf (g_strBuff2, "% 3d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("% 3d\r\n", i1);
    printf("% 3d\r\n", i1);printf("\r\n");}k++;}                     

    //20
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%03d", i1);
    sprintf (g_strBuff2, "%03d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%03d\r\n", i1);
    printf("%03d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+4d", i1);
    sprintf (g_strBuff2, "%+4d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%+4d\r\n", i1);
    printf("%+4d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-4d", i1);
    sprintf (g_strBuff2, "%-4d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%-4d\r\n", i1);
    printf("%-4d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 4d", i1);
    sprintf (g_strBuff2, "% 4d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("% 4d\r\n", i1);
    printf("% 4d\r\n", i1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%04d", i1);
    sprintf (g_strBuff2, "%04d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%04d\r\n", i1);
    printf("%04d\r\n", i1);printf("\r\n");}k++;}                     

    //25
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+6d", i1);
    sprintf (g_strBuff2, "%+6d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%+6d\r\n", i1);
    printf("%+6d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-6d", i1);
    sprintf (g_strBuff2, "%-6d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%-6d\r\n", i1);
    printf("%-6d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 6d", i1);
    sprintf (g_strBuff2, "% 6d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("% 6d\r\n", i1);
    printf("% 6d\r\n", i1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%06d", i1);
    sprintf (g_strBuff2, "%06d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%06d\r\n", i1);
    printf("%06d\r\n", i1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 08d", i1);
    sprintf (g_strBuff2, "% 08d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("% 08d\r\n", i1);
    printf("% 08d\r\n", i1);printf("\r\n");}k++;}                     

    //30
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+08d", i1);
    sprintf (g_strBuff2, "%+08d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%+08d\r\n", i1);
    printf("%+08d\r\n", i1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, i_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+ 08d", i1);
    sprintf (g_strBuff2, "%+ 08d", i1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, i_str[k]);
    rz_printf("%+ 08d\r\n", i1);
    printf("%+ 08d\r\n", i1);printf("\r\n");}k++;}         
            
}

void test_x(){
    int res = 0;
    int k = 0;
    int x1 = 0x1234;
    char* x_str[] = {
            PR_STR(%x, x1),  //0
            PR_STR(%+x, x1),
            PR_STR(%-x, x1),
            PR_STR(% x, x1),
            PR_STR(%0x, x1),

            PR_STR(%3x, x1),    //5
            PR_STR(%4x, x1),
            PR_STR(%5x, x1),
            PR_STR(%.3x, x1),
            PR_STR(%.4x, x1),

            PR_STR(%.5x, x1),   //10
            PR_STR(%2.3x, x1),
            PR_STR(%2.4x, x1),
            PR_STR(%2.5x, x1),
            PR_STR(%10.3x, x1),

            PR_STR(%10.4x, x1), //15
            PR_STR(%10.5x, x1),
            PR_STR(%+3x, x1),
            PR_STR(%-3x, x1),
            PR_STR(% 3x, x1),

            PR_STR(%03x, x1),   //20
            PR_STR(%+4x, x1),
            PR_STR(%-4x, x1),
            PR_STR(% 4x, x1),
            PR_STR(%04x, x1),

            PR_STR(%+6x, x1),   //25
            PR_STR(%-6x, x1),
            PR_STR(% 6x, x1),
            PR_STR(%06x, x1),
            PR_STR(% 08x, x1),

            PR_STR(%+08x, x1),  //30
            PR_STR(%+ 08x, x1),
        };

  printf("[%d] = %s ......", k, x_str[k]);
    {
        memset((void*)g_strBuff, 0, 1024);
        memset((void*)g_strBuff2, 0, 1024);
        dbg_printf("%x", x1);
        sprintf (g_strBuff2, "%x", x1);
        res = strcmp(g_strBuff, g_strBuff2);
        if (res == 0) {
            printf("PASS\r\n");
        } else {
            printf("FAIL:\r\n");
              rz_printf("%x\r\n", x1);
            printf("%x\r\n", x1);
            printf("\r\n");
        }
        k++;
    } 
 
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+x", x1);
    sprintf (g_strBuff2, "%+x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%+x\r\n", x1);
    printf("%+x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-x", x1);
    sprintf (g_strBuff2, "%-x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%-x\r\n", x1);
    printf("%-x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% x", x1);
    sprintf (g_strBuff2, "% x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("% x\r\n", x1);
    printf("% x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%0x", x1);
    sprintf (g_strBuff2, "%0x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%0x\r\n", x1);
    printf("%0x\r\n", x1);printf("\r\n");}k++;}          

    //5     
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%3x", x1);
    sprintf (g_strBuff2, "%3x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%3x\r\n", x1);
    printf("%3x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%4x", x1);
    sprintf (g_strBuff2, "%4x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%4x\r\n", x1);
    printf("%4x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%5x", x1);
    sprintf (g_strBuff2, "%5x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%5x\r\n", x1);
    printf("%5x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.3x", x1);
    sprintf (g_strBuff2, "%.3x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%.3x\r\n", x1);
    printf("%.3x\r\n", x1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.4x", x1);
    sprintf (g_strBuff2, "%.4x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%.4x\r\n", x1);
    printf("%.4x\r\n", x1);printf("\r\n");}k++;}                     

    //10
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%.5x", x1);
    sprintf (g_strBuff2, "%.5x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%.5x\r\n", x1);
    printf("%.5x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%2.3x", x1);
    sprintf (g_strBuff2, "%2.3x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%2.3x\r\n", x1);
    printf("%2.3x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%2.4x", x1);
    sprintf (g_strBuff2, "%2.4x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%2.4x\r\n", x1);
    printf("%2.4x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%2.5x", x1);
    sprintf (g_strBuff2, "%2.5x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%2.5x\r\n", x1);
    printf("%2.5x\r\n", x1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%10.3x", x1);
    sprintf (g_strBuff2, "%10.3x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%10.3x\r\n", x1);
    printf("%10.3x\r\n", x1);printf("\r\n");}k++;}                     

    //15
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%10.4x", x1);
    sprintf (g_strBuff2, "%10.4x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%10.4x\r\n", x1);
    printf("%10.4x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%10.5x", x1);
    sprintf (g_strBuff2, "%10.5x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%10.5x\r\n", x1);
    printf("%10.5x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+3x", x1);
    sprintf (g_strBuff2, "%+3x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%+3x\r\n", x1);
    printf("%+3x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-3x", x1);
    sprintf (g_strBuff2, "%-3x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%-3x\r\n", x1);
    printf("%-3x\r\n", x1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 3x", x1);
    sprintf (g_strBuff2, "% 3x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("% 3x\r\n", x1);
    printf("% 3x\r\n", x1);printf("\r\n");}k++;}                     

    //20
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%03x", x1);
    sprintf (g_strBuff2, "%03x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%03x\r\n", x1);
    printf("%03x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+4x", x1);
    sprintf (g_strBuff2, "%+4x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%+4x\r\n", x1);
    printf("%+4x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-4x", x1);
    sprintf (g_strBuff2, "%-4x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%-4x\r\n", x1);
    printf("%-4x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 4x", x1);
    sprintf (g_strBuff2, "% 4x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("% 4x\r\n", x1);
    printf("% 4x\r\n", x1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%04x", x1);
    sprintf (g_strBuff2, "%04x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%04x\r\n", x1);
    printf("%04x\r\n", x1);printf("\r\n");}k++;}                     

    //25
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+6x", x1);
    sprintf (g_strBuff2, "%+6x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%+6x\r\n", x1);
    printf("%+6x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%-6x", x1);
    sprintf (g_strBuff2, "%-6x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%-6x\r\n", x1);
    printf("%-6x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 6x", x1);
    sprintf (g_strBuff2, "% 6x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("% 6x\r\n", x1);
    printf("% 6x\r\n", x1);printf("\r\n");}k++;}          

    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%06x", x1);
    sprintf (g_strBuff2, "%06x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%06x\r\n", x1);
    printf("%06x\r\n", x1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("% 08x", x1);
    sprintf (g_strBuff2, "% 08x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("% 08x\r\n", x1);
    printf("% 08x\r\n", x1);printf("\r\n");}k++;}                     

    //30
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+08x", x1);
    sprintf (g_strBuff2, "%+08x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%+08x\r\n", x1);
    printf("%+08x\r\n", x1);printf("\r\n");}k++;}                     
    
    printf("[%d] = %s ......", k, x_str[k]);{memset((void*)g_strBuff, 0, 1024);memset((void*)g_strBuff2, 0, 1024);
    dbg_printf("%+ 08x", x1);
    sprintf (g_strBuff2, "%+ 08x", x1);res = strcmp(g_strBuff, g_strBuff2);if (res == 0) {printf("PASS\r\n", k);} else {printf("FAIL:\r\n", k, x_str[k]);
    rz_printf("%+ 08x\r\n", x1);
    printf("%+ 08x\r\n", x1);printf("\r\n");}k++;}         
            


}

void test_s(){

}

void test_c(){

}


