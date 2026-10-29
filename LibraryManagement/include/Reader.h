#pragma once
#include <string>

// Loại thẻ độc giả: quyết định số sách được mượn cùng lúc
enum class CardType { Student = 0, Teacher = 1, Guest = 2 };

// Thông tin một độc giả (khóa chính: CMND)
struct Reader {
    std::string cmnd;       // Số CMND/CCCD (duy nhất)
    std::string fullName;   // Họ tên
    std::string email;      // Email
    std::string phone;      // Số điện thoại
    CardType cardType = CardType::Student;
    int borrowingCount = 0; // Số sách đang mượn (để kiểm tra ràng buộc)
};
