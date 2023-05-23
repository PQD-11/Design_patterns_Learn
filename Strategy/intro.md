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

|       NoDiscountStrategy          |       |       HalfDiscountStrategy        |
-------------------------------------       -------------------------------------
| DoDiscount(price: double): double |       | DoDiscount(price: double): double |


Thuận tiện cho việc thay đổi các loai Discount, chỉ cần thay đổi loại discount.
class PromoteStrategy trong C# được gọi interface

*Lưu ý: Việc sử dụng con trỏ cho _promoteStrategy trong class Ticket cho phép linh hoạt thay đổi các loại Discount trong khui chương trinh đang chạy. Khi sủ dụng con trỏ có thể thay đổi đối tượng Discount bằng cách chỉ định một Discount khác thông qua con trỏ
Lý do chính để sử dụng con trỏ là để tránh việc sao chép toàn bộ đối tượng Discount mỗi khi muốn thay đổi. Nếu sử dụng trực tiếp thay vi con trỏ, việc thay đổi Discount sẽ yêu cầu tạo ra một bản sao của đối tượng và phải gán lại vào Ticket. Điều này không chỉ tốn thời gian và tài nguyên mà còn gây ra vấn đề hiệu suất và bộ nhớ. 