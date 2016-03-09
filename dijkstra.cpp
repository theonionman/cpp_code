#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "dijkstra.hpp"
#include "node.hpp"
#include "edge.hpp"
typedef unsigned int uint;

dijkstra::dijkstra(uint s_id, uint d_id, NodeSet n_set) : 
	_source_node_id(s_id), _destination_node_id(d_id), _node_set(n_set) {
}

uint dijkstra::CalOptPath() {
	UpdateNodeSet(_source_node_id, _source_node_id);
	Node *pNode = _node_set.GetNode(_source_node_id);
}

void dijkstra::UpdateNodeSet(uint cur_id, uint pre_id) {
	_selected_node_set.push_back(cur_id);
	_pre_node_set.push_back(pre_id);
}
