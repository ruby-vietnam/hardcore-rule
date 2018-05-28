#
# Link: https://leetcode.com/problems/simplify-path
#
# 252 / 252 test cases passed.
# Status: Accepted
# Runtime: 39 ms
# Your runtime beats 99.53 % of cpp submissions.
#

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        directories = path.split("/")

        pwds = []
        for directory in directories:
            if directory == "." or directory == "":
                continue
            elif directory == "..":
                if pwds: pwds.pop()
            else:
                pwds.append(directory)

        return "/" + "/".join(pwds)
