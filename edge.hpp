#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
using std::vector;

//#include "node.h"
#include "stdio.h"

class Node;

class Edge{
	public:
		Edge() {
		}
		unsigned int EdgeInit( unsigned int link_id, Node *from_node, Node *to_node, unsigned int cost ) {
			EdgeID = link_id;
			WeightValue = cost; 
			FromNode = from_node;
			ToNode = to_node;
			return 0;
		}
		unsigned int GetEdgeID() {
			return EdgeID;
		}
		unsigned int GetEdgeWeightValue() {
			return WeightValue;
		}
		Node *GetFromNode() {
			return FromNode;
		}
		Node *GetToNode() {
			return ToNode;
		}
	private:
		unsigned int EdgeID;
		unsigned int WeightValue;
		Node *FromNode;
		Node *ToNode;
};

class EdgeSet{
	public:
		EdgeSet() {
		}
		int AddEdge(unsigned int id, Edge* edge) {
			EdgeIdSet.push_back(id);
			_edge_set.push_back(edge);
		}
		Edge *GetEdge(unsigned int id) {
			for (auto iter = EdgeIdSet.begin(); iter != EdgeIdSet.end(); ++iter) {
				if( id == *iter){
					auto edge_id_iter_begin = EdgeIdSet.begin();
					auto edge_iter_begin = _edge_set.begin();
					return *( edge_iter_begin + (iter - edge_id_iter_begin) );
				}
			}
			return NULL;
		}
		bool IsExist(unsigned int id) {
			for (auto iter = EdgeIdSet.begin(); iter != EdgeIdSet.end(); ++iter) {
				if( id == *iter ){
					return true;
				}
			}
			return false;
		}
		unsigned int GetEdgeSetLength() {
			return EdgeIdSet.size();			
		}
	private:
		vector<unsigned int> EdgeIdSet;
		vector<Edge *> _edge_set;
};
#endif

