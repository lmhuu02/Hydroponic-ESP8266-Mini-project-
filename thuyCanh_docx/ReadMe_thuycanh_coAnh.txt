

/****************************************************/
A. 
time: 4/8/2023
location: Thai Nguyen, Viet Nam
project: smart farm (thủy canh mini)
driver: hardware, application smartphone
hardware: esp8266, pin, pin mat troi, on ap mach sac, dong co bom nuoc
	mang dung nuoc, relay, sensor: dht11, anh sang, do ph nuoc
name: Duong Ngoc Anh - Phu Binh, Thai Nguyen.
/****************************************************/

/----------------------------------------------------/
B.
1, câu hỏi cần trả lời:

	1. sp khác gì những sp khác trên thị trường?
	2. điểm mới, tính sáng tạo, tính thương mại hóa?
	3. tổng chi phí để hoàn thiện 1 sp trong thực tế?
	4. độ bền trong nhiều điều kiện khác nhau là như thế nào?
	5. App trên điện thoại có sử dụng dễ dàng không?


2, yêu cầu khi làm:
	1. không được copy, đảm bảo tính độc quyền. NOTE
	2. đảm bảo yếu tố thẩm mĩ, hoạt động ổn định.
	3. quay video, chụp ảnh quá trình, linh kiện, lắp ráp, vận hành.
	4. chuẩn bị nội dung đến sp: trả lời câu hỏi ở trên.\
	
	
/----------------------------------------------------/

/====================================================/
C. 
1, gia đoạn 1: chuẩn bị tư liêu, linh kiện
	1. tông hợp tất cả thông tin về thuy canh trong nuoc va ngoai nuoc.
		cơ chế hoạt động, mô hình, lắp ráp, nguyên liệu, giá thành.
		các loại rau khác nhau, thời gian sinh trưởng, đặc tính riêng.
		tổng hợp sâu có chọn lọc, đọc kỹ, dễ hiểu, nhiều nguồn.
		
	2. chuẩn bị trang thiết bị: phần cứng, phần mềm
		esp, bơm, pin mặt trời, cb,... 
		IDE, laptop, git, firebase, mô phỏng.....
		
2, gia đoại 2: thực hiện 2 phần:
	1. chạy tự động, có sản phẩm demo
		- kết nối phần cứng: esp+bơm+dht11+ph+as+pinmăt trời + khung cơ bản.
		- điều khiển bơm nước, độ ẩm, ánh sáng, mực nước
		- kết nối firebase, wifi -> đẩy dữ liệu lên.
	2. chạy điều khiển trên app
		- build app gồm: lấy dữ liệu từ firebase: nhiệt độ, độ ẩm, độ ph, mực nước, trạng thái bơm, k bơm, đèn tắt hay bật, thời gian bắt đầu gieo hat, ước lượng thời gian thu hoạch.
	3. test, kiểm tra độ ổn định và sửa lỗi.
	4. tổng hợp thông tin,đóng gói sản phẩm
	
/====================================================/

