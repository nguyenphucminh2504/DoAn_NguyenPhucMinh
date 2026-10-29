#pragma once
#include <string>
#include "Date.h"

enum class LoanStatus { Borrowing = 0, Returned = 1 };

// Một phiếu mượn sách
struct Loan {
    std::string loanId;     // Mã phiếu (duy nhất)
    std::string cmnd;       // CMND độc giả mượn
    std::string isbn;       // ISBN sách được mượn
    Date borrowDate;        // Ngày mượn
    Date dueDate;           // Ngày hẹn trả
    Date returnDate;        // Ngày trả thực tế (chỉ có nghĩa khi đã trả)
    LoanStatus status = LoanStatus::Borrowing;
    long fine = 0;          // Tiền phạt (đồng), tính khi trả sách
};
