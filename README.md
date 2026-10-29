# Chương Trình Quản Lý Thư Viện

- **Môn học**: Đồ án Tin học
- **Giảng viên hướng dẫn**: Lương An Vinh
- **Sinh viên thực hiện:**
  - Nguyễn Phúc Minh - MSSV: DH52301145

---

# Giới thiệu chung

- Đồ án xây dựng phần mềm quản lý thư viện bằng ngôn ngữ C++.
- Chương trình tự cài đặt các cấu trúc dữ liệu và giải thuật đã học, kết hợp với một cấu trúc dữ liệu tự tìm hiểu. Dữ liệu được lưu trực tiếp trên file (nhị phân và văn bản), không sử dụng hệ quản trị cơ sở dữ liệu.

---

# Các chức năng chính

- **Quản lý sách:** thêm, xóa, sửa, tìm theo ISBN, tìm theo tiền tố tên, nhập/xuất file.
- **Quản lý độc giả:** thêm, xóa, sửa thông tin, quản lý theo CMND.
- **Mượn/trả sách:** lập phiếu mượn, xử lý trả sách, tính tiền phạt quá hạn, kiểm tra ràng buộc.
- **Thống kê - báo cáo:** thống kê lượt mượn theo tháng/thể loại, top 10 sách và độc giả mượn nhiều nhất.
- **Tìm kiếm nâng cao và gợi ý:** gợi ý sách cùng thể loại (đồ thị), tìm sách theo tiền tố tên (Trie - autocomplete).
- **Lưu trữ:** tự động đọc/ghi file nhị phân (.dat), xuất báo cáo (.txt), sao lưu dữ liệu.

---

# Cấu trúc dữ liệu áp dụng

| STT | Cấu trúc dữ liệu / Giải thuật      | Áp dụng cho chức năng                    |
|:---:|:-----------------------------------|:-----------------------------------------|
| 1   | **Cây AVL**                        | Quản lý sách theo mã ISBN                |
| 2   | **Cây BST**                        | In danh mục sách theo tên (in-order)     |
| 3   | **Hash Table** (Separate Chaining) | Quản lý độc giả theo CMND                |
| 4   | **Danh sách liên kết đơn**         | Danh sách phiếu mượn                     |
| 5   | **Danh sách đặc (mảng động)**      | Lịch sử giao dịch                        |
| 6   | **Đồ thị (danh sách kề)**          | Gợi ý sách cùng thể loại (BFS/DFS)       |
| 7   | **CTDL tự tìm hiểu: Cây Trie**     | Tìm sách theo tiền tố tên (autocomplete) |
| 8   | **Đọc/Ghi file nhị phân**          | Lưu trữ toàn bộ dữ liệu                  |

---

# Cấu trúc thư mục dự án

```
LibraryManagement/
│
├── LibraryManagement/
│   ├── include/       # Chứa các file header (.h)
│   └── src/           # Chứa các file source code (.cpp)
├── data/              # Chứa file dữ liệu mẫu (.dat, .txt)
├── docs/              # Chứa báo cáo, hình ảnh, sơ đồ lớp
├── tests/             # Chứa các file test case
├── LibraryManagement.sln   # Solution của Visual Studio
└── README.md          # File mô tả dự án (file này)
```

## 📅 Checklist Tiến Độ

### Tuần 1

- [x] Repo Git
- [x] SRS.pdf
- [x] Cấu trúc thư mục

### Tuần 2

- [x] Design.pdf
- [x] Sơ đồ lớp
- [x] Định nghĩa struct

### Tuần 3

- [x] AVL
- [ ] BST
- [ ] Test quản lý sách

### Tuần 4

- [ ] Hash Table
- [ ] Test quản lý độc giả

### Tuần 5

- [ ] LinkedList
- [ ] Dynamic Array
- [ ] File I/O

### Tuần 6

- [ ] Mượn sách
- [ ] Trả sách
- [ ] Tính phạt

### Tuần 7

- [ ] Graph
- [ ] BFS/DFS
- [ ] Thống kê top 10

### Tuần 8

- [ ] CTDL mới (Trie)
- [ ] Tích hợp
- [ ] Demo

### Tuần 9

- [ ] Unit test
- [ ] Bảng so sánh
- [ ] User manual

### Tuần 10

- [ ] Báo cáo
- [ ] Video
- [ ] Slide
- [ ] Nộp + ký
