class Solution
{
    public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);

        while(!q.empty())
        {
            int crr = q.front();
            q.pop();
            if(arr[crr] == 0)
                return true;
            if(arr[crr] < 0)
                continue;

            if (crr + arr[crr] < arr.size()) q.push(crr + arr[crr]);
            if (crr - arr[crr] >= 0) q.push(crr - arr[crr]);

            arr[crr] = -arr[crr];
        }
        return false;
    }
};