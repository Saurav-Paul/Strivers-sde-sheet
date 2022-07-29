//https://leetcode.com/problems/two-sum/
map<int,int> freq ;
        for(auto n : nums){
            freq[n] ++;
        }
        
        int n1 = -1 , n2 = -1;
        
        for(auto n : nums){
            int baki = target - n;
            
            if(baki == n && freq[baki] <= 1) continue;
            
            if(freq[baki] > 0){
                n1 = n;
                n2 = baki;
                break;
            }
        }
        
        vector<int> ans ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == n1){
                ans.push_back(i);
                break;
            }
        }
        
        for(int i = nums.size() - 1 ; i >= 0; i--){
            if(nums[i] == n2){
                ans.push_back(i);
                break;
            }
        }
