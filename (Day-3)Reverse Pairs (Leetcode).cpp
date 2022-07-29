// https://leetcode.com/problems/reverse-pairs/submissions/
class Solution
{
    public:
	int merge(vector<int> &nums, vector<int> &temp, int st, int mid, int sp){
		int cnt = 0;
        
		for(int i = st, j = mid+1; i <= mid ; i++){
			
			while(j <= sp && nums[i] > 2LL * nums[j]){
				j ++;
			}
			cnt += (j - (mid+1));
		}

		int i = st;
		int j = mid + 1;
		int k = st ;

		while(i <= mid && j <= sp){
			if(nums[i] <= nums[j]){
				temp[k++] = nums[i++];
			}
			else{
				temp[k++] = nums[j++];
			}
		}

		while(i <= mid){
			temp[k++] = nums[i++];
		}

		while(j <= sp){
			temp[k++] = nums[j++] ;
		}

		for(int _i = st ; _i <= sp; _i++){
			nums[_i] = temp[_i];
		}

		return cnt ;
	}

	int mergeSort(vector<int> &nums, vector<int> &temp, int st, int sp){
		int cnt = 0;
		if(st < sp){
			int mid = st + sp;
			mid /= 2;

			cnt += mergeSort(nums,temp,st,mid);
			cnt += mergeSort(nums,temp,mid+1,sp);

			cnt += merge(nums,temp,st,mid,sp);
		}
		return cnt ;
	}
	int reversePairs(vector<int> &nums)
	{
		int n = nums.size() ;
		vector<int> temp(n, 0);
		int ans = mergeSort(nums, temp, 0, n-1);
		return ans ;
	}
};
