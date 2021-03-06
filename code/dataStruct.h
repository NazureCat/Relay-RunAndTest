// 每周波采样点数
#define POINTS 48
// 数据窗总长(包括记忆量) 4个周波
#define WINDOW 192
#define PI 3.1415926
#define MAXSIZE 655350
#define RECORD_LENGTH 10*POINTS

// 配置文件读取
#define PARAMCOUNT 50
#define MAX_BUF_LEN 1024
#define MAX_KEY_LEN 64
#define MAX_VAL_LEN 256



/*
* 相量
*/
typedef struct Phasor {
    double real;
    double img;
} Phasor;


/* 保护装置通用的数据结构--全局变量
* sample, 本次12通道采样值
* instVma, instVmb等数组: 瞬时值数组
* phasor 本次相量计算结果
* setValue数组: 通用整定值数组,具体每一个元素所代表的的整定值含义见各个保护的说明
* relayTime数组, 通用延时数组 
* relayFlag数组, 通用跳闸标记
*/
typedef struct Device {
    // 装置是否启用
    int onOff;

    char globalFileName[100];
    char deviceFileName[100];
    char deviceName[40];
    // 采样计数器, 用于仿真10次, 保护装置跑一次
    int sampleCount;


    double time;
    double sample[12];
    // 断路器状态采样,合位为1,断开为0
    int brkStatus[6];

    // 具体长度根据录波长度确定
    double instTime[RECORD_LENGTH];
    double instVma[RECORD_LENGTH];
    double instVmb[RECORD_LENGTH];
    double instVmc[RECORD_LENGTH];
    double instIma[RECORD_LENGTH];
    double instImb[RECORD_LENGTH];
    double instImc[RECORD_LENGTH];
    double instVna[RECORD_LENGTH];
    double instVnb[RECORD_LENGTH];
    double instVnc[RECORD_LENGTH];
    double instIna[RECORD_LENGTH];
    double instInb[RECORD_LENGTH];
    double instInc[RECORD_LENGTH];
    
    double filterVma[WINDOW];
    double filterVmb[WINDOW];
    double filterVmc[WINDOW];
    double filterIma[WINDOW];
    double filterImb[WINDOW];
    double filterImc[WINDOW];
    double filterVna[WINDOW];
    double filterVnb[WINDOW];
    double filterVnc[WINDOW];
    double filterIna[WINDOW];
    double filterInb[WINDOW];
    double filterInc[WINDOW];

    // 记忆量
    Phasor memoryVma[POINTS], memoryVmb[POINTS], memoryVmc[POINTS];
    Phasor memoryIma[POINTS], memoryImb[POINTS], memoryImc[POINTS];
    Phasor memoryVna[POINTS], memoryVnb[POINTS], memoryVnc[POINTS];
    Phasor memoryIna[POINTS], memoryInb[POINTS], memoryInc[POINTS];

    // 运行参数
    double ratedVoltage, ratedCurrent; // 相电压, 相电流
    double ratedBetweenVoltage, ratedBetweenCurrent; // 额定相间电压, 线电流
    double capacityCurrent; // 电容电流

    // 线路参数
    Phasor lineZ1; // 正序阻抗
    Phasor lineZ2; // 负序阻抗
    Phasor lineZ0; // 零序阻抗
    
    // 保护启动标志
    int startFlag;
    // 保护启动时间
    double startTime;

    // 相量实时计算值
    Phasor phasor[12];

    // 线路启动元件整定值: 0:电流突变量整定值  1:零序电流整定值  ...
    double lineStartSetValue[10];

    
    // 工频变化量距离
    double deltaDistanceSetValue[10];
    double deltaDistanceTimeSetValue[10];

    // 过电流保护
    double overCurrentSetValue[10];
    double overCurrentTimeSetValue[10];
    int overCurrentTripFlag[3];

    // 距离保护
    double distanceSetValue[10];
    double distanceTimeSetValue[10];
    int distanceTripFlag[3];
    
    // 电流差动保护
    double currentDiffSetValue[10];
    double currentDiffTimeSetValue[10];
    int currentDiffTripFlag[3];

    // 零序电流保护
    double zeroSequenceSetValue[10];
    double zeroSequenceTimeSetValue[10];
    int zeroSequenceTripCount[3];    
    

    // 跳闸动作标志
    int tripFlag[3];

    // 唯一执行语句标志位
    int notYetFlag[MAXSIZE];

   
} Device;

