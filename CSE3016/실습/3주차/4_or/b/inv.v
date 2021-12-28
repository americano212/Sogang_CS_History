`timescale 1ns / 1ps


module inv(
    input a,
    input b,
    input c,
    input d,
    output e_and,
    output f_and,
    output g_and    
    );
    or(e_and,a,b);
    or(f_and,e_and,c);
    or(g_and,f_and,d);    
endmodule