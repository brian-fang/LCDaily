class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Returns the root of a pruned tree, or None if the whole tree is made up of 0's or
# None 
def pruneTree(root):
    if not root:
        return None
    
    root.left = pruneTree(root.left)
    root.right = pruneTree(root.right)
    
    # Whether this node can/must be removed
    prunethis = (root.val==0) and (not root.left) and (not root.right)
    return None if prunethis else root
