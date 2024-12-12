class Solution {
  public:
        // code here
        int firstOcc(vector<int>& arr, int target) {
    int s = 0, e = arr.size() - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2; // Avoids overflow
        if (arr[mid] == target) {
            ans = mid;
            e = mid - 1; // Search on the left
        } else if (arr[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int lastOcc(vector<int>& arr, int target) {
    int s = 0, e = arr.size() - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2; // Avoids overflow
        if (arr[mid] == target) {
            ans = mid;
            s = mid + 1; // Search on the right
        } else if (arr[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int countFreq(vector<int>& arr, int target) {
    int first = firstOcc(arr, target);
    int last = lastOcc(arr, target);
    if (first == -1 || last == -1) return 0; // Target not found
    return last - first + 1;
    }
};
