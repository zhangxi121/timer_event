#!/bin/bash

exeprogram="test_timer_event"
if [ -f $exeprogram ];then 
    rm $exeprogram
fi 
g++ *.cpp -g -o $exeprogram -lpthread -std=c++14
