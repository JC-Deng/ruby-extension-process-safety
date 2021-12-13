# file_lock.rb
require "./demo_ext.so"

def file_lock_increase
    loop do
        lock_status = File.new("./demo_data.lock").flock(File::LOCK_NB|File::LOCK_EX)
        if lock_status == 0
            puts Process.pid
            puts "Lock acquired.\n"
            test_file_increase
            break
        end
    end
end

test_file_generate
10.times do
    Process.fork do
        file_lock_increase
    end
end
Process.waitall

puts "\nResult with file lock protection:"
puts test_file_read