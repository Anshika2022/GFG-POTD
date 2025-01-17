class Solution {
    public static int[] productExceptSelf(int arr[]) {
        // code here
        int right=arr[arr.length-1];
        int[] Ip=new int[arr.length];
        Ip[0]=1;
        for(int i=1; i<arr.length;i++)Ip[i]=Ip[i-1]*arr[i-1];
        for(int i=arr.length-2;i>=0;i--){
            Ip[i]*= right;
            right*=arr[i];
        }
        return Ip;
    }
}
