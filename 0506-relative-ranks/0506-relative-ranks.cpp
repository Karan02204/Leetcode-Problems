class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> answer;
        vector<int> temp(score.size());
        for(int i=0;i<score.size();i++){
            temp[i] = score[i];
        }
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp.size()-1;j++){
                if(temp[j+1] > temp[j]){
                    swap(temp[j+1],temp[j]);
                }
            }
        }

        int index ;
        for(int i=0;i<score.size();i++){
            int element = score[i];
            for(int j=0;j<temp.size();j++){
                if(element == temp[j]){
                    index = j+1;
                }

            }
                if(index == 1){
                    answer.push_back("Gold Medal");
                } else if(index == 2){
                    answer.push_back("Silver Medal");
                } else if(index == 3){
                    answer.push_back("Bronze Medal");
                } else if(index >3){
                    answer.push_back(to_string(index));
                }
        }

        return answer;
    }
};