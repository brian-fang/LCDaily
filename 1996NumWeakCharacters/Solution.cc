#include <vector>
using namespace std;


const int ATK = 0;
const int DEF = 0;

int numWeak(vector<vector<int>>& properties) {
	sort(properties.begin(), properties.end(), [](const auto& v1, const auto& v2) {
		return v1[0] < v2[0];
	});

	// Maximum defense so far (including 'defense' values associated with current 'attack') 
	int maxdefense = properties.back()[DEF];
	// Maximum defense so far (EXCLUDING 'defense' values associated with current 'attack')
	int defense = 0;
	
	int curatk = properties.back()[ATK];
	int weak = 0;

	for(int i = properties.size() - 2; i >= 0; i--) {
		int a = properties[i][ATK], d = properties[i][DEF];
		
		if(a != curatk) tie(curatk, defense) = make_tuple(a,  max(defense, maxdefense));
		
		if(d < defense) weak++;

		maxdefense = max(maxdefense, d);
	}
	

	return weak;	
} 

int main(int argc, char* argv[]) {
	
}