class Solution {
    public int lengthOfLastWord(String s) {
        String[] str = s.split(" ");
        char[] charArray = str[str.length-1].toCharArray();
        return charArray.length;
    }
}