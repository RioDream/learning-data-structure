#include <iostream>
#include <map>
#include <vector>


using namespace std;

int main(){
	string s;
	char key;
	char value;
	map<char,vector<char> > map_level1;
	map<char,vector<char> > map_level2;
	while(cin>>s){
		key = s[0];
		value = s[3];
		if(map_level1.find(key) == map_level1.end() && map_level2.find(key) == map_level2.end()){
			map_level1[key].push_back(value);
		}else if(map_level1.find(key) != map_level1.end()){
			map_level2[key].push_back(value);
		}
	}
	
	map<char,vector<char> >::iterator it = map_level1.begin();
	map<char,vector<char> >::iterator it_end = map_level1.end();
	for(;it != it_end;it++){
		cout<<it->first<<endl;
		
		//vec in level1 
		for(int i=0;i<map_level1[it->first].size();i++){
			cout<<"  ";
			cout<<map_level1[it->first][i]<<endl;

			//in map2
			if(map_level2.find(map_level1[it->first][i]) != map_level2.end()){
				cout<<"     ";
				for(int j=0;j<map_level2[map_level1[it->first][i]].size();j++){
					cout<<map_level2[map_level1[it->first][i]][j]<<endl;
				}
			}
			
		}
		
	}

	return 0;
}
