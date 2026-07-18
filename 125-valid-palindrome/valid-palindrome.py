class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Step 1: Normalize string (remove non-alphanumeric, lowercase)
        cleaned = "".join(c.lower() for c in s if c.isalnum())
        
        # Step 2: Check palindrome
        return cleaned == cleaned[::-1]