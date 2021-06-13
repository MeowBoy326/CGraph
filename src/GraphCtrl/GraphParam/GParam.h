/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GParam.h
@Time: 2021/6/11 6:32 下午
@Desc: 
***************************/


#ifndef CGRAPH_GPARAM_H
#define CGRAPH_GPARAM_H

#include <shared_mutex>
#include "../../CObject/CObject.h"
#include "../../UtilsCtrl/UtilsInclude.h"
#include "GParamDefine.h"

struct GParam : public CObject {
public:
    std::shared_mutex lock_;

private:
    CSTATUS run() override;

    /**
     * 每次pipeline执行结束，会调用一次reset，防止pipeline执行的时候，参数污染
     * @return
     */
    virtual void reset() = 0;

    friend class GParamManager;
};

using GParamPtr = GParam *;


#endif //CGRAPH_GPARAM_H
