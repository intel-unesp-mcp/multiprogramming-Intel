#!/bin/bash
time numactl -m 4,5,6,7 ./runme-CPU 15000 100
time numactl -m 0,1,2,3 ./runme-CPU 15000 100
