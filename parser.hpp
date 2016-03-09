#ifndef PARSER_HPP
#define PARSER_HPP
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "math.h"
vector<string> *CsvParser(char *, vector<string> *);
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

#endif
