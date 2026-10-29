#pragma once
#include <string>

// Thông tin một cuốn sách (khóa chính: ISBN)
struct Book {
    std::string isbn;       // Mã ISBN (duy nhất)
    std::string title;      // Tên sách
    std::string author;     // Tác giả
    std::string genre;      // Thể loại
    int year = 0;           // Năm xuất bản
    int totalCopies = 0;    // Tổng số bản
    int available = 0;      // Số bản còn lại trong kho
};
