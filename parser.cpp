#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "stdio.h"
#include "stdlib.h"
#include "parser.hpp"
vector<string>* CsvParser(char *graph_filename, vector<string>* par_graph) {
	FILE *fp;
	char ch;
    string str;
	if ( (fp = fopen (graph_filename, "r")) == NULL ) {
		cout << "can not open " << graph_filename << endl;
		return NULL;
	}
	ch = getc(fp);
	while ( ch != EOF ) {
		if ( (ch != '\n')) {
			str.push_back(ch);
			if( ((ch = getc(fp)) == EOF) ) {
				string str_line(str); 
				par_graph->push_back(str_line);
				str = "";
			}
		}
		else {
			string str_line(str); 
			par_graph->push_back(str_line);
			str = "";	
			ch = getc(fp);		
		}
	}
	cout << "The total number of lines is " << par_graph->size() << endl;
	return par_graph;
}

