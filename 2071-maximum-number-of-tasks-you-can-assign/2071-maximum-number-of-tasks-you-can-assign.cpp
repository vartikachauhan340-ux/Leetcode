class Solution {
public:
    bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int> st;
        int n= workers.size();
        for(int i= n-mid; i<n; i++){
            st.insert(workers[i]);
        }
        int p= pills;
        for(int i= mid-1; i>=0; i--){
            auto it= prev(st.end());
            if(*it >= tasks[i]){
                st.erase(it);
            } else{
                if(p==0){
                    return false;
                }
                auto itr= st.lower_bound(tasks[i] - strength);
                if(itr == st.end()){
                    return false;
                }
                st.erase(itr);
                p--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low=0;
        int high= min(tasks.size(), workers.size());
        int ans=0;
        while(low<= high){
            int mid= low+(high-low)/2;
            if(check(mid, tasks, workers, pills, strength)){
                ans=mid;
                low= mid+1;
            } else{
                high= mid-1;
            }
        }
        return ans;
    }
};