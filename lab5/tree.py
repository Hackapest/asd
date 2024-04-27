import graphviz

class TreeNode:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        # Helper function to insert a key into the tree
        def _insert(root, key):
            if root is None:
                return TreeNode(key)
            else:
                if key < root.val:
                    root.left = _insert(root.left, key)
                else:
                    root.right = _insert(root.right, key)
                return root

        self.root = _insert(self.root, key)

    def inorder_traversal(self):
        # Perform an inorder traversal of the tree
        def _inorder(node, result):
            if node:
                _inorder(node.left, result)
                result.append(node.val)
                _inorder(node.right, result)

        result = []
        _inorder(self.root, result)
        return result

    def visualize_binary_tree(self):
        dot = graphviz.Digraph()
        dot.node(str(self.root.val))

        def add_nodes_edges(node):
            if node.left:
                dot.node(str(node.left.val))
                dot.edge(str(node.val), str(node.left.val))
                add_nodes_edges(node.left)
            if node.right:
                dot.node(str(node.right.val))
                dot.edge(str(node.val), str(node.right.val))
                add_nodes_edges(node.right)

        add_nodes_edges(self.root)
        dot.render('binary_tree', view=True, format='png')

    def find_biggest(self):
        if self.root is None:
            return None

        node = self.root
        while node.right:
            node = node.right
        return node.val

    def find_element(self, key):
        if self.root is None:
            return None

        node = self.root
        while node:
            if key == node.val:
                return node
            elif key < node.val:
                node = node.left
            else:
                node = node.right
        return None


# Example usage:
if __name__ == "__main__":
    tree = BinaryTree()
    keys = [5, 3, 8, 2, 4, 7, 9]

    for key in keys:
        tree.insert(key)

    tree.visualize_binary_tree()

    print("Inorder traversal:", tree.inorder_traversal())