`timescale 1ns / 1ps


module inv(
    input a,
    input b,
    input c,
    output d_and,
    output e_and
    );
    assign d_and = a & b;
    assign e_and = d_and & c;
    
endmodule