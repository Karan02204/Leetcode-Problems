class Solution {
    public int strStr(String haystack, String needle) {
        boolean contains = haystack.contains(needle);
        if(contains){
            int firstIndex = haystack.indexOf(needle);
            return firstIndex;
        } else {
            return -1;
        }
    }
}