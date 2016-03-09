#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
using std::vector;

class Edge;

class Node{
	public:
		Node() {
		}
		int GetNodeID() {
			return NodeID;
		}
		unsigned int SetNodeID(unsigned int id) {
			NodeID = id;
			return 0;
		}
		unsigned int AddToEdge(Edge *edge) {
			_edges.push_back(edge);
			return 0;
		}
	private:
		unsigned int NodeID;
		vector<Edge *> _edges;
};

class NodeSet{
	public:
		NodeSet() {
		}
		int AddNode(unsigned int id, Node* node) {
			NodeIdSet.push_back(id);
			_node_set.push_back(node);
		}
		Node *GetNode(unsigned int id) {
			for (vector<unsigned int>::iterator iter = NodeIdSet.begin(); iter != NodeIdSet.end(); ++iter) {
				if( id == *iter) {
					auto node_id_iter_begin = NodeIdSet.begin();
					auto node_iter_begin = _node_set.begin();
					return *( node_iter_begin + (iter - node_id_iter_begin) );
				}
			}
			return NULL;
		}
		bool IsExist(unsigned int id) {
			for (auto iter = NodeIdSet.begin(); iter != NodeIdSet.end(); ++iter) {
				if( id == *iter ){
					return true;
				}
			}
			return false;
		}
		unsigned int GetNodeSetLength() {
			return NodeIdSet.size();			
		}
	private:
		vector<unsigned int> NodeIdSet;
		vector<Node *> _node_set;
};

#endif

