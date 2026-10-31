
# Hướng dẫn cài đặt & phần cứng dự án (STM32)

## 📑 Mục lục
- [Giới thiệu nhanh](#giới-thiệu-nhanh)
- [1. Cài đặt STM32CubeIDE](#1-cài-đặt-stm32cubeide)
  - [Các bước chi tiết](#các-bước-chi-tiết)
  - [Ảnh minh họa](#ảnh-minh-họa)
- [2. Phần cứng (Bill of Materials)](#2-phần-cứng-bill-of-materials)
- [Ghi chú & mẹo thực hành](#ghi-chú--mẹo-thực-hành)
---

## Giới thiệu nhanh
Tài liệu này chuẩn hóa nội dung để đưa vào **README.md** trên GitHub. Phần 1 hướng dẫn tải và cài **STM32CubeIDE**, phần 2 liệt kê **phần cứng** cần thiết cho dự án (STM32F103C8T6 + GPS + SIM 4G + cảm biến + còi/đèn).

> **Môi trường đề xuất:** Windows cho bản cài `STM32CubeIDE-Win`.

---

## 1. Cài đặt STM32CubeIDE

### Liên kết chính thức
- Trang tải về: <https://www.st.com/en/development-tools/stm32cubeide.html>

### Các bước chi tiết
1. Truy cập trang trên và bấm **Get Software**.  
2. Tại danh sách bộ cài, tìm dòng **STM32CubeIDE-Win** (Windows) và bấm **Get latest**.  
3. Hệ thống yêu cầu điền thông tin Email. Nhập **địa chỉ email** của bạn để nhận **link cài đặt** trong mail từ ST.  
4. Tải file cài đặt từ email, chạy trình cài đặt và làm theo hướng dẫn.  
5. Mở **STM32CubeIDE** sau khi cài đặt xong. (Giao diện ví dụ bên dưới.)

### Ảnh minh họa
![STM32CubeIDE - Get Software](assets/stm32cubeide-download.png)

> _Nếu ảnh chưa hiển thị trên GitHub, hãy chắc chắn rằng tệp hình đã được commit vào repo tại đường dẫn trên._

---

## 2. Phần cứng (Bill of Materials)

| # | Hạng mục | Mã/Model | Gợi ý/Thông số | Ghi chú |
|---|---|---|---|---|
| 1 | **Vi điều khiển** | STM32F103C8T6 | Dòng STM32F1, board Blue Pill hoặc tương đương | Lõi ARM Cortex‑M3, phù hợp dự án nhúng cơ bản |
| 2 | **Nguồn/Pin** | Sạc dự phòng | Dòng xả **≥ 3A** | Bảo đảm ổn định cho module 4G |
| 3 | **Module GPS** | **NEO‑6M** (GEO 6M tương đương) | UART, anten GPS kèm theo | Cần đặt nơi “thông thoáng” để bắt vệ tinh tốt |
| 4 | **Module SIM 4G** | **A7680C** | UART/USB, cần SIM data | Dòng đỉnh cao khi TX—ưu tiên nguồn khỏe |
| 5 | **Cảnh báo** | Còi hú + đèn | 5V/12V tùy lựa chọn | Dùng transistor/MOSFET hoặc driver để điều khiển |
| 6 | **Cảm biến** | Cảm biến **độ ẩm** | Tùy loại (đất/không khí) | Kiểm tra điện áp làm việc & giao tiếp |
| – | Dây, breadboard, vỏ, ốc vít | – | – | Tùy nhu cầu lắp đặt thực tế |

> _Bạn có thể bổ sung sơ đồ khối và sơ đồ nối dây trong thư mục `docs/` của repo (khuyến nghị: `docs/wiring.md`)._

---

## Ghi chú & mẹo thực hành
- **Nguồn nuôi module 4G:** ưu tiên nguồn độc lập hoặc tách đường cấp để tránh sụt áp khi module phát sóng (peak current).
- **Mức điện áp:** Kiểm tra mức logic (3.3V) giữa STM32 và các module; dùng **level shifter** khi cần.
- **UART Debug:** Dành một UART để debug (ví dụ USART1) và một UART cho GPS/SIM (USART2/USART3).
- **Quản lý dự án trong IDE:** Mỗi module (GPS, SIM, Sensor) nên tách thành **driver** / **service** riêng để dễ bảo trì.
- **Tối ưu tiêu thụ:** Bật chế độ tiết kiệm năng lượng của MCU khi không cần xử lý, nhất là khi dùng pin.

---
