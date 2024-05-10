#include <iostream>
#include <vector>
#include <string>

class TreeNode {
public:
    std::string data;
    std::vector<TreeNode*> children;
    TreeNode* parent;

    TreeNode(std::string data) : data(data), parent(nullptr) {}

    void add_child(TreeNode* child) {
        child->parent = this;
        children.push_back(child);
    }

    int get_level() {
        int level = 0;
        TreeNode* p = parent;
        while (p) {
            level++;
            p = p->parent;
        }
        return level;
    }

    void print() {
        std::string spaces(get_level() * 4, ' ');
        std::string prefix = parent ? "|__: " : "";
        std::cout << spaces << prefix << data << std::endl;
        if (!children.empty()) {
            for (TreeNode* child : children) {
                child->print();
            }
        }
    }
};

TreeNode* build_product_tree() {
    TreeNode* root = new TreeNode("Electronics");

    TreeNode* laptop = new TreeNode("Laptop");
    laptop->add_child(new TreeNode("Micorosft surface"));
    TreeNode* macbook = new TreeNode("Macbook");
    macbook->add_child(new TreeNode("MAC OS 14.4.1"));
    macbook->add_child(new TreeNode("MAC OS 13.6.6"));
    macbook->add_child(new TreeNode("MAC OS 12.7.4"));
    macbook->add_child(new TreeNode("MAC OS 10.5.7"));

    laptop->add_child(macbook);

    laptop->add_child(new TreeNode("Windows"));

    TreeNode* cell_phones = new TreeNode("Cell Phones");
    cell_phones->add_child(new TreeNode("Iphone"));
    cell_phones->add_child(new TreeNode("Samsung"));

    TreeNode* tv = new TreeNode("Television");
    tv->add_child(new TreeNode("LG"));
    tv->add_child(new TreeNode("Samsung"));

    root->add_child(laptop);  
    root->add_child(cell_phones);
    root->add_child(tv);

    return root;
}

int main() {
    TreeNode* tree = build_product_tree();
    tree->print();
    return 0;
}
