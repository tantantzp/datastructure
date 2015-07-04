#ifndef _BENEFICIATION_LIB_H
#define _BENEFICIATION_LIB_H

#include <stdio.h>
#include "beneficiation.h"

static FILE * fr = NULL;
static FILE * fw = NULL;

static int m, n;
static unsigned int ore[10000];
static int report[10000];

static int data_count;
static int report_count;
static int measure_count;

static int max(int a, int b)
{
    if (a == -1)
      return b;
    if (b == -1)
      return a;
    if (ore[a] > ore[b])
      return a;
    else
      return b;
}

static int min(int a, int b)
{
    if (a == -1)
      return b;
    if (b == -1)
      return a;
    if (ore[a] < ore[b])
      return a;
    else
      return b;
}

extern int GetNumOfOre(void)
{
    int i;
    if (fr == NULL) {
        fr = fopen("beneficiation.in", "r");
        fw = fopen("beneficiation.out", "w");
        fscanf(fr, "%d", &m);
        data_count = 0;
    }
    if (data_count == m) {
        fclose(fr);
        fclose(fw);
        return 0;
    }
    fscanf(fr, "%d", &n);
    for (i = 0; i < n; i++) 
        fscanf(fr, "%u", &ore[i]);
    data_count++;
    report_count = 0;
    measure_count = 0;
    return n;
}

#define CALC(num) (num == -1) ? 0 : \
    ((num == max_index) ? 1 : ((num == min_index) ? -1 : 0))
extern void Measure(int a, int b, int c, int d,
            int *wa, int *wb, int *wc, int *wd)
{
    int max_index = max(max(a, b), max(c, d));
    int min_index = min(min(a, b), min(c, d));
    *wa = CALC(a);
    *wb = CALC(b);
    *wc = CALC(c);
    *wd = CALC(d);
    measure_count++;
}

extern void Report(int no, int rank)
{
    if (report_count < n) {
        report[rank] = no;
        report_count++;
        if (report_count == n) {
            int i;
            fprintf(fw, "%d\n", measure_count);
            for (i = 0; i < n; i++) {
                fprintf(fw, "%d\n", report[i]);
            }
        }
    }
}

#endif
