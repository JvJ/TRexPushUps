#include "SVGLoader.h"
#include <sstream>

using namespace std;
using namespace pugi;

SVGLoader::SVGLoader(string filename)
{

	doc.load_file(filename.data());

	doc.traverse(*this);
}



SVGLoader::~SVGLoader(void)
{
}

void SVGLoader::parseVertices(string init, vector<b2Vec2> &vec){
	auto str = stringstream(init);

		string s;
		while(str.good()){
			str >> s;
			int idx = s.find(',');

			if (idx == -1){
				continue;
			}
			else{
				string s1 = s.substr(0,idx);
				string s2 = s.substr(idx+1, -1);

				double x;  stringstream(s1) >> x;
				double y;  stringstream(s2) >> y;

				vec.push_back(b2Vec2(x, y));
			}
		}
	}

bool SVGLoader::for_each(xml_node &node){

	
	string name = node.name();
	string id = node.attribute("id").as_string();

	if(name == "path"){

		// The vertex path attribute
		string vs = node.attribute("d").as_string();

		paths[id] = vector<b2Vec2>();

		parseVertices(vs, paths[id]);
			
			// End the traversal
			return false;
		}

		// Continue the traversal
		return true;
}

b2EdgeShape *SVGLoader::createEdge(string obj_id){

	auto &vec = paths[obj_id];

	b2EdgeShape *ret = new b2EdgeShape();

	for (auto itr = vec.begin(); itr != vec.end()-1;){
		ret->Set(*itr, *(++itr));
	}

	return ret;
}