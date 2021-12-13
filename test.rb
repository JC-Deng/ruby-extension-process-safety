# test.rb  
require "./demo_ext.so"  
  
test_file_generate()  
10.times do  
    Process.fork do  
        test_file_increase()  
    end  
end  
Process.waitall

puts test_file_read() 