//  Created by Irvanda Kurniadi Virdaus
//  Copyright (c) 2018 Irvanda Kurniadi Virdaus. All rights reserved.
//

//  Packet Forwarding in WSN - Hop-Count-based

#include <stdio.h>
#include <iostream>
#include <fstream>

// OPTIONAL
#include <cmath>
// #include <climits>
#include <algorithm>
// #include <string>
#include <vector>

using namespace std;

#define max_dist 500
#define n_dist 20

struct packet { // packet 
	int nslot; // number of slot
	int nhop; // number of hops
	int min_hop; // min hop of source node
	int p_id; // packet id
	int backoff; // backoff timer
	int s_node; //source node
};



struct UE { // UE = User Entity / node
	int x_pos; // position x
	int y_pos; // position y
	int min_hop; // minimum hop
	bool active; // state of a node
	vector<int> rcv_p; // buffer of received packet id
	vector<packet> p_buff; //packet buffer
	vector<packet> r_buff; //received packet buffer
};



double compute_distance(int x, int y, int x_s, int y_s){
	double distance = sqrt(pow((x-x_s),2) + pow((y-y_s),2));
	return distance;
}

// function to initialize the minimum hop count to the sink
int init_hop_count(double dist, double tr){
	bool check = true;
	int hop;
	int i=1;
	while(check)
	{	
		if (dist<(tr*i))
		{
			hop=i;
			check = false;
		}	
			
		i++;
	}
	
	return hop;
}


int main(){
	//write into external file
	// ofstream check;
	// check.open("check_HC.txt");
		ofstream trace;
	trace.open("trace_HC_625_15.txt");
	ofstream genPkt;
	genPkt.open("genPkt_HC_625_15.txt");
	
	
	//START HERE
	
	//Parameter
	double t_range = 50.0; // average transmission range for zigbee IEEE 802.15.4 around 20m - 100m (indoor and outdoor)
	
	int t_msg =  640; // 250 kbps for 200 bytes (1600 bits = 1.6 kb) = 6400 us = 640 slots
    
    int simSlot = 2000000; // Number of time slots in the simulation
                            // 1 slot = 320 us --> IEEE 802.15.4
							
	// Set Contention Window Size for backoff timer
	int CW = 32;
							
	// Set probability of packet generation
	int gen_prob = 15; // 5% packet generation
	int gen_gap = 100000;
							
	//Global Var
	int i,j, k, slot, tr_cnt, rnd, size, pid_counter, transmit_cnt;
	double dist;
	bool transmit;
	bool busy;
	// int max_buff;
	int buff_size=16;
	
	
	// End of simulation
	bool end;
	int end_gen = 500000; // end of generation
	
	
	int n = max_dist/n_dist; // n is number of users in a row
	int n_n = n*n;
	struct UE node[n_n];
	
	// select node n_n-1 as a sink
	int sink = n_n-1;
	
	cout << "number of nodes: " << n_n << endl;
	cout << "sink is node " << sink << endl;
	
	//Initialize nodes
	k=0;
	for (i=0; i<n; i++)
	{
		for (j=0;j<n; j++)
		{
			node[k].x_pos = (j*n_dist);
			node[k].y_pos = (i*n_dist);
			k++;
		}
		dist = compute_distance(node[i].x_pos, node[i].y_pos, node[sink].x_pos, node[sink].y_pos);
		node[i].min_hop = init_hop_count(dist, t_range);
		if (i==sink)
			node[i].min_hop = 0;
		else
			node[i].min_hop = init_hop_count(dist, t_range);
	}
	cout << "initialize nodes: done" << endl;
	
	
	
	// cout << "size node 0: " << node[0].p_buff.size() << endl;
	cout << "initialize min hop : done" << endl;
	
	// seed random number generator
	srand(time(NULL));
	
	cout << "Start simulation . . . . ." << endl;
	
	// check header information to tracer
	//check << "number of nodes: " << n_n << endl;
	//check << "sink node: " << sink << endl;
	//check << "=============================================" << endl;
	//check << "type; " << "time slot; "<< "d_nodes; " << "pid; " << "nslot;" << "nhop; " << endl;
	trace << "iter; " << "type; " << "time slot; "<< "d_nodes; " << "s_nodes; " << "pid; " << "nslot; " << "nhop" << endl;
	genPkt << "iter; " << "generated packet; " << "transmitted packet" << endl;
	
 
	// Start of Simulation
	//=======================
	
	for (int iter=0; iter<10; iter++)
	{
	//initialize global var
	busy = false;
	pid_counter = 0;
	tr_cnt = 0;
	transmit_cnt = 0;
	// max_buff = 0;
	end = false;
	
	for (i=0; i<n_n; i++)
	{
		node[i].p_buff.resize(0);
		node[i].r_buff.resize(0);
		node[i].rcv_p.resize(0);
	}
	
	for (slot =0; slot <= simSlot; slot++)
	{
		
		// set ending of packet generation
		if (slot >= end_gen)
			end = true;
	
		// set no transmission in each round before checking
		transmit = false;
		
		// check busy tranmission
		if (busy)
		{
			tr_cnt--;
		}
		
		
		if (tr_cnt == 0)
			busy = false;
		
		
		// Check each node if there is packet to be transmitted
		if (!busy)
		{
			for (i=0; i<n_n; i++)
			{
				//Check all nodes except sink node
				if (i != sink)
				{
					size = node[i].p_buff.size();
					//Check if there is packet inside buffer
					if (size > 0)
					{
						
						// check << "debug 1: node= " << i << "; backoff = " << node[i].p_buff[j].backoff << endl;
						
						if (node[i].p_buff[0].backoff == 0)
						{
							// check << "Debug 1" << endl;
							// check << node[i].p_buff.size() << endl;
							//check << "t; " << slot << "; " << i << "; "<< node[i].p_buff[0].p_id << "; "<< node[i].p_buff[0].nslot << "; "<< node[i].p_buff[0].nhop << "; "<< endl;
							
							transmit_cnt++;
							
							for(k=0; k<n_n;k++)
							{
								dist = compute_distance(node[i].x_pos, node[i].y_pos, node[k].x_pos, node[k].y_pos);
								
								// check << "node: " << i << "-" << k << "; dist = " << dist << endl;
								
								//check if the node still inside the transmission range
								if (dist < t_range && dist !=0)
								{
									// check << "Debug 2" << endl;
									bool p_exist=false;
									size = node[k].rcv_p.size();
									for (int l=0; l<size; l++)
									{
										//check if the packet is already overheard
										if (node[k].rcv_p[l] == node[i].p_buff[0].p_id)
										{
											// check << "Debug 3" << endl;
											p_exist = true;
											break;
										}
									}
								
									if(p_exist) //overheard same packet
									{
										size = node[k].p_buff.size();
										for (int l=0; l<size; l++)
										{
											//check if the packet which is overheard is inside the buffer. If so, flush the packet
											if (node[k].p_buff[l].p_id == node[i].p_buff[0].p_id)
											{
												node[k].p_buff.erase(node[k].p_buff.begin()+l);
												// check << "Debug 4" << endl;
											}
										}
									}
									else // new packet, then push the packet to receiving node
									{
										// check << "Debug 5" << endl;
										
										node[k].r_buff.push_back(packet());
										int size = node[k].r_buff.size();
										// check << "size of r_buff = " << size << endl;
										node[k].r_buff[size-1].nslot = node[i].p_buff[0].nslot;
										node[k].r_buff[size-1].nhop = node[i].p_buff[0].nhop + 1;
										node[k].r_buff[size-1].p_id = node[i].p_buff[0].p_id;
										node[k].r_buff[size-1].backoff = rand()%CW;
										node[k].r_buff[size-1].s_node = node[i].p_buff[0].s_node;
										node[k].r_buff[size-1].min_hop = node[i].min_hop;
										// transmit_packet(node[k], t_msg, node[i].p_buff[j].nslot, node[i].p_buff[j].nhop, node[i].p_buff[j].p_id, CW );
										
									}
									
								}
							}
							if(!transmit)
							{
								// check << "Debug 6" << endl;
								transmit = true;
								tr_cnt = t_msg;
								busy = true;
							}
							// check << "Debug 6.1" << endl;	
							// check << node[i].p_buff.size() << endl;
							// After trasnmit packet, erase the packet from buffer
							node[i].p_buff.erase(node[i].p_buff.begin());
							// check << "Debug 6.2" << endl;
						}
												
					}
				}
			}
		}
			
		
		// IF there is transmission, Check the collision status
		
		if (busy)
		{
			if(transmit)
			{
				// check << "Debug 7" << endl;
				for (i=0; i<n_n; i++)
				{
					
					size = node[i].r_buff.size();
					if (size > 1) //collision detected
					{
						// check << "Debug 7.1" << endl;
						//check << "c; " << slot << "; " << i << "; " << "-; " << "-; " << "-;" << endl;
						
						node[i].r_buff.resize(0);
					}
					else if(size == 1) // push packet to buffer
					{
						node[i].rcv_p.push_back(node[i].r_buff[0].p_id);
						
						if (i == sink)
						{
							trace << iter << "r; " << slot << "; " << i << "; " << node[i].r_buff[0].s_node << "; " << node[i].r_buff[0].p_id << "; "<< node[i].r_buff[0].nslot << "; " << node[i].r_buff[0].nhop << endl;
						}
						
						if (node[i].p_buff.size() < buff_size)
						{
							//check << "Debug 8: min hop node " << node[i].r_buff[0].s_node << " = " << node[i].r_buff[0].min_hop << "; min hop node " << i << " = " << node[i].min_hop << endl;
							
							if (node[i].r_buff[0].min_hop >= node[i].min_hop) 
								node[i].p_buff.push_back(node[i].r_buff[0]);
						}
						
						//check << "r; " << slot << "; " << i << "; " << node[i].r_buff[0].p_id << "; "<< node[i].r_buff[0].nslot << "; " << node[i].r_buff[0].nhop << "; "<< endl;
						
						// if (max_buff < node[i].p_buff.size())
							// max_buff = node[i].p_buff.size();
						
						node[i].r_buff.resize(0);
					}

					
				}

			}
			
		}
		else // channel idle
		{
			for (i=0; i<n_n; i++)
			{
				size = node[i].p_buff.size();
				if (size > 0)
				{
					// check << "Debug 9" << endl;
					node[i].p_buff[0].backoff=node[i].p_buff[0].backoff-1;
				}
			}
		}
		
		// increasing slot by 1
		for (i=0; i<n_n; i++)
		{
			size = node[i].p_buff.size();
			for (j=0; j<size; j++)
			{
				node[i].p_buff[j].nslot=node[i].p_buff[j].nslot+1;
			}
		}

		
		
		// Packet Generator
		
		// if (slot == 0)
		// {
			// node[0].p_buff.push_back(packet());
			// size = node[0].p_buff.size();
			// node[0].p_buff[size-1].nslot=0;
			// node[0].p_buff[size-1].nhop=0;
			// node[0].p_buff[size-1].p_id=0;
			// node[0].p_buff[size-1].backoff=rand() % CW;
		// }
			
		// check << "slot: " << slot << "transmission counter: " << tr_cnt << endl;
		
		if (!end && slot%gen_gap==0)
		{
			for (i=0; i<n_n; i++)
			{
				// Generate packet for all nodes except sink node
				if (i != sink)
				{
					rnd = (rand() % 100 )+ 1;
					if (rnd <= gen_prob )
					{
						node[i].p_buff.push_back(packet());
						size = node[i].p_buff.size();
						node[i].p_buff[size-1].nslot=0;
						node[i].p_buff[size-1].nhop=0;
						node[i].p_buff[size-1].p_id=pid_counter;
						pid_counter++;
						node[i].p_buff[size-1].backoff=rand() % CW;
						node[i].p_buff[size-1].s_node=i;
						node[i].p_buff[size-1].min_hop=node[i].min_hop;
						//check << "slot: " << slot << "; node: " << i << "; pid: " << node[i].p_buff[size-1].p_id << "; backoff = " << node[i].p_buff[size-1].backoff << endl;
					}
				}
			}
		}
	}
	
	genPkt << iter << "; " << pid_counter << "; " << transmit_cnt << endl;
	
	} //end of iteration
	
	
	return 0;
	
}