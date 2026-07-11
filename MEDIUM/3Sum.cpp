class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int left = i+1,right = nums.size()-1;

            if(i>0 && nums[i]==nums[i-1]) continue;

            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];

                if(sum == 0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                while(left < right && nums[left]==nums[left-1]) left++;
                while(left < right && nums[right]==nums[right+1]) right--;
                }

                else if(0 < sum) right--;
                else left++;
            }
        }

        return ans;
    }
};

// If you add this thing to your code than your run time and memory time should be reduce.(It's advance C++ method.)
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}
