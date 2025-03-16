class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 1) return 0;  // Already at the last index
        if (arr[0] == 0) return -1;  // Cannot move from the first index

        int maxReach = arr[0], steps = arr[0], jumps = 1;

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // Reached the end

            maxReach = max(maxReach, i + arr[i]);  // Update max reachable index
            steps--;  // Use a step

            if (steps == 0) {  // If no more steps left
                jumps++;  // Take a jump

                if (i >= maxReach) return -1;  // Cannot reach further
                steps = maxReach - i;  // Reset steps
            }
        }
        return -1;  // If unreachable
    }
};
