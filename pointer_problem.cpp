/*The input graph file format of every line: LinkID,SourceID,DestinationID,Cost
 *The input path file format: SourceID,DestinationID,IncludingSet, and the nodes in IncludingSet are seperated by '|'. 
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "stdio.h"
#include "math.h"
#include "stdlib.h"
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

class Edge{
	public:
		Edge( unsigned int link_id, unsigned int cost, Node *from_node, Node *to_node): EdgeID(link_id), WeightValue(cost), FromNode(from_node), ToNode(to_node) {
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
/*notice the difference between new and malloc, malloc is used when the size of an object is fixed, such as Edge;
whereas, new is used for the dynamic situation, such as Node which contains a vector member.*/
/*
int _main() {
	for (int i=0; i<4; i++) {
		cout << "start" << endl;
		Node *pSourceNode = new Node; 
		Edge *pEdge = (Edge *)malloc(sizeof(Edge));
		cout << "end" << endl;
        pSourceNode->AddToEdge(pEdge);   
        cout << "new s node" << endl;
	}	
}
*/
