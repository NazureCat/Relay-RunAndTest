// common

void globalInit();

void linkSimulation(Device* device, char* deviceName, double time, int onOff, double* port1, double* port2, int* tripSignal);

void deviceInit(Device* device, char* deviceName, int onOff);
int readConfiguration(Device* device);
double findSetValueIndex(char* target, char (*paramName)[50], double* paramValue, int n);

int upTo10(Device* device);
// 仿真采样
void sample(Device* device, double time, double* input, double* brk);

void sample2inst(Device*);

void dataFilter(Device*);

void toPhasor(Device*);


double phasorAbs(Phasor p);
Phasor phasorAdd(Phasor pa, Phasor pb);
Phasor phasorSub(Phasor, Phasor);
Phasor phasorMulti(double a, Phasor p);

Phasor phasorContrarotate(Phasor p, double angle);
Phasor phasorSeq(Phasor pa, Phasor pb, Phasor pc, int seq);
double phasorAngleDiff(Phasor pa, Phasor pb);

void lowPassFilter(double* aft, double* bef);

void inst2phasor(double* inst, int start, Phasor* phasor);

int notYet(Device* device, char* str);
unsigned int SDBMHash(char *str, int arrLength); 

void writeLog(Device* device, char* content);
void writeLogWithPhase(Device* device, char* content, int phase);

Phasor memoryPhasorValue(Device* device, Phasor* memoryPhasors);

void recordData(Device* device);





