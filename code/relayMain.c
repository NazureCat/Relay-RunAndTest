#include "..\\code\\dataStruct.h"
#include "..\\code\common.h"

/**
 * RelayMain.c
 * 所有保护装置的入口函数
 */


Device s1_line1;
Device s1_line2;

int globalInitFlag = 0;// 全局初始化标志
char logDirName[100];

// 声明各类保护函数
extern double line(Device*); // 线路保护


// 注意采用GFORTRAN,C函数名需要多一个下划线
void s1_line1_(double* time, int* onOff, double* port1, double* port2, int* tripSignal) {
    globalInit();
    linkSimulation(&s1_line1, "s1-line1", *time, *onOff, port1, port2, tripSignal);
}

void s1_line2_(double* time, int* onOff, double* port1, double* port2, int* tripSignal) {
    linkSimulation(&s1_line2, "s1-line2", *time, *onOff, port1, port2, tripSignal);
}












