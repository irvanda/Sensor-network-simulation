#!/bin/bash

echo "start simulation BroadCast 625_5"
g++ Bcast_625_5.cpp -o sim
./sim
echo "simulation Broadcast 625_5: Done"
echo "================================"
echo "start simulation Broadcast 625_10"
g++ Bcast_625_10.cpp -o sim
./sim
echo "simulation Broadcast 625_10: Done"
echo "================================"
echo "start simulation Broadcast 625_15"
g++ Bcast_625_15.cpp -o sim
./sim
echo "simulation Broadcast 625_15: Done"
echo "================================"
echo "start simulation Broadcast 1000_5"
g++ Bcast_1000_5.cpp -o sim
./sim
echo "simulation Broadcast 1000_5: Done"
echo "================================"
echo "start simulation Broadcast 1600_5"
g++ Bcast_1600_5.cpp -o sim
./sim
echo "simulation Broadcast 1600_5: Done"
echo "================================"
echo "start simulation DC 625_5"
g++ DC_625_5.cpp -o sim
./sim
echo "simulation DC 625_5: Done"
echo "================================"
echo "start simulation DC 625_10"
g++ DC_625_10.cpp -o sim
./sim
echo "simulation DC 625_10: Done"
echo "================================"
echo "start simulation DC 625_15"
g++ DC_625_15.cpp -o sim
./sim
echo "simulation DC 625_15: Done"
echo "================================"
echo "start simulation DC 1000_5"
g++ DC_1000_5.cpp -o sim
./sim
echo "simulation DC 1000_5: Done"
echo "================================"
echo "start simulation DC 1600_5"
g++ DC_1600_5.cpp -o sim
./sim
echo "simulation DC 1600_5: Done"
echo "================================"
echo "start simulation HC 625_5"
g++ HC_625_5.cpp -o sim
./sim
echo "simulation HC 625_5: Done"
echo "================================"
echo "start simulation HC 625_10"
g++ HC_625_10.cpp -o sim
./sim
echo "simulation HC 625_10: Done"
echo "================================"
echo "start simulation HC 625_15"
g++ HC_625_15.cpp -o sim
./sim
echo "simulation HC 625_15: Done"
echo "================================"
echo "start simulation HC 1000_5"
g++ HC_1000_5.cpp -o sim
./sim
echo "simulation HC 1000_5: Done"
echo "================================"
echo "start simulation HC 1600_5"
g++ HC_1600_5.cpp -o sim
./sim
echo "simulation HC 1600_5: Done"
echo "================================"
echo "start simulation DC_HC 625_5"
g++ DC_HC_625_5.cpp -o sim
./sim
echo "simulation DC_HC 625_5: Done"
echo "================================"
echo "start simulation DC_HC 625_10"
g++ DC_HC_625_10.cpp -o sim
./sim
echo "simulation DC_HC 625_10: Done"
echo "================================"
echo "start simulation DC_HC 625_15"
g++ DC_HC_625_15.cpp -o sim
./sim
echo "simulation DC_HC 625_15: Done"
echo "================================"
echo "start simulation DC_HC 1000_5"
g++ DC_HC_1000_5.cpp -o sim
./sim
echo "simulation DC_HC 1000_5: Done"
echo "================================"
echo "start simulation DC_HC 1600_5"
g++ DC_HC_1600_5.cpp -o sim
./sim
echo "simulation DC_HC 1600_5: Done"
echo "================================"
echo "finish . . . . . ."
