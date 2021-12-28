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
    and(e_and,a,b);
    and(f_and,e_and,c);
    and(g_and,f_and,d);    
endmodule