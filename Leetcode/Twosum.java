class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        unordered_map<int,int> tmap;
        for(int i=0;i<nums.size();i++)
        {
            if(tmap.find(target-nums[i])!=tmap.end())
            {
                ans.push_back(tmap[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }else{
                tmap[nums[i]] = i;   
            }
        }
        return ans;
    }
};