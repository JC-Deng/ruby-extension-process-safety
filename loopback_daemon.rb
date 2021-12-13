# loopback_daemon.rb
require "./demo_ext.so"
require "socket"

critical_service = TCPServer.open(2000)

@data_mutex = Mutex.new
loop do
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