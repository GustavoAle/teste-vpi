module main;
    reg [11:0] val = {12{1'b0}};
    //reg [2:0] val;
    
    reg clk = 1'b0;


    always @(posedge clk)
    begin
        val = val + 1;
        clk = ~clk;
        $clkval(val);
    end

    always @(negedge clk)
    begin
        clk = ~clk;
    end

    initial 
    begin
        clk = ~clk;    
    end


    // initial 
    // begin: proc0
    //     integer i;
    //     for (i = 0; i < 10; i = i+1) 
    //     begin
    //         $increment(val);
    //         $display("After $increment, val=%d", val);
    //         $increment(val);
    //         $display("After $increment, val=%d", val);
    //                 $increment(val);
    //         $display("After $increment, val=%d", val);
    //     end
    // end
endmodule