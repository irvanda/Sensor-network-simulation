#!/bin/bash

echo "start running process bcast_625_5"
./process.sh trace_bcast_625_5.txt genPkt_bcast_625_5.txt
mv result process_done/result_bcast_625_5.txt

echo "start running process bcast_625_10"
./process.sh trace_bcast_625_10.txt genPkt_bcast_625_10.txt
mv result process_done/result_bcast_625_10.txt

echo "start running process bcast_625_15"
./process.sh trace_bcast_625_15.txt genPkt_bcast_625_15.txt
mv result process_done/result_bcast_625_15.txt

echo "start running process bcast_1000_5"
./process.sh trace_bcast_1000_5.txt genPkt_bcast_1000_5.txt
mv result process_done/result_bcast_1000_5.txt

echo "start running process bcast_1600_5"
./process.sh trace_bcast_1000_5.txt genPkt_bcast_1000_5.txt
mv result process_done/result_bcast_1000_5.txt

echo "start running process DC_625_5"
./process.sh trace_DC_625_5.txt genPkt_DC_625_5.txt
mv result process_done/result_DC_625_5.txt

echo "start running process DC_625_10"
./process.sh trace_DC_625_10.txt genPkt_DC_625_10.txt
mv result process_done/result_DC_625_10.txt

echo "start running process DC_625_15"
./process.sh trace_DC_625_15.txt genPkt_DC_625_15.txt
mv result process_done/result_DC_625_15.txt

echo "start running process DC_1000_5"
./process.sh trace_DC_1000_5.txt genPkt_DC_1000_5.txt
mv result process_done/result_DC_1000_5.txt

echo "start running process DC_1600_5"
./process.sh trace_DC_1000_5.txt genPkt_DC_1000_5.txt
mv result process_done/result_DC_1000_5.txt

echo "start running process HC_625_5"
./process.sh trace_HC_625_5.txt genPkt_HC_625_5.txt
mv result process_done/result_HC_625_5.txt

echo "start running process HC_625_10"
./process.sh trace_HC_625_10.txt genPkt_HC_625_10.txt
mv result process_done/result_HC_625_10.txt

echo "start running process HC_625_15"
./process.sh trace_HC_625_15.txt genPkt_HC_625_15.txt
mv result process_done/result_HC_625_15.txt

echo "start running process HC_1000_5"
./process.sh trace_HC_1000_5.txt genPkt_HC_1000_5.txt
mv result process_done/result_HC_1000_5.txt

echo "start running process HC_1600_5"
./process.sh trace_HC_1000_5.txt genPkt_HC_1000_5.txt
mv result process_done/result_HC_1000_5.txt

echo "start running process DC_HC_625_5"
./process.sh trace_DC_HC_625_5.txt genPkt_DC_HC_625_5.txt
mv result process_done/result_DC_HC_625_5.txt

echo "start running process DC_HC_625_10"
./process.sh trace_DC_HC_625_10.txt genPkt_DC_HC_625_10.txt
mv result process_done/result_DC_HC_625_10.txt

echo "start running process DC_HC_625_15"
./process.sh trace_DC_HC_625_15.txt genPkt_DC_HC_625_15.txt
mv result process_done/result_DC_HC_625_15.txt

echo "start running process DC_HC_1000_5"
./process.sh trace_DC_HC_1000_5.txt genPkt_DC_HC_1000_5.txt
mv result process_done/result_DC_HC_1000_5.txt

echo "start running process DC_HC_1600_5"
./process.sh trace_DC_HC_1000_5.txt genPkt_DC_HC_1000_5.txt
mv result process_done/result_DC_HC_1000_5.txt


