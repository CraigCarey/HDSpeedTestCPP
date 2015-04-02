# compiles a cpp file and then uploads it to the VAR-SOM via SSH with password

#!/bin/sh

# compile
echo compiling...
arm-linux-gnueabi-g++ *.cpp -o speed_test
echo compiled

# secure copy with password
echo uploading...
export SSHPASS=toor			# so pw not sent as plaintext
sshpass -e scp -r speed_test craig@192.168.1.68:/tmp/
echo uploaded
echo running...
echo
sshpass -e ssh craig@192.168.1.68 'cd /tmp/ && ./speed_test'
#echo
#sshpass -e ssh craig@192.168.1.68 'ls /tmp/'
#echo
#sshpass -e ssh craig@192.168.1.68 'cat /tmp/write_test'
#sshpass -e ssh craig@192.168.1.68 'rm /tmp/speed_test'
#sshpass -e ssh craig@192.168.1.68 'rm /tmp/write_test'
echo
