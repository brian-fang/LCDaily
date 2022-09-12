#include <vector>
using namespace std;

/*
 
 Aim to
    increase score with smallest loss of power (spend is token[i])
 
    if you can't increase score,
        you may be able to increase power by decreasing score so that you may
        be able to increase score later
        
        should increase power by maximum amount (spend is one score)
 
 
 Idea:
    sort array
 
    increase score from left until you can't (minimum decrease in power for the same
    increase in score)
 
    increase power/decrease score from right (maximum increase in power for the same
    decrease in score)
 
 */


int max_score(vector<int>& tokens, int power) {

    sort(tokens.begin(), tokens.end());
    
    int l = 0, r = tokens.size() - 1;
    int res = 0;
    int score = 0;
    
    while(l <= r) {
        if(power >= tokens[l]) {
            power -= tokens[l++];
            res = max(res, ++score);
        }
        else if(score) {
            power += tokens[r--];
            score--;
        }
        else return res;
    }
    
    return res;
}

int main(int argc, char* argv[]) {
    
}
