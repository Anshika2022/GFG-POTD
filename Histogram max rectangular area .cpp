class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
    stack<int> s; // Stack to store indices of histogram bars
    int maxArea = 0; // Initialize max area
    int tp;  // Store top of stack
    int areaWithTop; // Store area with top bar as the smallest bar

    int i = 0;
    while (i < n) {
        // If this bar is higher than the bar at stack top, push it to stack
        if (s.empty() || arr[s.top()] <= arr[i]) {
            s.push(i++);
        } else {
            // Pop the top
            tp = s.top();
            s.pop();
            
            // Calculate the area with hist[tp] as the smallest (or minimum height) bar
            areaWithTop = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            
            // Update max area
            maxArea = max(maxArea, areaWithTop);
        }
    }

    // Now pop the remaining bars from stack and calculate area
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        areaWithTop = arr[tp] * (s.empty() ? i : i - s.top() - 1);
        maxArea = max(maxArea, areaWithTop);
    }

    return maxArea;
}

int main() {
    vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
    cout << "Maximum rectangular area: " << getMaxArea(arr) << endl;
    return 0;
    }
};
