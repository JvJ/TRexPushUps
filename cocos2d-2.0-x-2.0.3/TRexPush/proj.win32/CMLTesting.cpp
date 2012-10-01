#include "XMLTesting.h"
#include <iostream>
#include "pugixml.hpp"

using namespace std;
using namespace pugi;

void xmlTests(std::string filename){

	xml_document doc;

	xml_parse_result result = doc.load_file(filename.data());

	cout<< "Load result: "<<result.description()<<endl;
}