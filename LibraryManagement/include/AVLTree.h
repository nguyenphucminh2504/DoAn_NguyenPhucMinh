#pragma once
#include <algorithm>
#include <functional>
#include "Book.h"

// Cây AVL quản lý sách theo ISBN: thêm / xóa / tìm đều O(log n)
class AVLTree {
private:
    struct Node {
        Book data;
        Node* left = nullptr;
        Node* right = nullptr;
        int height = 1;
        explicit Node(const Book& b) : data(b) {}
    };

    Node* root = nullptr;
    int count = 0;

    static int height(Node* n) { return n ? n->height : 0; }
    static int balanceFactor(Node* n) { return n ? height(n->left) - height(n->right) : 0; }
    static void update(Node* n) { n->height = 1 + std::max(height(n->left), height(n->right)); }

    // Xoay phải quanh y (trường hợp lệch trái)
    static Node* rotateRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        update(y);
        update(x);
        return x;
    }

    // Xoay trái quanh x (trường hợp lệch phải)
    static Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        update(x);
        update(y);
        return y;
    }

    // Cân bằng lại nút n sau khi thêm/xóa
    static Node* rebalance(Node* n) {
        update(n);
        int bf = balanceFactor(n);
        if (bf > 1) {                                   // lệch trái
            if (balanceFactor(n->left) < 0)             // Left-Right
                n->left = rotateLeft(n->left);
            return rotateRight(n);                      // Left-Left
        }
        if (bf < -1) {                                  // lệch phải
            if (balanceFactor(n->right) > 0)            // Right-Left
                n->right = rotateRight(n->right);
            return rotateLeft(n);                       // Right-Right
        }
        return n;
    }

    Node* insert(Node* n, const Book& b, bool& ok) {
        if (!n) { ok = true; return new Node(b); }
        if (b.isbn < n->data.isbn)      n->left = insert(n->left, b, ok);
        else if (b.isbn > n->data.isbn) n->right = insert(n->right, b, ok);
        else { ok = false; return n; }                  // trùng ISBN
        return rebalance(n);
    }

    static Node* minNode(Node* n) {
        while (n->left) n = n->left;
        return n;
    }

    Node* remove(Node* n, const std::string& isbn, bool& ok) {
        if (!n) { ok = false; return nullptr; }
        if (isbn < n->data.isbn)      n->left = remove(n->left, isbn, ok);
        else if (isbn > n->data.isbn) n->right = remove(n->right, isbn, ok);
        else {
            ok = true;
            if (!n->left || !n->right) {                // 0 hoặc 1 con
                Node* child = n->left ? n->left : n->right;
                delete n;
                return child;
            }
            Node* m = minNode(n->right);                // 2 con: lấy nút nhỏ nhất bên phải
            n->data = m->data;
            bool dummy;
            n->right = remove(n->right, m->data.isbn, dummy);
        }
        return rebalance(n);
    }

    static void inorder(Node* n, const std::function<void(const Book&)>& visit) {
        if (!n) return;
        inorder(n->left, visit);
        visit(n->data);
        inorder(n->right, visit);
    }

    static void destroy(Node* n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

public:
    AVLTree() = default;
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;
    ~AVLTree() { destroy(root); }

    // Trả về false nếu ISBN đã tồn tại
    bool insert(const Book& b) {
        bool ok = false;
        root = insert(root, b, ok);
        if (ok) ++count;
        return ok;
    }

    // Trả về false nếu không tìm thấy ISBN
    bool remove(const std::string& isbn) {
        bool ok = false;
        root = remove(root, isbn, ok);
        if (ok) --count;
        return ok;
    }

    // Trả về con trỏ tới sách (sửa trực tiếp được) hoặc nullptr
    Book* find(const std::string& isbn) const {
        Node* cur = root;
        while (cur) {
            if (isbn == cur->data.isbn) return &cur->data;
            cur = (isbn < cur->data.isbn) ? cur->left : cur->right;
        }
        return nullptr;
    }

    // Duyệt theo thứ tự ISBN tăng dần
    void forEach(const std::function<void(const Book&)>& visit) const { inorder(root, visit); }

    int size() const { return count; }
    int treeHeight() const { return height(root); }
};
