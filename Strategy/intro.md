        |   Ticket                                                      |
        -----------------------------------------------------------------
        | _price: double                                                |
        | _promoteStrategy: PromoteStrategy                             |
        | _name: string                                                 |
        -----------------------------------------------------------------
        | GetPromoteStrategy(): PromoteStrategy                         |
        | SetPromoteStrategy(promoteStrategy: PromoteStrategy): void    |
        | GetPromotedPrice(): double                                    |
        | GetPrice(): double                                            |
        | SetPrice(price: double): void                                 |
        | GetName(): string                                             |
        | SetName(name: string): void                                   |
        -----------------------------------------------------------------
                                        ||           
                                        vv            

                    |   PromoteStrategy                 |  
                    -------------------------------------
                    | DoDiscount(price: double): double |   
                    -------------------------------------
                                        ||
                                        vv       
|       NoDiscountStrategy          |       |       HalfDiscountStrategy        |
-------------------------------------       -------------------------------------
| DoDiscount(price: double): double |       | DoDiscount(price: double): double |


Thuận tiện cho việc thay đổi các loai Discount, chỉ cần thay đổi loại discount.
class PromoteStrategy trong C# được gọi interface

*Lưu ý: Việc sử dụng con trỏ cho _promoteStrategy trong class Ticket cho phép linh hoạt thay đổi các loại Discount trong khi chương trình đang chạy. Khi sử dụng con trỏ có thể thay đổi đối tượng Discount bằng cách chỉ định một Discount khác thông qua con trỏ (chỉ cần thay đổi đối tượng mà con trỏ _promoteStrategy đang trỏ tới thông qua hàm SetPromoteStrategy)
Lý do chính để sử dụng con trỏ là để tránh việc sao chép toàn bộ đối tượng Discount mỗi khi muốn thay đổi. Nếu sử dụng trực tiếp thay vì con trỏ, việc thay đổi Discount sẽ yêu cầu tạo ra một bản sao của đối tượng và phải gán lại vào Ticket. Điều này không chỉ tốn thời gian và tài nguyên mà còn gây ra vấn đề hiệu suất và bộ nhớ. 

Tính đa hình: bằng cách sử dụng con trỏ IPromoteStrategy* lớp Ticket có thể tham chiếu đến các đối tượng "IPromoteStrategy" khác nhau với các hành vi khác nhau. Điều này cho phép Ticket hoạt động với các loại Promote khác nhau mà không cần biết chi tiết các lớp Promote khác nhau. Khi ticket thực thi "GetPromotedPrice" thì lớp Ticket sẽ thực thi hành vi DoDiscount của lớp Promote mà con trỏ _promoteStrategy đang trỏ tới.