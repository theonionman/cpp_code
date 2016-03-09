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

#include "node.hpp"
#include "edge.hpp"
#include "parser.hpp"
/*
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

class NodeSet{
	public:
		NodeSet() {
		}
		int AddNode(unsigned int id, Node* node) {
			NodeIdSet.push_back(id);
			_node_set.push_back(node);
		}
		Node *GetNode(unsigned int id) {
			for (auto iter = NodeIdSet.begin(); iter != NodeIdSet.end(); ++iter) {
				if( id == *iter){
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

vector<string> parse_graph;
int CsvParser(char *graph_filename) {
	FILE *fp;
	char ch;
    string str;
	if ( (fp = fopen (graph_filename, "r")) == NULL ) {
		cout << "can not open " << graph_filename << endl;
		return -1;
	}
	ch = getc(fp);
	while ( ch != EOF ) {
		if ( (ch != '\n')) {
			str.push_back(ch);
			if( ((ch = getc(fp)) == EOF) ) {
				string str_line(str); 
				parse_graph.push_back(str_line);
				str = "";
			}
		}
		else {
			string str_line(str); 
			parse_graph.push_back(str_line);
			str = "";	
			ch = getc(fp);		
		}
	}
	cout << "The total number of lines is " << parse_graph.size() << endl;
	return 0;
}

class LineParser{
	public:
		LineParser() {
		}
		unsigned int StrParser(string str) {
			unsigned int length[3];
			string s;
			unsigned int i = 0;
			auto iter_begin = str.begin();
			for (auto iter=str.begin(); iter!=str.end(); iter++) {              //mark the location of each ','
				if( *iter == ',') {
					length[i] =(iter - str.begin());
					i++;
				}
			}
			
			for (int j=0; j<length[0]; j++) {  //find the string which represents the vaule of link id and calculate link id;
				s.push_back(str[j]);
			}
			link_id = StrToInt(s);
			s = "";
			
			for (int j=length[0]+1; j<length[1]; j++) {  //find the string which represents the vaule of source node id and calculate source node id;
				s.push_back(str[j]);
			}
			source_node_id = StrToInt(s);
			s = "";
			for (int j=length[1]+1; j<length[2]; j++) {  //find the string which represents the vaule of destination node id and calculate destination node id;
				s.push_back(str[j]);
			}
			destination_node_id = StrToInt(s);
			s = "";
			for (int j=length[2]+1; j<str.size(); j++) {  //find the string which represents the vaule of link cost and calculate link cost;
				s.push_back(str[j]);
			}
			link_cost = StrToInt(s);
			s = "";
			return 0;
		}
		unsigned int StrToInt(string s) {
			unsigned int a[s.size()];
			unsigned int value = 0;
			unsigned int i = 0; 
			for (auto c : s) {
				a[i] = c -'0';
				i++;
			}
			for ( i=0; i<s.size(); i++) {
				value += a[i]*pow(10, (s.size()-1-i));
			}
			return value;
		}
		unsigned int GetLinkID() {
			return link_id;
		}
		unsigned int GetSourceNodeID() {
			return source_node_id;
		}
		unsigned int GetDestinationNodeID() {
			return destination_node_id;
		}
		unsigned int GetLinkCost() {
			return link_cost;
		}
	private:
		string link_info;
		unsigned int link_id;
		unsigned int source_node_id;
		unsigned int destination_node_id;
		unsigned int link_cost;
};
*/
int main() {
	unsigned int LinkID = 0;
	unsigned int SourceID = 0;
	unsigned int DestinationID = 1;
	unsigned Cost = 1;
	NodeSet node_set;
	EdgeSet edge_set;
	vector<string> *parse_graph = new vector<string>;
	parse_graph = CsvParser("topo.csv", parse_graph); //Dose it work? or should use reference explictly.
	LineParser line_parser;
	for (auto str : *parse_graph) {
		line_parser.StrParser(str);
		LinkID = line_parser.GetLinkID();
		SourceID = line_parser.GetSourceNodeID();
		DestinationID = line_parser.GetDestinationNodeID();
		Cost = line_parser.GetLinkCost();
		cout << LinkID << '|' << SourceID << '|' << DestinationID << '|' << Cost << endl;
	
		if( !node_set.IsExist(SourceID) ) {
			if( !node_set.IsExist(DestinationID) ) {
				Node *pSourceNode = new Node;
				pSourceNode->SetNodeID(SourceID);
				node_set.AddNode(SourceID, pSourceNode);
				
				Node *pDestinationNode = new Node;
				pDestinationNode->SetNodeID(DestinationID);
				node_set.AddNode(DestinationID, pDestinationNode);
				
				Edge *pEdge = new Edge;
				pEdge->EdgeInit(LinkID, pSourceNode, pDestinationNode, Cost);
				edge_set.AddEdge(LinkID, pEdge);
		        pSourceNode->AddToEdge(pEdge);
		        
		        cout << "new s node new d node" << endl;
			} 
			else {
				Node *pSourceNode = new Node;
				pSourceNode->SetNodeID(SourceID);
				node_set.AddNode(SourceID, pSourceNode);
				
				Edge *pEdge = new Edge;
				pEdge->EdgeInit(LinkID, pSourceNode, node_set.GetNode(DestinationID), Cost);
				edge_set.AddEdge(LinkID, pEdge);
				
		        pSourceNode->AddToEdge(pEdge);
		        
		        cout << "new s node old d node" << endl;
			} 
		}
		
		else if ( !node_set.IsExist(DestinationID) ) {
				Node *pDestinationNode = new Node;
				pDestinationNode->SetNodeID(DestinationID);
				node_set.AddNode(DestinationID, pDestinationNode);
				
		        Edge *pEdge = new Edge;
				pEdge->EdgeInit(LinkID, node_set.GetNode(SourceID), pDestinationNode, Cost);
				edge_set.AddEdge(LinkID, pEdge);
				
				node_set.GetNode(SourceID)->AddToEdge(pEdge);
				cout << "old s node new d node" << endl;
			}
			else {
				Edge *pEdge = new Edge;
				pEdge->EdgeInit(LinkID, node_set.GetNode(SourceID), node_set.GetNode(DestinationID), Cost);
				edge_set.AddEdge(LinkID, pEdge);
				
				node_set.GetNode(SourceID)->AddToEdge(pEdge);
				cout << "old s node old d node" << endl;
			}
    }
    cout << "the number of nodes is " << node_set.GetNodeSetLength() << endl << "the number of edges is " << edge_set.GetEdgeSetLength() << endl; 
    return 0;
}
