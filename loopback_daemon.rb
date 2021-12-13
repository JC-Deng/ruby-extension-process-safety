# loopback_daemon.rb
require "./demo_ext.so"
require "socket"

critical_service = TCPServer.open(2300)

@data_mutex = Mutex.new
10.times do
    Thread.start(critical_service.accept) do |client|
        command = client.gets
        if command.include?"update_data"
            loop do
                if @data_mutex.try_lock
                    test_file_increase
                    @data_mutex.unlock
                    break
                end
            end
        end
        client.close
    end
end

sleep(0.5)
puts "\nResult with loopback protection:"
puts test_file_read