//
//  CPURuntime.hpp
//  MNN
//
//  Created by MNN on 2018/08/31.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef CPURuntime_hpp
#define CPURuntime_hpp

#ifdef ENABLE_ARMV82
struct cpuinfo_arm_isa{
    bool fp16arith;
    bool dot;
};
#endif


/*
 CPU thread mode, only effective on HMP（Heterogeneous Multi-Processing）arch CPUs
 that have ARM big.LITTLE technology and on Android
 */
typedef enum {
    /* Compliance with Operating System Scheduling */
    MNN_CPU_MODE_DEFAULT = 0,
    /* Bind threads to CPU IDs according to CPU frequency, but this mode is power-friendly */
    MNN_CPU_MODE_POWER_FRI = 1,
    /* Bind threads to little CPUs */
    MNN_CPU_MODE_LITTLE = 2,
    /* Bind threads to big CPUs */
    MNN_CPU_MODE_BIG = 3,
    /* Bind threads to  0,1,2,3(4xA55) */
    MNN_CPU_MODE_one_a55 = 4,
    /* Bind threads to 1(1xA55) */
    MNN_CPU_MODE_four_a55 = 5
} MNNCPUThreadsMode;
int MNNSetCPUThreadsMode(MNNCPUThreadsMode mode);

//
float MNNGetCPUFlops(uint32_t number);

#ifdef ENABLE_ARMV82

void cpuinfo_arm_init(struct cpuinfo_arm_isa* cpuinfo_isa);

#endif // __aarch64__

#endif /* CPUInfo_hpp */
