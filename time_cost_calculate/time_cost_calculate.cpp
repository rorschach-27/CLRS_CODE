//
// Created by zy on 2021/8/30.
//

#include "time_cost_calculate.h"

void _time_cost::get_time_cost() {
    cout<<endl;
    end=clock();
    ret=double (end-begin)/CLOCKS_PER_SEC;
    cout<<"runtime: "<<ret<<endl;
}
