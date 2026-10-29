#pragma once
#include <string>
#include "Date.h"

enum class TransactionType { Borrow = 0, Return = 1 };

// Một dòng trong lịch sử giao dịch (lưu bằng mảng động)
struct Transaction {
    TransactionType type = TransactionType::Borrow;
    std::string loanId;
    std::string cmnd;
    std::string isbn;
    Date date;
    long amount = 0;        // Tiền phạt phát sinh (0 nếu là giao dịch mượn)
};
