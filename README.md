## Cấu trúc dự án

### Thư mục
- **assets/**
    - Chứa các tài nguyên của trò chơi như phông chữ, shader, loại tetromino, và texture.
- **cmake-build-debug/**
    - Chứa các tệp được tạo bởi CMake để gỡ lỗi.
- **include/**
    - Chứa các thư viện và tệp tiêu đề bên ngoài cần thiết cho dự án.
        - `glad/` và `KHR/`: Tệp tiêu đề cho chức năng OpenGL.
        - `glad.c`: Triển khai thư viện GLAD.
- **src/**
    - Chứa mã nguồn của dự án.
        - `block.cpp`, `block.h`: Xử lý logic cho các khối trò chơi.
        - `game.cpp`, `game.h`: Quản lý vòng lặp trò chơi và gameplay chính.
        - `main.cpp`: Điểm vào của ứng dụng.
        - `render.cpp`, `render.h`: Xử lý logic hiển thị.
        - `resourceManager.cpp`, `resourceManager.h`: Quản lý tài nguyên trò chơi (ví dụ: texture, shader).
        - `shader.cpp`, `shader.h`: Triển khai chức năng shader.
        - `squareMap.cpp`, `squareMap.h`: Quản lý bảng hoặc lưới trò chơi.
        - `tetromino.cpp`, `tetromino.h`: Logic cho các mảnh Tetromino.
        - `texture.cpp`, `texture.h`: Xử lý tải và quản lý texture.
- **External Libraries/**
    - Thư mục dành cho các thư viện bổ sung được sử dụng trong dự án.
- **README.md**
    - Tài liệu cho dự án.
- **CMakeLists.txt**
    - Tệp cấu hình CMake để xây dựng dự án.
- **stb_image.h**
    - Tệp tiêu đề để tải hình ảnh (sử dụng cho texture).

---

## Yêu cầu

Đảm bảo bạn đã cài đặt các phần mềm sau trên hệ thống:
- Trình biên dịch C++ hỗ trợ C++17 trở lên
- CMake 3.15+
- OpenGL

### Cách cài đặt OpenGL:
#### Trên Ubuntu:
1. Cài đặt thư viện OpenGL:
   ```bash
   sudo apt update
   sudo apt-get install libglew-dev
   ```
2. Kiểm tra phiên bản OpenGL:
   ```bash
   glxinfo | grep OpenGL
   ```
---

## Hướng dẫn tải và cài đặt

### Trên Ubuntu

1. **Tải dự án:**
    - Clone repository từ GitHub:
      ```bash
      git clone git@github.com:ntrg1317/tetris-opengl.git
      cd tetris-opengl
      ```

2. **Cài đặt các thư viện cần thiết:**
    - **GLFW:**
      ```bash
      sudo apt-get install libglfw3-dev
      ```
    - **GLAD:**
        - Truy cập [GLAD](https://glad.dav1d.de/).
        - Chọn OpenGL, Core Profile, và tải tệp.
        - Giải nén và sao chép tệp vào thư mục `include/glad` trong dự án.
      
3. **Xây dựng dự án:**
    - Tạo thư mục `build` và di chuyển vào đó:
      ```bash
      mkdir build && cd build
      ```
    - Chạy CMake để cấu hình dự án:
      ```bash
      cmake ..
      ```
    - Xây dựng dự án:
      ```bash
      cmake --build .
      ```

### Trên Windows

1. **Tải dự án:**
    - Clone repository từ GitHub bằng Git Bash:
      ```bash
      git clone git@github.com:ntrg1317/tetris-opengl.git
      cd tetris-opengl
      ```

2. **Cài đặt các thư viện cần thiết:**
    - **GLFW:**
        - Tải GLFW từ trang chủ: [GLFW Downloads](https://www.glfw.org/download.html).
        - Giải nén và cấu hình trong IDE của bạn (Visual Studio hoặc MinGW).
    - **GLAD:**
        - Truy cập [GLAD](https://glad.dav1d.de/).
        - Chọn OpenGL, Core Profile, và tải tệp.
        - Giải nén và sao chép tệp vào thư mục `include/glad` trong dự án.

3. **Xây dựng dự án:**
    - Sử dụng CMake GUI:
        - Chọn thư mục gốc dự án và thư mục `build` làm nơi lưu trữ tệp biên dịch.
        - Nhấn nút "Configure" và chọn trình biên dịch phù hợp (Visual Studio hoặc MinGW).
        - Nhấn "Generate" để tạo các tệp dự án.
    - Mở tệp dự án bằng Visual Studio hoặc MinGW và tiến hành xây dựng.

---

## Chạy dự án

Sau khi xây dựng, tệp thực thi sẽ nằm trong thư mục `build`. Chạy ứng dụng:

### Trên Ubuntu
```bash
./tetris-opengl
```

### Trên Windows
- Mở tệp `.exe` được tạo từ quá trình xây dựng.

---

## Đóng góp

1. Fork repository.
    ```bash
    git fork git@github.com:ntrg1317/tetris-opengl.git
    ```
2. Tạo nhánh mới:
   ```bash
   git checkout -b feature-name
   ```
3. Commit thay đổi:
   ```bash
   git commit -m "Add your message here"
   ```
4. Push nhánh của bạn:
   ```bash
   git push origin feature-name
   ```
5. Tạo pull request.

---

