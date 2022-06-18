/*
 * Copyright (C) 2013-2018, Shenzhen Huiding Technology Co., Ltd.
 * All Rights Reserved.
 * Version: V1.0
 * Description:
 * History:
 */

#ifndef _TALOGDUMP_H_
#define _TALOGDUMP_H_

#include <stdint.h>

namespace goodix
{
    class TaLogDump
    {
    public:
        uint32_t getDumpLevel(void);
        void printLog(uint8_t *buffer);
    private:
        uint32_t mLogDumpLevel;
    };
}

#endif  // _TALOGDUMP_H_
