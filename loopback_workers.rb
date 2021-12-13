# loopback_workers.rb
require "./demo_ext.so"
require "socket"

test_file_generate
10.times do
    Process.fork do
        connection = TCPSocket.open("localhost", 2000)
        connection.puts("update_data")
        connection.close
    end
end
Process.waitall

puts "\nResult with loopback protection:"
puts test_file_read