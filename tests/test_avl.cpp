#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "../include/AVLTree.h"

static Book makeBook(const std::string& isbn, const std::string& title) {
    Book b;
    b.isbn = isbn;
    b.title = title;
    b.totalCopies = b.available = 1;
    return b;
}

int main() {
    AVLTree tree;

    // 1. Thêm 1000 sách theo thứ tự tăng dần (trường hợp xấu nhất của BST thường)
    for (int i = 1; i <= 1000; ++i)
        assert(tree.insert(makeBook(std::to_string(100000 + i), "Sach " + std::to_string(i))));
    assert(tree.size() == 1000);
    assert(tree.treeHeight() <= 11);                // AVL: chiều cao ~ log2(n)
    std::cout << "[OK] Them 1000 sach, chieu cao = " << tree.treeHeight() << "\n";

    // 2. Không cho trùng ISBN
    assert(!tree.insert(makeBook("100001", "Trung")));
    std::cout << "[OK] Tu choi ISBN trung\n";

    // 3. Tìm kiếm
    Book* p = tree.find("100500");
    assert(p && p->title == "Sach 500");
    assert(tree.find("999999") == nullptr);
    std::cout << "[OK] Tim kiem\n";

    // 4. Sửa trực tiếp qua con trỏ
    p->title = "Da sua";
    assert(tree.find("100500")->title == "Da sua");
    std::cout << "[OK] Sua thong tin\n";

    // 5. Xóa: lá, nút 1 con, nút 2 con
    for (int i = 1; i <= 1000; i += 2)
        assert(tree.remove(std::to_string(100000 + i)));
    assert(tree.size() == 500);
    assert(!tree.remove("100001"));                 // đã xóa rồi
    assert(tree.treeHeight() <= 10);
    std::cout << "[OK] Xoa 500 sach, con " << tree.size() << ", chieu cao = " << tree.treeHeight() << "\n";

    // 6. Duyệt in-order phải ra thứ tự tăng dần
    std::vector<std::string> keys;
    tree.forEach([&](const Book& b) { keys.push_back(b.isbn); });
    for (size_t i = 1; i < keys.size(); ++i) assert(keys[i - 1] < keys[i]);
    std::cout << "[OK] Duyet in-order tang dan\n";

    std::cout << "\nTat ca test AVL deu dat!\n";
    return 0;
}
