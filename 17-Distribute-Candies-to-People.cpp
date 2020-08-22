class Solution {
public:
    vector<int> distributeCandies(double candies, int num_people) {
	    vector<int> res(num_people, 0);
        int idx = 0,candy_count = 1;
        while(candies > 0){
            res[idx++] += candy_count;
            candies -= candy_count++;
            if(idx == num_people) idx = 0;
            if(candy_count > candies)
                candy_count = candies;
            
        }
        return res;
    }
};