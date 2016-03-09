#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <vector>
using std::vector;

#include "node.hpp"
#include "edge.hpp"
typedef unsigned int uint;
class dijkstra {
	public:
		dijkstra(uint, uint, NodeSet);
		uint CalOptPath();
		vector<uint> GetOptPath(uint);
		void UpdateNodeSet(uint, uint);
	private:
		uint _source_node_id;
		uint _destination_node_id;
		//vector<uint>   _node_id_set;
		NodeSet        _node_set;          //all nodes in the graph, including nodes ID vector and nodes vector. 
		vector<uint>   _selected_node_set; //the set is used to specify the nodes which are calculated to be optimal.
		vector<uint>   _pre_node_set;      //the set contains the corresponding previous node to the node in selected node set.
};
#endif
