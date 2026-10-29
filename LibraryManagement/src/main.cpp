#include <iostream>
#include "../include/AVLTree.h"

// Tuần 3 (tạm thời): demo AVL. Các tuần sau sẽ thay bằng menu chương trình đầy đủ.
int main() {
    AVLTree books;
    books.insert({"978001", "Lap trinh C++", "Nguyen Van A", "Cong nghe", 2020, 5, 5});
    books.insert({"978002", "Cau truc du lieu", "Tran Van B", "Cong nghe", 2019, 3, 3});
    books.insert({"978003", "Doraemon tap 1", "Fujiko", "Truyen tranh", 2015, 10, 10});

    std::cout << "Danh sach sach (theo ISBN):\n";
    books.forEach([](const Book& b) {
        std::cout << b.isbn << " | " << b.title << " | " << b.genre << " | con " << b.available << "\n";
    });
    return 0;
}
